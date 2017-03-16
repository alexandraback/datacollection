#include <iostream>
#include <unordered_map>
#include <fstream>
using namespace std;

void quickSort(int array[], int start, int end);

int main() {
  	ifstream testCase ("./C-small-attempt0.in");
  	ofstream testCaseAns ("./output.txt");

  	int T = 0;
  	testCase >> T;
  	for (int i = 0; i < T; i++) {
    		int N = 0;
    		testCase >> N;
        int bff[1005];
        for (int j = 0; j < N; j++) {
            testCase >> bff[j + 1];
        }
        int ans = 0;
        for (int j = 1; j <= N; j++) {
            int add[1005] = {0};
            int index = j;
            int count = 0;
            int prev = j;
            while (add[index] != 1) {
                // printf("%d ", index);
                add[index] = 1;
                count++;
                prev = index;
                index = bff[index];
            }
            // printf("\nindex = %d prev = %d", index, prev);
            if (bff[index] == prev) {
                // printf("type2 ");
                int end = 0;
                while (!end) {
                    end = 1;
                    for (int k = 1; k <= N; k++) {
                        if (add[k] == 0 && bff[k] == prev) {
                            // printf("%d ", k);
                            add[k] = 1;
                            count++;
                            prev = k;
                            end = 0;
                            break;
                        }
                    }
                }
                if (ans < count) {
                    ans = count;
                }
            }
            else if (index == j && ans < count) {
                // printf("type1");
                ans = count;
            }
            // printf("\n");
        }
        // printf("\n");
        testCaseAns << "Case #" << i + 1 << ": " << ans << "\n";
  	}
  	testCase.close();
  	testCaseAns.close();
  	return 0;
}
