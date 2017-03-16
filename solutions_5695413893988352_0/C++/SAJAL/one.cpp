#include <bits/stdc++.h>

using namespace std;

#define sf scanf
#define pf printf
#define MAX 1000000007

vector < int > one ;
vector < string > p ;
vector < int > two ;
vector < string > q ;

void dfs(int pos , int len , int id , string a )
{
    if(pos >= len)
    {
        if(id == 0) { one.push_back(atoi(a.c_str())); p.push_back(a); }
        if(id == 1) { two.push_back(atoi(a.c_str())); q.push_back(a); }
        return ;
    }
    if(a[pos] == '?')
    {
        string x = a ;
        for(int i = 0 ; i < 10 ; ++i)
        {
            x[pos] = (char) ('0' + i);
            dfs(pos + 1 , len , id , x);
        }
    }
    else dfs(pos + 1 , len , id , a);
}


int main()
{
    freopen("input.txt" , "r" , stdin);
    freopen("output.in" , "w" , stdout);
    int t , ans , x , y , cc = 0 , idx , idy ;
    cin >> t ;
    string a , b ;
    while(t--)
    {
        one.clear(); two.clear();
        p.clear(); q.clear();
        cin >> a >> b;
        dfs(0 , a.size() , 0 , a);
        dfs(0 , b.size() , 1 , b);
       // cout << a << " " << one.size() << endl;
        //cout << b << " " << two.size() << endl;
        ans = (1 << 30);
        x = (1 << 30);
        y = (1 << 30);
        for(int i = 0 ; i < one.size() ; ++i)
        {
            for(int j = 0 ; j < two.size() ; ++j)
            {
                if(abs(one[i] - two[j]) <= ans)
                {
                    if(ans == abs(one[i] - two[j]))
                    {
                        if(x <= one[i])
                        {
                            if(x == one[i])
                            {
                                if(y >= two[j]) { x = one[i]; y = two[j]; idx = i; idy = j; }
                            }
                        }
                        else { x = one[i];  y = two[j]; idx = i ; idy = j; }
                    }
                    else
                    {
                        ans = abs(one[i] - two[j]);
                        x = one[i];
                        idx = i;
                        y = two[j];
                        idy = j;
                    }
                }
            }
        }
        pf("Case #%d: %s %s\n" , ++cc , p[idx].c_str() , q[idy].c_str());
    }
    return 0;
}
