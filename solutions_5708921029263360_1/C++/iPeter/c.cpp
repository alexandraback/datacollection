#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int J,P,S,K,m=0;
int q[5000][3],s[4],p[3000],g[30][30],qq[3];

int chk[5000], ansp[3000];
int ansq[5000][3];

void dfs(int a){
	if(a==3){
		for (int i = 0; i < 3; ++i)
		{
			q[m][i] = qq[i];
		}
		m++;
		return;
	}
	for (int i = 0; i < s[a]; ++i)
	{
		qq[a] = i+1;
		dfs(a+1);
	}
}

int ans;
void f(int a, int b){
	if (m-a+b <= ans)
	{
		return;
	}
	if(a == m){
		if(b < ans) return;
		ans = b;
		for (int i = 0; i < m; ++i)
		{
			ansp[i]=p[i];
		}
		return;
	}

	p[a] = 1;
	chk[q[a][0]*100 + q[a][1]*10] ++;
	chk[q[a][2] + q[a][1]*10] ++;
	chk[q[a][0]*100 + q[a][2]] ++;
	if (chk[q[a][0]*100 + q[a][1]*10] <= K &&
		chk[q[a][2] + q[a][1]*10] <= K &&
		chk[q[a][0]*100 + q[a][2]] <= K)
	{
		f(a+1, b+1);
	}

	chk[q[a][0]*100 + q[a][1]*10] --;
	chk[q[a][2] + q[a][1]*10] --;
	chk[q[a][0]*100 + q[a][2]] --;
	p[a] = 0;
	f(a+1, b);
}

void ff(){

	ans = m;
	for (int a = 0; a < m; ++a)
	{
		chk[q[a][0]*100 + q[a][1]*10] ++;
		chk[q[a][2] + q[a][1]*10] ++;
		chk[q[a][0]*100 + q[a][2]] ++;
	}

	while(1){
		int x=0;
		for (x = 0; x <= 1000 && chk[x]<=K; ++x);
		if(x>1000)break;

		bool flag = 1;
		for (int a = 0; a < m; ++a)
		{
			if(p[a]==1)continue;
			int v1 = q[a][0]*100 + q[a][1]*10;
			int v2 = q[a][2] + q[a][1]*10;
			int v3 = q[a][0]*100 + q[a][2];
			if (chk[v1]>K && chk[v2]>K && chk[v3]>K)
			{
				flag = 0;
				chk[v1] --;
				chk[v2] --;
				chk[v3] --;
				p[a] = 1;
				ans--;
			}
		}
		if(flag == 0)continue;

		for (int a = 0; a < m; ++a)
		{
			if(p[a]==1)continue;
			int v1 = q[a][0]*100 + q[a][1]*10;
			int v2 = q[a][2] + q[a][1]*10;
			int v3 = q[a][0]*100 + q[a][2];
			if ((chk[v1]>K && chk[v2]>K) || (chk[v1]>K && chk[v3]>K) || (chk[v3]>K && chk[v2]>K))
			{
				flag = 0;
				chk[v1] --;
				chk[v2] --;
				chk[v3] --;
				p[a] = 1;
				ans--;
			}
		}
		if(flag == 0)continue;

		for (int a = 0; a < m; ++a)
		{
			if(p[a]==1)continue;
			int v1 = q[a][0]*100 + q[a][1]*10;
			int v2 = q[a][2] + q[a][1]*10;
			int v3 = q[a][0]*100 + q[a][2];
			if (chk[v1]>K || chk[v2]>K || chk[v3]>K)
			{
				flag = 0;
				chk[v1] --;
				chk[v2] --;
				chk[v3] --;
				p[a] = 1;
				ans--;
			}
		}
	}

	for (int a = 0; a < m; ++a)
	{
		if(p[a]==0)continue;
		int v1 = q[a][0]*100 + q[a][1]*10;
		int v2 = q[a][2] + q[a][1]*10;
		int v3 = q[a][0]*100 + q[a][2];
		if (chk[v1]<K && chk[v2]<K && chk[v3]<K)
		{
			chk[v1] ++;
			chk[v2] ++;
			chk[v3] ++;
			p[a] = 0;
			ans++;
		}
	}

}

int main(void){
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        scanf("%d%d%d%d",&J,&P,&S,&K);
        s[0]=J;s[1]=P;s[2]=S;
        m=0;
        dfs(0);

        // for(int i=0;i<m;i++)
        // 	for(int j=0;j<m;j++){
        // 		if(q[i][0] == q[j][0] && q[i][1] == q[j][1]) g[i][j] = 1;
        // 		else if(q[i][2] == q[j][2] && q[i][1] == q[j][1]) g[i][j] = 1;
        // 		else if(q[i][0] == q[j][0] && q[i][2] == q[j][2]) g[i][j] = 1;
        // 		else g[i][j] = 0;
        // 	}

        int mans = 0;
        ans = 0;
        // f(0, 0);

        for (int i = 0; i < 5000; ++i)
        {
		    memset(p, 0, sizeof(p));
		    memset(chk, 0, sizeof(chk));
		    random_shuffle(q, q+m);
		    ff();
        	if (mans < ans)
        	{
        		mans = ans;
        		for (int i = 0; i < m; ++i)
        		{
        			ansp[i]=p[i];
        			ansq[i][0]=q[i][0];
        			ansq[i][1]=q[i][1];
        			ansq[i][2]=q[i][2];
        		}
        	}
        }

        printf("Case #%d: %d\n", tt, mans);
        for (int i = 0; i < m; ++i)
        {
        	if(ansp[i]==1) continue;
        	printf("%d %d %d\n", ansq[i][0], ansq[i][1], ansq[i][2]);
        }
    }
    return 0;
}

