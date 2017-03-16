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

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int ololo(vector< vector <int> > data, int N, int M)
{
    int count = 0;
    for(int n = 1; n <= N; ++n)
    {
        for(int m = 1; m <= M; ++m)
        {
            if(data[n][m])
            {
                for(int i = 0; i < 4; ++i)
                {
                    if(!data[n + dx[i]][m + dy[i]])
                    {
                        ++count;
                        break;
                    }
                }
            }
        }
    }

    return count;
}

int main()
{
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);

    int T;

    cin >> T;

    for(int test_case = 1; test_case <= T; ++test_case)
    {

        int N, M, K, Answer = 0;

        cin >> N >> M >> K;

        vector< vector<int> > data(N + 2, vector<int>(M + 2));

        for(int n = 1; n <= N; ++n)
        {
            for(int m = 1; m <= M; ++m)
            {
                data[n][m] = 1;
            }
        }

        if(K < 7 || M <= 2 || N <= 2)
        {
            cout << "Case #" << test_case << ": "<< K << endl;
            continue;
        }

        int count = N * M;

        if(count == K)
        {
            cout << "Case #" << test_case << ": "<< K << endl;
            continue;
        }

        data[1][1] = 0;
        --count;

        if(count == K)
        {
            Answer = ololo(data, N, M);
            cout << "Case #" << test_case << ": "<< Answer << endl;
            continue;;
        }

        data[N][1] = 0;
        --count;

        if(count == K)
        {
            Answer = ololo(data, N, M);
            cout << "Case #" << test_case << ": "<< Answer << endl;
            continue;;
        }

        data[1][M] = 0;
        --count;

        if(count == K)
        {
            Answer = ololo(data, N, M);
            cout << "Case #" << test_case << ": "<< Answer << endl;
            continue;;
        }

        data[N][M] = 0;
        --count;

        if(count == K)
        {
            Answer = ololo(data, N, M);
            cout << "Case #" << test_case << ": "<< Answer << endl;
            continue;;
        }

        while(count > K)
        {
            int i = 1;
            int w = 0;
            while(i < N)
            {
                int j = 2;
                while(j < M)
                {
                    data[i][j] = 0;
                    --count;
                    if(count == K)
                    {
                        ++w;
                        Answer = ololo(data, N, M);
                        cout << "Case #" << test_case << ": "<< Answer << endl;
                        break;
                    }
                    ++j;
                }
                ++i;
                if(w)
                    break;
                if(data[i][1])
                {
                    data[i][1] = 0;
                    --count;
                }

                if(count == K)
                {
                    Answer = ololo(data, N, M);
                    cout << "Case #" << test_case << ": "<< Answer << endl;
                    break;
                }

                if(data[i][M])
                {
                    data[i][M] = 0;
                    --count;
                }

                if(count == K)
                {
                    Answer = ololo(data, N, M);
                    cout << "Case #" << test_case << ": "<< Answer << endl;
                    break;
                }

            }
            if(w)
                break;

        }


        
    } 

    return 0;
}