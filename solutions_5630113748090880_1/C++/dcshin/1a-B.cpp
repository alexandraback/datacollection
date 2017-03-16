#include <iostream>
#include <cstring>

using namespace std;

int T, tcase;
int N, num;
int height[2501];

int main()
{
    cin >> T;
    tcase = 1;
    while (tcase<=T) {
        memset (height, 0, sizeof(int)*2501);
        cin >> N;

        for (int i=0; i<2*N-1; ++i) {
            for (int j=0; j<N; ++j) {
                cin >> num;
                height[num]++;
            }
        }

        cout << "Case #" << tcase++ << ":";
        for (int i=1; i<=2500; ++i) {
            if (height[i]%2) {
                cout << " " << i;
            }
        }
        cout << endl;
    }
}
