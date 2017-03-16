///SACAR FREOPEN.
#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<set>
#include<list>
#include<cstdlib>
#include<cstdio>
#include<iomanip>
#include<stack>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<map>
#include<sstream>

using namespace std;

#define all(c) (c).begin(),(c).end()
#define forn(i,n) for(int i=0;i<(int)n;i++)
#define dforn(i,n) for(int i=n-1;i>=0;i--)
#define formn(i,m,n) for(int i=m;i<(int)n;i++)
#define dformn(i,m,n) for(int i=n-1;i>=m;i--)
#define mp make_pair
#define pb push_back

const double PI=acos(-1.0);

typedef long long tint;
typedef pair<int,int> pint;

int main(){
freopen("Ain.txt","r",stdin);
freopen("Aout.txt","w",stdout);
	tint TC;cin>>TC;
	formn(tc,1,TC+1){
		tint A,N; cin>>A>>N;
		vector<tint> a(N); forn(i,N) cin>>a[i];
		sort(all(a));
		tint res = N;///con N puedo seguro.
		if(A >= 2){
			for(tint saco = 0; saco <= N-1; saco++){
				///el minimo sacando saco.
				tint meto = 0;
				tint B = A;
				tint pos = 0;
				while(pos <= N-1-saco){
					if(a[pos] < B){
						B += a[pos];
						pos++;
					}
					else{
						B += (B-1);
						meto++;
					}
				}
				res = min(res , saco + meto);
			}
		}
		cout<<"Case #"<<tc<<": "<<res<<endl;
	}
    return 0;
}
