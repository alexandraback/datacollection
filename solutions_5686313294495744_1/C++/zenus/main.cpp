#include <bits/stdc++.h>

using namespace std;

const int nmax = 1009;

int tests , T , i , n , nr , w , j , ok , bst , _i;
vector < string > er;
int a[nmax] , b[nmax] , tmp[nmax] , marked[2][nmax];
string x[nmax] , y[nmax];

int main()
{
srand(time(0));

freopen("test.in" , "r" , stdin);
freopen("test.out" , "w" , stdout);

cin >> tests;
for (T = 1 ; T <= tests ; ++T)
{
    cin >> n;
    er.clear();

    for (i = 1 ; i <= n ; ++i)
    {
        cin >> x[i] >> y[i];
        er.push_back(x[i]);
        er.push_back(y[i]);
    }

    sort(er.begin() , er.end());
    er.resize(distance(er.begin() , unique(er.begin() , er.end())));

    for (i = 1 ; i <= n ; ++i)
    {
        a[i] = lower_bound(er.begin() , er.end() , x[i]) - er.begin() + 1;
        b[i] = lower_bound(er.begin() , er.end() , y[i]) - er.begin() + 1;
    }

    bst = 0;
    for (i = 1 ; i <= n ; ++i)
    tmp[i] = i;

    for (int RT = 1 ; RT <= 10000 ; RT++)
    {
        random_shuffle(tmp + 1 , tmp + n + 1);
        memset(marked , 0 , sizeof(marked));

        nr = 0;
        for (_i = 1 ; _i <= n ; ++_i)
        {
            i = tmp[_i];
            if (marked[0][a[i]] && marked[1][b[i]]) nr++;
            marked[0][a[i]] = 1 , marked[1][b[i]] = 1;
        }

        bst = max(bst , nr);
    }

    cout << "Case #" << T << ": " << bst << '\n';
}

return 0;
}
