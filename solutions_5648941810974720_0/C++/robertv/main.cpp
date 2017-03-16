#include <bits\stdc++.h>
using namespace std;
typedef long long ll;
template <class T> T sqr(T x) { return x*x; }

int T;
char ss[10][10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
char str[20000];
int lens[10];
int hist[30];
void solve(int testi){
    printf("Case #%d: ",testi);
}
void solvesmall(int testi){
    scanf("%s", str);
    memset(hist, 0, 30*4);
    int lstr = strlen(str);
    for(int i=0; i<lstr;i++)
        hist[str[i]-'A']++;

    int X[10];
    for(int k=0; k<10; k++)
        X[k] = -1;

    int k = 0;
    while(k>=0){
        while(X[k]<9){
            X[k]++;
            int L = 0;
            for(int i=0; i<=k; i++)
                L += lens[X[i]];
            if (L==lstr){
                int hist2[30] = {0};
                for(int i=0; i<=k; i++)
                    for(int j=0; j<lens[X[i]]; j++)
                        hist2[ss[X[i]][j]-'A']++;
                bool good = 1;
                for(int j=0; j<26 && good; j++)
                    if (hist2[j]!=hist[j])
                        good = 0;
                if (good){
                    printf("Case #%d: ",testi);
                    vector<int> sol;
                    for(int i=0; i<=k; i++)
                        sol.push_back(X[i]);
                    sort(sol.begin(), sol.end());
                    for(int x : sol)
                        printf("%d",x);
                    printf("\n",testi);
                    goto endit;
                }
            }
            else if (L<lstr){
                k++;
                X[k] = -1;
            }
            else
                continue;
        }
        X[k] = 0;
        k--;
    }
    endit:
        k = 10;
}
int main(){
	#ifdef LOCAL_PROJECT
		freopen("d:\\src\\CppProjects\\stdin","r",stdin);
		freopen("d:\\src\\CppProjects\\stdout","w",stdout);
	#endif
	for(int i=0; i<10; i++)
        lens[i] = strlen(ss[i]);
	scanf("%d\n",&T);
    for(int i=1; i<=T; i++){
        cerr << i << endl;
        solvesmall(i);
    }
	return 0;
}
