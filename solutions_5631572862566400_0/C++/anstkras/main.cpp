#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("1.in");
    ofstream fout("1.out");
    int t;
    fin >> t;
    for (int i = 0; i < t; i++)
    {
        fout << "Case #" << i + 1 << ": ";
        int n;
        fin >> n;
        vector<vector<int>> v(2000);
        vector<vector<int>> vv(2000);
//        for (int j = 0; j < 2000; j++)
//            v[i].push_back(vector<int>());
        //ar[2000] = {};
        set<int> m;
        for (int j = 1; j < n + 1; j++)
        {
            int x;
            fin >> x;
            //ar[j] = x;
            v[j].push_back(x);
            vv[x].push_back(j);
            //v[x].push_back(j);
        }
        queue<int> q;
        int max = 0;
        for (int j = 1; j < n + 1; j++)
        {
            int ans = 0;
            bool used[2000] = {};
            int aa[2000] = {};
            q.push(j);
            aa[j] = 1;
            used[j] = true;
            //ans++;
            while (!q.empty())
            {
                int r = q.front();
                q.pop();
                for (int k = 0; k < v[r].size(); k++)
                {
                    if (!used[v[r][k]])
                    {
                        q.push(v[r][k]);
                        aa[v[r][k]] = aa[r] + 1;
                        bool f = false;
//                        for (int w : vv[r])
//                        {
//                            if (!used[w])
//                                f = true;
//                        }
                        ans = aa[v[r][k]];
                        used[v[r][k]] = true;
//                        if (vv[j].size() != 0)
//                            f = true;
                        for (int w :vv[j])
                        {
                            if (!used[w])
                                f = true;
                        else
                                if(w == v[r][k])
                                {
                                    f = true;
                                    ans--;
                                }
                        }
                        if (!f)
                        for (int w : vv[v[r][k]])
                            if (!used[w])
                                f = true;
                        else
                                if(w == j && w != r)
                                {
                                    f = true;
                                    ans--;
                                }
                        if (ans > max && f)
                            max = ans;

                    }
                }
                used[r] = true;
                //ans++;
            }


        }
        fout << max + 1;
        fout << "\n";
    }
    //cout << "Hello World!" << endl;
    return 0;
}

