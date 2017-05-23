#include<iostream>
#include<math.h>
using namespace std;
long long fast_pow(int a , int b)
{
    long long x=1,y=a;
    while (b!=0)
    {
        if(b%2==1)
            x=x*y;
        y=y*y;
        b=b/2;
    }
    return x;
}
long long to_base_x(string S , int X)
{
    int j=15;
    long long Ans=0;
    for (int i=0 ; i<16 ; i++)
    {
        long long c=fast_pow(X,j);
        if(S[i]=='1')
            Ans=Ans+c;
        j--;
    }
    return Ans;
}
long long prime(long long X)
{
    int a=sqrt(X);
    if (X%2==0)
    {
        return 2;
    }
    for (int i=3 ; i<=a ; i+=2)
    {
        if(X%i==0)
            return i;
    }
    return 0;
}
int b=50;
void solve(string S , int a )
{
    if(b==0)
        return;
    if(a==16)
    {
        long long A[9]={0},B[9]={0};
        for (int i=2 ; i<=10 ; i++)
        {
            long long V=to_base_x(S,i);
            long long K=prime(V);
            B[i-2]=V;
            if(K==0)
                return;
            A[i-2]=K;
        }
        cout<<S<<" ";
        for (int i=0 ; i<9 ; i++)
            cout<<A[i]<<" ";
        cout<<endl;
        b--;
        return;
    }
    if(a<15)
        solve(S+'0',a+1);
    solve(S+'1',a+1);
}
int main()
{
    string s;
    s=s+'1';
    solve(s,1);
}
