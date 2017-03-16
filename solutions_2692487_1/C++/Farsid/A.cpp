#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int B[110],C[110],N,DP[110];




int func(int pos)
{
    if(pos==N)return 0;
    //if(DP[pos]!=-1)return DP[pos];
    int a=C[pos]+func(pos+1);
    int ans=min(a,N-pos);

    return ans;
}


int main()
{
    freopen ("f.in","r",stdin);
    freopen ("in1.txt","w",stdout);
    //string str;
    //cin>>str;
    //cout<<str;

    int T,i,j,A,cas=0;
    scanf("%d",&T);
    while(T--)
    {
        //memset(DP,-1,sizeof(DP));
        memset(C,0,sizeof(C));
        scanf("%d%d",&A,&N);
        for(i=0;i<N;i++)scanf("%d",&B[i]);
        sort(B,B+N);
        int sum=A;
        if(A==1)
        {
            printf("Case #%d: %d\n",++cas,N);
            continue;
        }
        //bool t=1;
        //int x=0;
        for(i=0;i<N;i++)
        {
            if(B[i]<sum)sum+=B[i];
            else
            {
                int c=0;
                while(sum<=B[i])
                {
                    //x++;
                    sum+=(sum-1);c++;
                }
                C[i]=c;
                sum+=B[i];
            }
            //cout<<sum<<" ";
        }
        //cout<<endl;
        //cout<<x<<endl;

        int ans=func(0);

        printf("Case #%d: %d\n",++cas,ans);






    }

    return 0;
}
