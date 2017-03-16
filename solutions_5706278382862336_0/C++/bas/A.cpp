#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define ll long long

using namespace std;
	int   C;
void reduce (ll & p, ll & q){
    ll a=p, b=q;
    ll f = 0;
    while(a>0 && b>0)if(a>b)a%=b; else b%=a;
    f=a+b;
    p/=f; q/=f;
}
int main(){
	
	cin>>C; 
	for(int j=0; j<C; j++){
		ll p, q; char f;
		ll l= 1;
		cin>>p>>f>>q;
		reduce(p,q);
		bool good = false;
		int res =0;
		for(int sh =40; sh>=1; sh--){
		    if((l<<sh) == q){
			res=1; good=true;
			int t=sh-1;
			while( (1<<t)>p){res++; t--;}
		    }
		}
		cout<<"Case #"<<j+1<<": " ;
		if (!good)cout<<"impossible";
		else cout<<res;		
		cout<<"\n";

	}
	
}
