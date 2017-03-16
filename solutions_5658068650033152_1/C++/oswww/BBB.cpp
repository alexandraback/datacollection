#define OSW2
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int SQT(int x)
{
    if(x<=0) return 0;
    int l=0,r=40000,m;
    while(l<r)
    {
        m=(l+r+1)>>1;
        if(m*m>x) r=m-1;
        else l=m;
    }
    return l;
}

int N,M,K;
int ans;
int main()
{
    #ifdef OSW
    freopen("C:\\Users\\Oswww\\Desktop\\in.txt", "r", stdin);
    #endif // OSW
    #ifdef OSW2
    freopen("E:\\ACM\\Google Code Jam 2014\\C-large.in", "r", stdin);
    freopen("E:\\ACM\\Google Code Jam 2014\\outCC.txt", "w", stdout);
    #endif // OSW
    ios::sync_with_stdio(false);
    int casT;
    scanf("%d",&casT);
    for(int cas=1;cas<=casT;cas++)
    {
        //N=1000,M=1000,K=cas+100000;
        scanf("%d%d%d",&N,&M,&K);
        if(K<=3||N==1||M==1) ans=K;
        else
        {
            ans = (N-1+M-1)*2;
            //cout<<ans<<"hehe"<<endl;
            if(N>M) swap(N,M);
            for(int r=1;r<N;r++)
            for(int c=r;c<M;c++)
            {

                int lef = (r+1)*(c+1)-K;
                if(lef<0) continue;
                int Lmn = SQT(lef/2);
                while(Lmn*(Lmn+1)/2*4>lef) Lmn--;
                if(Lmn+Lmn>r) Lmn=min(Lmn,r/2);
                //cout<<r<<" "<<c<<" :: "<<lef<<" "<<Lmn<<endl;
                for(int edgnum=0;edgnum<4;edgnum++)
                {
                    int num0=4-edgnum,num1=edgnum;
                    int L0 = Lmn,L1 = Lmn+1;
                    if(num0!=4&&L0+L1>r) continue;
                    if(L0*(L0+1)/2*num0+L1*(L1+1)/2*num1<=lef)
                    {
                        ans=min(ans,(r+c)*2-num0*L0-num1*L1);
                        //if((r+c)*2-num0*L0-num1*L1==12)cout<<r<<" "<<c<<" : "<<Lmn<<" "<<num0<<endl;
                    }
                }
            }
        }
        //if(K<=3||N==1||M==1) continue;
        //cout<<"-- "<<N<<" "<<M<<" "<<K<<endl;
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}
