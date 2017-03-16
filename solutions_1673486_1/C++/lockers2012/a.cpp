#include <vector>
#include <iomanip>
#include <map>
#include <iostream>
#include <string>
#include <set>

using namespace std;

//#define DEBUG

#ifdef DEBUG
    #define debug(x...) msg(x);
#else
    #define debug(x...)
#endif

template <class t1>
void msg(t1 a)
{
    cerr << a << endl;
}
template <class t1, class t2>
void msg(t1 a, t2 b)
{
    cerr << a << '\t' << b << endl;
}
template <class t1, class t2, class t3>
void msg(t1 a, t2 b, t3 c)
{
    cerr << a << '\t' << b << '\t' << c << endl;
}
template <class t1, class t2, class t3, class t4>
void msg(t1 a, t2 b, t3 c, t4 d)
{
    cerr << a << '\t' << b << '\t' << c << '\t' << d << endl;
}

////////////////////////////////////////////////////////////////////////////

vector<long double> rets;
vector<double> poss;

void func()
{
    int i,j,k;
    int a,b;
    long double tmp;
    long double right=1,wrong=1;
    rets.clear();
    poss.clear();

    cin >> a >> b;
    for (i=0; i<a; i++)
    { 
        cin >> tmp;
        poss.push_back(tmp);
        right *= tmp;
    }
    wrong = 1-right;
    debug("right", right, "wrong", wrong);

    //keep typing
    tmp = (b-a+1)*right + (b-a+1+b+1)*wrong;
    debug("keep typing:", tmp);
    rets.push_back(tmp);

    //press enter right now
    tmp = 1+b+1;
    debug("press enter now", tmp);
    rets.push_back(tmp);

    //press delete
    for (i=a; i>0; i--)
    {
        right /= poss[i-1];
        wrong = 1-right;
        debug("right", right, "wrong", wrong);
        tmp = (b-i+1+1)*right + (b-i+1+1+b+1)*wrong + (a-i+1);
        debug("press delete i", tmp);
        rets.push_back(tmp);
    }

    sort(rets.begin(), rets.end());
    cout.setf(ios::fixed);
    cout << setprecision(6) << rets[0] << endl;
}


////////////////////////////////////////////////////////////////////////////

char in_file[] = "A-large.in";
char out_file[] = "A-large.out";

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
