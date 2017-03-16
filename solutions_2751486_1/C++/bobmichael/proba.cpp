//#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

ifstream cin("A-large (1).in");
ofstream cout("out2.txt");

long long T,n;

bool cns(char c){
	return c!='a' && c!='e' && c!='i' && c!='o' && c!='u';
}

int main(){
	cin>>T;
	for(long long t=1;t<=T;t++){
		string s;
		cin>>s;
		cin>>n;

		//NAVIE:
		//long long v=0;
		//for(long long i=0;i<s.size();i++){
		//	for(long long j=i;j<s.size();j++){
		//		long long cnt=0;
		//		for(long long k=i;k<=j;k++){
		//			if(cns(s[k])) cnt++;
		//			else cnt=0;
		//			if(cnt>=n){
		//				v++;
		//				break;
		//			}
		//		}
		//	}
		//}

		long long v=0,L=s.size();
		long long cnt=0;
		for(long long i=0;i<n;i++) if(cns(s[i])) cnt++;
		long long i=0;
		vector<long long> start,end,right;
		for(long long i=0;i<L;i++){ start.push_back(0); end.push_back(0); right.push_back(0); }

		while(i+n<=L){
			if(cnt==n){ start[i]=1; end[i+n-1]=1; }; //start.push_back(i);
			i++;
			if(i+n<=L){
				if(cns(s[i-1])){
					if(!cns(s[i+n-1])) cnt--;
				}
				else{
					if(cns(s[i+n-1])) cnt++;
				}
			}
		}
		long long r=-1;
		long long r2=-1;
		for(long long i=L-1;i>=0;i--){
			if(end[i]) r=i;
			if(i<=(r-n+1)) r2=r;
			right[i]=r2;
		}
		//for(long long i=0;i<L;i++) cout<<right[i]<<" "; cout<<endl;
		for(long long i=0;i<L;i++){
			if(start[i]) v+=L-1-(i+n-1)+1;
			else{
				if(right[i]!=-1 && i<=(right[i]-n)){
					//cout<<s<<endl;
					//for(long long j=0;j<i;j++) cout<<" ";
					//cout<<"^"<<endl;
					v+=L-1-(right[i])+1;
				}
			}
		}
		cout<<"Case #"<<t<<": "<<v<<endl;
	}
}