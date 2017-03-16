#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

int T;

int R, N, M, K;

int vals[6];
int minVals[6];
int freq[6];
int twoFour[2];

int main()
{
    freopen("3.in", "r", stdin);
    freopen("3.out", "w", stdout);
    cin >> T;
    cin >> R >> N >> M >> K;
        printf("Case #%d:\n", T);

    for (int i = 0; i < R; i++)
    {
        memset(minVals, 0, sizeof(minVals));
        memset(freq, 0, sizeof(freq));
        memset(twoFour, 0, sizeof(twoFour));


        for (int j = 0; j < K; j++)
        {
            memset(vals, 0, sizeof(vals));
            int cur;
            cin>> cur;

            if (cur == 2)
            {
                twoFour[0]++;
            }else if (cur == 4)
            {
                twoFour[1]++;
            }


            for (int k = 2; k <= M; k++)
            {
                if (k == 4) continue;
                while (cur%k == 0)
                {
                    cur /= k;
                    vals[k]++;
                    freq[k]++;
                }
                if (k==4 || k == 2) continue;
                minVals[k] = max(minVals[k], vals[k]);
            }
        }

        int numDigits = 0;


        for (int k = 2; k <= M; k++)
        {
            for (int z = 0; z < minVals[k]; z++)
            {
                cout << k;
                numDigits++;
            }
           // cout << k << " " << minVals[k] << endl;
            //cout << k << " " << freq[k] << endl;
        }
        if (twoFour[0]>0 && numDigits < N)
        {
            cout << 2;
            numDigits++;
        }

        while (numDigits < N)
        {
            int freqNum = 0;
            int maxFreq = 0;
            for (int qq = 2; qq <= M; qq++)
            {
                if (freq[qq]>maxFreq)
                {
                    maxFreq = freq[qq];
                    freqNum = qq;
                }
            }

            if (freqNum==2)
            {
                if (twoFour[1]>=twoFour[0])
                {
                    cout << 4;
                    numDigits++;
                    freq[2]/=2;
                    twoFour[1]/=2;
                }else
                {
                    cout << 2;
                    numDigits++;
                    freq[2]/=2;
                    twoFour[0]/=2;
                }
            }else if (freqNum == 0)
            {
                cout << (rand()%(M)+2);
                numDigits++;
            }
            else
            {
                cout << freqNum;
                freq[freqNum]/=2;
                numDigits++;
            }
        }
        cout << endl;

    }


    return 0;
}
