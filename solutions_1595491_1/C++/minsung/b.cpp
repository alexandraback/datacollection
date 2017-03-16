#include<cstdio>
#include<algorithm>

#define N 105
using namespace std;

int tc, n, m, p;
int ans;
int data[N];
int main(){
	int i,j,k;
	freopen("Input.txt", "r", stdin);
	scanf("%d",&tc);
	FILE *out = fopen("output.txt", "w");
	for(int tcc = 1; tcc<=tc; tcc++){
		ans = 0;
		scanf("%d %d %d",&n,&m,&p);
		for(i=0;i<n;i++)
			scanf("%d", &data[i]);
		sort(data, data+n);
		for(i=0;i<n;i++){
			if (data[i] < p*3-4) continue;
			if (data[i] >= p*3-2){
				ans++;
				continue;
			}
			if (m==0) continue;
			if (p-2 < 0) continue;
			m--;
			ans++;
		}
		fprintf(out, "Case #%d: %d\n", tcc, ans);
	}
	return 0;
}