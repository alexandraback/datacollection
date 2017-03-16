/*
AUTHOR: THANABHAT KOOMSUBHA
LANG: C++
*/

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<list>
#include<set>
#include<queue>
#include<map>
#include<cctype>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<ctime>

using namespace std;

int solve(int cc)
{
    int A,B,K;
    int bA[32],bB[32],bK[32];
    int mxA=-1,mxB=-1;
    scanf("%d %d %d",&A,&B,&K);
    A;
    B;
    for(int i=0;i<30;i++)
    {
        bA[i]=((1<<i)&A)?1:0;
        bB[i]=((1<<i)&B)?1:0;
        bK[i]=((1<<i)&K)?1:0;
        if(bA[i]) mxA=i;
        if(bB[i]) mxB=i;
    }
    bool debug=false;
//    if(debug)
//    {
//        for(int i=0;i<30;i++) printf("%d",bA[i]); printf("\n");
//        for(int i=0;i<30;i++) printf("%d",bB[i]); printf("\n");
//        for(int i=0;i<30;i++) printf("%d",bK[i]); printf("\n");
//        printf("\n");
//    }


    long long sol=0;

    long long tmp[30];
    int bTK[32];
    int bTA[32];
    int bTB[32];
    for(int i=0;i<30;i++) bTK[i]=0;
    for(int i=29;i>=0;i--)
    {
        if(bK[i])
        {
            bTK[i]=1;
            for(int ia=0;ia<30;ia++) bTA[ia]=0;
            for(int ia=29;ia>=0;ia--)
            {
                if(bA[ia])
                {
                    bTA[ia]=1;
                    for(int ib=0;ib<30;ib++) bTB[ib]=0;
                    for(int ib=29;ib>=0;ib--)
                    {
                        if(bB[ib])
                        {
                            bTB[ib]=1;

                            //j>i
                            for(int j=29;j>i;j--)
                            {
                                if(ia>j&&ib>j)  //0,1 0,1
                                {
                                    if(bTK[j]==0) tmp[j]=3;
                                    else tmp[j]=1;
                                }else if(ia==j&&ib>j)   //0 0,1
                                {
                                    if(bTK[j]==0) tmp[j]=2;
                                    else tmp[j]=0;
                                }else if(ia<j&&ib>j)    //x 0,1
                                {
                                    if(bTK[j]==0){
                                        if(bTA[j]==0) tmp[j]=2;
                                        else tmp[j]=1;
                                    }else
                                    {
                                        if(bTA[j]==0) tmp[j]=0;
                                        else tmp[j]=1;
                                    }
                                }else if(ia>j&&ib==j)   //0,1 0
                                {
                                    if(bTK[j]==0) tmp[j]=2;
                                    else tmp[j]=0;
                                }else if(ia==j&&ib==j)  //0 0
                                {
                                    if(bTK[j]==0) tmp[j]=1;
                                    else tmp[j]=0;
                                }else if(ia<j&&ib==j)   //x 0
                                {
                                    if(bTK[j]==0) tmp[j]=1;
                                    else tmp[j]=0;
                                }else if(ia>j&&ib<j)    //0,1 x
                                {
                                    if(bTK[j]==0){
                                        if(bTB[j]==0) tmp[j]=2;
                                        else tmp[j]=1;
                                    }else
                                    {
                                        if(bTB[j]==0) tmp[j]=0;
                                        else tmp[j]=1;
                                    }
                                }else if(ia==j&&ib<j)   //0 x
                                {
                                    if(bTK[j]==0) tmp[j]=1;
                                    else tmp[j]=0;

                                }else if(ia<j&&ib<j)    //x x
                                {
                                    if(bTK[j]==bTA[j]*bTB[j]) tmp[j]=1;
                                    else tmp[j]=0;
                                }

                            }

                            //j=i
                            {
                                int j=i;
                                if(ia>j&&ib>j)  //0,1 0,1
                                {
                                    tmp[j]=3;
                                }else if(ia==j&&ib>j)   //0 0,1
                                {
                                    tmp[j]=2;
                                }else if(ia<j&&ib>j)    //x 0,1
                                {
                                    if(bTA[j]==0) tmp[j]=2;
                                    else tmp[j]=1;
                                }else if(ia>j&&ib==j)   //0,1 0
                                {
                                   tmp[j]=2;
                                }else if(ia==j&&ib==j)  //0 0
                                {
                                    tmp[j]=1;
                                }else if(ia<j&&ib==j)   //x 0
                                {
                                    tmp[j]=1;
                                }else if(ia>j&&ib<j)    //0,1 x
                                {
                                    if(bTB[j]==0) tmp[j]=2;
                                    else tmp[j]=1;
                                }else if(ia==j&&ib<j)   //0 x
                                {
                                    tmp[j]=1;
                                }else if(ia<j&&ib<j)    //x x
                                {
                                    if(bTA[j]*bTB[j]==0) tmp[j]=1;
                                    else tmp[j]=0;
                                }
                            }

                            //j<i
                            for(int j=i-1;j>=0;j--)
                            {
                                if(ia>j&&ib>j)  //0,1 0,1
                                {
                                    tmp[j]=4;
                                }else if(ia==j&&ib>j)   //0 0,1
                                {
                                    tmp[j]=2;
                                }else if(ia<j&&ib>j)    //x 0,1
                                {
                                    tmp[j]=2;
                                }else if(ia>j&&ib==j)   //0,1 0
                                {
                                    tmp[j]=2;
                                }else if(ia==j&&ib==j)  //0 0
                                {
                                    tmp[j]=1;
                                }else if(ia<j&&ib==j)   //x 0
                                {
                                    tmp[j]=1;
                                }else if(ia>j&&ib<j)    //0,1 x
                                {
                                    tmp[j]=2;
                                }else if(ia==j&&ib<j)   //0 x
                                {
                                    tmp[j]=1;
                                }else if(ia<j&&ib<j)    //x x
                                {
                                    tmp[j]=1;
                                }
                            }


                            long long soltmp=1;
                            for(int iii=0;iii<30;iii++)
                            {
                                soltmp*=tmp[iii];
//                                printf("iii %d soltmp %lld %lld\n",iii,soltmp,tmp[iii]);
                            }
                            sol+=soltmp;

                                if(debug)
                                {
                                    for(int i=0;i<30;i++) printf("%d ",bTA[i]); printf("\n");
                                    for(int i=0;i<30;i++) printf("%d ",bTB[i]); printf("\n");
                                    for(int i=0;i<30;i++) printf("%d ",bTK[i]); printf("\n");
                                    for(int i=0;i<30;i++) printf("%lld ",tmp[i]); printf("\n");
                                    printf("%lld %lld\n",soltmp,sol);
                                }
                        }
                    }
                }
            }
        }
    }
    printf("Case #%d: %lld\n",cc,sol);


    return 1;
}

int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++)
        solve(i+1);

	return 0;
}
