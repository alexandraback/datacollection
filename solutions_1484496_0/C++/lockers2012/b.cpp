#include <vector>
#include <numeric>
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
vector<int> s1;
vector<int> s2;

bool func2(int i, int n)
{
    bool ret;
    if ((!s1.empty())  && (!s2.empty()))
    {
        int sum1 = accumulate(s1.begin(),s1.end(),0);
        int sum2 = accumulate(s2.begin(),s2.end(),0);
        if (sum1 == sum2)
        {
            cout << endl;
            for (int j=0; j!=s1.size(); j++)
            {
                cout << s1[j];
                if (j != s1.size()-1)
                    cout << ' ';
                else
                    cout << endl;
            }

            for (int j=0; j!=s2.size(); j++)
            {
                cout << s2[j];
                if (j != s2.size()-1)
                    cout << ' ';
                else
                    cout << endl;
            }
            return true;
        }
    }
    
    if (i==n)
        return false;
    

    s1.push_back(vec[i]);
    ret = func2(i+1, n);
    if (ret == true)
        return true;

    s1.pop_back();
    s2.push_back(vec[i]);
    ret = func2(i+1, n);
    if (ret == true)
        return true;

    s2.pop_back();
    ret = func2(i+1, n);
    if (ret == true)
        return true;

    return false;
}

void func()
{
    int i,j,k,n,t;
    bool ret;
    

    vec.clear();
    cin >> n;
    for (i=0;i<n;i++)
    {
        cin >> t;
        vec.push_back(t);
    }
    sort(vec.begin(), vec.end());

    s1.clear();
    s2.clear();
    ret = func2(0,n);
    if (!ret)
        cout << endl << "Impossible" << endl;
}


////////////////////////////////////////////////////////////////////////////

char in_file[] = "C-small-attempt0.in";
char out_file[] = "C-small-attempt0.out";

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
