#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include <iomanip>
#define big 1000000000
#define eps (1e-9)
typedef long long ll;

using namespace std;
ll N, x, y, ch, tot, x1;
vector<int> v;
vector<vector<double> > sav;

double f(ll x, ll N){
    if(x==0) return 1.0;
    if(x>N) return 0;
    if(sav[x][N]>-eps) return sav[x][N];
    double res=0;
    if(tot-N-x1+x>=ch){
        res = f(x-1, N-1);
    }else
    res = 0.5*f(x-1, N-1) + 0.5*f(x,N-1);
    sav[x][N] = res;
    return res;
}

int main(){
	int C;
	cin>>C; 
	for(int j=0; j<C; j++){
		cin>>N>>x>>y;
        double res=0;
        ll s=1, r=0, nr=1;
        while(s<N){
            nr+=4;
            r++;
            s+=nr;
        }
        if(s==N){
            if(abs(x)+y<=r*2)res=1; else res=0;
        }else{
            s-=nr;  r--; 
            if(abs(x)+y<=r*2)res=1; 
                else if( abs(x)+y>(r+1)*2 || x==0)res=0;
            else{
                sav.clear(); sav.resize(y+2, vector<double>(N-s+1, -1.0));
                ch = nr/2; tot=N-s; x1=y+1;
                res = f(y+1, N-s);
            }
        }
        
        //precision
		cout<<"Case #"<<j+1<<": "<<setprecision(10) <<res<<"\n";
	}
	
}
