#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <cstdlib>

using namespace std;

int t;

int solve() {
    int n,s,p;
    cin >> n >> s >> p;
    vector<int> score(n,0);
    for (int i=0;i<n;i++) cin >> score[i];
    int minScore=max(3*p-2,p);
    int minSurprisingScore=max(3*p-4,p);
    int result=0;
    for (int i=0;i<n;i++) {
        if (score[i]>=minScore) ++result;
        else if (score[i]>=minSurprisingScore&&s>0) {
            ++result;
            --s;
        }
    }
    return result;
}

int main()
{
    cin >> t;
    for (int i=0;i<t;i++) cout << "Case #" << i+1 << ": " << solve() << endl;
    return 0;
}
