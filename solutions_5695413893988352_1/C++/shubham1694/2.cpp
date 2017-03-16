#include <bits/stdc++.h>

using namespace std;

#define sd(x) scanf("%d", &x)
#define boost ios_base::sync_with_stdio(false);
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define f first
#define s second

typedef pair<int, int> pii;
typedef long long ll;

const int mod = 1000000007;
const int inf = 50000000;
const int maxn = 100010;

string c, j, ac, aj;
int n;
ll diff;

void solve(string tc, string tj, int cur, int flag)
{
	if(cur==n){
		ll p1 = stoll(tc);
		ll p2 = stoll(tj);
		if(llabs(p1-p2)<diff){
			ac = tc;
			aj = tj;
			diff = llabs(p1-p2);
		}
		else if(llabs(p1-p2)==diff){
			if(tc<ac){
				ac = tc;
				aj = tj;
			}
			else if(tc==ac){
				if(tj<aj)
					aj = tj;
			}
		}
		return;
	}
	if(c[cur]=='?' && j[cur]=='?'){
		if(flag==0){
			solve(tc+'0', tj+'0', cur+1, flag);
			solve(tc+'1', tj+'0', cur+1, 2);
			solve(tc+'0', tj+'1', cur+1, 1);
		}
		else if(flag==1){
			solve(tc+'9', tj+'0', cur+1, flag);
			solve(tc+'8', tj+'0', cur+1, flag);
		}
		else{
			solve(tc+'0', tj+'9', cur+1, flag);
			solve(tc+'0', tj+'8', cur+1, flag);
		}
	}
	else if(c[cur]=='?'){
		if(flag==0){
			solve(tc+j[cur], tj+j[cur], cur+1, flag);
			if(j[cur]!='0')
				solve(tc+(char)(j[cur]-1), tj+j[cur], cur+1, 1);
			if(j[cur]!='9')
				solve(tc+(char)(j[cur]+1), tj+j[cur], cur+1, 2);
		}
		else if(flag==1){
			solve(tc+'9', tj+j[cur], cur+1, flag);
			solve(tc+'8', tj+j[cur], cur+1, flag);
		}
		else{
			solve(tc+'0', tj+j[cur], cur+1, flag);
		}
	}
	else if(j[cur]=='?'){
		if(flag==0){
			solve(tc+c[cur], tj+c[cur], cur+1, flag);
			if(c[cur]!='0')
				solve(tc+c[cur], tj+(char)(c[cur]-1), cur+1, 2);
			if(c[cur]!='9')
				solve(tc+c[cur], tj+(char)(c[cur]+1), cur+1, 1);
		}
		else if(flag==1){
			solve(tc+c[cur], tj+'0', cur+1, flag);
		}
		else{
			solve(tc+c[cur], tj+'9', cur+1, flag);
			solve(tc+c[cur], tj+'8', cur+1, flag);
		}
	}
	else{
		int nf = flag;
		if(flag==0){
			if(c[cur]<j[cur])
				nf = 1;
			else if(j[cur]<c[cur])
				nf = 2;
		}
		solve(tc+c[cur], tj+j[cur], cur+1, nf);
	}
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	int cn = 1, t, i, flag;
	scanf("%d", &t);
	while(t--){
		diff = 1ll<<60;
		cin >> c >> j;
		n = (int)c.size();
		ac = aj = "";
		string tc, tj;
		tc = tj = "";
		solve(tc, tj, 0, 0);
		printf("Case #%d: ", cn++);
		cout << ac << " " << aj << "\n";
	}
	return 0;
}
