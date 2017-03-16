#include <algorithm>
#include <cassert>
#include <gmpxx.h>
#include <iostream>

using namespace std;

int M, m[5] = {2, 3, 4, 6, 8}, cnt;
int cur_factors[8], prod_factors[8];
int factors[16][4], ans[12], best_ans[1000][12];
mpz_class best_estimator;

void backtrack(int cur, int left) {
    if (cur >= 5) return;

    if (left == 0) {
        if(prod_factors[2] != cur_factors[2]) return;
        if(prod_factors[3] != cur_factors[3]) return;

        assert(cnt < 1000);
        memcpy(best_ans[cnt++], ans, sizeof ans);
        return;
    }

    {
        cur_factors[2] += factors[m[cur]][2];
        cur_factors[3] += factors[m[cur]][3];

        ans[left-1] = cur;
        backtrack(cur, left-1);

        cur_factors[2] -= factors[m[cur]][2];
        cur_factors[3] -= factors[m[cur]][3];
    }

    backtrack(cur+1, left);
}

int main() {
    memset(factors, 0, sizeof factors);

    factors[2][2] = 1;
    factors[3][3] = 1;
    factors[4][2] = 2;
    factors[6][2] = factors[6][3] = 1;
    factors[8][2] = 3;

    int T;
    cin >> T;

    int R, N, K;
    cin >> R >> N >> M >> K;
    cout << "Case #1:" << endl;

    for (int z = 1; z <= R; z++) {
        mpz_class vals[K];
        mpz_class prod = 1;

        for(int i = 0; i < K; i++) {
            cin >> vals[i];
            prod *= vals[i];
        }

        memset(cur_factors, 0, sizeof cur_factors);
        memset(prod_factors, 0, sizeof prod_factors);
        best_estimator = -1;
        cnt = 0;

        mpz_class temp_prod = prod;
        while(prod % 2 == 0) prod_factors[2]++, prod /= 2;
        prod_factors[2] = (prod_factors[2] + 2)/6;

        while(prod % 3 == 0) prod_factors[3]++, prod /= 3;
        prod_factors[3] = (prod_factors[3] + 2)/6;

        while(prod % 5 == 0) prod_factors[5]++, prod /= 5;
        prod_factors[5] = (prod_factors[5] + 2)/6;

        while(prod % 7 == 0) prod_factors[7]++, prod /= 7;
        prod_factors[7] = (prod_factors[7] + 2)/6;

        int left = N-prod_factors[5]-prod_factors[7];
        backtrack(0, left);

        for(int idx = 0; idx < cnt; idx++) {
            mpz_class num = 1;
            for(int i = 0; i < left; i++)
                num *= best_ans[idx][i];

            bool ok = true;
            for(int i = 0; i < K; i++) {
                if(num % vals[i] != 0)
                    ok = false;
                num /= vals[i];
            }

            if(ok) {
                for(int i = 0; i < left; i++) cout << m[best_ans[idx][i]];
                for(int i = 0; i < prod_factors[5]; i++) cout << 5;
                for(int i = 0; i < prod_factors[7]; i++) cout << 7;
                cout << endl;
                goto done;
            }
        }

        cout << "222222222222" << endl;
    done: continue;
    }
}
