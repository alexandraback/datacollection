#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int Maxn = 1010;
map<int,int> mp;
map<int,int>::iterator it;
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);

    int T,N,x;
    cin>>T;
    for(int cas = 1;cas <= T;cas ++)
    {
        cin>>N;
        mp.clear();
        for(int i = 0;i < 2 * N - 1;i ++)
        {
            for(int j = 0;j < N;j ++)
            {
                cin>>x;
                mp[x] ++;
            }

        }
        cout<<"Case #"<<cas<<":";
        for(it = mp.begin();it != mp.end();it ++)
        {
            if(it->second & 1)
                cout<<" "<<it->first;
        }
        cout<<endl;
    }
    return 0;
}
