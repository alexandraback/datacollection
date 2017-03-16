#include<bits/stdc++.h>
#define LL long long 
#define PI acos(-1)
#define x first
#define y second
#define PII pair<int,int>
#define F(x,y,z) for(int (x)=(y);(x)<(z);(x)++)
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define feq(x,y) (fabs((x)-(y)) <= eps)
#define flt(x,y) ((x)+eps < (y))
#define fle(x,y) ((x)+eps <= (y))
#define fgt(x,y) ((x) > (y)+eps)
#define fge(x,y) ((x) >= (y)+eps)
using namespace std;

int T,n,ans, k,l,s, mx = 1<<28, cnt;
char a[10] ;
string t;
vector<int> v;
void count(string s){
    cnt = 0;
    for(int i=0, L=s.length()-l+1; i<L;i++){
	if(s.substr(i,l) == t){ cnt++; }
    }
    mx = max(mx, cnt);
    v.pb(cnt);
}

void dfs(int d, string ss){
    if(d == s) {
	count(ss);
	return;
    }
    
    for(int i=0; i<k;i++){
	dfs(d+1, ss + a[i]);
    }
    return;    
}

int main(){
    scanf("%d", &T);
    for(int qwe=1; qwe<=T;qwe++){
	scanf("%d%d%d", &k,&l,&s);
	mx = cnt = 0;
	v.clear();
	getchar();
	for(int i=0; i<k;i++) scanf("%c", &a[i]);
	getchar();
	cin >> t;	
	dfs(0,"");
	int sum = 0;
	for(int i=0; i<v.size(); i++) {
	    sum += mx - v[i];
	}
	printf("Case #%d: %.7f\n", qwe, sum / pow(k,s));
    }
    return 0;
}
