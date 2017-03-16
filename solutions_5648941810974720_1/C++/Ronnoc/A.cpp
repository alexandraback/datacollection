#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
#define MP make_pair
#define PB push_back
#define AA first
#define BB second
#define OP begin()
#define ED end()
#define SZ size()
#define cmin(x,y) x=min(x,y)
#define cmax(x,y) x=max(x,y)
#define NAME "/Users/kybconnor/Download/A-small-attempt0"
#define UsingFile 1
const LL MOD = 1000000007;
const double PI = acos(-1.);

char s[11][11]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int f[11][26];
char ss[2222];
int cnt[55];
void del(int x){
	for(int i=0;i<26;i++)
		cnt[i]-=f[x][i];
}
int main(){
    //if(UsingFile)freopen(NAME".in","r",stdin);
    //if(UsingFile)freopen(NAME".out","w",stdout);
    int i,j,k,_T;
    memset(f,0,sizeof f);
    for(i=0;i<10;i++)
    	for(j=0;s[i][j];j++)
    		f[i][s[i][j]-'A']++;
    scanf("%d",&_T);
    for(int CA=1;CA<=_T;CA++){
    	scanf("%s",ss);
    	memset(cnt,0,sizeof cnt);
    	for(i=0;ss[i];i++){
    		cnt[ss[i]-'A']++;
    	}
    	vector<int>L;
    	while(cnt['Z'-'A']>0)del(0),L.PB(0);
    	while(cnt['W'-'A']>0)del(2),L.PB(2);
    	while(cnt['X'-'A']>0)del(6),L.PB(6);
    	while(cnt['S'-'A']>0)del(7),L.PB(7);
    	while(cnt['V'-'A']>0)del(5),L.PB(5);
    	while(cnt['F'-'A']>0)del(4),L.PB(4);
    	while(cnt['R'-'A']>0)del(3),L.PB(3);
    	while(cnt['G'-'A']>0)del(8),L.PB(8);
    	while(cnt['O'-'A']>0)del(1),L.PB(1);
    	while(cnt['I'-'A']>0)del(9),L.PB(9);
    	sort(L.OP,L.ED);
    	printf("Case #%d: ",CA);
    	for(i=0;i<L.SZ;i++)printf("%d",L[i]);
    		printf("\n");
    }
    return 0;
}