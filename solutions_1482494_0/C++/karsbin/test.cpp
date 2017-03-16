#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int maxn = 11 ;
int order[maxn] , n , visx , visy , sth , ans ;
bool fuck[21][(1<<20)+10] ;

struct node
{
	int x , y ;
}stu[maxn];

inline bool dfs(int score,int cnt,int mm)
{
	int i ;
	if( ans <= cnt || fuck[score][mm] ) return false ;
	if( visy == sth )
	{
		if( ans > cnt ) ans = cnt ;
		return true ;
	}
	bool flag = false ;
	for( i = 0 ; i < n && score >= stu[i].x ; i++) if( !( visx & ( 1 << i ) ) )	//Œ¥”√
	{
        visx |= ( 1 << i ) ;
        if( dfs(score+1,cnt+1,mm|(1<<i)) ) flag = true ;
        visx ^= ( 1 << i ) ;
	}
	for( i = 0 ; i < n ; i++) if( !( visy & ( 1 << i ) ) && score >= stu[i].y )	//Œ¥”√
	{
		visy |= ( 1 << i ) ;
		if( visx & ( 1 << i ) )
		{	if( dfs(score+1,cnt+1,mm|(1<<(i+n))) ) flag = true ;	}
		else
		{	if( dfs(score+2,cnt+1,mm|(1<<(i+n))) ) flag = true ;	}
		visy ^= ( 1 << i ) ;
	}
	fuck[score][mm] = 1 ;
    return flag ;
}

inline void solve()
{
	ans = 2*n + 1;
	visx = visy = 0 ;
	memset(fuck,0,sizeof(fuck));
	if(!dfs(0,0,0))	puts("Too Bad");
	else	printf("%d\n",ans);
}

bool cmp(node i,node j)
{
	return i.x < j.x || ( i.x == j.x && i.y < j.y ) ;
}

int main()
{
	int i , j , t ;
	freopen("bbb.in","r",stdin);
	freopen("outbbb.txt","w",stdout);
	scanf("%d",&t);
	for ( i = 1 ; i <= t ; i++)
	{
		scanf("%d",&n);
		sth = (1<<n) - 1 ;
		for( j = 0 ; j < n ; j++) scanf("%d%d",&stu[j].x,&stu[j].y) ;
		sort(stu,stu+j,cmp);
		//for( j = 0 ; j < n ; j++) printf("%d,%d\n",stu[j].x,stu[j].y);
		/*if( i == 67 )
		{
			printf("-----%d\n",n);
			for( j = 0 ; j < n ; j++)
                printf("----%d,%d\n",stu[j].x,stu[j].y);
		}*/
		printf("Case #%d: ",i);
		solve();
	}
}
