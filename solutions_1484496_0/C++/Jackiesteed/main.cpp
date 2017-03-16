#include <iostream>
#include <fstream>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <vector>
#include <map>




using namespace std;

const int MAXN =  1000;

int T;
typedef long long LL;

LL array[MAXN];
int N;
vector<int> record[2100000];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> T;

    for(int ncase = 1; ncase <= T; ncase++)
    {
        cin >> N;
        LL tot = 0;
        for(int i = 0; i < N; i++)
        {
            cin >> array[i];
            tot += array[i];
        }
        cout << "Case #" << ncase << ":" << endl;
        for(int i = 0; i < tot; i++) record[i].clear();

        //bool bingo = false;
        for(int i = 0; i < (1 << N); i++)
        {
            LL t = 0;
            for(int j = 0; j < N; j++)
            {
                if(i & (1 << j))
                {
                    t += array[j];
                }
            }
            record[t].push_back(i);
            //cout << t << " " << i << nedl;
        }
        bool bingo = false;
        for(int i = 0; i < tot; i++)
        {
            if(record[i].size() > 1)
            {
                int len = record[i].size();
                for(int j = 0; j < len; j++)
                {
                    for(int k = j + 1; k < len; k++)
                    {
                        if((record[i][j] & record[i][k]) == 0)
                        {
                            //cout << record[i][j] << "---" << record[i][k] << endl;
                            bingo = true;
                            bool start = true;
                            for(int l = 0; l < N; l++)
                            {

                                if(record[i][j] & (1 << l))
                                {
                                    if(start)
                                    {
                                        start = false;
                                    }
                                    else
                                    {
                                        cout << " ";
                                    }
                                    cout << array[l];
                                }
                            }
                            cout << endl;
                            start = true;
                            for(int l = 0; l < N; l++)
                            {

                                if(record[i][k] & (1 << l))
                                {
                                    if(start) start = false;
                                    else cout << " ";
                                    cout << array[l];
                                }
                            }
                            cout << endl;

                        }
                        if(bingo) break;
                    }
                    if(bingo) break;
                }
                if(bingo) break;
            }
        }
        if(!bingo)
        {
            cout << "Impossible" << endl;
        }

    }













    return 0;
}
