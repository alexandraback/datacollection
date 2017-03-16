#include <set>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool f(int n, set<int> ans)
{
    if(n < 0)
        return 0;
    if( n== 0)
        return 1;

    bool ret = 0;
    for(set<int>::iterator it = ans.begin(); it != ans.end();++it)
    {
        int k = *it;
        ans.erase(it);
        ret = (ret || f(n - k, ans));
        ans.insert(k);
        it = ans.find(k);
    }
    return ret;
}

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int t;
    cin >> t;
    for(int o = 0;o <t;++o)
    {
        int c,d,v;
        cin >> c >> d >> v;
        vector <int> m(d);
        set <int> ans;
        int ansv = 0;
        for(int i =0;i < d;++i)
        {
            int x;
            cin >> x;
            ans.insert(x);
        }

        for(int i = 1;i <= v;++i)
        {
            if(!f(i,ans))
            {
                ans.insert(i);
                ++ansv;
            }
        }
        cout << "Case #" << o+1 <<": " << ansv << endl;
    }


    return 0;
}

