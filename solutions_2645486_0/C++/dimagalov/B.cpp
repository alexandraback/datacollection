#include<fstream>
#include<iostream>
#include<cmath>
#include<vector>
#include<set>
#include<algorithm>
#define int long long int

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

set<pair<int, int> > :: iterator it;

main()
{
    int t;
    fin >> t;
    for (int q = 0; q < t; ++q)
    {
        fout << "Case #" << q + 1 << ": ";
        int E, R, N;
        fin >> E >> R >> N;
        vector<int> V(N);
        for(int i = 0; i < N; ++i)
        {
            fin >> V[i];
        }
        set<pair<int, int> > A, B;
        A.insert(make_pair(E, 0));
        for(int i = 0; i < N; ++i)
        {
            for (it = A.begin(); it != A.end(); ++it)
            {
                for (int e = 0; e <= (it -> first); ++e)
                {
                    B.insert(make_pair(min(E, (it -> first) - e + R), (it -> second) + e * V[i]));
                }
            }
            swap(A, B);
            B.clear();
        }
        int answer = -1;
        for (it = A.begin(); it != A.end(); ++it)
        {
            answer = max(answer, it -> second);
        }
        fout << answer << endl;
    }
}
