#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
   // freopen("B-small-attempt0.in","r",stdin);
   // freopen("B-small.txt","w",stdout);
    int a,b,k,cas;
    cin>>cas;
    for(int q=1;q<=cas;q++)
    {
        cin>>a>>b>>k;
        int sol =0;
        for(int i=0;i<a;i++)
            for(int j=0;j<b;j++)
            {
                if( (i&j) < k)sol++;
            }
        cout<<"Case #"<<q<<": "<<sol<<endl;
    }
    return 0;
}
