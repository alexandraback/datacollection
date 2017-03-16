#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int jp[20][20];
int js[20][20];
int ps[20][20];
int main (){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	for(int cs=1;cs<=t;++cs){
		int j,p,s,k;
		cin>>j>>p>>s>>k;
		vector <int>x;
		vector <int>y;
		vector <int>z;
		for(int c=1;c<=s;++c){
			for(int b=1;b<=p;++b){
				for(int a=1;a<=j;++a){
					jp[a][b]=0;
					js[b][c]=0;
					ps[a][c]=0;
				}
			}
		}
		for(int a=1;a<=j;++a){
			for(int b=1;b<=p;++b){
				for(int c=1;c<=s;++c){
					if(jp[a][b]==k){
						continue;
					}
					if(js[b][c]==k){
						continue;
					}
					if(ps[a][c]==k){
						continue;
					}
					x.push_back(a);
					y.push_back(b);
					z.push_back(c);
					++jp[a][b];
					++js[b][c];
					++ps[a][c];
				}
			}
		}
		cout<<"Case #"<<cs<<": "<<x.size()<<endl;
		for(int i=0;i<x.size();++i){
			cout<<x[i]<<" "<<y[i]<<" "<<z[i]<<endl;
		}
	}
	return 0;
}