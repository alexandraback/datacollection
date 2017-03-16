#include<stdio.h>
#include<iostream>
#include<fstream>
using namespace std;

ifstream fin("C-small-attempt0.in");
ofstream fout("out.txt");

int record[1002],weight1,weight2,weight3;
int max_pair(int P,int S,int K,int J,int start1,int start2,int sortn)
{

    if(sortn==1)
    {
        weight1=100;weight2=10;weight3=1;
    }
    else if(sortn==2)
    {
        weight1=10;weight2=100;weight3=1;
    }
    else
    {
        weight1=1;weight2=100;weight3=10;
    }
    if(P>=K)
    {
        for(int i=0;i<J;++i)
        {
            for(int m=start1;m<start1+K;++m)
            {
               for(int l=start2;l<start2+K;++l)
               {
                   record[weight1*i+weight2*m+weight3*l]=1;
               }
            }
        }
        return K*K+max_pair(P-K,S-K,K,J,start1+K,start2+K,sortn);
    }
    else
    {
        if(S>=K)
        {
        for(int i=0;i<J;++i)
        {
            for(int m=start1;m<start1+P;++m)
            {
               for(int l=start2;l<start2+K;++l)
               {
                   record[100*i+10*m+l]=1;
               }
            }
        }
            return K*P;
        }
        else
        {
                    for(int i=0;i<J;++i)
        {
            for(int m=start1;m<start1+P;++m)
            {
               for(int l=start2;l<start2+S;++l)
               {
                   record[100*i+10*m+l]=1;
               }
            }
        }
            return P*S;
        }

    }


}
int max_three(int J,int P,int S,int K)
{
    int ans,ans1,ans2,ans3;
    ans1=K*max_pair( P, S, K,J,0,0,1);
    ans2=K*max_pair( J, S, K,P,0,0,2);
    ans3=K*max_pair( J, P, K,S,0,0,3);
    ans=max(ans1,max(ans2,ans3));
    return ans;
}
int main()
{
    int T,J,P,S,K,N;
    int ans,ans1,ans2,ans3;
    fin>>T;
    for(int i=0;i<T;++i)
    {
        for(int m=0;m<1001;m++)record[m]=0;
        fin>>J>>P>>S>>K;

        if(J<=K){
                ans=J*max_pair(P,S,K,J,0,0,1);
        }
        else{
            ans=max_three(J,P,S,K);
        }

        fout<<"Case #"<<i+1<<": "<<ans<<endl;
        for(int j=0;j<J;++j)
            for(int p=0;p<P;++p)
                for(int s=0;s<S;++s)
        {

            if(record[100*j+10*p+s])fout<<j+1<<" "<<p+1<<" "<<s+1<<" "<<endl;
        }

    }

    return 0;
}
