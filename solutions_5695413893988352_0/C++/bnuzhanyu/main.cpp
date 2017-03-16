#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <random>
#include <map>
#include <functional>
using namespace std;

void use_file(const std::string& s = "")
{
    if (s != "std" && s != "") {
        freopen((s+".in").c_str(), "r", stdin);
        freopen((s+".out").c_str(), "w", stdout);
    }
}

bool satisfy(int i, string& s)
{
    for (int j = 0, t = s.size() - 1; j < s.size(); j++, t--){
        if (s[t] != '?' && s[t] != i % 10 + '0' ){
            return false;
        }
        i /= 10;
    }
    return true;
}

void calc(int& i, int& j, std::string& sa, std::string& sb)
{
    int limit[] = {1, 10, 100, 1000};
    int l = sa.size();
    int dif = limit[l];
    for (int a = 0; a < limit[l]; a++){
        for (int b = 0 ; b < limit[l]; b++){
            if (satisfy(a, sa) && satisfy(b, sb)){
                if (dif > abs(b - a)) {
                    dif = abs(b - a);
                    i = a;
                    j = b;
                }
            }
        }
    }

}

std::string output(int i, int s)
{
    string str;
    for (int j = 0; j < s; j++){
        str.push_back(i % 10 + '0');
        i /= 10;
    }
    reverse(str.begin(), str.end());
    return str;
}

int main() {
    use_file("B1");
    int T, N;
    cin >> T;

    std::string a, b;
    for(int ca = 1; ca <= T; ca++){
        cin >> a >> b;
        int i, j;
        calc(i, j, a, b);
        cout << "Case #" << ca << ": "  << output(i, a.size()) << " " << output(j, b.size()) << std::endl;
    }
	return 0;
}
