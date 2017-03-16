#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define sz(a) (int)a.size()
#define fs first
#define sc second

typedef long long ll;
typedef pair<int,int> ii;

int F[5000], n, w, p;

int main() {
	freopen("A-large.in","r",stdin);
	freopen("output.txt","w",stdout);
    int t; scanf("%d",&t); int tmp = t;
    while (t--) {
        int R;
        scanf("%d%d%d",&R,&n,&w);
        cout << "Case #" << tmp-t << ": " << (n/w)*(R-1) + w - (n%w==0) + (n/w) << endl;
    }
	return 0;
}
