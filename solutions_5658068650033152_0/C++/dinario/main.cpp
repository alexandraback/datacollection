#pragma comment(linker, "/STACK:64000000")
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
#define forn(i,n) for (int i=0;i<n;i++)
#define rforn(i,n) for (int i=n-1;i>=0;i--)
#define mp make_pair
#define __int64 long long
#define LL unsigned long long
#define re return
#define N 550000
#define double long double

typedef struct{int len;char c;}tp;
typedef struct{tp p[200];int len;}ts;

void solve(){
	LL i,j,n,k,m;
	cin>>n>>m>>k;
	int res=-1;
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j){
			int mres=i*j;
			if(mres-k<5){
				mres-=i*j-k;
				if(res==-1||mres<res)
					res=mres;
			}
		}
	cout<<res;
}

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C.out","w",stdout);

	LL T,t,i,j,k;
	cin>>T;
	for(t=0;t<T;++t){
		cout<<"Case #"<<t+1<<": ";
		solve();
		cout<<endl;
	}
	return 0;
}