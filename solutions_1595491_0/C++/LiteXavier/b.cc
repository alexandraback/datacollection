#include <cstdio>
#include <cstring>
#include <cstdlib>

const int sub_surp_const[] = {3, 4, 2};
const int sub_nosurp_const[] = {0, 1, 2};
const int plus_surp_const[] = {1, 1, 2};
const int plus_nosurp_const[] = {0, 1, 1};

int n, s, p;
int a[1000];
int dv[1000], rs[1000];
bool cansurp[1000];
bool issurp[1000];
int score_nosurp[1000];
int score_surp[1000];

int main ()
{
	int t;
	scanf("%d",&t);
	int caseno;
	for(caseno = 1; caseno <= t; caseno ++ )
	{
		scanf("%d%d%d",&n,&s,&p);
		for(int i = 0; i < n; i ++ )
		{
			scanf("%d",a+i);
			dv[i] = a[i]/3;
			rs[i] = a[i]%3;
			cansurp[i] = (a[i] >= sub_surp_const[rs[i]] && dv[i]+plus_surp_const[rs[i]]<=10);
		}
		for(int i = 0; i < n; i ++ )
		{
			score_nosurp[i] = dv[i] + plus_nosurp_const[rs[i]];
			if( cansurp[i] )
				score_surp[i] = dv[i] + plus_surp_const[rs[i]];
			else
				score_surp[i] = -1;
		}
		memset(issurp,0,sizeof(issurp));

		for(int i = 0; i < n && s > 0; i ++ )
			if( cansurp[i] && score_nosurp[i] < p && score_surp[i] >= p )
				issurp[i] = true, s--;
		
		for(int i = 0; i < n && s > 0; i ++ )
			if(!issurp[i] && cansurp[i])
				issurp[i] = true, s--;

		int ans = 0;
		for(int i = 0; i < n; i ++ )
			if(issurp[i])
				ans+=(score_surp[i]>=p?1:0);
			else
				ans+=(score_nosurp[i]>=p?1:0);	

		printf("Case #%d: %d\n", caseno, ans);
	}
	return 0;
}
