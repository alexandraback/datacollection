#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <cstdio>
#include <string>
#include <queue>
#include <iterator>

using namespace std;

const long long p = 1000000007;

int main()
{
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);

    int T;

    cin >> T;

    for(int test_case = 1; test_case <= T; ++test_case)
    {
        int A, B, K, Answer = 0;

        cin >> A >> B >> K;

        for(int a = 0; a < A; ++a)
        {
            for(int b = 0; b < B; ++b)
            {
                if((a & b) < K)
                {
                    ++Answer;
                }
            }
        }



            
        cout << "Case #" << test_case << ": "<< Answer << endl;
    } 

    return 0;
}