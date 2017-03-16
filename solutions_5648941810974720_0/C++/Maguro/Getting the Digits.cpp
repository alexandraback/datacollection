#include<bits/stdc++.h>
using namespace std;
char s[2135];
int hsh[30],num[30];
int order[12]={0,2,4,6,1,7,3,5,8,9};
char ch[12]={'z','o','w','r','u','v','x','s','h','i',};
string st[12]={"zero","one","two","three","four","five","six","seven","eight","nine"};
void del(char a,int b)
{
//    printf("%c %d %d\n",a,b,hsh[a-'a']);
    hsh[a-'a']-=b;
}
int main()
{
    int t,T,i,j,k,len,tmp;
//    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%s",s);
        len=strlen(s);
        memset(hsh,0,sizeof hsh);
        for(i=0;i<len;i++)
        {
            hsh[s[i]-'A']++;
        }
//        printf("!%d\n",hsh['Z'-'A']);
        for(i=0;i<10;i++)
        {
            j=order[i];
            tmp=hsh[ch[j]-'a'];
            if(tmp==0)
                continue;
            num[j]=tmp;
            for(k=0;k<st[j].size();k++)
            {
                del(st[j][k],tmp);
            }
        }
        printf("Case #%d: ",t);
        for(i=0;i<10;i++)
        {
            while(num[i]>0)
                printf("%d",i),num[i]--;
        }
        printf("\n");
    }
}

