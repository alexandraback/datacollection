#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
//cout<<"Case #"<<q+1<<": "<<
using namespace std;

vector<long long> lk;

bool isa(string g){
	char c=g[0];
	for(int i=0;i<g.length();i++){
		if(c!=g[i]) return false;
	}
	return true;
}

long long fact(long long z){
	if(z==1 ||z==0) return 1;
	return (z*fact(z-1)) % 1000000007;
}



bool dw(string g){
	char c1=g[0];
	vector<int> hb(26,0);
	hb[(int)(g[0]) - 97]++;
	for(int i=1;i<g.length();i++){
		if(g[i]!=g[i-1]){
			hb[(int)(g[i]) - 97]++;
			lk[(int)(g[i]) - 97]++;
		}
	}
	lk[(int)(g[g.length()-1]) - 97]--;
	for(int i=0;i<26;i++){
		if(hb[(int)(g[i]) - 97]>1) return false;
	}
	return true;
}


bool w(string g){
	char c1=g[0];
	char c2=g[g.length()-1];
	bool a=true;
	for(int i=0;i<g.length();i++){
		if(a){
			if(g[i]==c1) continue;
			else a=false;
		}
		if(!a){
			if(g[i]==c2) continue;
			else return false;
		}
	}
	return true;
}
		

int main(){
	int t;
	cin>>t;
	for(int q=0;q<t;q++){
		int n;
		cin>>n;
		int f=n;
		vector<string> s;	
		vector<int> b(26,0);
		vector<long long>y(26,0);
		lk=y;
		bool e=true;
		for(int j=0;j<n;j++){
			string g;
			cin>>g;
			if(isa(g)){
				//cout<<"isa"<<endl;
				b[(int)(g[0]) - 97]++;
				continue;
			}
			if(!dw(g)){
				//cout<<g<<endl;
				cout<<"Case #"<<q+1<<": "<<0<<endl;
				//cout<<"w"<<endl;
				e=false;
				break;
			}
			//cout<<"LLLLLLLLLLL"<<endl;
			y[(int) (g[0])-97]++;
			y[(int) (g[g.length()-1])-97]++;
		}
		if(!e) continue;
		int xs=0;
		//cout<<"kKKK"<<endl;
		for(int i=0;i<26;i++){
			if(y[i]>0 && lk[i]>0){
				cout<<"Case #"<<q+1<<": "<<0<<endl;
				 e=false;
				 break;
			 }
			if(!(y[i]==0 || y[i]==2 || y[i]==1)){
				 //cout<<"y"<<endl;
				 cout<<"Case #"<<q+1<<": "<<0<<endl;
				 e=false;
				 break;
			 }
			 if(y[i]==2 &&  b[i]!=0){
				 //cout<<"55555555"<<endl;
				 f=f-1-b[i];
				 continue;
			 }
			 if(y[i]==0 && b[i]!=0){
				 //cout<<"555533555"<<endl;
				 f=f-b[i]+1;
				 continue;
			 }
			 if(y[i]==1 && b[i]!=0){
				 //cout<<"5rr5555"<<endl;
				 f=f-b[i];
				 
				 continue;
			 }
			 if(y[i]==2){
				 f=f-1;
				 //cout<<"2222"<<endl;
				 continue;
			 }
			 if(y[i]==1)xs++;
			 
		}
		//cout<<"ffffff"<<endl;
		/*if(xs>2){
			e=false;
			cout<<"xs"<<endl;
			cout<<"Case #"<<q+1<<": "<<0<<endl;
		} */
		if(!e) continue;
		long long ans=1;
		//cout<<"dfgdddddddd"<<endl;
		//cout<<f<<endl;
		ans =ans*fact(f);
		//cout<<"dfgdddddddd"<<endl;
		for(int i=0;i<26;i++){
			ans=ans*fact(b[i]);
		}
		cout<<"Case #"<<q+1<<": "<<ans<<endl;
	}
}
