#include <iostream>
#include <set>


using namespace std;

typedef long double ld;

set<ld> nao1;
set<ld> nao2;
set<ld> ken1;
set<ld> ken2;
int n;


int game1()
{
    int res=0;
    for (int i=0;i<n;++i)
    {
        ld a=*nao1.begin();
        auto b_it=ken1.upper_bound(a);
        if (b_it==ken1.end())
        {
            ++res;
            ken1.erase(ken1.begin());
        }
        else
            ken1.erase(b_it);
        nao1.erase(nao1.begin());
    }
    return res;
}

int game2()
{
    int res=0;
    for (int i=0;i<n;++i)
    {
        ld a=*nao2.begin();
        if (*ken2.begin() < a )
        {
            ++res;
            ken2.erase(ken2.begin());
        }
        else
        {
            auto b_it=ken2.end();
            --b_it;
            ken2.erase(b_it);
        }
        nao2.erase(nao2.begin());
    }
    return res;
}


int main()
{
    int t;
    cin>>t;
    for (int nc=1;nc<=t;++nc)
    {
        nao1.clear();
        nao2.clear();
        ken1.clear();
        ken2.clear();
        cout<<"Case #"<<nc<<": ";
        cin>>n;
        for (int i=0;i<n;++i)
        {
            ld x;
            cin>>x;
            nao1.insert(x);
            nao2.insert(x);
        }
        for (int i=0;i<n;++i)
        {
            ld x;
            cin>>x;
            ken1.insert(x);
            ken2.insert(x);
        }
        cout<<game2()<<" "<<game1()<<"\n";
    }
    return 0;
}

