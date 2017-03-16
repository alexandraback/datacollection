#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

char keys[10],target[10];
int l,tot,max_kela;

int rec(int pos, char *str, int s, int k)
{
    if(pos==s)
    {
//        for(int i=0;i<s;i++)
//            printf("%c",str[i]);
//        printf("\n");
        tot++;
        int total=0,j;
        for(int i=0;i<s;i++)
        {
            for(j=i;j<i+l&&j<s;j++)
                if(str[j]!=target[j-i])
                    break;
            if(j==i+l)
                total++;
        }
        max_kela=max(max_kela,total);
        return total;
    }
    int result=0;
    for(int i=0;i<k;i++)
    {
        str[pos]=keys[i];
        result=result + rec(pos+1,str,s,k);
    }
    return result;
}

int main()
{
    freopen("2inp.in","r",stdin);
    freopen("2out.txt","w",stdout);
    int t,i,T,k,s,ans;
    char str[10];
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%d%d%d",&k,&l,&s);
        scanf("%s",keys);
        scanf("%s",target);
        tot=0;
        max_kela=0;
        ans=rec(0,str,s,k);
        if(max_kela==0)
        {
            printf("Case #%d: 0.0\n",t);
            continue;
        }
        int kelas=tot*max_kela;
        double result=(double)kelas-(double)ans;
        result=result/(double)tot;
        //printf("%d %d\n",ans,tot);
        printf("Case #%d: %lf\n",t,result);
    }
    return 0;
}




