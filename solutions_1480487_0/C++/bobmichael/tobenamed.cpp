//#include<iostream>
#include<fstream>
#include<iomanip>
#include<vector>
using namespace std;

int T,N,X,s[200];

ifstream cin("in");
ofstream cout("out");

bool canAvoidElimination(double f, int ind){
	double sc=f*X+s[ind];
	double left=1.0-f;
	for(int i=0;i<N;i++){
		if(i!=ind && s[i]<sc){
			double needed=(sc-s[i])/X;
			if(left<needed) return true;
			left-=needed;
		}
	}
	if(left==0) return true;
	return false;
}

int main(){
	vector<double> ans;
	cin>>T;
	for(int t=0;t<T;t++){
		ans.clear();
		cin>>N;
		X=0;
		for(int i=0;i<N;i++){
			cin>>s[i];
			X+=s[i];
		}
		for(int i=0;i<N;i++){
			double st=0,end=100,mid;
			for(int j=0;j<500;j++){
				mid=(st+end)/2.0;
				if(canAvoidElimination(mid/100.0,i))
					end=mid;
				else
					st=mid;
			}
			ans.push_back(mid);
		}
		cout<<"Case #"<<t+1<<": ";
		for(int i=0;i<ans.size();i++){ cout<<setprecision(15)<<ans[i]; if(i!=ans.size()-1) cout<<" "; }
		cout<<endl;
	}
	return 0;
}