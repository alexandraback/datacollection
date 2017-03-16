#include <bits/stdc++.h>
#define INF 1000000000
#define MAXN 1000005
#define PI 3.14159265358979323846
using namespace std;
typedef long long ll;
typedef int char_32;
const ll mod = 1000000007;
#define INF16 1000000

int used[2005];
int d[30];
vector <int> vi;
int main() {
    freopen("A-large (1).in", "r", stdin);
    freopen("ancestor.out", "w", stdout);
    int t; cin >> t;
    string s;
    for(int i = 0; i < t; ++i) {

        vi.clear();

        memset(d, 0, sizeof d);
        cin >> s;
        int k = s.length();
        for(int i = 0 ; i < s.length(); ++i) {
            d[ s[i] - 'A' ] += 1;
        }

        while(k != 0) {

            if(d[(int)('Z'-'A')]) {
                d[(int)('Z'-'A')] -= 1;
                d[(int)('E'-'A')] -= 1;
                d[(int)('R'-'A')] -= 1;
                d[(int)('O'-'A')] -= 1;
                k -= 4;
                vi.push_back(0);
            }

            else if(d[(int)('W'-'A')]) {
                d[(int)('T'-'A')] -= 1;
                d[(int)('W'-'A')] -= 1;
                d[(int)('O'-'A')] -= 1;
                k -= 3;

                vi.push_back(2);
            }


            else if(d[(int)('X'-'A')]) {
                d[(int)('S'-'A')] -= 1;
                d[(int)('I'-'A')] -= 1;
                d[(int)('X'-'A')] -= 1;
                k -= 3;

                vi.push_back(6);
            }



            else if(d[(int)('G'-'A')]) {
                d[(int)('E'-'A')] -= 1;
                d[(int)('I'-'A')] -= 1;
                d[(int)('G'-'A')] -= 1;
                d[(int)('H'-'A')] -= 1;
                d[(int)('T'-'A')] -= 1;
                k -= 5;

                vi.push_back(8);
            }


            else if(d[(int)('S'-'A')]) {
                d[(int)('S'-'A')] -= 1;
                d[(int)('E'-'A')] -= 1;
                d[(int)('V'-'A')] -= 1;
                d[(int)('E'-'A')] -= 1;
                d[(int)('N'-'A')] -= 1;
                k -= 5;

                vi.push_back(7);
            }

            else if(d[(int)('T'-'A')]) {
                d[(int)('T'-'A')] -= 1;
                d[(int)('H'-'A')] -= 1;
                d[(int)('R'-'A')] -= 1;
                d[(int)('E'-'A')] -= 1;
                d[(int)('E'-'A')] -= 1;
                k -= 5;

                vi.push_back(3);
            }

            else if(d[(int)('R'-'A')]) {
                d[(int)('F'-'A')] -= 1;
                d[(int)('O'-'A')] -= 1;
                d[(int)('U'-'A')] -= 1;
                d[(int)('R'-'A')] -= 1;
                k -= 4;

                vi.push_back(4);
            }

            else if(d[(int)('V'-'A')]) {
                d[(int)('F'-'A')] -= 1;
                d[(int)('I'-'A')] -= 1;
                d[(int)('V'-'A')] -= 1;
                d[(int)('E'-'A')] -= 1;
                k -= 4;

                vi.push_back(5);
            }

            else if(d[(int)('I'-'A')]) {
                d[(int)('N'-'A')] -= 1;
                d[(int)('I'-'A')] -= 1;
                d[(int)('N'-'A')] -= 1;
                d[(int)('E'-'A')] -= 1;
                k -= 4;

                vi.push_back(9);
            }



            else {

                d[(int)('O'-'A')] -= 1;
                d[(int)('N'-'A')] -= 1;
                d[(int)('E'-'A')] -= 1;
                k -= 3;

                vi.push_back(1);

            }

        }


        cout << "Case #" << i + 1 << ": ";
        sort(vi.begin(), vi.end());
        for(int i = 0; i < vi.size(); ++i) cout << vi[i];
        cout << endl;



    }
}
