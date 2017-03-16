#include <bits/stdc++.h>
using namespace std;
string ss;
string pp;
vector<int > failure;
int kmp(){
    int matches = 0;
    int N = pp.size();
	failure.resize(N+1);
    int pos = failure[0] = failure[N] = -1;
    for(int i = 1; i <= (int)pp.size(); i++){
		while(pos != -1 && pp[pos] != pp[i - 1]) pos = failure[pos];
		failure[i] = ++pos;
	}
	int sp = 0, tp = 0;
	while(tp < (int)ss.size()){
		while(sp != -1 && (sp == (int)pp.size() || pp[sp] != ss[tp])) sp = failure[sp];
		tp++, sp++;
		if(sp == (int)pp.size()) matches++;
	}
	return matches;
}

string s;
int cnt = 0;
int S;
int mx;
int generateC(int index, string so_far)
{
    if(index == S)
    {
        ss = so_far;
        cnt++;
        int current = kmp();
        mx = max(mx, current);
        return current;
    }
    int ans = 0;
    for(int i = 0; i < s.length(); ++i)
    {
        ans += generateC(index+1, so_far+s[i]);
    }
    return ans;
}

int main()
{

    freopen("B-small-attempt2.in", "r", stdin);
    freopen("B-small-attempt2.out", "w", stdout);
    int tc,k,l;
    cin >> tc;
    for(int t = 1; t <= tc; ++t)
    {
        cin >> k >> l >> S;
        cin >> s >> pp;
        cout << "Case #" << t << ": ";
        cnt = 0;
        mx = 0;
        double ans = (double)generateC(0,"") / cnt;
        ans = (double) mx - ans;
        printf("%.8lf\n", ans);
    }

}
