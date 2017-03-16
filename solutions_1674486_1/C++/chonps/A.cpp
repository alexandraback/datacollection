#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
ifstream fin ("A-large.in");
ofstream fout ("A-large.out");
struct MP{
	long ne,to;
}mp[20003];
long str[1003],he[1003];
bool vis[1003];
int main(){
	long i,j,k,m,n,t,h,e,T;
	bool YES;
	fin >> t;
	for (T=1;T<=t;++T){
		fin >> n;
		memset(he,0,4012);
		m=0;
		for (i=1;i<=n;++i){
			fin >> j;
			while (--j>=0){
				fin >> k;
				mp[++m].to=k;
				mp[m].ne=he[i];
				he[i]=m;
			}
		}
		for (k=1;k<=n;++k){
			h=0;
			e=1;
			str[1]=k;
			memset(vis,0,1003);
			vis[k]=1;
			YES=0;
			while (h<e){
				++h;
				for (i=he[str[h]];i!=0;i=mp[i].ne){
					if (!vis[mp[i].to]){
						vis[mp[i].to]=1;
						str[++e]=mp[i].to;
					}
					else{
						YES=1;
						break;
					}
				}
				if (YES) break;
			}
			if (YES) break;
		}
		if (YES) fout << "Case #" << T << ": Yes" << endl;
		else fout << "Case #" << T << ": No" << endl;
	}
	fin.close();
	fout.close();
	return 0;
}
