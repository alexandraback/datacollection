#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<utility>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<map>

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

#define openfile {freopen("test.txt","r",stdin);}
#define closefile {freopen("res.txt","w",stdout);}

using namespace std;

typedef long long ll;
typedef pair<int,int> pint;

const int maxn = 1000 + 10;

template <class T> inline T abs(T x) { if (x < 0) return -x; return x; }

int n;
int a,b;
int l[maxn];

bool isFair(int num) {

    string s = "";
    while (num > 0) {
        s = char(num%10 + '0') + s;
        num = num/10;
    }

    for(int i=0; i<s.length()/2; i++) if (s[i] != s[s.length()-i-1]) {
        return false;
    }

    return true;
}

int main() {

    openfile
    closefile

    memset(l,0,sizeof(l));
    for(int i=1; i*i<maxn; i++) if (isFair(i) && isFair(i*i)) {
        l[i*i] = 1;
    //     cout << i*i << endl;
    }

    for(int i=1; i<maxn; i++) l[i] += l[i-1];

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> a >> b;
        cout << "Case #" << i+1 << ": " << l[b] - l[a-1] << endl;
    }

	return 0;
}
