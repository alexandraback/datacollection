#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 1024; 
int d[maxn][maxn] , n ;

inline bool get(int &t)
{
	bool flag = 0 ;
	char c;
	while(!isdigit(c = getchar())&&c!='-') if( c == -1 ) break ;
	if( c == -1 ) return 0 ;
	if(c=='-') flag = 1 , t = 0 ;
	else t = c ^ 48;
	while(isdigit(c = getchar()))	t = (t << 1) + (t << 3) + (c ^ 48) ;
	if(flag) t = -t ;
	return 1 ;
}

inline bool floyed()
{
	int i,j,k;
	for(k = 1; k <= n; k++)
		for(i = 1; i <= n; i++)
			for(j = 1; j <= n; j++)
			if(d[i][k] >= 1 && d[k][j] >= 1)
			{
				d[i][j]++;
				if(d[i][j] >= 2)
				{
					return true;
				}
			}
	return false;
}

int main()
{
    //freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
    int t, Case = 1, i, c, j, num;
    get(t);
    while(t--)
    {
		get(n);
		memset(d,0,sizeof(d));
		for(i = 1; i <= n; i++)
		{
			get(num);
			while(num--)
			{
				get(c);
				d[i][c] = 1;
			}
		}
		printf("Case #%d: %s\n",Case++, floyed() ? "Yes" : "No");
    }
}