#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i,c1,j,k,r,c,w,cnt;
    freopen("111.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>t;
    for(c1=1;c1<=t;c1++)
    {
        cnt=0;
        cin>>r>>c>>w;
        cnt=c/w;
        cnt=cnt*r;
        cnt+=w-1;
        if(c%w!=0)
            cnt++;
        cout<<"Case #"<<c1<<": "<<cnt<<endl;
    }
return 0;
}
