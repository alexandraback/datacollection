#include<iostream>
using namespace std;
long long int* p;
long long int* q;
int main(){
	p=new long long int[20000000];
	q=new long long int[100000];
	
	long long int a;
	long long int b;
	int d[30];
	long long int e10=1;
	long long int tmp;
	long long int tmp2;
	long long int sum;
	int ps;
	ps=0;
	int qs;
	qs=0;

	for(int i=1;i<=7;++i){

		for(long long int j=e10;j<e10*10;++j){
			tmp=j/10;
			sum=0;
			for(int k=1;k<i;++k){
				sum*=10;
				sum+=tmp%10;
				tmp/=10;
			}
			sum+=j*e10;
			p[ps]=sum;
			++ps;
		}

		for(long long int j=e10;j<e10*10;++j){
			tmp=j;
			sum=0;
			for(int k=0;k<i;++k){
				sum*=10;
				sum+=tmp%10;
				tmp/=10;
			}
			sum+=j*e10*10;
			p[ps]=sum;
			++ps;
		}
		e10*=10;
		
	}

	//for(int i=0;i<300&&i<ps;++i){
	//	cout<<p[i]<<endl;
	//}
	//cout<<ps;
	
	int n=10000000;
		 // 1234567
	int up;
	int lo;
	int mi;
	long long int ta;
	for(int i=0;p[i]<=n&&i<ps;++i){
		up=ps-1;
		lo=0;
		ta=p[i]*p[i];

		while(lo<up){
			mi=(up+lo)/2;
			if(p[mi]>ta){
				up=mi-1;
			}
			else if(p[mi]<ta){
				lo=mi+1;
			}
			else{
				up=mi;
				lo=mi;
				break;
			}
		}
		if(p[up]==ta){
			q[qs]=ta;
			++qs;
		}

	}

	//for(int i=0;i<100&&i<qs;++i){
	//	cout<<q[i]<<endl;
	//}
	//cout<<qs;

	int T;
	cin>>T;
	
	int count;
	for(int Ti=1;Ti<=T;++Ti){
		cout<<"Case #"<<Ti<<": ";
		cin>>a>>b;
		count=0;

		for(int i=0;i<n;++i){
			if(q[i]>=a&&q[i]<=b){
				++count;
			}
			if(q[i]>b)
				break;
		}
		cout<<count<<"\n";

	}

	return 0;
}
