#include <bits\stdc++.h>
using namespace std;
typedef long long ll;
template <class T> T sqr(T x) { return x*x; }

int T,N;
int Ns[1000];
char strs[1][10] = {"INSOMNIA"};
int hist[10];
int found;
void countdigits(long long n){
    while(n){
        int d = n%10;
        if (hist[d]==0)
            found++;
        hist[d] = 1;
        n /= 10;
    }
}

void solve(int testi){
    long long N = Ns[testi];
    if (N==0){
        printf("Case #%d: INSOMNIA\n", testi+1);
        return;
    }
    found = 0;
    memset(hist, 0, 10*4);
    int time = 0;
    while(1){
        time++;
        countdigits(time*N);
        //printf("%10d : %d\n", time*N, found);
        if (found == 10)
            break;
    }
    printf("Case #%d: %I64d\n", testi+1, time*N);
}

int main(){
	#ifdef LOCAL_PROJECT
		freopen("d:\\src\\CppProjects\\stdin","r",stdin);
		freopen("d:\\src\\CppProjects\\stdout","w",stdout);
	#endif
	#if 1
    scanf("%d",&T);
    for(int i=0; i<T; i++)
        scanf("%d",Ns+i);
    #else
    T = 201;
    for(int i=0; i<=200; i++)
        Ns[i] = i;
    #endif
    for(int i=0; i<T; i++)
        solve(i);
	return 0;
}



