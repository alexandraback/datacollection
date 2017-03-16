#include <iostream>
#include <vector>

using namespace std;

int main(){
    int T;
    cin >> T;
    for (int test = 0; test < T; test++){
        int N;
        cin >> N;
        vector<int> heights(2510);
        for (int i = 0; i < 2 * N - 1; i++){
            for (int j = 0; j < N; j++){
                int height;
                cin >> height;
                heights[height]++;
            }
        }
        printf("Case #%d:", test + 1);
        for (int i = 0; i < 2510; i++)
            if (heights[i] % 2 == 1)
                printf(" %d", i);
        printf("\n");
    }
}
