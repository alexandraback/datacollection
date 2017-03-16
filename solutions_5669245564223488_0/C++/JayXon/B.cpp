#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        return 1;
    }
    char name[256];
    strcpy(name, argv[1]);

    ifstream fin(name);
    name[strlen(name)-2] = 0;
    strcat(name, "out");
    ofstream fout(name);

    if (!fin.is_open() || !fout.is_open())
    {
        return 1;
    }

    int t, t1 = 0;

    fin >> t;

    while (t1++ < t)
    {
        int n, r = 0;
        fin >> n;
        vector<string> v;
        v.resize(n);
        for (int i = 0; i < n; ++i)
        {
            fin >> v[i];
        }
        bool fail = false;
        for (int i = 0; i < n; ++i)
        {
            for (auto it = v[i].begin(); it != v[i].end(); ++it)
            {
                while (*it == *(it + 1))
                {
                    v[i].erase(it + 1);
                }
            }
            if (v[i].size() > 1 && v[i].front() == v[i].back())
            {
                fail = true;
                break;
            }
            for (int j = 1; j < v[i].size() - 1; ++j)
            {
                for (int k = 0; k < n; ++k)
                {
                    if (k != i && v[k].find(v[i][j]) != string::npos)
                    {
                        fail = true;
                        break;
                    }
                }
                int k = 0;
                while ((k = v[i].rfind(v[i][j], k)) != string::npos)
                {
                    if (k != j)
                    {
                        fail = true;
                        break;
                    }
                }
                if (fail)
                {
                    break;
                }
            }
            if (fail)
            {
                break;
            }
            else if (v[i].size() > 2)
            {
                v[i].erase(v[i].begin() + 1, v[i].end() - 1);
            }
        }

        if (!fail)
        {
            r = 1;
            for (int i = 0; i < v.size(); ++i)
            {
                vector<int> vj, vd;
                for (int j = 0; j < v.size(); ++j)
                {
                    if (j != i && v[j].front() == v[i].back())
                    {
                        if (v[j].size() == 2)
                        {
                            vj.push_back(j);
                        }
                        else if (v[i].size() == 1)
                        {
                            r = (r + r) % 1000000007;
                        }
                        vd.push_back(j);
                    }
                }
                if (vj.size() > 1)
                {
                    fail = true;
                    break;
                }
                else if (vj.size() == 1)
                {
                    v[i].back() = v[vj[0]].back();
                    v.erase(v.begin() + vj[0]);
                    i--;
                }

                for (int j : vd)
                {
                    v.erase(v.begin() + j);
                }
            }
            for (int i = v.size(); i; --i)
            {
                // fout << v[i-1] << endl;
                r = ((uint64_t)r * i) % 1000000007;
            }
            if (fail)
            {
                r = 0;
            }
        }
        

        fout << "Case #" << t1 << ": ";
        fout << r << endl;

    }

    return 0;
}