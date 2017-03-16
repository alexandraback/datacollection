#include <bits\stdc++.h>
using namespace std;
typedef long long ll;
template <class T> T sqr(T x) { return x*x; }

int T;
char S[1000];
int ans[1000];

void solve(int testi){
    scanf("%s",S);
    int n = strlen(S);
    int flips = S[n-1]=='-';
    char now = S[0];
    for(int i=1; i<n; i++){
        if (S[i]!=now){
            flips++;
            now = S[i];
        }
    }
    ans[testi] = flips;
}

int main(){
	#ifdef LOCAL_PROJECT
		freopen("d:\\src\\CppProjects\\stdin","r",stdin);
		freopen("d:\\src\\CppProjects\\stdout","w",stdout);
	#endif

    scanf("%d",&T);
    for(int i=0; i<T; i++)
        solve(i);
    for(int i=0; i<T; i++)
        printf("Case #%d: %d\n",i+1, ans[i]);
	return 0;
}



