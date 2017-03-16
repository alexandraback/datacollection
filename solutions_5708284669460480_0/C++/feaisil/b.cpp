#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <math.h>
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

using namespace std;

#define VCERR(vect)for(size_t iiivcerr=0; iiivcerr<vect.size(); iiivcerr++) {errlog(vect[iiivcerr]); errlog(" ");} errlog("\n");
#define VIN(t,vect, len) t vect(N); for(size_t iiivcerr=0; iiivcerr<len; iiivcerr++) cin >> vect[iiivcerr];
#define FORN(i, n) for(int i=0; i<n; i++)
typedef vector<string> Vs;
typedef vector<int> Vi;
typedef vector<double> Vd;
typedef map<int,Vi> MVi;
typedef vector<string> vstr;

#ifdef DBG
#define dbg true
#else
#define dbg false
#endif
template<typename T, bool a=dbg>
void errlog(const T& v)
{
    if(a)
    {
        cerr << v;
    }
}

int numDigits(int number)
{
    int digits = 0;
    if (number < 0) digits = 1;
    while (number) {
        number /= 10;
        digits++;
    }
    return digits;
}

//int f(Vi& v)
//{
//    int c=0;
//    for(int i=0; i < v.size(); i++ )
//    {
//        if(v[i]<i)
//            c++;
//    }
//    return c;
//}

void solve()
{
    double pb=0;
    int k, l ,s,d;

    cin >> k >> l >> s;
    std::string in, ta;
    cin >> in >> ta;
    errlog(k);
    errlog(" ");
    errlog(l);
    errlog(" ");
    errlog(s);
    errlog(" ");
    errlog(in);
    errlog(" ");
    errlog(ta);
    errlog("\n");


    map<char,double> f;
    FORN(i,k)
    {
        if(f.find(in[i])!=f.end())
            f[in[i]]++;
        else
            f[in[i]] = 1;
    }

    errlog("f: ");
    errlog("\n");
    for(map<char,double>::const_iterator it = f.begin(); it!=f.end(); ++it)
    {
        errlog(it->first);
        errlog(" ");
        errlog(it->second);
        errlog("\n");
    }
    errlog("\n");
    double p = 1;
    FORN(i,l)
    {
        if(in.find(ta[i]) == string::npos)
        {
            cout << pb << endl;
            return;
        }
        p=p*f[ta[i]]/k;
    }


    int n = s/l;
    double reste = n;
    errlog("prob ");
    errlog(p);
    errlog(" n ");
    errlog(n);
    errlog("\n");

    vector<vector<double> > pv;

    {

        errlog("building p");
        errlog(1);
        errlog(" {");
        vector<double> pi;
        FORN(i,s+1)
        {
            double p1 = 1-pow((1-p),(1+i-l));
            if (p1 < 0.0)
                p1 = 0;
            if (p1 > 1.0)
                p1 = 1;
            pi.push_back(p1);

            errlog(i);
            errlog(":");
            errlog(p1);
            errlog(",");
        }
        errlog("}\n");
        pv.push_back(pi);

    }
    errlog("let's continue\n");

    vector<double> pvi;
    double pi;
    for(int i=2; i <= n; i++)
    {
        errlog("building p");
        errlog(i);
        errlog(" {");
        FORN(ii,s+1)
        {
            pi = 0;
            if(ii-l>0)
            {
                for(int j=ii-l; j > 0; j--)
                {
                    if(j < pv.back().size())
                        pi += p*pv.back()[j];
                }
            }
            errlog(ii);
            errlog(":");
            errlog(pi);
            errlog(",");
            pvi.push_back(pi);
        }
        errlog("}\n");
        pv.push_back(pvi);
    }

    double pl=0;
    for(int i = n; i > 0; i--)
    {
        pl = pv[i-1].back()-pl;
        reste = reste - pl*i;
    }

    cout << (float)(reste) << endl;
}

int main()
{
    int T;
    cin >> T;
    cerr << T << endl;
    string re;

    for(int tt=1; tt <= T; tt++)
    {
        if(tt*1000/T%10 ==0)
            cerr << tt << ", " << tt*100/T<< "%" << endl;
        cout << "Case #" << tt << ": ";
        solve();
    }

    return 0;
}

