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
int main() {
    freopen("te","r",stdin);
	freopen("ans.txt","w",stdout);
	int T;
	cin>>T;
	char c[10000];
	int k,z,A;
	int test=0;
	while (T--){
        scanf("%d%s",&k,&c);
        z=c[0]-'0';
        A=0;
        for (int i=1;i<=k;i++){
            while (c[i]-'0'>0 && i>z) {
            A++;
            z++;
            }
            z+=c[i]-'0';
        }
        printf("Case #%d: %d\n",++test,A);
	}
	return 0;
}
