#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char s[2005],ans[1005];
int len,cnt[99];
void check (char key,char *a,int l,char c)
{
    while(cnt[key]>0){
        for(int i=0;i<l;i++)
            cnt[a[i]]--;
        ans[len++]=c;
    }

    return ;
}
void solve (void)
{
    int i,n;

    len=0;
    for(i='A';i<='Z';i++) cnt[i]=0;

    n=strlen(s);

    for(i=0;i<n;i++)
        cnt[s[i]]++;

    check('Z',"ZERO",4,'0');
    check('W',"TWO",3,'2');
    check('X',"SIX",3,'6');
    check('G',"EIGHT",5,'8');
    check('U',"FOUR",4,'4');
    check('F',"FIVE",4,'5');
    check('V',"SEVEN",5,'7');
    check('O',"ONE",3,'1');
    check('T',"THREE",5,'3');
    check('I',"NINE",4,'9');

    sort(ans,ans+len);
    printf("%s\n",ans);
    for(i=0;i<len;i++) ans[i]='\0';

    return ;
}
int main (void)
{
    int i,t;

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    scanf("%d",&t);
    for(i=0;i<t;i++){
        scanf("%s",s);
        printf("Case #%d: ",i+1);
        solve();
    }

    return 0;
}
