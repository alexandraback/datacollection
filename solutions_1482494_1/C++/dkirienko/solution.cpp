#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int Ntests, testnum;
    cin >> Ntests;
    int N, i;
    int A[1005], B[1005], used[1005];
    for(testnum = 1; testnum <= Ntests; ++testnum)
    {
        cin >> N;
        for (i = 0; i < N; ++i)
        {
            cin >> A[i] >> B[i];
            used[i] = 0;
        }
        int stars = 0;
        int Answer = 0;
        bool Fail = false;
        while(true)
        {
            Fail = true;
            for(i = 0; i < N; ++i)
            {
                if(B[i] <= stars && used[i] != 2)
                {
                    stars += 2 - used[i];
                    used[i] = 2;
                    Fail = false;
                    ++Answer;
                }
            }
            i = 0;
            while (i < N && used[i] == 2)
                ++i;
            if (i == N)
            {
                Fail = false;
                break;
            }
            if (!Fail)
                continue;
            int k = -1;
            int j = 0;
            for (j = 0; j < N; ++j)
            {
                if(used[j] == 0 && stars >= A[j])
                {
                    if (k == -1 || B[j] > B[k])
                        k = j;
                }
            }
            if (k == -1)
            {
                Fail = true;
                break;
            }
            else
            {
                used[k] = 1;
                stars += 1;
                ++Answer;
            }
        }
        cout << "Case #" << testnum << ": " ;
        if (Fail)
            cout << "Too Bad" << endl;
        else
            cout << Answer << endl;
    }
    return 0;
}
