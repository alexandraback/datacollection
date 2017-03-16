#include <bits\stdc++.h>
using namespace std;
typedef long long ll;
template <class T> T sqr(T x) { return x*x; }

int T;
int N;

void solve(int testi){
    scanf("%d",&N);
    set<string> left, right;
    vector<string> ls, rs;
    string s1, s2;
    for(int i=0; i<N; i++){
        cin >> s1 >> s2;
        left.insert(s1);
        right.insert(s2);
        ls.push_back(s1);
        rs.push_back(s2);
    }

    int sol = 0;
    for(int i=0; i< 1<<N; i++){
        set<string> newl, newr;
        for(int j=0; j<N; j++) if (i & (1<<j)){
            newl.insert(ls[j]);
            newr.insert(rs[j]);
        }
        bool good = 1;
        for(string ss : left)
            good &= (newl.find(ss)!=newl.end());
        for(string ss : right)
            good &= (newr.find(ss)!=newr.end());
        //good = newl.size()==left.size() && newr.size()==right.size();
        if (good){
            sol = max(sol, N-__builtin_popcount(i));
        }
    }
    printf("Case #%d: %d\n",testi, sol);
}
int main(){
	#ifdef LOCAL_PROJECT
		freopen("d:\\src\\CppProjects\\stdin","r",stdin);
		freopen("d:\\src\\CppProjects\\stdout","w",stdout);
	#endif
	scanf("%d\n",&T);
    for(int i=1; i<=T; i++){
        cerr << i << endl;
        solve(i);
    }
	return 0;
}
