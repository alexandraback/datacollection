#include <vector>
#include <iomanip>
#include <stack>
#include <map>
#include <iostream>
#include <string>
#include <set>

using namespace std;

#define DEBUG

#ifdef DEBUG
    #define debug(x...) msg(x);
#else
    #define debug(x...)
#endif

template <class t1>
void msg(t1 a)
{ cerr << a << endl; }
template <class t1, class t2>
void msg(t1 a, t2 b)
{ cerr << a << '\t' << b << endl; }
template <class t1, class t2, class t3>
void msg(t1 a, t2 b, t3 c)
{ cerr << a << '\t' << b << '\t' << c << endl; }
template <class t1, class t2, class t3, class t4>
void msg(t1 a, t2 b, t3 c, t4 d)
{ cerr << a << '\t' << b << '\t' << c << '\t' << d << endl; }
template <class t1, class t2, class t3, class t4, class t5>
void msg(t1 a, t2 b, t3 c, t4 d, t5 e)
{ cerr << a << '\t' << b << '\t' << c << '\t' << d << '\t' << e << endl; }
template <class t1, class t2, class t3, class t4, class t5, class t6>
void msg(t1 a, t2 b, t3 c, t4 d, t5 e, t6 f)
{ cerr << a << '\t' << b << '\t' << c << '\t' << d << '\t' << e << '\t' << f << endl; }

////////////////////////////////////////////////////////////////////////////

vector<int> vec;

void func()
{
    int i,j,k,n;
    int ret;
    long double sum = 0.0;

    vec.clear();
    cin >> n;
    for (i=0; i<n; i++)
    {
        cin >> k;
        vec.push_back(k);
        sum += k;
    }

    cout.precision(6);
    cout.setf(ios::fixed);

    long double cp = sum * 2;
    int m = n;
    for (i=0; i<n; i++)
    {
        if (vec[i] >= ((sum*2)/n))
        {
            cp -= vec[i];
            m--;
        }
    }

    for (i=0; i<n; i++)
    {
        if (vec[i] >= ((sum*2)/n))
            cout << 0.0;
        else
        {
            cout << ((cp/m - vec[i])/sum) * 100;
        }
        if (i != n-1)
            cout << ' ';
        else
            cout << endl;
    }
}


////////////////////////////////////////////////////////////////////////////

char in_file[] = "A-small-attempt0.in";
char out_file[] = "A-small-attempt0.out";

int main()
{
    int case_count, t;

    freopen(in_file, "r", stdin);       //确保文件在当前路径中
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
