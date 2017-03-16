#include <stdio.h>

int main()
{
	//freopen("G:\\chrome的下载区\\B-small-attempt0.in", "r", stdin);
	//freopen("D:\\B.out", "w", stdout);
	freopen("G:\\chrome的下载区\\B-large.in", "r", stdin);
	freopen("D:\\B-large.out", "w", stdout);
	int i,j,T,N,S,P,cases=0,a[100],num,cnt;
	scanf("%d", &T);
	while (++cases<=T)
	{
		num = 0;
		cnt = 0;
		scanf("%d%d%d", &N, &S, &P);
		for(i=0; i<N; i++)
			scanf("%d", &a[i]);
		for(i=0; i<N; i++)
		{
			switch(a[i]%3)
			{
				case 0:
					if(a[i]/3>=P)
						num++;
					else if(a[i]>0 && a[i]/3+1==P)
						cnt++;
					break;
				case 1:
					if(a[i]/3+1>=P)
						num++;
					break;
				case 2:
					if(a[i]/3+1>=P)
						num++;
					else if(a[i]/3+2==P)
						cnt++;
					break;
				default:;
			}
		}
		if(cnt>=S)
			num += S;
		else
			num += cnt;
		printf("Case #%d: %d\n", cases, num);
	}
	return 0;
}