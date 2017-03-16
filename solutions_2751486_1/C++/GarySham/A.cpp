#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define INF (1<<29)
#define min(x,y) (((x)<(y))?(x):(y))
#define max(x,y) (((x)>(y))?(x):(y))
#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define FOE(i,x,y) for(int i=(x);i<=(y);++i)
#define CLR(i) memset(i,0,sizeof(i))
#define ll long long

int T,len,n,pos;
char s[1000005];
//bool st[1000005];
int slist[1000005];

int main(){
	scanf("%d",&T); gets(s);
	FOE(t,1,T){
		scanf("%s%d",s,&n);
		len = strlen(s);

		//CLR(st);
		pos=0;
		int count=0;
		FOR(i,0,len){
			if ((s[i]=='a') || (s[i]=='e') || (s[i]=='i') || (s[i]=='o') || (s[i]=='u')) count=0;
			else ++count;
			if (count >= n) slist[pos++] = (i - n + 1);
		}

		//FOR(i,0,pos) printf("%d: %d\n",i,slist[i]);

		ll ans=0ll;
		int tpos = 0;
		FOR(i,0,len){
			while ((slist[tpos] < i) && (tpos < pos)) ++tpos;

			if (tpos >= pos) continue;
			else{
				//printf("%d %d %d\n",i,slist[tpos], n);
				ans += (ll)(len - (slist[tpos] + n) + 1);
			}
		}
		printf("Case #%d: %lld\n",t,ans);
	}
	return 0;
}
