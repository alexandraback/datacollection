#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

long long oomg[550];

bool brute_force(long long *omg, int N, vector<long long> &a, vector<long long> &b, map<long long, int> &ma)
{
    //brute force
    for(int i=1;i<(1<<N);++i)
    {
        long long su = 0;
        for(int j=0;j<N;++j)
        {
            if(i & (1<<j)){su += omg[j];}
        }
        if(ma.find(su) != ma.end())
        {
            int zt = ma[su];
            int cur = i;
            cur &= ~zt;
            zt &= ~i;
            a.clear();b.clear();
            for(int j=0;j<N;++j)
            {
                if(cur & (1<<j)){a.push_back(omg[j]);}
                if(zt & (1<<j)){b.push_back(omg[j]);}
            }
            return true;
        }
        else{ma[su] = i;}
    }
    return false;
}

void do_case(int cn)
{
    int N;
    cin >> N;
    for(int i=0;i<N;++i){cin >> oomg[i];}
    map<long long,int> ma, ma2;
    cout << "Case #" << cn << ":" << endl;
    if(N < 30)
    {
        vector<long long> a,b;
        if(brute_force(oomg, N, a, b, ma))
        {
            cout << a[0];
            for(int i=1;i<a.size();++i)
            {
                cout << " "<< a[i];
            }
            cout << endl;
            cout << b[0];
            for(int i=1;i<b.size();++i)
            {
                cout << " "<< b[i];
            }
            cout << endl;
        }
        else
        {
            cout << "Impossible" << endl;
        }
        return;
    }
    int NN = 22;
    while(1)
    {
        cerr << "TRYING" << endl;
        vector<long long> a,b;
        if(brute_force(oomg, NN, a, b, ma))
        {
            cout << a[0];
            for(int i=1;i<a.size();++i)
            {
                cout << " "<< a[i];
            }
            cout << endl;
            cout << b[0];
            for(int i=1;i<b.size();++i)
            {
                cout << " "<< b[i];
            }
            cout << endl;
            return;
        }
        if(brute_force(oomg+NN, NN, a, b, ma2))
        {
            cout << a[0];
            for(int i=1;i<a.size();++i)
            {
                cout << " "<< a[i];
            }
            cout << endl;
            cout << b[0];
            for(int i=1;i<b.size();++i)
            {
                cout << " "<< b[i];
            }
            cout << endl;
            return;
        }
        map<long long, int>::iterator aa, bb;
        aa = ma.begin();bb = ma2.begin();
        while(aa != ma.end() && bb != ma2.end())
        {
            if(aa->first == bb->first)
            {
                //done
                a.clear();b.clear();
                for(int i=0;i<NN;++i)
                {
                    if(aa->second & (1<<i)){a.push_back(oomg[i]);}
                    if(bb->second & (1<<i)){b.push_back(oomg[i+NN]);}
                }
                cout << a[0];
                for(int i=1;i<a.size();++i)
                {
                    cout << " "<< a[i];
                }
                cout << endl;
                cout << b[0];
                for(int i=1;i<b.size();++i)
                {
                    cout << " "<< b[i];
                }
                cout << endl;
                return;
            }
            else if(aa->first > bb->first)
            {
                ++bb;
            }
            else
            {
                ++aa;
            }
        }
        ma.clear();ma2.clear();
        random_shuffle(oomg, oomg + N);
    }
    cout << "Impossible" << endl;
}

int main(void)
{
    int T;
    cin >> T;
    for(int i=0;i<T;++i)
    {
        do_case(i+1);
    }
}
