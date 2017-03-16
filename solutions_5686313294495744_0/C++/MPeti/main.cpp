#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N1, N2;
vector<int> G[2000];
int Par[2000];
bool V[2000];

bool extendRoute(int p)
{
    V[p] = true;
    if (p < N1)
    {
        for (int ch : G[p])
        {
            if (!V[ch] && ch != Par[p] && extendRoute(ch))
            {
                Par[ch] = p;
                Par[p] = ch;
                return true;
            }
        }
        return false;
    }
    else
    {
        return Par[p] == -1 || (!V[Par[p]] && extendRoute(Par[p]));
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //istream& in = cin;
    //ostream& out = cout;
    ifstream in("in.txt");
    ofstream out("out.txt");
    int T;
    in >> T;
    for (int t = 1; t <= T; t++)
    {
        int N;
        in >> N;
        vector<pair<string,string>> P;
        set<string> S1;
        set<string> S2;
        for (int i = 0; i < N; i++)
        {
            string s1, s2;
            in >> s1 >> s2;
            P.push_back({s1, s2});
            S1.insert(s1);
            S2.insert(s2);
        }
        vector<string> V1;
        vector<string> V2;
        for (auto s : S1)
            V1.push_back(s);
        for (auto s : S2)
            V2.push_back(s);
        N1 = V1.size();
        N2 = V2.size();
        //cerr << "P1: " << N1 << ", P2: " << N2 << endl;
        for (int i = 0; i < N1+N2; i++)
        {
            Par[i] = -1;
            G[i].clear();
        }
        for (auto p : P)
        {
            int u = (lower_bound(V1.begin(), V1.end(), p.first) - V1.begin());
            int v = (lower_bound(V2.begin(), V2.end(), p.second) - V2.begin());
            G[u].push_back(N1+v);
            G[N1+v].push_back(u);
            //cerr << "Edge " << u << " " << v << endl;
            //cerr << "Modified: " << u << " " << v+N1 << endl;
        }
        int C = 0;
        for (int i = 0; i < N1; i++)
        {
            //cerr << "Node " << i<< ": ";
            if (Par[i] == -1)
            {
                //cerr << "Trying extend" << endl;
                if (extendRoute(i))
                {
                    //cerr << "Success" << endl;
                    C++;
                }
                //cerr << "PAR: ";
                //for (int i = 0; i < N1+N2; i++)
                    //cerr << Par[i] << " ";
                //cerr << endl;
            }
            //cerr << endl;
            for (int i = 0; i < N1+N2; i++)
            {
                V[i] = false;
            }
        }
        //cerr << C <<" pairs" << endl;
        out << "Case #" << t <<": " << N-(N1+N2-C) << endl;
    }
}
