#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <cassert>
#include <cmath>
#include <queue>

using namespace std;

const int N = 18;
const int oo = (1 << 30);

vector <int> ans;
int factor[8];
int last, preValue, two, minValue, maxValue;
int cntTwo, cntThree, cntFive;
int pp[1024], cntnumber;

void dfs( pair <int, pair <int, int> > p, int dep, int value)
{
    if(dep == last)
    {
        if(value * preValue >= minValue && preValue * value <= maxValue )
        {
            if((p.first == 0 && cntTwo != 0) || (p.first != 0 && cntTwo == 0)) return;
            if((p.second.first == 0 && cntThree != 0) || (p.second.first != 0 && cntThree == 0)) return;
            if((p.second.second == 0 && cntFive != 0) || (p.second.second != 0 && cntFive == 0)) return;
            //if(p.first % 2 == cntTwo % 2 && p.second.first % 2 == cntThree % 2 && p.second.second % 2 == cntFive % 2)
            {
                //flag = true;
                vector <int> tmpAns;
                for(int i = 0; i < 3; i++)
                {
                    tmpAns.push_back(factor[i]);
                    //cout << tmpAns[i] << " ";
                }
               // cout << endl;
                int cnt = 0;
                for(int i = 0; i < 8; i++)
                {
                    int p = 1;
                    for(int j = 0; j < 3; j++)
                    {
                        if((1 << j) & i)
                        {
                            p *= tmpAns[j];
                        }
                    }
                    if(pp[p])
                        cnt++;
                }
                if(cnt > cntnumber)
                {
                    cntnumber = cnt;
                    ans = tmpAns;
                }
            }
        }
        return;
    }
    factor[dep] = 2;
    p.first += 1;
    dfs(p, dep + 1, value * 2);
    factor[dep] = 4;
    p.first += 1;
    dfs(p, dep + 1, value * 4);
    factor[dep] = 3;
    p.first -= 2;
    p.second.first += 1;
    dfs(p, dep + 1, value * 3);
    p.second.first -= 1;
    p.second.second += 1;
    factor[dep] = 5;
    dfs(p, dep + 1, value * 5);
}

int main()
{
    freopen("out.txt", "w", stdout);
    int tcas, cas = 0;
    cin >> tcas;
    while(tcas --)
    {
        cout << "Case #" << ++cas << ":" << endl;
        int r, n, m, k;
        cin >> r >> n >> m >> k;
        for(int j = 0; j < r; j++)
        {
            cntTwo = 0, cntThree = 0, cntFive = 0;
            int product;
            cntnumber = -oo;
            memset(pp, 0, sizeof(pp));
            minValue = oo, maxValue = -oo;
            for(int i = 0; i < k; i++)
            {
                cin >> product;
                pp[product]++;
                int tmp = product;
                while(tmp % 3 == 0)
                {
                    tmp /= 3;
                    cntThree++;
                }
                tmp = product;
                if(tmp % 5 == 0)
                {
                    tmp /= 5;
                    cntFive++;
                }
                tmp = product;
                while(tmp % 2 == 0)
                {
                    cntTwo++;
                    tmp /= 2;
                }
                minValue = min(minValue, product);
                maxValue = max(maxValue, product);
            }
            ans.clear();
            preValue = 1;
            last = n;
            two = cntTwo;
            memset(factor, 0, sizeof(factor));
            pair <int, pair <int, int> > p = make_pair(0, make_pair(0, 0));
            dfs(p, 0, 1);
            sort(ans.begin(), ans.end());
            if(ans.size() == 0)
            {
                for(int i = 0; i < 3; i++)
                    ans.push_back(2);
            }
            for(int i = 0; i < 3; i++)
            {
                cout << ans[i];
            }
            cout << endl;
        }
    }
    return 0;
}
