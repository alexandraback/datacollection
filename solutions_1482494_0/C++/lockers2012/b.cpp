#include <vector>
#include <iomanip>
#include <stack>
#include <map>
#include <iostream>
#include <string>
#include <set>
#include <list>

using namespace std;

#define DEBUG

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

list<pair<int,int> > d;
list<pair<int,int> > r1;
list<pair<int,int> > r2;

void func()
{
    int i,j,k,n;
    int a,b;
    long ret = 0;
    long star = 0;
    d.clear();
    r1.clear();
    r2.clear();
    cin >> n;
    for (i=0; i<n; i++)
    { cin >> a >> b; d.push_back(make_pair(a,b));}

    list<pair<int,int> >::iterator iter;
    while(true)
    {
        while (true)
        {
            bool change = false;
            for(iter=d.begin(); iter!=d.end(); iter++)
                if (iter->second <= star)
                { star += 2; r2.push_back(*iter); iter=d.erase(iter); ret++; change = true;}
            
            for (iter=r1.begin(); iter!=r1.end(); iter++)
                if (iter->second <= star)
                { star += 1; iter = r1.erase(iter); ret++; change = true;}


            if (!change)
                break;
        }

        if (d.empty() && r1.empty())
        { cout << ret << endl; return; }

        bool bad = true;

        if (!r2.empty())
        {
            for (iter=r2.begin(); iter!=r2.end(); iter++)
                if (iter->first <= star)
                   { star += 1; iter=r2.erase(iter); ret++; bad=false; break; }
        }
        if (bad && (!d.empty()))
        {
            for (iter=d.begin(); iter!=d.end(); iter++)
                if (iter->first <= star)
                   { star += 1; r1.push_back(*iter); iter=d.erase(iter); ret++; bad=false; break; }
        }

        if (bad && ((!d.empty()) || (!r1.empty())))
        { cout << "Too Bad" << endl; return; }

        
    }

    return;
}


////////////////////////////////////////////////////////////////////////////

char in_file[] = "B-small-attempt1.in";
char out_file[] = "B-small-attempt1.out";

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
