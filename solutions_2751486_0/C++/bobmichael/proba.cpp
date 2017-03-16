//#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

ifstream cin("A-small-attempt1.in");
ofstream cout("out2.txt");

int T,n;

bool cns(char c){
	return c!='a' && c!='e' && c!='i' && c!='o' && c!='u';
}

int main(){
	cin>>T;
	for(int t=1;t<=T;t++){
		string s;
		cin>>s;
		cin>>n;
		int v=0;
		for(int i=0;i<s.size();i++){
			for(int j=i;j<s.size();j++){
				int cnt=0;
				for(int k=i;k<=j;k++){
					if(cns(s[k])) cnt++;
					else cnt=0;
					if(cnt>=n){
						v++;
						break;
					}
				}
			}
		}
		//int v=0,L=s.size();
		//int cnt=0;
		//for(int i=0;i<n;i++) if(cns(s[i])) cnt++;
		//int i=0;
		//while(i+n<=L){
		//	if(cnt==n){
		//		v+=(i+1);
		//	}
		//	i++;
		//	if(i+n<=L){
		//		if(cns(s[i-1])){
		//			if(!cns(s[i+n-1])) cnt--;
		//		}
		//		else{
		//			if(cns(s[i+n-1])) cnt++;
		//		}
		//	}
		//}
		cout<<"Case #"<<t<<": "<<v<<endl;
	}
}