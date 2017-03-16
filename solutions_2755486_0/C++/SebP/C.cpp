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

///VECTOR show function.
template<class T>
void show(vector<T> & v){
    for(int i=0;i<(int)v.size();i++) cout<<v[i]<<" ";///Horizontal.
    ///for(int i=0;i<v.size();i++) cout<<v[i]<<endl;///Vertical.
    cout<<endl;
}

const int maxN = 10;
int t[maxN][8];
const int di = 0;
const int ni = 1;
const int wi = 2;
const int ei = 3;
const int si = 4;
const int ddi = 5;
const int dpi = 6;
const int dsi = 7;

const int offset = 10000;
vector<int> wall;
vector<int> wall2;

int main(){
freopen("Cin.txt","r",stdin);
freopen("Cout.txt","w",stdout);
	wall.resize(2*offset + 1);
	wall2.resize(2*offset + 1);
	tint TC;cin>>TC;
	formn(tc,1,TC+1){
		int N;cin>>N;
		forn(i,2*offset + 1){
			wall[i] = 0;
			wall2[i] = 0;
		}
		set<pair<int,int> > ataques;///<dia, tribu>
		int totAtaques = 0;
		forn(i,N){
			forn(j,8) cin >> t[i][j];
			ataques.insert(mp(t[i][di],i));
			totAtaques += t[i][ni];
		}
		int res = 0;
		while(totAtaques > 0){
			///proceso los ataques del proximo dia.
			///invariante: t tiene la info del proximo ataque para cada tribu.
			wall2 = wall;///wall 2 guarda la nueva wall despues de los ataque de hoy.
			pair<int,int> primAtaqueDia = *ataques.begin();
			int dia = primAtaqueDia.first;
			bool hayMasAtaquesHoy = true;
			while(hayMasAtaquesHoy){
//cout<<endl;
				pair<int,int> aActual = *ataques.begin();
				ataques.erase(ataques.begin());
				int nTribu = aActual.second;
//cout<<nTribu<<endl;
//cout<<"di ni wi ei si"<<endl;
//cout<<t[nTribu][di]<<"  "<<t[nTribu][ni]<<"  "<<t[nTribu][wi]<<"  "<<t[nTribu][ei]<<"  "<<t[nTribu][si]<<endl;
				int fAtaque = t[nTribu][si];
				///proceso ataque.
				bool aExitoso = false;
				for(int pos = t[nTribu][wi]; pos < t[nTribu][ei]; pos++){
					if(wall[pos + offset] < fAtaque)
						aExitoso = true;
					wall2[pos + offset] = max(wall2[pos + offset] , fAtaque);
				}
				if(aExitoso)
					res++;
//show(wall);
//show(wall2);
//cout<<aExitoso<<endl;
				///updateo la info de la tribu para el prox. ataque.
				t[nTribu][di] += t[nTribu][ddi];
				t[nTribu][ni]--;
				t[nTribu][wi] += t[nTribu][dpi];
				t[nTribu][ei] += t[nTribu][dpi];
				t[nTribu][si] += t[nTribu][dsi];
//cout<<t[nTribu][di]<<"  "<<t[nTribu][ni]<<"  "<<t[nTribu][wi]<<"  "<<t[nTribu][ei]<<"  "<<t[nTribu][si]<<endl;
				///me fijo si tengo que hacer mas ataques.
				if(t[nTribu][ni] >= 1){
					ataques.insert(mp(t[nTribu][di],nTribu));
				}
				totAtaques--; ///hay un ataque menos.
				
				hayMasAtaquesHoy = false;
				if(totAtaques > 0){///hay prox ataque.
					if((*ataques.begin()).first == dia) hayMasAtaquesHoy = true;///hay prox ataque hoy.
				}
			}
			wall = wall2;
		}
		cout<<"Case #"<<tc<<": "<<res<<endl;
	}
    return 0;
}
