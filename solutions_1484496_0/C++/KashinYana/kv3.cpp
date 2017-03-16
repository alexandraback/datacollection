#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <ctime>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>

using namespace std;

#define fi first
#define se second
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
vector<pair<int, int> > V;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int r;
    cin >> r;
    for(int test = 1; test <= r; test++)
    {
        V.clear();
        int n;
        cin >> n;
        vector<int> A(n);
        for(int i = 0; i < n; i++)
            cin >> A[i];
        //cout << "F" << endl;
        int id = 0;
        while(id < (1<<n))
        {
            //cout << id << endl;
            int sum = 0;
            int temp = id;
            int i = 0;
            while(temp > 0)
            {
                if(temp & 1)
                {
                    sum += A[i];
                }
                temp >>= 1;
                i++;
            }
            V.pb(mp(sum, id));
            //if(id < 10)
            //    cout << sum << " " << id << endl;
            id++;
        }
        sort(V.begin(), V.end());
        cout << "Case #"<< test<<": " << endl;
        bool ans = false;
        for(int i = 1; i < V.size(); i++)
        {
            if(V[i].first == V[i-1].first)
            {
                //cout << V[i-1].first << " " << V[i-1].second << endl;
                //cout << V[i].first << " " << V[i].second << endl;
                int temp = V[i].second;
                int j = 0;
                while(temp > 0)
                {
                    if(temp & 1)
                    {
                        cout << A[j] << " ";
                    }
                    temp >>= 1;
                    j++;
                }
                cout << endl;
                temp = V[i-1].second;
                j = 0;
                while(temp > 0)
                {
                 //   cout << "!" << temp << endl;
                    if(temp & 1)
                    {
                        cout << A[j] << " ";
                    }
                    temp >>= 1;
                    j++;
                }
                cout << endl;
                ans = true;
                break;
            }
        }
        if(!ans)
        {
            cout << "Impossible" << endl;
        }
    }

    return 0;
}
