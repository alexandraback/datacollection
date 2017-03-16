#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int a[10000010], t;
char ch[100];
bool f(long long a){
	int tot = 0;
	while(a){
		ch[tot++] = a%10 + '0';
		a /= 10;
	}
	for(int i = 0,j = tot-1;j > i; ++i,--j)
		if(ch[i] != ch[j]) return false;
	return true;
}
int binary(long long x){
	int l = 0, r = t-1, mid;
	while(r >= l){
		mid = (l + r) >> 1;
		if(1ll*a[mid]*a[mid] >= x) r = mid - 1;
		else l = mid + 1;
	}
	return l;
}
int main()
{
	freopen("C-large-1.in","r",stdin);
	freopen("C-large-1.out","w",stdout);
	t = 0;
	for(int i = 0;i <= 10000000; ++i)
		if(f(i)) a[t++] = i;
	int T;
	scanf("%d",&T);
	long long A, B;
	for(int it = 1;it <= T; ++it){
		printf("Case #%d: ",it);
		scanf("%lld%lld",&A,&B);
		int x = binary(A);
		int ret = 0;
		for(int i = x;i < t && 1ll*a[i]*a[i] <= B; ++i){
			//printf("!!%lld\n",1ll*a[i]*a[i]);
			if(f(1ll*a[i]*a[i])) ret ++;
		}
		printf("%d\n",ret);
	}
}
