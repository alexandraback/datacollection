#include <bits\stdc++.h>
using namespace std;
typedef long long ll;
template <class T> T sqr(T x) { return x*x; }

int T;
char str[1000+7];
void solve(int testi){
    gets(str);
    list<char> Q;
    for(int i=0; i<strlen(str); i++){
        if (i==0 || str[i]>=Q.front())
            Q.push_front(str[i]);
        else
            Q.push_back(str[i]);
    }
    printf("Case #%d: ",testi);
    for(char c:Q)
        printf("%c",c);
    printf("\n");
}
int main(){
	#ifdef LOCAL_PROJECT
		freopen("d:\\src\\CppProjects\\stdin","r",stdin);
		freopen("d:\\src\\CppProjects\\stdout","w",stdout);
	#endif
	scanf("%d\n",&T);
    for(int i=1; i<=T; i++)
        solve(i);
	return 0;
}
