#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
using namespace std;
long long n;
long long s;
long long arr0[21];
long long arr9[21];
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    arr9[0]=0;
    arr0[1]=1;
    for(int i=1;i<=20;i++)
        arr9[i]=arr9[i-1]*10+9;
    for(int i=2;i<=20;i++)
        arr0[i]=arr0[i-1]*10;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cout<<"Case #"<<i<<": ";
        cin>>n;
        s=0;
        if(n<=10)
        {
            cout<<n<<endl;
            continue;
        }
        else
            s=10;
        long long n1=10;
        int j=1;
        while(n1*10<=n)
        {
            j++;
            if(j%2==1)
                s+=1+arr9[j/2]+arr9[j/2+1];
            else
                s+=1+arr9[j/2]*2;
            n1*=10;
        }
        j++;
        int k;
        if(j%2==0)
            k=j/2+1;
        else
            k=j/2+2;
        if(arr0[j]==n-n%arr0[k])
            s+=n%arr0[k];
        else
        {
            if(n%arr0[k]==0)
            {
                s+=arr9[k-1];
                n=n-arr0[k]+1;
            }
            if(arr0[j]==n-n%arr0[k])
                s+=n%arr0[k];
            else
            {
            s+=n%arr0[k];
            n/=arr0[k];
            k=j-k+1;
            for(int j=k;j>=1;j--)
            {
                s+=arr0[j]*(n%10);
                n/=10;
            }
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
