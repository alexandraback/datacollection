#include<bits/stdc++.h>
#define LL long long 
#define PI acos(-1)
#define x first
#define y second
#define PII pair<int,int>
#define F(x,y,z) for(int (x)=(y);(x)<(z);(x)++)
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define flt(x,y) ((x)+eps < (y))
using namespace std;

int T,n,ans;
vector<PII> hiker;
int main(){
    scanf("%d", &T);
    for(int qwe=1; qwe<=T;qwe++){
	scanf("%d", &n);
	int cnt = 0;
	hiker.clear();
	for(int i=0,tp,tm,th; i<n;i++){
	    scanf("%d%d%d", &tp, &th, &tm);
	    while(th--){
		hiker.pb(mp(tp, tm++));
	    }   
	}	    
		
	if(cnt == 1 || hiker[0].y == hiker[1].y)
	    printf("Case #%d: %d\n", qwe, 0);
	else{
	    sort(hiker.begin(), hiker.end());
	    if(hiker[0].y > hiker[1].y){
		double t0 = (360.0 - hiker[0].x)/(360.0/hiker[0].y);
		double t1 = (720.0 - hiker[1].x)/(360.0/hiker[1].y);
		if(flt(t0,t1)) ans = 0; else ans = 1;
	    }	
	    else{
		double t0 = (360.0 - hiker[0].x)/(360.0/hiker[0].y);
		double t1 = (360.0 - hiker[1].x)/(360.0/hiker[1].y);
		if(flt(t1,t0)) ans = 0;
		else{
		    t0 = (720.0 - hiker[0].x)/(360.0/hiker[0].y);
		    if(flt(t1,t0)) ans = 0;
		    else ans = 1;
		}
	    }
	    printf("Case #%d: %d\n", qwe, ans);
	}
    }
    return 0;
}
