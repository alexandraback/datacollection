// Template By Fendy Kosnatha (Seraph)
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string.h>

#define fs first
#define sc second
#define mp make_pair
#define pii pair<int, int>

using namespace std;
int main()
{
    int tc;
    cin>>tc;
    int count=1;
    while (tc--)
    {
        vector<pair<int, int> > ostar;
        vector<pair<int, int> > tstar;
        int comp[1001]={0};
        int n;
        cin>>n;
        for (int i=1;i<=n;i++)
        {
            int a, b;
            cin>>a>>b;
            ostar.push_back(mp(a, i));
            tstar.push_back(mp(b, i));
        }
        sort(ostar.begin(), ostar.end());
        sort(tstar.begin(), tstar.end());
        int io=0;
        int it=0;
        int state=1;
        int star=0;
        int byk=0;
        int salah=0;
        int langkah=0;
        while (true)
        {
            if (byk==n) {break;}
            
            if (state==1) //periksa two star
            {
                if (tstar[it].first<=star)
                {
                    star+=(2-comp[tstar[it].second]);
                    comp[tstar[it].second] = 2;
                    byk++;
                    it++;
                    langkah++;
                }
                else
                {
                    state=0;
                }
            }
            else
            {
                if (io==n) {salah=1;break;}
                if (comp[ostar[io].second]!=0)
                    io++;
                else if (ostar[io].first<=star && comp[ostar[io].second]!=2)
                {
                    star+=1;
                    comp[ostar[io].second]=1;
                    io++;
                    langkah++;
                }
                else
                {
                    salah=1;
                    break;
                }
                state=1;
            }
        }
        cout<<"Case #"<<count++<<": ";
        if (salah==1) cout<<"Too Bad"<<endl;
        else cout<<langkah<<endl;
    }
    return 0;
}
