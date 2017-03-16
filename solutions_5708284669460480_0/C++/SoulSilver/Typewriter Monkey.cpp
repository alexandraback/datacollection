#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define sz(a) (int)a.size()
#define fs first
#define sc second

typedef long long ll;
typedef pair<int,int> ii;

int K, L, S, cnt[500], mx;
double F[500], res;
char a[105], b[105];
string s;

void DQ1(int x, int SL, double TL) {
    if (x == S) {
        mx = max(mx,SL);
        return;
    }
    for (char i = 'A'; i <= 'Z'; ++i) {
        if (F[i]==0.0) continue;
        s[x] = i;
        bool cnt = true;
        if (x+1 >= L) {
            for (int j = x; j > x-L; --j)
            if (s[j]!=b[L-(x-j)-1]) {
                cnt = false;
                break;
            }
        }
        else cnt = false;
        DQ1(x+1,SL+cnt,TL*F[i]);
    }
}

void DQ(int x, int SL, double TL) {
    if (x == S) {
        res += TL*(mx-SL);
        return;
    }
    for (char i = 'A'; i <= 'Z'; ++i) {
        if (F[i]==0.0) continue;
        s[x] = i;
        bool cnt = true;
        if (x+1 >= L) {
            for (int j = x; j > x-L; --j)
            if (s[j]!=b[L-(x-j)-1]) {
                cnt = false;
                break;
            }
        }
        else cnt = false;
        DQ(x+1,SL+cnt,TL*F[i]);
    }
}

int main() {
	freopen("B-small-attempt0.in","r",stdin);
	freopen("output.txt","w",stdout);
    int t; scanf("%d\n",&t); int tmp = t;
    while (t--) {
        int K;
        scanf("%d%d%d\n",&K,&L,&S);
        scanf("%s\n",a);
        scanf("%s\n",b);
        memset(cnt,0,sizeof cnt);
        memset(F, 0.0, sizeof F);
        for (int i = 0; i < K; ++i)
            cnt[a[i]]++;
        for (char i = 'A'; i <= 'Z'; ++i)
            F[i] = (double)cnt[i]/(double)K;
        s = ""; for (int i = 0; i < S; ++i)
            s = s+' ';
        mx = 0;
        DQ1(0,0,1.0);
        res = 0.0;
        DQ(0,0,1.0);
        cout << "Case #" << tmp-t << ": " << fixed << setprecision(9) << res << endl;
    }
	return 0;
}
