#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int get_comb(int n,int k){
	if(n==k) return 1;
	int res=1;
	for(int i=0;i<k;i++){
		res*=n-i;
	}
	for(int i=0;i<k;i++){
		res/=k;
	}
	return res;
}

double get_prob(int num_correct,int count){
//	cout<<"call "<<num_correct<<" "<<count<<endl;
	if(num_correct<=0) return 1.;
	int c=0;
	for(int i=0;i<=count-num_correct;i++){
		c+=get_comb(count,i);
	}
	double res=1.0*c;
	for(int i=0;i<count;i++){
		res/=2.0;
	}
	return res;
}

int main()
{
	int T;
	cin>>T;
	int num[4]={1,6,15,28};
	for(int t=1;t<=T;t++){
		int N,X,Y;
		cin>>N>>X>>Y;
		double ans=1.0;
		if(X<0) X*=-1;
		int m_idx=(X+Y)/2;
		int c_idx=m_idx*2-X;
		int given_m_idx=1;
		//		cout<<m_idx<<" "<<c_idx<<endl;
		//		cout<<given_m_idx<<endl;

		if(N>=num[1]) given_m_idx=2;
		if(N>=num[2]) given_m_idx=3;

		bool is_end=false;
		for(int i=0;i<4;i++){
			if(N==num[i] && X==0 && Y<=i){
				ans=1.0;
				is_end=true;
			}
		}
		if(!is_end){
			if(given_m_idx>m_idx) ans=1.0;
			else if(given_m_idx<m_idx) ans=0.0;
			else{//same mount
				if(c_idx==m_idx*2){//top
					if(N==num[m_idx]) ans=1.0;
					else ans=0.0;
				}
				else{//not top
					int count=N-num[m_idx-1];
					int num_correct=c_idx+1;
					int ahure=count-(num[m_idx]-num[m_idx-1]-1)/2;
					if(ahure-1>=c_idx) ans=1.0;
					else ans=get_prob(num_correct,count);
				}
			}
		}
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
}