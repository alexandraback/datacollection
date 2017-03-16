//
//  main.cpp
//  codejam
//
//  Created by Cloudzfy on 3/11/15.
//  Copyright (c) 2015 Cloudzfy. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int map[8][8]= {
    {0,1,2,3,4,5,6,7},
    {1,4,3,6,5,0,7,2},
    {2,7,4,1,6,3,0,5},
    {3,2,5,4,7,6,1,0},
    {4,5,6,7,0,1,2,3},
    {5,0,7,2,1,4,3,6},
    {6,3,0,5,2,7,4,1},
    {7,6,1,0,3,2,5,4},
};
char data[10010];
int info[10000];
int main(int argc, const char * argv[]) {
    int T,L,X;
    freopen("C-small-attempt7.in.txt","r",stdin);
    freopen("C-small-attempt7.out.txt","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d%d",&L,&X);
        scanf("%s",data);
        for(int i=0;i<L;i++)
        {
            info[i]=data[i]-'i'+1;
        }
        int sum=info[0];
        for(int i=1;i<L;i++)
        {
            sum=map[sum][info[i]];
        }
        int ans=1;
        if(sum==0)ans=0;
        else if((sum>=1&&sum<=3)||(sum>=5&&sum<=7))
        {
            if(X%4!=2)
            {
                ans=0;
            }
        }
        else if(sum==4 && X%2!=1)
        {
            ans=0;
        }
        if(!ans)
        {
            printf("Case #%d: NO\n",t);
            continue;
        }
        ans=0;
        int st=0,pst=sum,ppst=map[sum][sum],pppst=map[map[sum][sum]][sum];
        int marki[4],markk[4];
        for(int i=0;i<4;i++)
        {
            marki[i]=-1;
            markk[i]=-1;
        }
        for(int i=0;i<L;i++)
        {
            if(map[st][info[i]]==1 && marki[0]==-1)
            {
                marki[0]=i;
            }
            if(map[pst][info[i]]==1 && marki[1]==-1)
            {
                marki[1]=i;
            }
            if(map[ppst][info[i]]==1 && marki[2]==-1)
            {
                marki[2]=i;
            }
            if(map[pppst][info[i]]==1 && marki[3]==-1)
            {
                marki[3]=i;
            }
            st=map[st][info[i]];
            pst=map[pst][info[i]];
            ppst=map[ppst][info[i]];
            pppst=map[pppst][info[i]];
        }
        st=0,pst=sum,ppst=map[sum][sum],pppst=map[map[sum][sum]][sum];
        for(int i=L-1;i>=0;i--)
        {
            if(map[info[i]][st]==3 && markk[0]==-1)
            {
                markk[0]=i;
            }
            if(map[info[i]][pst]==3 && markk[1]==-1)
            {
                markk[1]=i;
            }
            if(map[info[i]][ppst]==3 && markk[2]==-1)
            {
                markk[2]=i;
            }
            if(map[info[i]][pppst]==3 && markk[3]==-1)
            {
                markk[3]=i;
            }
            st=map[info[i]][st];
            pst=map[info[i]][pst];
            ppst=map[info[i]][ppst];
            pppst=map[info[i]][pppst];
        }
        if((sum>=1&&sum<=3)||(sum>=5&&sum<=7))
        {
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    if(marki[i]!=-1 && markk[j]!=-1)
                    {
                        int a=0;
                        for(int k=marki[i]+1;k<L;k++)
                        {
                            a=map[a][info[k]];
                        }
                        int b=0;
                        for(int k=0;k<markk[j];k++)
                        {
                            b=map[b][info[k]];
                        }
                        if(map[a][b]==2 && i+j+2<=X && (X-(i+j+2))%4==0) ans=1;
                        if(map[map[a][sum]][b]==2 && i+j+3<=X && (X-(i+j+3))%4==0) ans=1;
                        if(map[map[map[a][sum]][sum]][b]==2 && i+j+4<=X && (X-(i+j+4))%4==0) ans=1;
                        if(map[map[map[map[a][sum]][sum]][sum]][b]==2 && i+j+5<=X && (X-(i+j+5))%4==0) ans=1;
                        if(marki[i]<markk[j])
                        {
                            int a=0;
                            for(int k=marki[i]+1;k<markk[j];k++)
                            {
                                a=map[a][info[k]];
                            }
                            if(a==2 && i+j+1<=X && (X-(i+j+1))%4==0) ans=1;
                        }
                    }
                }
            }
        }
        if(sum==4)
        {
            for(int i=0;i<4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    if(marki[i]!=-1 && markk[j]!=-1)
                    {
                        int a=0;
                        for(int k=marki[i]+1;k<L;k++)
                        {
                            a=map[a][info[k]];
                        }
                        int b=0;
                        for(int k=0;k<markk[j];k++)
                        {
                            b=map[b][info[k]];
                        }
                        if(map[a][b]==2 && i+j+2<=X && (X-(i+j+2))%2==0) ans=1;
                        if(map[map[a][sum]][b]==2 && i+j+3<=X && (X-(i+j+3))%2==0) ans=1;
                        if(map[map[map[a][sum]][sum]][b]==2 && i+j+4<=X && (X-(i+j+4))%2==0) ans=1;
                        if(map[map[map[map[a][sum]][sum]][sum]][b]==2 && i+j+5<=X && (X-(i+j+5))%2==0) ans=1;
                        if(marki[i]<markk[j])
                        {
                            int a=0;
                            for(int k=marki[i]+1;k<markk[j];k++)
                            {
                                a=map[a][info[k]];
                            }
                            if(a==2 && i+j+1<=X && (X-(i+j+1))%2==0) ans=1;
                        }
                    }
                }
            }
        }
        if(ans)printf("Case #%d: YES\n",t);
        else printf("Case #%d: NO\n",t);
    }
    return 0;
}
