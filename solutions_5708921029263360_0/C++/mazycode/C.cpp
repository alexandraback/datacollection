#include<stdio.h>
using namespace std;
int pa[3]= {1,2,3};
int pb[3]= {1,2,3};
int pc[3]= {1,2,3};
int ss[27][3];
bool ff[27];
int top= 0;
bool find(int a,int b,int c)
{
    int p1,p2,p3;
    p1=p2=p3=0;
    for(int i=0;i<top;i++)
       {
           if(ss[i][0]==a&&ss[i][1]==b) p1++;
           if(ss[i][0]==a&&ss[i][2]==c) p2++;
           if(ss[i][2]==c&&ss[i][1]==b) p3++;
       }
      // printf("! %d %d %d\n",p1,p2,p3);
       if(p1<3&&p2<3&&p3<3)return false;
       return true;

}
void doit()
{
    int a,b,c,k;
    scanf("%d%d%d%d",&a,&b,&c,&k);
    top =0;
    for(int i=0;i<a;i++)
        for(int j=0;j<b;j++)
            for(int w=0;w<c;w++)
                {
                    ss[top][0] = pa[i];
                    ss[top][1] = pb[j];
                    ss[top][2] = pc[w];
                    top++;
                }
    if(k>=3)
    {
        printf("%d\n",top);
        for(int i=0;i<top;i++)
            printf("%d %d %d\n",ss[i][0],ss[i][1],ss[i][2]);
    }
    if(k == 1)
    {
        printf("%d\n",a*b);
        printf("1 1 1\n");
        if(b>=2){printf("1 2 2\n");}
        if(b>=3){printf("1 3 3\n");}
        if(a>=2&&b<=2){printf("2 1 2\n");printf("2 2 1\n");}
        if(a>=2&&b>=3){printf("2 1 3\n");printf("2 2 1\n");printf("2 3 2\n");}
        if(a>=3){printf("3 1 2\n");printf("3 2 3\n");printf("3 3 1\n");}
    }
    if(k == 2)
    {
        int ccc = 0;
        for(int i=0;i<top;i++)
        {
            if((find(1,1,1))&&ss[i][0] == 1 && ss[i][1] == 1&& ss[i][2] == 1) continue;
             if((find(1,2,2))&&ss[i][0] == 1 && ss[i][1] == 2&& ss[i][2] == 2) continue;
              if((find(1,3,3))&&ss[i][0] == 1 && ss[i][1] == 3&& ss[i][2] == 3) continue;
               if((find(2,2,1))&&ss[i][0] == 2 && ss[i][1] == 2&& ss[i][2] == 1) continue;
                if((find(2,3,2))&&ss[i][0] == 2 && ss[i][1] == 3&& ss[i][2] == 2) continue;
                 if((find(3,1,2))&&ss[i][0] == 3 && ss[i][1] == 1&& ss[i][2] == 2) continue;
                  if((find(3,2,3))&&ss[i][0] == 3 && ss[i][1] == 2&& ss[i][2] == 3) continue;
                   if((find(3,3,1))&&ss[i][0] == 3 && ss[i][1] == 3&& ss[i][2] == 1) continue;
                    if((find(2,1,2))&&ss[i][0] == 2 && ss[i][1] == 1&& ss[i][2] == 2) continue;
            ccc++;
        }
        printf("%d\n",ccc);
        for(int i=0;i<top;i++)
        {
             if((find(1,1,1))&&ss[i][0] == 1 && ss[i][1] == 1&& ss[i][2] == 1) continue;
             if((find(1,2,2))&&ss[i][0] == 1 && ss[i][1] == 2&& ss[i][2] == 2) continue;
              if((find(1,3,3))&&ss[i][0] == 1 && ss[i][1] == 3&& ss[i][2] == 3) continue;
               if((find(2,2,1))&&ss[i][0] == 2 && ss[i][1] == 2&& ss[i][2] == 1) continue;
                if((find(2,3,2))&&ss[i][0] == 2 && ss[i][1] == 3&& ss[i][2] == 2) continue;
                 if((find(3,1,2))&&ss[i][0] == 3 && ss[i][1] == 1&& ss[i][2] == 2) continue;
                  if((find(3,2,3))&&ss[i][0] == 3 && ss[i][1] == 2&& ss[i][2] == 3) continue;
                   if((find(3,3,1))&&ss[i][0] == 3 && ss[i][1] == 3&& ss[i][2] == 1) continue;
                    if((find(2,1,2))&&ss[i][0] == 2 && ss[i][1] == 1&& ss[i][2] == 2) continue;
           printf("%d %d %d\n",ss[i][0],ss[i][1],ss[i][2]);
        }
    }
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        doit();
    }
}
