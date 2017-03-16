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

///Combinatorios c[n][k] con 0<=n,k<=1000.
///*PARA INICIALIZAR LLAMAR A combinatorios();*
tint c[1001][1001];
void combinatorios(){
    for(int n=0;n<1001;n++) c[n][0]=1;
    for(int n=0;n<1001;n++){
        for(int k=1;k<1001;k++){
            if(k>n) c[n][k]=0;
            else if(n==k) c[n][k]=1;
            else c[n][k]=c[n-1][k-1]+c[n-1][k];
        }
    }
}

tint below(tint lvl){
	return (((2*lvl-1)*2*lvl)/2);
}

int main(){
freopen("Bin.txt","r",stdin);
freopen("Bout.txt","w",stdout);
	int TC;cin>>TC;
	combinatorios();
	formn(tc,1,TC+1){
		tint n,x,y; cin>>n>>x>>y;
		if(x < 0) x = -x;///sin perdida de generalidad x >= 0
		double res = 0.0;
		if((x+y)%2==0){
			tint lvl = (x + y)/2;
			if(n <= below(lvl)) res = 0.0;
			else if( n >= below(lvl + 1)) res = 1.0;
			else{
				/// below(lvl) < n <= below(lvl + 1)
				/// en este nivel hay 4 * lvl + 1 diamantes
				n = n - below(lvl);/// 0 < n < 4*lvl + 1
				if(y == 2*lvl){
					if(n == 4*lvl + 1) res = 1.0;
					else res = 0.0;
				}
				else{
					//cout<<n<<" "<<x<<" "<<y<<" "<<lvl<<endl;
					///ahora el diamante no esta en la punta.
					///y no tengo que pensar en [][]
					double dp[2*lvl+1][2*lvl+1];
					///dp[i][j] = probabilidad de tener despues de i+j tiradas
					///i en la izq y j en la derecha.
					forn(i,2*lvl+2) forn(j, 2*lvl+2) dp[i][j] = 0.0;
					dp[0][0] = 1.0;
					for(int k = 1; k<=n; k++){
						for(int l = 0; l <= 2*lvl; l++){
							for(int r = 0; r <= 2*lvl; r++){
								if((l + r) != k) continue;
								else if(l==0) dp[l][r] = dp[l][r-1]/2.0;
								else if(r==0) dp[l][r] = dp[l-1][r]/2.0;
								else if(l==2*lvl){
									dp[l][r] = dp[l][r-1] + dp[l-1][r]/2.0;
								}
								else if(r == 2*lvl){
									dp[l][r] = dp[l-1][r] + dp[l][r-1]/2.0;
								}
								else{
									dp[l][r] = dp[l][r-1]/2.0 + dp[l-1][r]/2.0;
								}
							}
						}
					}
					res = 0.0;
				//cout<<"va dp:"<<endl;
					for(int l = 0; l<= 2*lvl; l++){
						for(int r = 0; r<= 2*lvl;r++){
							//cout<<l<<" "<<r<<" "<<dp[l][r]<<endl;
							if(r + l == n){
								if((r >= (y+1))) res+=dp[l][r];
							}
						}
					}
				}
			}
		}
		cout<<"Case #"<<tc<<": "<<res<<endl;
	}
    return 0;
}
