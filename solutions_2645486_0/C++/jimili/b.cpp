#include <vector>
#include <cstring>
#include <iomanip>
#include <stack>
#include <map>
#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <set>
#include <cmath>

using namespace std;
long long max_gain = 0;
long long values[10000010];
long long e,r,n;

void get(long long gain, long long e_now, int ele)
{
    //printf("gain:%lld, e_now:%lld, ele:%lld\n", gain,e_now,ele);
    if (ele == n-1)
    {
        long long total_gain = gain + values[ele] * e_now;
        max_gain = max(max_gain, total_gain);
        return;
    }
    else if (ele > n-1)
    {
        max_gain = max(max_gain, gain);
        return;
    }

    for (int i = 0; i <= e_now; ++i)
    {
        long long gain_i = values[ele] * i;
        if (i != 0)
            get (gain_i + gain, min(e, e_now-i+r), ele+1);
        else
            get (gain, min(e,e_now+r), ele+1);
    }

    return;
}

void func()
{
    cin >> e >> r >> n;
    memset(values, 0, sizeof(values));
    int cnt = 0;
    for (long long i = 0; i < n; ++i)
        cin >> values[cnt++];
    max_gain = 0;

    for (long long i = 0; i <= e; ++i)
    {
        long long gain_i = values[0] * i;
        if (i != 0)
            get (gain_i, min(e, e-i+r), 1);
        else
            get (0, e, 1);
    }

    cout << max_gain << endl;
}


////////////////////////////////

char in_file[] = "test5.in";
char out_file[] = "test.out";

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
