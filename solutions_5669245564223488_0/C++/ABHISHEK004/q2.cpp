#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string.h>
#include<cstdlib>

using namespace std;

int gcd(int a,int b)
{
 int r, i;
  while(b!=0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}


int min(int a,int b)
{
        return a<b?a:b;
}
int max(int a,int b)
{
        return a>b?a:b;
}

long long int fact(long long int a)
{
        long long int i,j,k,p=1;
        for(i=1;i<=a;i++)
        {
                p=p*i;
        }
        return p;
}


void reduce(char *a,char *sa)
{
        int i,i1=0;
        int a1=strlen(a);
                for(i=0;i<a1-1;)
                {
                        int cc=0;
                        while(i<a1-1 && a[i]==a[i+1])
                        {
                                cc++;
                                //int yh=34;
                                i++;
                        }
                        //aa[i1]=cc+1;
                        sa[i1]=a[i];
                        i1++;
                        i++;
                }
                if(a[i-1]!=a[i])
                {
                        //aa[i1]=1;
                        sa[i1]=a[i];
                        i1++;
                }
                sa[i1]='\0';
                i1++;

}

int main()
{
        freopen("C:\\Users\\ABHISHEK KUMAR\\Desktop\\a.in","r",stdin);
       freopen("C:\\Users\\ABHISHEK KUMAR\\Desktop\\b.out","w",stdout);
        int t,i,j,m,n,k,k1,k2,p,a1,a2,ans;
        int ar[27];
        int cn[27];
        int ch[27];
        char r;
        char b[11][110];
        char a[11][110];
        scanf("%d",&t);
        k=t;
        while(t--)
        {
                int f=0;
                scanf("%d",&n);
                scanf("%c",&r);
                for(i=0;i<n;i++)
                {
                        scanf("%s",&b[i]);

                }
                /*for(i=0;i<n;i++)
                {
                        printf("%s\n",a[i]);
                }*/

                for(i=0;i<n;i++)
                {
                        reduce(b[i],a[i]);
                }
                //for(i=0;i<n;i++)
                //{
                        //printf("%s\n",a[i]);
               // }

                memset(ar,-1,sizeof(ar));
                memset(cn,0,sizeof(cn));
                memset(ch,0,sizeof(ch));
                for(i=0;i<n;i++)
                {
                        for(j=0;j<strlen(a[i]);j++)
                        {
                                if(strlen(a[i])>1){
                                if(j==0 && ((ar[a[i][j]-97]==-1)||(ar[a[i][j]-97]==3)))
                                {
                                        ar[a[i][j]-97]=1;// 1 start
                                        ch[a[i][j]-97]++;
                                        if(ch[a[i][j]-97]>2)
                                        {
                                                f=1;
                                                //printf(" if 1 1 flag\n");
                                                break;
                                        }
                                }
                                else if(j>0 && j<(strlen(a[i])-1) && ((ar[a[i][j]-97]==-1)||(ar[a[i][j]-97]==2)))
                                {
                                        ar[a[i][j]-97]=2;//2 mid
                                }
                                else if(j==(strlen(a[i])-1)  && ((ar[a[i][j]-97]==-1)||(ar[a[i][j]-97]==1)))
                                {
                                        ar[a[i][j]-97]=3;//3 tail
                                        ch[a[i][j]-97]++;
                                        if(ch[a[i][j]-97]>2)
                                        {
                                                f=1;
                                                //printf("if 1 3 flag\n");
                                                break;
                                        }
                                }
                                else
                                {
                                        f=1;
                                        //printf("i-> %d  j->%d\n",i,j);
                                        //printf("a[i][j] %c\n",a[i][j]);
                                        //printf("ar[i][j] %d\n",ar[a[i][j]-97]);
                                        //printf("ch[i][j] %d\n",ch[a[i][j]-97]);
                                        //printf("else flag\n");
                                        break;
                                }
                                }
                                else if(strlen(a[i])==1)
                                {
                                        cn[a[i][0]-97]++;
                                }
                        }
                        if(f==1)
                                break;
                }
                long long int ans=1,aaa,cnt=0;
                if(f==1)
                {
                        //printf("flag\n");
                        printf("Case #%d: 0\n",k-t);
                }
                else
                {
                        for(i=0;i<=25;i++)
                        {
                                if(cn[i]>1)
                                {
                                        //printf("i-> %d  cn[i]->%d\n",i,cn[i]);
                                        aaa=(long long int)cn[i];
                                        ans=ans*fact(aaa);
                                        cnt++;
                                }
                        }
                        //printf("ans-> %d  cnt->%d\n",ans,cnt);
                        ans=ans*fact(cnt+1);
                        printf("Case #%d: %lld\n",k-t,ans);
                }
        }
       return 0;
}

