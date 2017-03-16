/*Author : Md. Al- Amin
           20th batch
           Dept. of CSE, SUST*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<vector>
#define pi (2*acos(0))
#define SF scanf
#define SFd1(a) scanf("%d",&a)
#define SFd2(a,b) scanf("%d%d",&a,&b)
#define SFd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define PF printf
#define inf 99999999
#define eps 0.00000001
#define ll long long
#define ull long long unsigned
#define int_max 2147483647
#define int_min -2147483648
#define long_max 9223372036854775807
#define long_min -9223372036854775808
#define fr(i,n) for(i=0;i<n;i++)
#define ms(dp,a) memset(dp,a,sizeof(dp))
#define dist(x1,y1,x2,y2) sqrt( ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)) )
#define PB push_back
#define mem(arr,val) memset(arr,val,sizeof(arr))

using namespace std;
//int rr[]={1,2,-1,-2,1,2,-1,-2};
//int cc[]={2,1,2,1,-2,-1,-2,-1};
//int rr[]={0,0,1,-1};
//int cc[]={-1,1,0,0};

char arr1[22],arr2[22];
int t,p,l;

int eq(int a,int b)
{
    for(int i=l-1; i>=0; a/=10,b/=10,i--)
    {
        if((a%10)!=(arr1[i]-'0')&&arr1[i]!='?')
            return 0;
        if((b%10)!=(arr2[i]-'0')&&arr2[i]!='?')
            return 0;
    }
    return 1;
}

int main()
{
    freopen("B-small-attempt0a.in","r",stdin);
    freopen("closematchout.txt","w",stdout);
    scanf(" %d",&t);
    int x,y;
    for(p=1; p<=t; p++)
    {
        scanf(" %s %s",&arr1,&arr2);
        l=strlen(arr1);
        int diff=1000000,i,j,k,i2,j2,k2,a,b;
        x=0;
        y=0;
        if(l==3)
        {
            for(i=0; i<10; i++)
            {
                for(j=0; j<10; j++)
                {
                    for(k=0; k<10; k++)
                    {
                        for(i2=0; i2<10; i2++)
                        {
                            for(j2=0; j2<10; j2++)
                            {
                                for(k2=0; k2<10; k2++)
                                {
                                    a=i*100+j*10+k;
                                    b=i2*100+j2*10+k2;
                                    if(eq(a,b))
                                    {
                                        if(abs(a-b)<diff)
                                        {
                                            diff=abs(a-b);
                                            x=a;
                                            y=b;
                                        }
                                        else if(abs(a-b)==diff&&x>a)
                                        {
                                            diff=abs(a-b);
                                            x=a;
                                            y=b;
                                        }
                                        else if(abs(a-b)==diff&&x==a&&y>b)
                                        {
                                            diff=abs(a-b);
                                            x=a;
                                            y=b;
                                        }
                                    }

                                }
                            }
                        }

                    }
                }
            }
        }

        if(l==2)
        {
            for(i=0; i<10; i++)
            {
                for(j=0; j<10; j++)
                {
                    for(i2=0; i2<10; i2++)
                    {
                        for(j2=0; j2<10; j2++)
                        {
                            a=i*10+j;
                            b=i2*10+j2;
                            if(eq(a,b))
                            {
                                if(abs(a-b)<diff)
                                {
                                    diff=abs(a-b);
                                    x=a;
                                    y=b;
                                }
                                else if(abs(a-b)==diff&&x>a)
                                {
                                    diff=abs(a-b);
                                    x=a;
                                    y=b;
                                }
                                else if(abs(a-b)==diff&&x==a&&y>b)
                                {
                                    diff=abs(a-b);
                                    x=a;
                                    y=b;
                                }
                            }

                        }
                    }

                }
            }
        }
        if(l==1)
        {
            for(i=0; i<10; i++)
            {
                for(i2=0; i2<10; i2++)
                {
                    a=i;
                    b=i2;
                    if(eq(a,b))
                    {
                        if(abs(a-b)<diff)
                        {
                            diff=abs(a-b);
                            x=a;
                            y=b;
                        }
                        else if(abs(a-b)==diff&&x>a)
                        {
                            diff=abs(a-b);
                            x=a;
                            y=b;
                        }
                        else if(abs(a-b)==diff&&x==a&&y>b)
                        {
                            diff=abs(a-b);
                            x=a;
                            y=b;
                        }
                    }

                }


            }

        }

        printf("Case #%d: ",p);
        string s1="",s2="";
        for(i=l-1;i>=0;i--,x/=10)
        {
            s1=(char)(x%10+'0')+s1;
        }
        for(i=l-1;i>=0;i--,y/=10)
        {
            s2=(char)(y%10+'0')+s2;
        }
        cout<<s1<<" "<<s2;
        printf("\n");
    }

    return 0;
}
