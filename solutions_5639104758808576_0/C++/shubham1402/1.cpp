#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream cin("in.txt");
    ofstream cout("out.txt");
    int t;
    cin>>t;
    int k = 1;
    while(t--)
    {
        cout<<"Case #"<<k<<": ";
        k++;
        int sMax;
        cin>>sMax;
        int tot = 0;
        int ans = 0;
        for(int i=0;i<=sMax;i++)
        {
            char ch;
            cin>>ch;
            int temp = ch - '0';
            if(i <= tot)
            {
                tot += temp;
            }
            else
            {
                ans += (i-tot);

                tot += (i-tot);
                tot += temp;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
