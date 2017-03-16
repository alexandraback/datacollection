#include <bits/stdc++.h>
#include <ext/numeric>
#include <hash_map>
using namespace std;
using namespace __gnu_cxx;

#define oo			1e9
#define OO			1e18
#define EPS			1e-7
#define f			first
#define s			second
#define pi 			acos(-1.0)
#define ll			long long
#define ld			long double
#define ull			unsigned long long
#define sz(x)		(int)x.size()
#define all(x)		x.begin(),x.end()
#define rall(x)		x.rbegin(),x.rend()
#define popCnt(x)   __builtin_popcount(x)

int T;
int n,m;
vector<string> arr;

void go(string s){
	if(sz(s)==n-2){
		arr.push_back("1"+s+"1");
		return;
	}
	go(s+'0');
	go(s+'1');
}

bitset<100000010> isPrime;
vector<int> primes;

void sieve(){
	isPrime.set();
	isPrime[0]=isPrime[1]=0;
	for(int i=2;i<100000010;i++)
		if(isPrime[i]){
			for(long long j=1LL*i*i;j<100000010;j+=i)
				isPrime[j]=0;
			primes.push_back(i);
		}
}

long long pwr(long long base, long long pw){
	long long res = 1;
	while (pw){
		if (pw % 2 == 1)res *= base;
		base *= base;
		pw /= 2;
	}
	return res;
}

long long convToBase(int base,string num){
	long long res=0;
	reverse(all(num));
	for(int i=0;i<sz(num);i++){
		if(num[i]=='0')continue;
		res+=pwr(base,i);
	}
	return res;
}

int getDiv(long long num){
	int idx=0;
	while(idx<sz(primes)&&1LL*primes[idx]*primes[idx]<=num){
		if(num%primes[idx]==0)return primes[idx];
		idx++;
	}
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("C-small-attempt0.in", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	sieve();
	scanf("%d",&T);
	for(int C=1;C<=T;C++){
		printf("Case #%d:\n",C);
		scanf("%d%d",&n,&m);
		arr.clear();
		go("");
		int cur=0;
		while(m--){
			for(int i=cur;;i++){
				vector<int> divs;
				for(int j=2;j<=10;j++)
					divs.push_back(getDiv(convToBase(j,arr[i])));
				if(count(all(divs),-1)==0){
					cout<<arr[i];
					for(int j=0;j<9;j++)
						printf(" %d",divs[j]);
					printf("\n");
					cur=i+1;
					break;
				}
			}
		}
	}
}
