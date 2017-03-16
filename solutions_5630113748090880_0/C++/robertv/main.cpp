#include <bits\stdc++.h>
using namespace std;
typedef long long ll;
template <class T> T sqr(T x) { return x*x; }

int T, N;
int hist[3000];
int a[1000];
void solve(int testi){
    scanf("%d",&N);
    memset(hist, 0, 3000*4);
    for(int i=0; i<(2*N-1)*N; i++){
        scanf("%d",a+i);
        hist[a[i]]++;
    }
    vector<int> sol;
    for(int i=0; i<=2500; i++)
        if (hist[i]%2==1)
            sol.push_back(i);
    sort(sol.begin(), sol.end());
    printf("Case #%d: ",testi);
    for(int x : sol)
        printf("%d ",x);
    printf("\n");
}
int main(){
	#ifdef LOCAL_PROJECT
		freopen("d:\\src\\CppProjects\\stdin","r",stdin);
		freopen("d:\\src\\CppProjects\\stdout","w",stdout);
	#endif
	scanf("%d",&T);
    for(int i=1; i<=T; i++)
        solve(i);
	return 0;
}
