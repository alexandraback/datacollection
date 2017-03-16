#include <iostream>
using namespace std;
const long long maxn = 100 + 10;

long long n, m;
long long count_a[maxn], count_b[maxn];
long long type_a[maxn], type_b[maxn];

long long min(long a, long long b)
{
        return a < b ? a : b;
}

long long solve1(long long pre, long long s, long long k_a, long long st_b, long long end_b, long long &left) {
        long long count = count_a[k_a];
        if (pre == type_a[k_a])
                count -= s;
        left = 0;
        for (long long i = st_b; count > 0 && i <= end_b; i++)
                if (type_b[i] == type_a[k_a]) {
                        if (count < count_b[i])
                                left = count_b[i] - count;
                        count -= min(count, count_b[i]);
                }
        return count_a[k_a] - count;
}

long long solve2(long long end_b, long long &left) {
        long long answer = 0;

        left = 0;
        for (long long i = 0; i <= end_b; i++) {
                long long left1, left2;
                long long tmp = solve1(0, 0, 1, 1, i, left1);
                tmp += solve1(type_a[1], left1, 2, i + 1, end_b, left2);
                if (tmp > answer) {
                        answer = tmp;
                        left = left2;
                }
        }
        return answer;
}

long long solve3() {
        long long answer = 0;
        for (long long i = 0; i <= m; i++) {
                long long left;
                long long tmp = solve2(i, left);
                tmp += solve1(type_a[2], left, 3, i + 1, m, left);
                if (tmp > answer)
                        answer = tmp;
        }
        return answer;
}

int main(void)
{
        long long T;
        cin >> T;
        for (long long loop = 1; loop <= T; loop++) {
                cin >> n >> m;

                for (long long i = 1; i <= n; i++) {
                        cin >> count_a[i] >> type_a[i];
                }
                for (long long i = 1; i <= m; i++) {
                        cin >> count_b[i] >> type_b[i];
                }

                bool end;
                do {
                        end = true;
                        if (n == 2 && type_a[1] == type_a[2]) {
                                count_a[1] += count_a[2];
                                --n;
                        }
                        if (n == 3) {
                                if (type_a[1] == type_a[2]) {
                                        count_a[1] += count_a[2];
                                        count_a[2] = count_a[3];
                                        type_a[2] = type_a[3];
                                        --n;
                                        end = false;
                                } else if (type_a[2] == type_a[3]) {
                                        count_a[2] += count_a[3];
                                        --n;
                                        end = false;
                                }
                        }
                } while (!end);

                long long answer, tmp;
                if (n == 1)
                        answer = solve1(0, 0, 1, 1, m, tmp);
                if (n == 2)
                        answer = solve2(m, tmp);
                if (n == 3) {
                        answer = solve3();
                        count_a[2] = count_a[3];
                        type_a[2] = type_a[3];
                        long long r = solve2(m, tmp);
                        if (r > answer)
                                answer = r;
                }

                cout << "Case #" << loop << ": " << answer << endl;
        }
        return 0;
}

