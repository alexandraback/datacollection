#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(i=0;i<n;i++)
#define sd(n) scanf("%d",&n);
#define sl(n) scanf("%lld",&n);
#define pd(n) printf("%d ",n);
#define pl(n) printf("%lld ",n);
#define pln printf("\n");
#define pb push_back

char ar[3000],ar1[3000];
int ss1,ss2;
int ar2[2000],ar3[2000];
int minm;
void recur(char ar[],int i,char ar1[], int j)
{
    if(i==strlen(ar)&&j==strlen(ar1))
    {
        int s1=0;
        int s2=0;

        for(i=0;i<strlen(ar);i++)
        {
            s1=s1*10+ar2[i];

        }
        for(i=0;i<strlen(ar1);i++)
        {
            s2=s2*10+ar3[i];

        }

        if(abs(s1-s2)<minm)
        {
            minm=abs(s1-s2);
            ss1=s1;
            ss2=s2;


        }
        else if(abs(s1-s2)==minm)
        {
            if(s1<ss1)
            {
                ss1=s1;
                ss2=s2;


            }
            else if(s1==ss1)
            {
                if(s2<ss2)
                {

                    ss1=s1;
                    ss2=s2;

                }


            }


        }



    }

    if(i!=strlen(ar))
    {
        if(ar[i]=='?')
        {
            for(int i1=0;i1<10;i1++)
            {
                ar2[i]=i1;
                recur(ar,i+1,ar1,j);

            }


        }
        else
        {
            ar2[i]=ar[i]-'0';
            recur(ar,i+1,ar1,j);


        }

    }

    if(j!=strlen(ar1))
    {
        if(ar1[j]=='?')
        {
            for(int i1=0;i1<10;i1++)
            {
                ar3[j]=i1;
                recur(ar,i,ar1,j+1);

            }


        }
        else
        {
            ar3[j]=ar1[j]-'0';
            recur(ar,i,ar1,j+1);


        }

    }



}

int main()
{
int t,i,j;

scanf("%d",&t);
for(j=0;j<t;j++)
{

        cout<<"Case #"<<j+1<<": ";
        scanf("%s%s",&ar,&ar1);

 minm=1020939;
 ss1=173826;
 ss2=1267235;

 recur(ar,0,ar1,0);
 for(i=strlen(ar)-1;i>=0;i--)
 {
     ar2[i]=ss1%10;
     ss1/=10;

 }

 for(i=strlen(ar1)-1;i>=0;i--)
 {
     ar3[i]=ss2%10;
     ss2/=10;

 }

 for(i=0;i<strlen(ar);i++)
 cout<<ar2[i];

 cout<<" ";

 for(i=0;i<strlen(ar1);i++)
 cout<<ar3[i];



 cout<<endl;

 }



    return 0;

}

