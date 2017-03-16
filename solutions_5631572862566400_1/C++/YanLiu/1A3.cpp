#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
        ifstream input;
        ofstream output;
        input.open("./Downloads/C-large.in");
        output.open("result20160203");

        unsigned T;
        input >> T;

	for (unsigned t = 0; t < T; t ++) {
		unsigned N;
		input >> N;

                vector<int> map(N + 1, 0);
                for (int i = 0; i < N; i ++) {
                        input >> map[i + 1];
                }

                int result = 0;
                vector<int> s_mark(N + 1, 1);
                vector<int> c_len(N + 1, 0);
                for (int i = 1; i <= N; i ++) {
                        s_mark[map[i]] = 0;
                        if (c_len[i] == 0 && map[map[i]] == i) {
                                c_len[i] = 2;
                                c_len[map[i]] = 2;
                        }
                }
                for (int i = 1; i <= N; i ++) {
                        vector<int> mark(N + 1, 0);
                        int start = i;
                        int temp_res = 0;
                        while(mark[start] != 1) {
                                temp_res ++;
                                mark[start] = 1;
                                start = map[start];
                        }
                        if (start != i && start != map[map[start]]) {
                                continue;
                        }
                        if (start == map[map[start]] && s_mark[i] == 1) {
                                 int left_t = 0;
                                 for (int t = 0; t <= N; t ++) {
                                         if (s_mark[t] == 1 && mark[t] == 0) {
                                                 vector<int> t_mark(N + 1, 0);
                                                 int n_start = t;
                                                 int new_temp = 0;
                                                 while(t_mark[n_start] != 1 && mark[n_start] != 1) {
                                                         t_mark[n_start] = 1;
                                                         n_start = map[n_start];
                                                         new_temp ++;
                                                 }
                                                 if (mark[n_start] == 1 && n_start == map[start] && new_temp > left_t) {
                                                         left_t = new_temp;
                                                 }
                                         }
                                 }
                                 temp_res = temp_res + left_t;
                                 if (c_len[start] < temp_res) {
                                         c_len[start] = temp_res;
                                         c_len[map[start]] = temp_res;
                                 } 
                        }
                        if (temp_res > result) {
                                result = temp_res;
                        }
                }
                int ac = 0;
                for (int i = 1; i <= N; i ++) {
                        ac += c_len[i];
                }
                ac = ac / 2;
                if (ac > result) {
                        result = ac;
                }

		output << "Case #" << t + 1 << ": " << result << endl;
	}

	return 0;
}
