#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <sstream>
#include <Windows.h>
#include <iomanip>
#include <list>

using namespace std;

#define pb push_back
#define ppb pop_back
#define pi 3.1415926535897932384626433832795028841971
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
#define pdd pair<double,double>
#define INF 1000000000
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define VI vector <int>
#define ll long long


struct Ataque
{
    int dia;
    int faixa_inicio;
    int faixa_fim;
    int forca;
};

bool fcmp(Ataque a, Ataque b) {
  if(a.dia==b.dia) return a.forca>b.forca;
  return a.dia < b.dia;
}
void doit()
 {
  map<int, int> wall;
  vector<Ataque> ataques;
  int N;
  cin>>N;
  FOR(i, 0, N-1) {
     int di, ni, wi, ei, si, delta_di, delta_pi, delta_si;
     cin>> di>> ni>> wi>> ei>> si>> delta_di>> delta_pi>> delta_si;   
     FOR(j, 0, ni-1) {            
            Ataque novo;
            novo.dia=di+j*delta_di;
            novo.faixa_inicio=wi+j*delta_pi;
            novo.faixa_fim=ei+j*delta_pi;
            novo.forca=si+j*delta_si;  
            ataques.pb(novo); 
     }
  }
  
  sort(all(ataques), fcmp);
  int diaAnterior=-1;
  map<int, int> wallUPD;
  int resp=0;
  FOR(i, 0, L(ataques)-1) {
         if(diaAnterior!=ataques[i].dia) {
             for(map<int,int>::iterator it = wallUPD.begin(); it != wallUPD.end(); it++) {
                   if(wall.find(it->x)!=wall.end()) 
                      wall.find(it->x)->y=it->y;                 
                   else
                      wall.insert(mp(it->x, it->y));
                   
             }                            
             wallUPD.clear();
                                         }
         diaAnterior=ataques[i].dia;
         bool atacou=false;
         FOR(j, ataques[i].faixa_inicio*2, ataques[i].faixa_fim*2) {
                if(wall.find(j)==wall.end() || wall.find(j)->y<ataques[i].forca) {
                    if(wallUPD.find(j)==wallUPD.end()) {
                       wallUPD.insert(mp(j, ataques[i].forca));
                       }
                    atacou=true;
                }
         } 
         if(atacou)resp++;
  }
  cout<<resp;
  
 
}


int main()
{  
   freopen("C-small-attempt0.in", "r", stdin);  
   //freopen("practice.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
    
   int T;
   cin>>T;
   
   for ( int i = 0; i < T; i++ )
   {
     cout<<"Case #"<<i+1<<": ";
     doit();
     cout<<endl;
   }

   return 0;
}
