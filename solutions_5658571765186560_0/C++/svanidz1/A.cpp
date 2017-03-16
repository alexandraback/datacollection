#include <bits/stdc++.h>
#define MA(a,b) ((a)>(b)?(a):(b))
#define MI(a,b) ((a)<(b)?(a):(b))
#define AB(a) (-(a)<(a)?(a):-(a))
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pob pop_back
#define ep 0.00000001
#define pi 3.1415926535897932384626433832795
#define na(x) ((x)<P?(x):(x)-P)
using namespace std;
char* so(int n,int x,int y){
    if (x*y%n) return "RICHARD";
    if (n>6) return "RICHARD";
    for (int i=1;i<=n;i++){
        int j=n-i+1;
        if (!((x>=i && y>=j)||(x>=j && y>=i))) return "RICHARD";
    }
    if (x<y) swap(x,y);
    if (y>n) return "GABRIEL";
    if (y==2) {
        if (n>3) return "RICHARD";
    }
    if (y==3){
        if (n==6){
            return "RICHARD";
        }
    }
    return "GABRIEL";
}
int main() {
	freopen("D2","r",stdin);
	freopen("ans.txt","w",stdout);
	int T;
	cin>>T;
	int n,r,c;
	int test=0;
	while (T--){
        scanf("%d%d%d",&n,&r,&c);
        printf("Case #%d: %s\n",++test,so(n,r,c));
  }
	return 0;
}
