#include <stdio.h>
#include <stdlib.h>
#include<string.h>


char gStr[39][16]=  {
                    "1",
                    "4",
                    "9",
                    "121",
                    "484",
                    "10201",
                    "12321",
                    "14641",
                    "40804",
                    "44944",
                    "1002001",
                    "1234321",
                    "4008004",
                    "100020001",
                    "102030201",
                    "104060401",
                    "121242121",
                    "123454321",
                    "125686521",
                    "400080004",
                    "404090404",
                    "10000200001",
                    "10221412201",
                    "12102420121",
                    "12345654321",
                    "40000800004",
                    "1000002000001",
                    "1002003002001",
                    "1004006004001",
                    "1020304030201",
                    "1022325232201",
                    "1024348434201",
                    "1210024200121",
                    "1212225222121",
                    "1214428244121",
                    "1232346432321",
                    "1234567654321",
                    "4000008000004",
                    "4004009004004"

                    };
/*void inita(int a[100][100])
{
    int i,j;
    for(i=0;i<100;i++)
    for(j=0;j<100;j++)
    a[i][j] = 0;
}

int indcount(int cur)
{

   int cnt =0,n;

    if(cur%2 == 0)
    {
        if(cur>0)
        cnt+=2;
        if(cur>2)
        {
            cnt+=(cur-2)/2;
        }
        if(cur>4)
        {
            n = (cur-2)/2;
            cnt+=n*(n-1)/2;

        }
        if(cnt>6)
        {
            n=(cur-2)/2;
            cnt+=(n*(n-1)*(n-2))/(1*2*3);

        }
    }
    else
    {
        if(cur==1)
        cnt = 3;
        else
        {
            cnt=3+2;
            if(cur>3)
            {
                cnt+=((cur-3)/2)*3;
               // cnt*=3;
            }
            if(cur>5)
            {
                n=(cur-3)/2;
                cnt+=n*(n-1);

            }
            if(cur>7)
            {
                n = (cur-3)/2;
                cnt+=n*(n-1)*(n-2);
                cnt/=(1*2*3);
                cnt*=2;
            }
        }

    }
    return cnt;
}

int count(int stL,int enL,char F[101],char S[101],int cur)
{

int cnt=0;
if(cur!=stL && cur!=enL)
cnt+=indcount(cur);
if(stL==cur)
{
    if(strlen(F)%2==0)
    {
        cnt=0;
    }

}
return 0;

}

int solveP(char H[101],char W[101])
{
int stL,enL,i,cnt =0;
stL=strlen(H)/2+strlen(H)%2;
enL=strlen(W)/2+strlen(W)%2;
for(i=stL;i<=enL;i++)
cnt += count(stL,enL,H,W,i);
}*/

int gOrE(char x[16],char y[16])
{
    int i,l;
    if(strlen(x)>strlen(y))
    return 1;
    else
    if(strlen(x)<strlen(y))
    return 0;
    else
    {
        l=strlen(x);
        for(i=0;i<l;i++)
        {
            if(x[i]>y[i])
            return 1;
            else
            if(x[i]<y[i])
            return 0;

        }
    }
    return 1;
}

void solve(int T,FILE *fp1)
{
    int i,cnt = 0,j;;
    FILE *fp2;
    fp2 = fopen("p.out","w");
    char H[16],W[16];
    //int H,W;
    for(i=0;i<T;i++)
    {
        cnt = 0;
        fprintf(fp2,"Case #%d: ",i+1);
        fscanf(fp1,"%s %s ",H,W);
        //cnt = solveP(H,W);
   //     for(j=0;j<8;j++)
     //   cnt+=indcount(j);
        for(j=0;j<39;j++)
        {
            if(gOrE(gStr[j],H)==1 && gOrE(W,gStr[j])==1)
            cnt++;
            //printf("\n%s",gStr[j]);
        }
        //printf("\n## %d",cnt);
        //printf("H = %d, W = %d\n",H,W);
        fprintf(fp2,"%d\n",cnt);


    }
}




int main()
{
    FILE *fp1;
    int i;
   // long long a;
    //long int g;
    //printf("a - %d",sizeof(g));
   // a = 100*10000000;
    //printf("\n a = %d",a);
    int T = 0;
    fp1 = fopen("A-small-practice.in","r");
    fscanf(fp1,"%d",&T);
    solve(T,fp1);
    printf("T = %d\n",T);
    //for(i=0;i<8;i++)
    //printf("\n##%d - %d",i,indcount(i));
    return 0;
}

