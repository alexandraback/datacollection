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

char ans[3000];

int main() {
    use_file("A1");
    int T;
    cin >> T;
    string s;

    int b, e;
    for(int ca = 1; ca <= T; ca++){
        cin >> s;
        b = e = 1500;
        ans[--b] = s[0];
        for (int i = 1; i < s.size(); i++){
            if (ans[b] > s[i]){
                ans[e++] = s[i];
            }else{
                ans[--b] = s[i];
            }
        }

        cout << "Case #" << ca << ": ";
        while(b < e){
            cout << ans[b++];
        }
        cout << endl;
    }
	return 0;
}
