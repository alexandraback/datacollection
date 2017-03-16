#include<cstdio>
#include<iostream>

using namespace std;

int main()
{
    long long int t,n,row,col,w,i;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    cin>>t;
    for(int j=1;j<t+1;j++)
    {

        cin>>row>>col>>w;
        n=w+(col/w)*row;
        if(col%w==0)
            n=n-1;

        cout<<"Case #"<<j<<": "<<n<<endl;
    }
    return 0;
}
