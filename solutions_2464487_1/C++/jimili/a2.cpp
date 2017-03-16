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

void func()
{
    long long r,t;
    cin >> r >> t;

    long double a = 2;
    long double b = 2*r-1;
    long double c = -1 * t;

    long double ret = ((-1 * b) + sqrt(b*b-4*a*c)) / (2*a);
    cout << floor(ret) << endl;
}


////////////////////////////////

char in_file[] = "test2.in";
char out_file[] = "test2.out";

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
