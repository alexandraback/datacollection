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

using namespace std;

void func()
{
    long long r,t;
    cin >> r >> t;
    int s_r = r;
    int b_r = r+1;
    
    int cnt_circle = 0;
    while(true)
    {
        long long need = b_r*b_r-s_r*s_r;
        if (t >= need)
            cnt_circle++;
        else
            break;
        t -= need;
        s_r = b_r+1;
        b_r = s_r+1;
    }

    cout << cnt_circle << endl;
}


////////////////////////////////

char in_file[] = "test.in";
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
