#include<iostream>
#include<math.h>
#include<stdio.h>
#include<string>
using namespace std;
long long wow = 10000000000000016;
int print(int a,  int x)
{
    cout<<"Case #"<<x<<": "<<a<<endl;
    return 0;
}
int main()
{
    freopen("out.txt", "w", stdout);
    //freopen("in.in", "r", stdin);
    int t, r, c, w;
    cin>>t;
    for(int test = 0 ; test < t ; test++)
    {
        cin>>r>>c>>w;
        int ans = c / w * r;
        ans += w;
        if(c%w == 0)
            ans--;
        print(ans, test+1);
    }
}
