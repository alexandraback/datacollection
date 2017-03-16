#include<iostream>
#include<sstream>
#include<iomanip>
#include<array>
#include<stdlib.h>
#include<string>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<map>
#include<utility>
#include<algorithm>
#include<complex>
using namespace std;
#define loop(i,l,r) for(int (i)=(int)(l);(i)<(int)(r);(i)++)
#define rloop(i,l,r) for(int (i)=(int)(l);(i)>(int)(r);(i)--)
#define rep(i,n) loop(i,0,n)
#define rrep(i,n) rloop(i,n-1,-1)
#define INF 0x3f3f3f3f
#define mod 1000000007LL
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef complex<double> C;

vector<string> split(stringstream& ss){
	string str;
	vector<string> res;
	while(ss>>str)res.push_back(str);
	return res;
}

int main(){
		int T,J,P,S,K;
		cin>>T;
		rep(i,T){
				cin>>J>>P>>S>>K;
				int a[10][10],b[10][10],c[10][10];
				vector<array<int,3>> ar;
				array<int,3>tmp;
				rep(j,10)rep(k,10){
						a[j][k]=0;
						b[j][k]=0;
						c[j][k]=0;
				}
				rep(j,S)rep(k,P)rep(l,J){
						if(a[l][k]<K&&b[k][j]<K&&c[l][j]<K&&(j!=k||k!=l)){
							tmp[0]=l,tmp[1]=k,tmp[2]=j;
							ar.push_back(tmp);
							a[l][k]++;
							b[k][j]++;
							c[l][j]++;
						}
				}
				rep(j,S)rep(k,P)rep(l,J){
						if(a[l][k]<K&&b[k][j]<K&&c[l][j]<K&j==k&&k==l){
							tmp[0]=l,tmp[1]=k,tmp[2]=j;
							ar.push_back(tmp);
							a[l][k]++;
							b[k][j]++;
							c[l][j]++;
						}
				}
				cout<<"Case #"<<i+1<<": "<<ar.size()<<endl;
				rep(j,ar.size()){
						rep(k,2)cout<<ar[j][k]+1<<" ";
						cout<<ar[j][2]+1<<endl;
				}
		}
}
