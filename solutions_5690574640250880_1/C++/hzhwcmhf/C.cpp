#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#include <iomanip>
#include <string>
#ifndef _GLIBCXX_DEBUG
#define NDEBUG
#endif
#include <cassert>
#include <complex>
using namespace std;
#ifdef _GLIBCXX_DEBUG
string filename(__FILE__,string(__FILE__).find(".cpp"));
#endif
#define PB push_back
#define MP make_pair
#define SIZE(a) ((int)a.size())
#define REP(x,a) for(typeof(a.begin()) x=a.begin();x!=a.end();x++)
#define ACS(a,b) (a?a->b:0)
#define EACS(a,b,c) (a?a->b:c)
#define AUTO(a,b) typeof(b) a=(b)
#define ft first
#define sd second
const int INF=0x3f3f3f3f;
const long long INFLL=0x3f3f3f3f3f3f3f3fLL;
template<class T>
inline bool tension(T &a,const T &b)
{
	if(b<a){
		a=b;
		return true;
	}
	return false;
}
template<class T>
inline bool relax(T &a,const T &b)
{
	if(a<b){
		a=b;
		return true;
	}
	return false;
}
int T;
int main()
{
	//freopen((filename+".in").c_str(),"r",stdin);
	//freopen((filename+".out").c_str(),"w",stdout);
	//freopen((filename+".err").c_str(),"w",stderr);
	scanf("%d",&T);
	int CN=0;
	while(T--){
		printf("Case #%d:\n",++CN);
		int n,m,p;
		scanf("%d %d %d",&n,&m,&p);
		p=n*m-p;
		int i,j;
		if(n==1 && m==1){
			printf("c\n");
		}else if(n==1 || m==1){
			for(i=1;i<=n;i++){
				for(j=1;j<=m;j++){
					if(i==1 && j==1){
						printf("c");
						p--;
					}else if(p){
						printf(".");
						p--;
					}else{
						printf("*");
					}
				}
				printf("\n");
			}
		}else{
			if(p==1){
				for(i=1;i<=n;i++){
					for(j=1;j<=m;j++){
						if(i==1 && j==1){
							printf("c");
						}else{
							printf("*");
						}
					}
					printf("\n");
				}
				continue;
			}
			for(i=2;i<=n;i++){
				for(j=2;j<=m;j++){
					if(p<=i*j && p>=i*j-(i-2)*(j-2)){
						goto suc;
					}
				}
			}
			printf("Impossible\n");
			continue;
			suc:
			int q=i,w=j,left = p-i*j+(i-2)*(j-2);
			for(i=1;i<=n;i++){
				for(j=1;j<=m;j++){
					if(i==1 && j==1){
						printf("c");
					}else if(i<=q && j<=w && (i<=2 || j<=2 || left)){
						if(i>2 && j>2){
							left--;
						}
						printf(".");
					}else{
						printf("*");
					}
				}
				printf("\n");
			}
		}
	}
	return 0;
}
