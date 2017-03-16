#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int s[200];
int flag[200];

int main()
{
    freopen("A-large_y.in", "r", stdin);
    freopen("A-large_l.out", "w", stdout);
    int t;
    cin>>t;
    for (int no = 1; no <= t; no++)
    {
        memset(flag, 0, sizeof(flag));
        int n;
        cin>>n;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin>>s[i];
            sum += s[i];
        }
        int total = sum*2;
        double avg = (double)total/n;
        int cnt = n;
        for (int i = 0; i < n; i++)
        {
            if (s[i] > avg - 1e-9)
            {
                flag[i] = 1;
                total -= s[i];
                cnt--;
            }
        }

        double toGet = (double)total/cnt;

        //cout<<setprecision(9)<<fixed<<toGet<<endl;
        cout<<"Case #"<<no<<":";
        for (int i = 0; i < n; i++)
        {
            if (flag[i]) cout<<" "<<0;
            else cout<<setprecision(9)<<fixed<<" "<<100*(toGet-s[i])/sum;
        }
        cout<<endl;
    }
}
