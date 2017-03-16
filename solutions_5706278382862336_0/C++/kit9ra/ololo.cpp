#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <cstdio>
#include <string>
#include <queue>
#include <iterator>
#include <stack>

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

        long long A, B, Answer = 100500;

        char C;

        cin >> A >> C >> B;

        long long count = 0;

        while( count <= 40 && A != 0)
        {
            while(A / B < 1 && count <= 40)
            {
                ++count;

                A *= 2;
            }

            if(A >= B)
                Answer = min(Answer, count);
            A = A % B;
        }

        if(A != 0)
            cout << "Case #" << test_case << ": "<< "impossible" << endl;
        else
            cout << "Case #" << test_case << ": "<< Answer << endl;

            
        
    } 

    return 0;
}