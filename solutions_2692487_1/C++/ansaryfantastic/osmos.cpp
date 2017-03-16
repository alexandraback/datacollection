#include <iostream>
#include <fstream>

using namespace std;

int moteSizes[105];

int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int tc;
    cin >> tc;
    for (int c = 1; c <= tc; c++){
        int a, n;
        cin >> a >> n;
        for (int i = 0; i < n; i++){
            cin >> moteSizes[i];
        }

        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                if (moteSizes[j] < moteSizes[i]){
                    int x = moteSizes[i];
                    moteSizes[i] = moteSizes[j];
                    moteSizes[j] = x;
                }
            }
        }

        int answer = 0;

        for (int i = 0; i < n; i++){
            if (a > moteSizes[i]){
                a += moteSizes[i];
                continue;
            }
            else{
                int k = 0;
                if (a+a-1 <= a){
                    answer+= n-i;
                    break;
                }
                while (true){
                    a += a-1;
                    k++;
                    if (a > moteSizes[i])
                        break;
                }
                if (n-i < k){
                    answer+= n-i;
                    break;
                }
                answer+=k;
                a += moteSizes[i];
                continue;
            }
        }

        answer = (answer > n) ? n : answer;

        cout << "Case #" << c << ": " << answer << endl;
    }

    return 0;
}
