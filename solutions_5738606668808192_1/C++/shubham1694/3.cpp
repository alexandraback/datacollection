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
const int lim = 10000;

vector<vector<int> > bit;
vector<int> primes, divisors;
int isprime[lim+10], n;

void generate(int lt, vector<int> &v)
{
	if(bit.size()>lim)
		return;
	if(!lt){
		vector<int> temp(n, 1);
		for(int i=1; i<n-1; i++)
			temp[i] = v[i-1];
		bit.pb(temp);
		return;
	}
	v.pb(1);
	generate(lt-1, v);
	v.pop_back();
	v.pb(0);
	generate(lt-1, v);
	v.pop_back();
}

void pre()
{
	int i, j;
	for(i=4; i<lim; i+=2)
		isprime[i] = 1;
	primes.pb(2);
	for(i=3; i<lim; i++){
		if(!isprime[i]){
			primes.pb(i);
			for(j=i*i; j<lim; j+=i)
				isprime[j] = 1;
		}
	}
}

ll modpow(ll a, ll b, ll m)
{
	ll x=1, y=a;
	while(b){
		if(b&1)
			x = (x*y)%m;
		y = (y*y)%m;
		b/=2;
	}
	return x;
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);
	int i, j, t, k, l, p, s, cnt = 0;
	ll temp;
	scanf("%d%d%d", &t, &n, &s);
	vector<int> v;
	generate(n-2, v);
	pre();
	printf("Case #1:\n");
	for(i=0; i<lim; i++){
		divisors.clear();
		for(j=2; j<=10; j++){
			p = 0;
			for(k=0; k<primes.size(); k++){
				temp = 0;
				for(l=0; l<bit[i].size(); l++){
					if(bit[i][l]==1)
						temp = (temp + modpow(j, l, primes[k]))%primes[k];
				}
				if(temp==0){
					divisors.pb(primes[k]);
					p = 1;
					break;
				}
			}
			if(!p)
				break;
		}
		if(p && (int)divisors.size()==9){
			cnt++;	
			for(l=bit[i].size()-1; l>=0; l--)
				printf("%d", bit[i][l]);
			for(l=0; l<9; l++)
				printf(" %d", divisors[l]);
			printf("\n");
		}
		if(cnt==s)
			break;
	}
	return 0;
}
