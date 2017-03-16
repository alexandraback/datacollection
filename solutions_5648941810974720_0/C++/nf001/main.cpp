#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;
#define inf 0x3f3f3f3f
#define N 1001
#define ll long long
#define M 2002
#define mm 1000000007

string s[]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int l[10],cnt[256],ok;
void dfs(int x){
    if (x==10){
        int p=0;
        for (int i='A';i<='Z';i++) p+=cnt[i];
        if (p==0) ok=1;
        return;
    }
    int c[27],len=s[x].length();
    for (int i='A';i<='Z';i++) c[i-'A'] = cnt[i];
    while (1){
        dfs(x+1);
        if (ok) return;
        l[x]++;
        int no=0;
        for (int i=0;i<len;i++){
            cnt[s[x][i]]--;
            if (cnt[s[x][i]]<0) {no=1;break;}
        }
        if (no) break;
    }
    for (int i='A';i<='Z';i++) cnt[i] = c[i-'A'];
    l[x]=0;
}
char a[2020];
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int T,cas=0;
    cin>>T;
    while (T--){
        memset(l,0,sizeof l);
        ok=0;
        scanf("%s",a);
        int len=strlen(a);
        for (int i=0;i<len;i++){
            cnt[a[i]]++;
        }
        dfs(0);
        printf("Case #%d: ",++cas);
        for (int i=0;i<10;i++){
         //   cout<<l[i]<<endl;
            while (l[i]--){
                printf("%d",i);
            }
        }
        puts("");
    }
}
