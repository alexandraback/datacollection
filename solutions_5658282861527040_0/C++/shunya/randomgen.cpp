#include <iostream>

using namespace std;

int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("output2.txt","w",stdout);
    int t;
    cin>>t;int testcaseno=1;
    //cout<<t<<endl;
    while(t--)
    {
    int a,b,k;
    cin>>a>>b>>k;
    int x1,x2,y1,y2;
    if(a>=k){x1=k;x2=a-k;}
    else {x1=a;x2=0;}
    if(b>=k){y1=k;y2=b-k;}
    else {y1=b;y2=0;}
    int count=0;
    count+=(x1*y1+x1*y2+x2*y1);
    if(a>=k && b>=k)
    for(int i=k;i<a;++i)
    {
        for(int j=k;j<b;++j)
        {
            if((i&j)<k)count++;
        }
    }
    cout<<"Case #"<<testcaseno<<": ";
    cout<<count<<endl;
    testcaseno++;
    }
    return 0;
}
