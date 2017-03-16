#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

#define miN(a,b) (a<b)?(a):(b)

vector<int> u,v;
int t,n,a,b,stars,levels;

int main(){
	cin>>t;
	for(int i=1;i<=t;i++){
		stars=0;
		levels=0;
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a>>b;
			u.push_back(a);
			v.push_back(b);
		}
		int m=3000;
		bool o=true;
		while((v.size()>0) && o){
			o=false;
			for(int j=0;j<v.size();j++){
				if(stars>=v[j]) {
					if(u[j]>=0)
						stars+=2;
					else
						stars+=1;
					o=true;
					v.erase(v.begin()+j);
					u.erase(u.begin()+j);
					levels++;
					break;
				}
			}
			if(o) continue;
			for(int j=0;j<u.size();j++){
				if(stars>=u[j] && u[j]>=0) {
					stars+=1;
					u[j]=-1;
					o=true;
					levels++;
					break;
				}
			}
		}
		if(v.size()==0)
			cout<<"Case #"<<i<<": "<<levels<<endl;
		else
			cout<<"Case #"<<i<<": Too Bad"<<endl;
		v.clear();
		u.clear();
	}
	return 0;
}
	
