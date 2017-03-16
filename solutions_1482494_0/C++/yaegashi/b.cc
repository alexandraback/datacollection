#include <cstdio>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int
scan(int N, int *reqs)
{
        bool done, completed;
        int count = 0, score = 0;
        int rates[N];
        memset(rates, 0, sizeof(rates));

try2:
        do {
                done = true;
                completed = true;
                for (int i = 0; i < N; i++) {
                        if (rates[i] == 2)
                                continue;
                        completed = false;
                        int *req = reqs + i*2;
                        if (req[1] <= score) {
                                count++;
                                score += 2 - rates[i];
                                rates[i] = 2;
                                done = false;
                        }
                }
                if (completed)
                        return count;
        } while (!done);

        for (int i = 0; i < N; i++) {
                int *req = reqs + i*2;
                if (rates[i] < 1 && req[0] <= score) {
                        count++;
                        score++;
                        rates[i] = 1;
                        goto try2;
                }
        }

        return -1;
}


int
cmp(const void *a, const void *b)
{
        const int *x = reinterpret_cast<const int *>(a);
        const int *y = reinterpret_cast<const int *>(b);
        return y[1] - x[1];
}


int
main(int argc, char **argv)
{
        int T;

        string lineT;
        getline(cin, lineT);
        stringstream ssT(lineT);
        ssT >> T;

        for (int i = 0; i < T; i++) {

                int N;
                string lineN;
                getline(cin, lineN);
                stringstream ssN(lineN);
                ssN >> N;

                int reqs[2*N];

                for (int j = 0; j < N; j++) {
                        string line;
                        getline(cin, line);
                        stringstream ss(line);
                        ss >> reqs[j*2+0] >> reqs[j*2+1];
                }

                qsort(reqs, N, 2*sizeof(int), cmp);

                cerr << "#" << i+1 << endl;
                for (int j = 0; j < N; j++) 
                        cerr << reqs[j*2+0] << " " << reqs[j*2+1] << endl;

                int count = scan(N, reqs);

                cout << "Case #" << i+1 << ": ";
                if (count < 0)
                        cout << "Too Bad";
                else
                        cout << count;
                cout << endl;

        }

        return 0;
}
