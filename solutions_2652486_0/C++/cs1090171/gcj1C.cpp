#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

map<int,int> ma[125],c[25];

int t,r,n,m,k;
vector<int> v;

int preprocess(){
	int l=0;
	for(int i=2;i<=5;i++){
		for(int j=2;j<=5;j++){
			for(int k=2;k<=5;k++){
				ma[l][i]=ma[l][j]=ma[l][k]=1;
				ma[l][i*j]=ma[l][i*k]=ma[l][j*k]=ma[l][i*j*k]=ma[l][1]=1;
				l++;
			}
		}
	}	
	l=0;
	for(int i=1;i<=5;i++){
		for(int j=1;j<=5;j++){	
			c[l][i]=c[l][j]=c[l][k]=c[l][i*j]=c[l][i*k]=c[l][j*k]=c[l][k]=1;
			l++;
		}
	}	
}

bool check2(){
	int l=0;
	bool res=true;
	for(int i=1;i<=5;i++){
		for(int j=1;j<=5;j++){
			if(i<=m && j<=m){
					for(int a=0;a<v.size();a++){
						if(c[l][v[a]]!=1){
							res=false;
							break;
						}
					}
					if(res){
						cout<<i<<j<<endl;
						return true;
					}
					res=true;
			}
		}
	}
}

bool check(){
	int l=0;
	bool res=true;
	for(int i=2;i<=5;i++){
		for(int j=2;j<=5;j++){
			for(int k=2;k<=5;k++){
				if(i<=m && j<=m && k<=m){
					for(int a=0;a<v.size();a++){
						if(ma[l][v[a]]!=1){
							res=false;
							break;
						}
					}
					if(res){
						cout<<i<<j<<k<<endl;
						return true;
					}
					res=true;
				}
				l++;
			}
		}
	}
}

int main(){
	int temp;
	cout<<"Case #1:"<<endl;
	preprocess();
	cin>>t>>r>>n>>m>>k;
	for(int i=0;i<r;i++){
		v.clear();
		for(int j=0;j<k;j++){
			cin>>temp;
			v.push_back(temp);
		}
		if(n==3)
		check();
		if(n==2)
		check2();
		if(n==1){
			for(int i=1;i<=m;i++){
				bool res=true;
				for(int a=0;a<v.size();a++){
					if(v[a]!=1 && v[a]!=i){
						res=false;
						break;
					}
					if(res)
						cout<<i<<endl;
				}
			}
							
		}
	}
	return 0;
}
