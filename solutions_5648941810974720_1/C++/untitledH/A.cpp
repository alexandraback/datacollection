/*
	jsrkrmciB
 */
using namespace std;
#include <bits/stdc++.h> // precompiled headers
#define fora(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define clr clear()
#define inf (1<<30)
#define eps 1e-9
#define getnum(x) scanf("%d",&x);
#define dprintf(x...) fprintf(stderr,x);
#define lld I64d;
#define result(x,y)  printf("Case #%d: %I64d\n", x+1, (long long)y);
#if __cplusplus <= 199711L
  #error This library needs at least a C++11 compliant compiler
#endif
#define sd(x)  scanf("%d",&x)
#define sc(x) scanf("%c",&x)
#define sll(x) scanf("%I64d",&x)
#define sf(x) scanf("%Lf",&x)
#define ss(x) scanf("%s",x)
typedef long double ld;
typedef long long ll;
typedef string str;

int T;
int cnt[26];
int num[10];

int main() {
	//ios::sync_with_stdio(false);//use with care
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    getnum(T);
    // dprintf("%d %d\n",T,T);
    fora(t,T){
        char str[2001];
        fora(i,26) cnt[i] = 0;
        fora(i,10) num[i] = 0;
        scanf("%s",str);
        for(char c:str){
            if(c==0) break;
            if(c>='A'&&c<='Z')cnt[c-'A']++;
            // printf("%c",c);
        }
        num[2] = cnt['W'-'A'];
        cnt['T'-'A'] -= num[2];
        cnt['W'-'A'] -= num[2];
        cnt['O'-'A'] -= num[2];
        num[4] = cnt['U'-'A'];
        cnt['F'-'A'] -= num[4];
        cnt['O'-'A'] -= num[4];
        cnt['U'-'A'] -= num[4];
        cnt['R'-'A'] -= num[4];
        num[6] = cnt['X'-'A'];
        cnt['S'-'A'] -= num[6];
        cnt['I'-'A'] -= num[6];
        cnt['X'-'A'] -= num[6];
        num[7] = cnt['S'-'A'];  
        cnt['S'-'A'] -= num[7];
        cnt['E'-'A'] -= num[7];
        cnt['V'-'A'] -= num[7];
        cnt['E'-'A'] -= num[7];
        cnt['N'-'A'] -= num[7];     
        num[8] = cnt['G'-'A'];  
        cnt['E'-'A'] -= num[8];
        cnt['I'-'A'] -= num[8];
        cnt['G'-'A'] -= num[8];
        cnt['H'-'A'] -= num[8];
        cnt['T'-'A'] -= num[8];     
        num[0] = cnt['Z'-'A'];  
        cnt['Z'-'A'] -= num[0];
        cnt['E'-'A'] -= num[0];
        cnt['R'-'A'] -= num[0];
        cnt['O'-'A'] -= num[0];
        num[1] = cnt['O'-'A'];  
        cnt['O'-'A'] -= num[1];
        cnt['N'-'A'] -= num[1];
        cnt['E'-'A'] -= num[1];
        num[3] = cnt['H'-'A'];  
        cnt['T'-'A'] -= num[3];
        cnt['H'-'A'] -= num[3];
        cnt['R'-'A'] -= num[3];  
        cnt['E'-'A'] -= num[3];
        cnt['E'-'A'] -= num[3];  
        num[5] = cnt['F'-'A'];  
        cnt['F'-'A'] -= num[5];
        cnt['I'-'A'] -= num[5];
        cnt['V'-'A'] -= num[5];  
        cnt['E'-'A'] -= num[5];   
        num[9] = cnt['E'-'A']; 
        printf("Case #%d: ",t+1);
        fora(i,10){
            fora(j,num[i]){
                printf("%d",i);
            }
        }
        printf("\n");
    }
    return 0;
}