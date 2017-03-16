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
int val[4*maxn];
int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C1.out","w",stdout);
    int t,index=1,L,X;
    scanf("%d",&t);
    while(t--)
    {

        scanf("%d%d",&L,&X);
        scanf("%s",input);
        int indx1[5],indx=0;
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<L; j++)
            {
                if(j==0&&i==0)
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
            indx1[i+1]=indx-1;
        }
       // cout<<L<<" "<<X<<endl;
       // cout<<input<<endl;
       // cout<<val[indx1[1]]<<endl;
        //cout<<val[indx1-1]<<" | "<<val[indx-1]<<endl;
        bool flag=false;
        int tempX=X;
        if(val[indx1[1]]!=1)
        {
            for(int i=1; i<=4; i++)
            {
                //cout<<i
                if(i==3) continue;
                tempX=X;
                if(i==1&&val[indx1[i]]!=-1) continue;
                else
                {
                    tempX-=i;
                    if(tempX<0) continue;

                    if(i!=1&&fabs(val[indx1[1]])!=1)
                    {
                        if(tempX%2==0)
                            tempX/=2;
                        else continue;
                    }
                    // cout<<tempX<<endl;
                    for(int j=0; j<=indx1[i]; j++)
                    {
                        if(fabs(val[j])==2)
                        {
                            for(int k=j+1; k<=indx1[i]; k++)
                            {
                                if(fabs(val[k])==4)
                                {
                                    if(val[j]>0)
                                    {
                                        if(val[k]>0)
                                        {
                                            if(i==4)
                                            {
                                                if(tempX%2)
                                                {
                                                    flag=true;
                                                    //  cout<<"sd";
                                                    break;
                                                }
                                            }
                                            else
                                            {
                                                if(tempX%2==0)
                                                {
                                                    flag=true;
                                                    break;
                                                }
                                            }
                                        }
                                        else
                                        {
                                            if(i==4)
                                            {
                                                if(tempX%2)
                                                {
                                                    flag=true;
                                                    break;
                                                }
                                            }
                                            else
                                            {
                                                if(tempX>=2&&tempX%2==0)
                                                {
                                                    flag=true;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if(val[k]>0)
                                        {
                                            if(i==4)
                                            {
                                                if(tempX>=3&&tempX%2)
                                                {
                                                    flag=true;
                                                    break;
                                                }
                                            }
                                            else
                                            {
                                                if(tempX>=2&&tempX%2==0)
                                                {
                                                    flag=true;
                                                    break;
                                                }
                                            }
                                        }
                                        else
                                        {
                                            if(i==4)
                                            {
                                                if(tempX%2)
                                                {
                                                    flag=true;
                                                    break;
                                                }
                                            }
                                            else
                                            {
                                                if(tempX>=2&&tempX%2==0)
                                                {
                                                    flag=true;
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            if(flag) break;
                        }
                    }
                }
            }
        }//cout<<endl;
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
