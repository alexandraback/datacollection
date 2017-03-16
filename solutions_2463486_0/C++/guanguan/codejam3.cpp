#include<cstdio>
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;
vector<long long> v;

int main()
{
    freopen("codejam3.in","r",stdin);
    freopen("codejam3out.txt","w",stdout);
    ifstream in("fairandsquare.txt");
    long long tmp1,tmp2;
    while (in.good())
    {
          in >> tmp1 >> tmp2;
          v.push_back(tmp2);
    }
    v.pop_back();
    /*for (int i=0; i<v.size(); i++)
    {
        printf("%lld\n",v[i]);
    }*/
    long long tc,a,b;
    cin >> tc;
    for (long long j=0; j<tc; j++)
    {
        cin >> a >> b;
        int ans=0;
        for (int i=0; i<v.size(); i++)
        {
            if (a<=v[i] && b>=v[i])
            {
               ans++;
            }
        }
        cout << "Case #" << j+1 << ": " << ans << endl;
    }
}
