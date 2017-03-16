#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int t;
    cin >> t;
    for (int q = 0; q < t; ++q)
    {
        int n;
        cin >> n;
        set<long double> A, B;
        set<long double> AA, BB;
        for (int i = 0; i < n; ++i)
        {
            long double temp;
            cin >> temp;
            A.insert(temp);
            AA.insert(temp);
        }
        for (int i = 0; i < n; ++i)
        {
            long double temp;
            cin >> temp;
            B.insert(temp);
            BB.insert(temp);
        }
        
        int answer = 0;
        for (int i = 0; i < n; ++i)
        {
            long double a = *A.begin(), b = *B.begin();
            A.erase(A.begin());
            if (a < b)
                B.erase(--B.end());
            else
            {
                B.erase(B.begin());
                ++answer;
            }
        }
        int bad_answer = 0;
        for (int i = 0; i < n; ++i)
        {
            long double a = *AA.begin();
            AA.erase(AA.begin());
            set<long double> :: iterator it = BB.upper_bound(a);
            if (it == BB.end())
            {
                ++bad_answer;
                BB.erase(BB.begin());
            }
            else
                BB.erase(it);
        }
        cout << "Case #" << q + 1 << ": " << answer << " " << bad_answer << endl;
    }
}