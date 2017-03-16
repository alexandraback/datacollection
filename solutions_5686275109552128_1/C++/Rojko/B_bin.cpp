#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

bool check(int t, int s, vector<int> &v) {
	for (int i = 0; i<v.size(); ++i) {
        int tt = min(t,v[i]);
        int ss = (v[i]-1)/tt;
		if (ss > s) return false;
		s -= ss;
    }
	return true;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 0; t<T; ++t) {
        int d;
        scanf("%d", &d);
        vector<int> v(d);
        for (int i = 0; i<d; ++i) scanf("%d", &v[i]);
        sort(v.begin(), v.end(), greater<int>());
        int kolko = v[0];
        //binarne vyhladat
        int imin = 1, imax = v[0];
        while (imax - imin > 0) {
            int imid = (imax+imin)/2;
            //printf("<%d , %d> .. %d\n", imin, imax, imid);
            kolko = -1;
            for (int j = 1; j<=imid; ++j) {
                int sp = imid-j;
                if (check(j,sp,v)) {
                    kolko = imid;
                    break; 
                }
            }
            if (kolko > -1) {
                //printf("menim hornu\n");
                imax = imid;
            } else {
                //printf("menim dolnu\n");
                imin = imid+1;
            }
        }
        printf("Case #%d: %d\n", t+1, imin);
    }
    return 0;
}
