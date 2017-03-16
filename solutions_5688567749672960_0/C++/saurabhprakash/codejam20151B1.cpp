#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

typedef long long ll;
ll ans[20];
void initializer()
{
    int i;
    ans[0]=1,ans[1]=10;
    ll num=9;
    for(i=2;i<16;i++)
        ans[i]=ans[i-1]+10+num,num=num*10+9;
}
int main()
{
    //freopen("C:\\Users\\Saurabh Prakash\\Desktop\\in.txt","r",stdin);
    //freopen("C:\\Users\\Saurabh Prakash\\Desktop\\out.txt","w",stdout);
    initializer();
    int t,cas=1;
    cin>>t;
    while(t--)
    {
        ll n,i,temp;
        cin>>n;
        int index=log10(n);
        ll a,num2=n/ll(pow(10,index))*pow(10,index)+1;
        if(n>=num2)
            a=ans[index]+n/ll(pow(10,index))+n-num2+1;
        else
            num2-=100,a=ans[index]+n/ll(pow(10,index))-1+n-num2;
        cout<<"Case #"<<cas++<<": "<<a<<endl;
    }

    return 0;
}
