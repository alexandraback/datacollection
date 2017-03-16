#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define N 2010
int a[30];
int ans[30];
char s[N];
int main()
{
    int T,len,i;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    int i1=1,tmp;
    while(T--)
    {
        scanf("%s",s);
        memset(a,0,sizeof(a));
        memset(ans,0,sizeof(ans));
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            s[i]=s[i]-'A'+'a';
            a[s[i]-'a']++;
        }
        ans[0]=a['z'-'a'];
        tmp=a['z'-'a'];
        a['z'-'a']-=tmp;a['e'-'a']-=tmp;a['r'-'a']-=tmp;a['o'-'a']-=tmp;
        ans[2]=a['w'-'a'];
        tmp=ans[2];
        a['t'-'a']-=tmp;a['w'-'a']-=tmp;a['o'-'a']-=tmp;
        ans[6]=a['x'-'a'];
        tmp=ans[6];
        a['s'-'a']-=tmp;a['i'-'a']-=tmp;a['x'-'a']-=tmp;
        ans[7]=a['s'-'a'];
        tmp=ans[7];
        a['s'-'a']-=tmp;a['e'-'a']-=2*tmp;a['v'-'a']-=tmp;a['n'-'a']-=tmp;
        ans[5]=a['v'-'a'];
        tmp=ans[5];
        a['f'-'a']-=tmp;a['i'-'a']-=tmp;a['v'-'a']-=tmp;a['e'-'a']-=tmp;
        ans[4]=a['f'-'a'];
        tmp=ans[4];
        a['f'-'a']-=tmp;a['o'-'a']-=tmp;a['u'-'a']-=tmp;a['r'-'a']-=tmp;
        ans[8]=a['g'-'a'];
        tmp=ans[8];
        a['e'-'a']-=tmp;a['i'-'a']-=tmp;a['g'-'a']-=tmp;a['h'-'a']-=tmp;a['t'-'a']-=tmp;
        ans[3]=a['h'-'a'];
        tmp=ans[3];
        a['t'-'a']-=tmp;a['h'-'a']-=tmp;a['r'-'a']-=tmp;a['e'-'a']-=tmp;a['e'-'a']-=tmp;
        ans[1]=a['o'-'a'];
        tmp=ans[1];
        a['o'-'a']-=tmp;a['n'-'a']-=tmp;a['e'-'a']-=tmp;
        ans[9]=a['i'-'a'];
        tmp=ans[9];
        a['n'-'a']-=tmp;a['i'-'a']-=tmp;a['n'-'a']-=tmp;a['e'-'a']-=tmp;
        printf("Case #%d: ",i1++);
        for(i=0;i<10;i++)
        {
            while(ans[i]--)
                printf("%d",i);
        }
        printf("\n");
    }

    return 0;
}
