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

vector<vector<int> > d;
vector<int> ds;
vector<int> dn;
vector<int> dp;
set<pair<int,int> > r;

void func()
{
    int i,j,k,n,m;
    int ret,temp;
    int start;
    int end;
    int cur;
    d.clear();
    ds.clear();
    dn.clear();
    dp.clear();
    r.clear();

    cin >> n;
    for (i=0; i<n; i++)
    {
        cin >> m;
        vector<int> tt;
        for (j=0; j<m; j++)
        {
            cin >> temp; 
            tt.push_back(temp-1);
        }
        d.push_back(tt);
        ds.push_back(m);
    }

    for (i=0; i<ds.size(); i++)
    {
        if (ds[i] > 1)
        {
            dn.push_back(i);
            dp.push_back(0);
            start = i;
            cur = 0;
            break;
        }
    }
    if (i == ds.size())
    {
        cout << "No" << endl;
        return;
    }

    while(true)
    {
        end = d[dn[cur]][dp[cur]];
        if (r.count(make_pair(start,end)) == 1)
        {
            cout << "Yes" << endl;
            return;
        }
        r.insert(make_pair(start,end));
        if (ds[end] != 0)
        {
            dn.push_back(end);
            dp.push_back(0);
            cur++;
        }
        else
        {
            while (true)
            {
                if (dp[cur] != (ds[dn[cur]] -1))
                { dp[cur]++; break; }
                else
                {
                    dp.pop_back();
                    dn.pop_back();
                    cur--;
                }

                if (dn.size()==0)
                {
                    for (j=start+1; j<ds.size(); j++)
                    {
                        if (ds[j] > 1)
                        {
                            dn.push_back(j);
                            dp.push_back(0);
                            start = j;
                            cur = 0;
                            break;
                        }
                    }
                    if (j==ds.size())
                    {
                        cout << "No" << endl;
                        return;
                    }
                    else
                        break;
                }
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////

char in_file[] = "A-small-attempt0.in";
char out_file[] = "A-small-attempt0.out";

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
