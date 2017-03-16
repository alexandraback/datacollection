#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <deque>
#include <cstring>
#include <functional>
#include <climits>

using namespace std;

int t,n,m;
char x;
char y[10005];
int cnt[10005][8];
char z[10005];
int tt;
int times[8][8]={{0,1,2,3,4,5,6,7},{1,4,3,6,5,0,7,2},{2,7,4,1,6,3,0,4},{3,2,5,4,7,6,1,0}};
bool ok;

int main(){
	for(int a=4;a<8;a++)for(int b=0;b<8;b++)times[a][b]=(times[a-4][b]+4)%8;
	scanf("%d",&t);
	for(int a=1;a<=t;a++){
		memset(cnt,0,sizeof(cnt));
		scanf("%d%c",&n,&x);
		scanf("%d%c",&m,&x);
		for(int b=0;b<n;b++)scanf("%c",&y[b]);
		scanf("%c",&x);
		//for(int b=0;b<n*m;b++)printf("%c",y[b%n]);printf("\n");
		cnt[0][0]=1;
		tt=0;
		for(int b=0;b<n*m;b++){
			for(int c=0;c<8;c++)cnt[b+1][c]=cnt[b][c];
			if(y[b%n]=='i')tt=times[tt][1];
			else if(y[b%n]=='j')tt=times[tt][2];
			else tt=times[tt][3];
			z[b]=tt;
			cnt[b+1][tt]++;
			//for(int c=0;c<8;c++)printf("%d ",cnt[b+1][c]);printf("\n");
		}
		ok=false;
		if(tt==4){
			//printf("!\n");
			for(int b=0;b<n*m-2;b++){
			 	//if(z[b]==1)printf("! %d %d %d\n",b,cnt[n*m-2+1][3],cnt[b+1][3]);
				if(z[b]==1&&cnt[n*m-2+1][3]-cnt[b+1][3]>0){
					ok=true;
					break;
				}
			}
		}
		if(ok)printf("Case #%d: YES\n",a);
		else printf("Case #%d: NO\n",a);
	}
	//system("pause");
	return 0;
}
