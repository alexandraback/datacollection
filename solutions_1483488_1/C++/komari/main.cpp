/*
PROG: C
LANG: C++
*/
#include <iostream>
#include <fstream>
//#include <algorithm>
#include <set>
#include <sstream>
using namespace std;

#define SUBMIT
#define DSP(X)
#   define DV(Var) cout<<#Var<<"="<<Var<<' '
#ifdef SUBMIT
    ofstream fout ("C.out");ifstream fin ("C.in");
#   define cin fin
#   define cout fout
#endif

int D;
inline int right(int i)
{
    return i/10+(i%10)*D;
}
inline int high(int i)
{
    int ans=1;
    while(i/=10)ans*=10;
    return ans;
}

int main()
{
    int T;
    cin>>T;cin.ignore();
    for(int t=1;t<=T;++t)
    {
        std::set<int> used; used.clear();

        int a,b;
        cin>>a>>b;
        D=high(b);

        int total=0;
        for(int i=a;i<=b;++i)
        {
            int cnt=1;
            if(used.find(i)==used.end())
            {
                used.insert(i);
                for(int j=1,now=i;j<D;j*=10)
                {
                    now=right(now);
                    if((now>=a)&&(now<=b)
                       &&(used.find(now)==used.end()))
                    {
                        ++cnt;
                        used.insert(now);
                    }
                }
            }
            total+=(cnt>1?(cnt*(cnt-1))/2:0);
        }

        cout<<"Case #"<<t<<": "<<total<<endl;
    }

    return 0;
}
