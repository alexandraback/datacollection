#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
vector<string> v;
vector<int> nchar;
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int t,i,n,cnt,ans,l,j,f,cse=1,tmp,sum,avg,a,b,k;
    cin>>t;
    while(t--)
    {
        cnt=0;
        cin>>a>>b>>k;
        for(i=0;i<a;i++)
        {
            for(j=0;j<b;j++)
            {
                if((i&j)<k)
                {
                    cnt++;
                }
            }
        }
        cout<<"Case #"<<cse++<<": "<<cnt<<endl;
    }
    return 0;
}
