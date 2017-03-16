#include <bits/stdc++.h>

#define INF 1000000010
#define FO(i,a,b) for (int (i) = (a); (i) < (b); ++(i))
#define sz(v) int(v.size())

using namespace std;
//PAIRS:
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pii;
typedef long long ll;

/*~~~~TEMPLATE END~~~~*/

int T;
int N;
char str[1005];

vector <char> myStr;

int main() {
    scanf ("%d", &T);
    FO (_z,1,T+1) {
        printf ("Case #%d: ", _z);
        scanf ("%s ", str);
        myStr.clear();
        N = strlen(str);
        FO (i,0,N) {
            vector <char> temStr1;
            vector <char> temStr2;
            temStr1.push_back (str[i]);
            FO (p,0,myStr.size()) {
                temStr1.push_back (myStr[p]);
                temStr2.push_back (myStr[p]);
            }
            temStr2.push_back (str[i]);
            int firstBetter = 0;
            FO (p,0,temStr1.size()) {
                if (temStr1[p] > temStr2[p]) {
                    firstBetter = true;
                    break;
                }
                if (temStr1[p] < temStr2[p]) {
                    firstBetter = false;
                    break;
                }
            }
            if (firstBetter) {
                myStr.clear();
                FO (p,0,temStr1.size()) myStr.push_back (temStr1[p]);
            } else {
                myStr.clear();
                FO (p,0,temStr2.size()) myStr.push_back (temStr2[p]);
            }
        }
        FO (p,0,myStr.size()) printf ("%c", myStr[p]);
        printf ("\n");
    }
    return 0;
}
