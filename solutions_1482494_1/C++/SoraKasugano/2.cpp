#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define drep(i,r,l) for(int i=r;i>=l;i--)
int n;
struct arr {
	int x , y;
	bool operator<(const arr &t)const {
		return y < t.y || y == t.y && x > t.x;	
	}
}a[1000008];
bool t[1008];
int main() {
	//freopen("1.in" , "r" , stdin);
	//freopen("1.txt" , "w" , stdout);
	int T, p = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		rep(i,1,n)
        scanf("%d%d", &a[i].x, &a[i].y);
		sort(a+1, a+n+1);
		memset(t, 0, sizeof(t));
		p++;
		int k = 0, cnt = 0;
		rep(i,1,n) {
			while (k < a[i].y) {
				bool f = 0;
				drep(j,n,i)
                if (!t[j] && k >= a[j].x) {
                    t[j] = 1; k++; cnt++; f = 1; break;
                }
				if (!f) { printf("Case #%d: Too Bad\n", p); goto end; }
			}
			if (t[i]) k++; else k += 2;	
		}
		printf("Case #%d: %d\n", p, cnt + n);
        end:;
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
