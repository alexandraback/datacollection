#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <climits>

using namespace std;

#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)

typedef pair<int, int> PII;
typedef pair<double, double> PDD;

const int inf = INT_MAX;

int main(){
    int T;
    cin >> T;
    for(int cas = 1; cas <= T; cas++) {
        int a_big, a_small;
        int n;
        vector<double> naomi, ken;
        cin >> n;
        for(int i = 0; i < n; i++) {
            double biu;
            cin >> biu;
            naomi.push_back(biu);
        }
        for(int i = 0; i < n; i++) {
            double biu;
            cin >> biu;
            ken.push_back(biu);
        }

        sort(naomi.begin(), naomi.end(), greater<double>()); // descendint
        sort(ken.begin(), ken.end()); // ascending

        vector<double> naomi2(naomi), ken2(ken);
        sort(ken2.begin(), ken2.end(), greater<double>()); // descendint

        int cnt = 0;
        a_small = 0;
        while(cnt < n) {
            /*for(int i = 0; i < naomi.size(); i++) {
                cout << naomi[i] << ' ';
            } cout << endl;
            for(int i = 0; i < ken.size(); i++) {
                cout << ken[i] << ' ';
            } cout << endl;*/
            double nao = naomi[0];
            naomi.erase(naomi.begin());
            int i;
            for(i = 0; i < ken.size(); i++) {
                if(nao < ken[i]) {
                    break;
                }
            }
            if(i == ken.size()) {
                a_small++;
                ken.erase(ken.begin());
            }
            else {
                ken.erase(ken.begin() + i);
            }
            cnt++;
        }

        /*for(int i = 0; i < naomi2.size(); i++) {
            cout << naomi2[i] << ' ';
        } cout << endl;
        for(int i = 0; i < ken2.size(); i++) {
            cout << ken2[i] << ' ';
        } cout << endl;*/

        cnt = 0;
        a_big = 0;
        while(cnt < n) {
            if(naomi2[naomi2.size()-1] < ken2[ken2.size()-1]) {
                naomi2.erase(naomi2.begin()+naomi2.size()-1);
                ken2.erase(ken2.begin());
            }
            else {
                naomi2.erase(naomi2.begin()+naomi2.size()-1);
                ken2.erase(ken2.begin() + ken2.size()-1);
                a_big++;
            }
            cnt++;
        }

        printf("Case #%d: %d %d\n", cas, a_big, a_small);
    }
}
