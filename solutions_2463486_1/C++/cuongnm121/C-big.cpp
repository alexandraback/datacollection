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

const ll maxn = 10000000 + 10;
const int maxm = 1000;

const int total = 40;
const ll number[40] = {1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001,10221412201,12102420121,12345654321,40000800004,1000002000001,1002003002001,1004006004001,1020304030201,1022325232201,1024348434201,1210024200121,1212225222121,1214428244121,1232346432321,1234567654321,4000008000004,4004009004004,100000020000001};

template <class T> inline T abs(T x) { if (x < 0) return -x; return x; }

int n;
ll a,b;

bool isFair(ll num) {

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

    int x,y;

    cin >> n;
    for(int t=0; t<n; t++) {
        cin >> a >> b;
        x = 0;
        for(int i=0; i<total; i++) if (number[i] <  a) x = i+1;
        y = 0;
        for(int i=0; i<total; i++) if (number[i] <= b) y = i+1;
        cout << "Case #" << t+1 << ": " << y - x << endl;
    }

	return 0;
}
