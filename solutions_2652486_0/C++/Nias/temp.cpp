#include <cstdio>
#include <cstring>

int num[10], tt[111];
bool vis[1005];

int main()
{
	freopen("d://test/c-small.in", "r", stdin);
	freopen("d://test/c-small.out", "w", stdout);
	int t, p, n, m, k, cnt = 0;
	bool f;
	
	scanf("%d", &t);
	printf("Case #1:\n");
	scanf("%d %d %d %d", &p, &n, &m, &k);
	while(p--)
	{
		memset(num, 0, sizeof(num));
		cnt = 0;
		memset(vis, false, sizeof(vis));
		for(int i = 0; i < k; i++)
		{
			scanf("%d", &tt[i]);
			t = tt[i];
			if(cnt < n)
			{
				if(t == 1) continue;
				else if(t == 2)
				{
					if(num[2]) continue;
					printf("2"); cnt++; num[2]++; continue;
				}
				else if(t == 3)
				{
					if(num[3]) continue;
					printf("3"); cnt++; num[3]++; continue;
				}
				else if(t == 4){f = 1; continue;}
				else if(t == 5)
				{
					if(num[5]) continue;
					printf("5"); cnt++; num[5]++; continue;
				}
				else if(t == 6)
				{
					if(num[2] && num[3]) continue;
					else if(num[2]){printf("3"); cnt++; num[3]++; continue;}
					else if(num[3]){printf("2"); cnt++; num[2]++; continue;}
					else{printf("23"); cnt+=2; num[2]++; num[3]++; continue;}
				}
				else if(t == 8){vis[t] = 1; continue;}
				else if(t == 9)
				{
					if(num[3] >= 2) continue;
					else if(num[3]){printf("3"); cnt++; num[3]++; continue;}
					else{printf("33"); cnt+=2; num[3]+=2; continue;}
				}
				else if(t == 10)
				{
					if(num[2] && num[5]) continue;
					else if(num[2]){printf("5"); cnt++; num[5]++; continue;}
					else if(num[5]){printf("2"); cnt++; num[2]++; continue;}
					else{printf("25"); cnt+=2; num[2]++; num[5]++; continue;}
				}
				else if(t == 12){vis[t] = 1; continue;}
				else if(t == 15)
				{
					if(num[3] && num[5]) continue;
					else if(num[3]){printf("5"); cnt++; num[5]++; continue;}
					else if(num[5]){printf("3"); cnt++; num[3]++; continue;}
					else{printf("35"); cnt+=2; num[3]++; num[5]++; continue;}
				}
				else if(t == 16){vis[t] = 1; continue;}
				else if(t == 18)
				{
					if(!num[3]) printf("333");
					if(num[3] == 1) printf("33");
					if(num[3] == 2) printf("3");
					cnt = 3; continue;
				}
				else if(t == 20){vis[t] = 1; continue;}
				else if(t == 24)
				{
					if(!num[2]) printf("2");
					if(!num[3]) printf("3");
					if(!num[5]) printf("5");
					cnt = 3; continue;
				}
				else if(t == 25)
				{
					if(num[5] >= 2) continue;
					else if(num[5]){printf("5"); cnt++; num[5]++; continue;}
					else{printf("55"); cnt+=2; num[5]+=2; continue;}
				}
				else if(t == 27)
				{
					if(!num[3]) printf("333");
					if(num[3] == 1) printf("33");
					if(num[3] == 2) printf("3");
					cnt = 3; continue;
				}
				else if(t == 30)
				{
					if(!num[2]) printf("2");
					if(!num[3]) printf("3");
					if(!num[5]) printf("5");
					cnt = 3; continue;
				}
				else if(t == 32)
				{
					if(!num[4]) printf("44");
					if(num[4] == 1) printf("4");
					if(!num[2]) printf("2");
					cnt = 3; continue;
				}
				else if(t == 36)
				{
					if(!num[3]) printf("33");
					if(num[3] == 1) printf("3");
					if(!num[4]) printf("4");
					cnt = 3; continue;
				}
				else if(t == 40)
				{
					if(!num[2]) printf("2");
					if(!num[4]) printf("4");
					if(!num[5]) printf("5");
					cnt = 3; continue;
				}
				else if(t == 45)
				{
					if(!num[3]) printf("33");
					if(num[3] == 1) printf("3");
					if(!num[5]) printf("5");
					cnt = 3; continue;
				}
				else if(t == 48)
				{
					if(!num[4]) printf("44");
					if(num[4] == 1) printf("4");
					if(!num[3]) printf("3");
					cnt = 3; continue;
				}
				else if(t == 50)
				{
					if(!num[5]) printf("55");
					if(num[5] == 1) printf("5");
					if(!num[2]) printf("2");
					cnt = 3; continue;
				}
				else if(t == 60)
				{
					if(!num[3]) printf("3");
					if(!num[4]) printf("4");
					if(!num[5]) printf("5");
					cnt = 3; continue;
				}
				else if(t == 64)
				{
					if(!num[4]) printf("444");
					if(num[4] == 1) printf("44");
					if(num[4] == 2) printf("4");
					cnt = 3; continue;
				}
				else if(t == 75)
				{
					if(!num[5]) printf("55");
					if(num[5] == 1) printf("5");
					if(!num[3]) printf("3");
					cnt = 3; continue;
				}
				else if(t == 80)
				{
					if(!num[4]) printf("44");
					if(num[4] == 1) printf("4");
					if(!num[5]) printf("5");
					cnt = 3; continue;
				}
				else if(t == 100)
				{
					if(!num[5]) printf("55");
					if(num[5] == 1) printf("5");
					if(!num[4]) printf("4");
					cnt = 3; continue;
				}
				else if(t == 125)
				{
					if(!num[5]) printf("555");
					if(num[5] == 1) printf("55");
					if(num[5] == 2) printf("5");
					cnt = 3; continue;
				}
			}
		}
		if(cnt < 3 && f)
		{
			if(vis[8] && vis[16]) 
			{
				if(!num[2])
					printf("244"), cnt = 3;
				else
					printf("44"), cnt = 3;
			}
			else if(vis[8] && vis[20])
			{
				if(!num[2] && !num[5])
					printf("245"), cnt = 3;
				if(!num[2])
					printf("24"), cnt = 3;
				if(!num[5])
					printf("45"), cnt = 3;
				else
					printf("4"), cnt = 3;
			}
			else if(vis[16] && vis[20])
			{
				if(!num[5])
					printf("445"), cnt = 3;
				else
					printf("44"), cnt = 3;
			}
			else if(vis[8] && cnt)
			{
				if(!num[2])
					printf("24"), cnt+=2;
				else
					printf("4"), cnt++;
			}
			else if(vis[16] && cnt) printf("44"), cnt+=2;
			else if(vis[20] && cnt)
			{
				if(!num[5])
					printf("45"), cnt+=2;
				else
					printf("4"), cnt++;
			}
			else if(vis[16]) printf("4");
			else if(vis[20] && !num[5]) printf("5");
		}
		for(int i = 0; i < n-cnt; i++)
				printf("2");
		puts("");
	}
	return 0;
}