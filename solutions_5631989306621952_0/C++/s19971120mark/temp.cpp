#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int L,n,i;
int dat[10050];
char st[10050];
char now;

int main(){
	freopen("temp.in","r",stdin);
	freopen("temp.out","w",stdout);
	scanf("%d",&n);
	for (int tt = 1;tt <= n;tt++)
	{
		memset(st,0,sizeof(st));
		scanf("%s",st);
		L = strlen(st);
		now = st[0];
		for (i = 1;i < L;i++)
		{
			if (st[i] >= now)
			{
				now = st[i];
				dat[i] = 1;
			}
			else
			{
				dat[i] = 0;
			}
		}
		printf("Case #%d: ",tt);
		for (i = L-1;i >=0; i--) if (dat[i] == 1) printf("%c",st[i]);
		for (i = 0;i<= L-1; i++) if (dat[i] == 0) printf("%c",st[i]);
		printf("\n");
	}
}
