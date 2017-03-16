#include <iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=10005;
int changemat[5][5]= {0,0, 0, 0, 0,
                      0,1, 2, 3, 4,
                      0,2,-1, 4,-3,
                      0,3,-4,-1, 2,
                      0,4, 3,-2,-1
                     };
int Num(char c)
{
    if(c=='1') return 1;
    if(c=='i') return 2;
    if(c=='j') return 3;
    if(c=='k') return 4;
}
int sig(int a,int b)
{
    return (a*b)/fabs(a*b);
}
char input[maxn];
int val[maxn];
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C.out","w",stdout);
    int t,index=1,L,X;
    scanf("%d",&t);
    while(t--)
    {

        scanf("%d%d",&L,&X);
        scanf("%s",input);
        int indx=0;
        for(int i=0; i<X; i++)
        {
            for(int j=0; j<L; j++)
            {
                if(i==0&&j==0)
                {
                    val[indx]=Num(input[j]);
                    indx++;
                }
                else
                {
                    val[indx]=sig(val[indx-1],Num(input[j]))*changemat[(int)fabs(val[indx-1])][Num(input[j])];
                    indx++;
                }
            }
        }
        bool flag=false;
        if(val[indx-1]==-1)
        {
            for(int i=0; i<indx; i++)
            {
                if(val[i]==2)
                {
                    for(int j=i+1; j<indx; j++)
                    {
                        if(val[j]==4)
                        {
                            flag=true;
                            break;
                        }
                    }
                }
                if(flag) break;
            }

        }
        if(flag)
        {
            printf("Case #%d: YES\n",index++);
        }
        else
        {
            printf("Case #%d: NO\n",index++);
        }
    }
    return 0;
}
