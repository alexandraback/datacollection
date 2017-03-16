#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long int LL;
typedef vector<int> VI;

#define sd(x) scanf("%d", &x)
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define INF 2000000000
#define MOD 1000000007
#define D double
#define LD long double

int mat[5][5] =  { {0, 0,  0,  0,  0},
				   {0, 1,  2,  3,  4},
				   {0, 2, -1,  4, -3},
				   {0, 3, -4, -1,  2},
				   {0, 4,  3, -2, -1} };

int mul(int a, int b){
	int ret = 1;
	if(a < 0){
		a = -a;
		ret = -1;
	}
	if(b < 0){
		b = -b;
		ret = -ret;
	}
	ret *= mat[a][b];
	return ret;
}

#define N 1123456

string s;
string op[] = {"NO", "YES"};
int a[N];

inline int solve(){
	LL x;
	int l, p, i, i1, i2, i3, i4, l1, l2;
	cin>>l>>x;
	cin>>s;
	if(x % 4 == 0){
		return 0;
	}
	for(i = 0; i < l; i++){
		a[i] = s[i] - 'g';
		a[i + l] = a[i];
		a[i + l + l] = a[i];
		a[i + l + l + l] = a[i];
	}
	p = 1;
	l1 = -1;
	l2 = -1;
	for(i = 0; i < 4 * l; i++){
		p = mul(p, a[i]);
		if(p == 2){
			l1 = i + 1;
			break;
		}
	}
	p = 1;
	for(i = 4 * l - 1; i >= 0; i--){
		p = mul(a[i], p);
		if(p == 4){
			l2 = 4 * l - i;
			break;
		}
	}
	//cout<<l1<<" "<<l2<<endl;
	if(l1 == -1 || l2 == -1){
		return 0;
	}
	p = 1;
	for(i = 0; i < l; i++){
		p = mul(p, a[i]);
	}
	if(x % 2 == 0){
		if(p == -1 || p == 1){
			return 0;
		}
	}
	else{
		if(p != -1){
			return 0;
		}
	}
	if(l1 + l2 <= x * l){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	freopen("inp.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t;
	sd(t);
	for(int i = 1; i <= t; i++){
		printf("Case #%d: ", i);
		cout<<op[solve()]<<"\n";
	}
	return 0;
}
