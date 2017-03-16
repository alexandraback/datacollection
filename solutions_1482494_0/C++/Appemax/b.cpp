#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int MAXN = 1010;

bool S[MAXN][2];
int d[MAXN][2];

int main()
{
  int t, i, j, k, n, ti;
  int sum, level2_cnt, level_mark, cnt, rate_mark;
	freopen("B-small-attempt3.in", "r", stdin);
	freopen("B-small-attempt3.out", "w", stdout);
	scanf("%d", &t);

	for(ti=0; ti<t; ti++)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++){
		      scanf("%d %d", &d[i][0], &d[i][1]);
		      S[i][0] = S[i][1] = false;
		}

		sum = level2_cnt = 0;
		cnt = 0;
		while(level2_cnt<n){
		  level_mark = -1; rate_mark = -1;
		  for(i=0; i<n; i++)
		    {
		      if(!S[i][1] && !S[i][0] && 1>=rate_mark && sum>=d[i][1]){
			level_mark = i;
			rate_mark = 1;
			break;
		      }
		      else if(!S[i][1] && sum>=d[i][1] && rate_mark<1){
			level_mark = i; rate_mark = 1;
		      }
		      else if(!S[i][0] && S[i][1] && rate_mark<=0 && sum>=d[i][0]){
			  level_mark = i; rate_mark = 0;
		      }
			  else if(!S[i][0] && rate_mark<0 && sum>=d[i][0]){
				  level_mark = i; rate_mark = 0;
			  }
		    }
		      if(level_mark!=-1){
			if(rate_mark==0) sum++;
			else if(rate_mark==1 && S[level_mark][0]) sum++;
			else if(rate_mark==1 && !S[level_mark][0]) sum+=2;
			if(rate_mark==1) level2_cnt++;
			S[level_mark][rate_mark] = true;
			cnt++;
		      }
		      else break;

		}

		  if(level2_cnt<n)
		printf("Case #%d: Too Bad\n", ti+1);
		  else printf("Case #%d: %d\n", ti+1, cnt);
	}

	return 0;
}


