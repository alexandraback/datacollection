#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <random>
#include <functional>
using namespace std;

void use_file(const std::string& s = "")
{
    if (s != "std" && s != "") {
        freopen((s+".in").c_str(), "r", stdin);
        freopen((s+".out").c_str(), "w", stdout);
    }
}




int main() {
    use_file("B2");
    int T, N;
    cin >> T;

    for(int ca = 1; ca <= T; ca++){
        int h[3000] = {0};
        cin >> N;
        for (int i = 0; i < N * 2 - 1; i++)
        {
           for (int i = 0; i < N; i++){
                int a;
                cin >> a;
                h[a] ++;
           }
        }
        cout << "Case #" << ca << ": ";
        for (int i = 0; i <= 2500; i++){
            if (h[i] & 1) {
                cout << " " << i;
            }
        }
        cout << endl;
    }
	return 0;
}
