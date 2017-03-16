#include <iostream>
#include <map>
#include <vector>
using namespace std;

long long omg[550];
void do_case(int cn)
{
    int N;
    cin >> N;
    for(int i=0;i<N;++i){cin >> omg[i];}
    cout << "Case #" << cn << ":" << endl;
    if(N < 30)
    {
        map<long long, int> ma;
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
                vector<int> a,b;
                for(int j=0;j<N;++j)
                {
                    if(cur & (1<<j)){a.push_back(omg[j]);}
                    if(zt & (1<<j)){b.push_back(omg[j]);}
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
            else{ma[su] = i;}
        }
        cout << "Impossible" << endl;
    }
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
