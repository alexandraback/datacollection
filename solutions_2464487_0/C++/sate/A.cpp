#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef long double ld;
int T;
int main(){
  cin >> T;
  for(int loop=1;loop<=T;loop++){
    ll r,t;
    ld dr,dt;
    cin >> r >> t;
    //  dr = (ld)r;
    //  dt = (ld)t;
    //    dt -= dr*M_PI;

    // ld pi = (ld)M_PI;
    /* ll res = 0;
      ll st = 1;
            while ( st<=ed ){
	ll h = (st+ed)/2;
	//	ld n = (ld)h;
	//	cout << h << " := "<< n*n*pi + n*dr*pi - n*pi << " <= "<<dt<<"\n";
	//	if( n*n*pi + n*dr*pi - n*pi <= dt ){
	cout << h << " := "<<h*h + h*r - h << " <= "<<t<<"\n";
	if( h*h + h*r - h <= t ){
	  st = h+1;
	  res = h;
	} else {
	  ed = h-1;
	}
	}*/
    t-=(r+1)*(r+1)-r*r;
    ll res=0;
    if(t<0) res = 0;
    else {
      res = 1;
      for(ll i = 2; ; i+=2){
	//	cout << t << endl;
	t-=(r+i+1)*(r+i+1)-(r+i)*(r+i);
	if(t<0) break;
	res++;
      }
    }
    cout << "Case #" << loop << ": "<<res<<"\n";
  }
}
