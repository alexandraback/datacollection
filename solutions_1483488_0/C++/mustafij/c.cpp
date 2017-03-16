#include<ctime>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<vector>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
#include<locale>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(a) (int((a).size()))
typedef istringstream iss; typedef ostringstream oss; typedef long long lli;
const double TOLL=1e-9;
int mark[20000010];

int main()
{
    int t; cin>>t; int cn=0; int marker=0;
    while(t--)
    {
        int a,b; lli rv=0;
        cin>>a>>b; vector<int> v;
        for(int n=a;n<=b;n++)
        {
            marker++;
            v.clear();
            int t=n;
            while(t)
            {
                v.push_back(t%10); t/=10;
            }
            reverse(all(v));
            int run=sz(v)-1;
            while(run--)
            {
                int x=v[sz(v)-1];
                v.erase(v.end()-1);
                v.insert(v.begin(),x);
                int now=0;
                for(int j=0;j<sz(v);j++) now=now*10+v[j];
                if(n<now && mark[now]!=marker && now>=a && now<=b) rv++, mark[now]=marker;
            }
        }
        printf("Case #%d: ",++cn); cout<<rv<<endl;

    }

}
