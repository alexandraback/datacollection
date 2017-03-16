#include <bits/stdc++.h>

#define MAXN 11

#define cin fin
#define cout fout

using namespace std;

ifstream fin("C-small-attempt0.in");
ofstream fout("C-small-attempt0.out");

int T, N;
int F[MAXN];
int idx[MAXN];
int answer;

int isOK(int len) {
    for (int i=0; i<len; i++) {
        if ((F[idx[i]-1] != idx[(i-1+len)%len]) && (F[idx[i]-1] != idx[(i+1)%len])) return -1;
    }
    return len;
}

int main()
{
    cin >> T;

    for (int t=1; t<=T; t++) {
        answer = 1;
        cin >> N;
        for (int i=0; i<N; i++) {
            cin >> F[i];
            idx[i] = i+1;
        }
        do {
            for (int i=2; i<=N; i++) answer = max(answer, isOK(i));
        } while(next_permutation(idx, idx+N));

        cout << "Case #" << t << ": " << answer << endl;
    }


    return 0;
}
