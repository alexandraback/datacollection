#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    ifstream cin("in1.txt");
    ofstream cout("out1.txt");
    cin>>t;
    int l = 0;
    while(t--)
    {
        l++;
        int a,b,k;
        cin>>a>>b>>k;
        int cnt = 0;
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                //cout<<(i&j)<<endl;
                if((i&j) < k)
                {
                    cnt++;
                }
            }
        }
        cout<<"Case #"<<l<<": "<<cnt<<endl;
    }
    return 0;
}
