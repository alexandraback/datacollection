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
#define feq(x,y) (fabs((x)-(y)) <= eps)
#define flt(x,y) ((x)+eps < (y))
#define fle(x,y) ((x)+eps <= (y))
#define fgt(x,y) ((x) > (y)+eps)
#define fge(x,y) ((x) >= (y)+eps)
using namespace std;

int T,n,r,c,w,ans;
int main(){
    scanf("%d", &T);
    for(int qwe=1; qwe<=T;qwe++){
	scanf("%d%d%d", &r,&c,&w);
	ans = (r-1)*(c/w);
	ans += (c - w)/w + w + (c%w != 0);

	printf("Case #%d: %d\n", qwe, ans);
    }
    return 0;
}
