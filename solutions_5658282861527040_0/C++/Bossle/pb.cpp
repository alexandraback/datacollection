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

using namespace std;

void print(int i){cout << i << " ";}
void print(string s){cout << s << endl;}
template<class T> void print(vector<T> v){for(int i=0;i<v.size();++i)print(v[i]);cout << endl;}

typedef unsigned long long int num;

num ways(num m,num bit)
{
    if(m<bit) return 0;
    num mp=1; while(mp<=m) mp*=2; mp/=2;
    num res=0;
    if(mp>bit) res+=mp/2;
    if(mp==bit) return m-mp+1;
    else return res+ways(m-mp,bit);
}

num func(num a,num b,num k)
{
    if(k>a || k>b) return a*b;
    num mp=1; while(mp<=k) mp*=2; mp/=2;
    num res = mp*mp; // entre [0 e mp)
    return res;//+maneiras de fazer entre [mp e k)
}

int main()
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int tt;
    scanf("%d", &tt);
    for (int qq=1;qq<=tt;qq++)
    {
        printf("Case #%d: ", qq);

        num a,b,k;
        cin >> a >> b >> k;

        num res=0;
        for(int i=0;i<a;++i) for(int j=0;j<b;++j) if((i&j)<k) ++res;

        cout << res << endl;
    }
}














