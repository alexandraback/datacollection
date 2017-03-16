#include<stdio.h>
#include<cstring>
char s[1000005];
int N;
int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int T;
	scanf("%d",&T);
	int i, cnt;
	long long tot;
	int tt;
	for(int t = 1; t <= T; t++)
	{
		tot = 0;
		cnt = 0;
		tt = -99;
		scanf("%s %d", s, &N);
		int l =strlen(s);
		for(i = 0; i < l; i++)
		{
			if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] =='u'){
				cnt = 0;
			}
			else cnt++;

			if(cnt >= N){
				tot += (i+2-N);
				tt = i+2-N; 
			}
			else {
				if(tt == -99) continue;
				else tot += tt;
			}
		}
		printf("Case #%d: %lld\n", t, tot);
	}
	return 0;
}