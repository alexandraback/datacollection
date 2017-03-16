#include <vector>
#include <cmath>
#include <cstdio>
#include <list>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <stack>
#include <map>
#include <iostream>
#include <string>
#include <set>

using namespace std;

//map<int, vector<int> > mapper;
//list<type> lister;
//set<type> seter;
#define ll long long

ll fac(ll a)
{
    ll ret = 1;
    while (a > 1)
        ret += a--;
    return ret;
}

void func()
{
    ll n,x,y;
    cin>>n>>x>>y;
    cout.precision(8);
    cout.setf(ios::fixed);


    if (x == 0 && y == 0)
        cout << 1.0 << endl;
    else if (x == 0)
    {
        ll k = fac(y+1);
        long double ret = 0.0;
        for (ll i=k-1; i<n; ++i)
            ret += pow(0.5,i);
        cout << ret << endl;
    }
    else
    {
        ll k = fac(x+y-1) + y + 1;
        //cout << '\n' << k << endl;
        long double ret = 0.0;
        for (ll i=k-1; i<n;++i)
            ret += pow(0.5, i);
        cout << ret << endl;
    }
}


//////////////////////////////

char in_file[] = "testb.in";
char out_file[] = "testb.out";

int main()
{
    int case_count, t;

    freopen(in_file, "r", stdin);
    freopen(out_file,"w", stdout);

    cin >> case_count;
    for (t = 1; t <= case_count; t++)
    {
        cerr << "\nDealing Case #" << t << endl;
        cout << "Case #" << t << ": ";
        func();
    }

	return 0;    
}
