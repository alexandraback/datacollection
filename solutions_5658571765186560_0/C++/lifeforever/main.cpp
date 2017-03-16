#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
    int R,C,X;
    int T,index=1;
    freopen("D-small-attempt2.in","r",stdin);
    freopen("D.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&X,&R,&C);
        //cout<<X<<" "<<R<<" "<<C<<endl;
        if(X==1)
        {
            printf("Case #%d: GABRIEL\n",index++);
        }
        else
        {
            if(X==2)
            {
                if(R%2==0||C%2==0)
                {
                    printf("Case #%d: GABRIEL\n",index++);
                }
                else
                {
                    printf("Case #%d: RICHARD\n",index++);
                }
            }
            else if(X==3)
            {
                if((R==3||C==3)&&R>=2&&C>=2)
                {
                    printf("Case #%d: GABRIEL\n",index++);
                }
                else
                {
                    printf("Case #%d: RICHARD\n",index++);
                }
            }
            else if(X==4)
            {
                if((R==4||C==4)&&R>=3&&C>=3)
                {
                    printf("Case #%d: GABRIEL\n",index++);
                }
                else
                {
                    printf("Case #%d: RICHARD\n",index++);
                }

            }
        }
    }
    return 0;
}
