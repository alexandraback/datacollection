#include <vector>
#include <algorithm>
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

ll arr[200];
ll a,n;
ll count_step(ll &b, ll e);
ll get(ll now_step, ll now_num, ll level)
{
    if (level >= n)
        return now_step;

    //ll s1;
    if (now_num == 1)
        return get(now_step+1, now_num, level+1);
    
    if (arr[level] < now_num)
        return get(now_step, now_num+arr[level], level+1);
    else
    {
        ll t = now_num;
        ll cnt = count_step(t, arr[level]);
        if (cnt > n-level)
            return now_step+(n-level);
        else
        {
            ll s1 = get(now_step+cnt, t+arr[level], level+1);
            ll s2 = get(now_step+1, now_num, level+1);
            return min(s1, s2);
        }
    }
}

ll count_step(ll &b, ll e)
{
    ll cnt = 0;
    while(b <= e)
    {
        cnt++;
        b+=(b-1);
    }
    return cnt;
}

void func()
{
    cin >> a >>n;
    memset(arr,0,sizeof(arr));
    for (ll i=0; i<n;++i)
        cin >> arr[i];
    sort(arr, arr+n);

    //ll step;
    //ll s1;
    if (a == 1)
    {
        cout << get(1, a, 1) << endl;
        return;
    }

    if (arr[0] < a)
        cout <<get(0, a+arr[0], 1) << endl; 
    else
    {
        ll t = a;
        ll cnt = count_step(t, arr[0]);
        if (cnt > n)
            cout << n << endl;
        else
        {
            ll s1 = get(cnt, t+arr[0], 1);
            ll s2 = get(1, a, 1);
            cout << min(s1, s2) << endl;
        }
    }
}


//////////////////////////////

char in_file[] = "testa.in";
char out_file[] = "testa.out";

int main()
{
    int case_count_step, t;

    freopen(in_file, "r", stdin);
    freopen(out_file,"w", stdout);

    cin >> case_count_step;
    for (t = 1; t <= case_count_step; t++)
    {
        cerr << "\nDealing Case #" << t << endl;
        cout << "Case #" << t << ": ";
        func();
    }

	return 0;    
}
