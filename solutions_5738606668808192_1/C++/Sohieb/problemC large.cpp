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
	if(sz(s)==min(n-2,16)){
		arr.push_back("1"+s+"1");
		return;
	}
	go(s+'0');
	go(s+'1');
}

bitset<1000000> isPrime;
vector<int> primes;

void sieve(){
	isPrime.set();
	isPrime[0]=isPrime[1]=0;
	for(int i=2;i<1000000;i++)
		if(isPrime[i]){
			for(long long j=1LL*i*i;j<1000000;j+=i)
				isPrime[j]=0;
			primes.push_back(i);
		}
}

long long pwr(long long base, long long pw, int MD){
	long long res = 1;
	while (pw){
		if (pw % 2 == 1)res *= base;
		base *= base;
		base %= MD;
		res %= MD;
		pw /= 2;
	}
	return res;
}

int convToBase(int base,string num,int md){
	long long res=0;
	reverse(all(num));
	for(int i=0;i<sz(num);i++){
		if(num[i]=='0')continue;
		res+=pwr(base,i,md);
		res%=md;
	}
	return res;
}

int getDiv(int base,string s){
	int idx=0;
	while(idx<10){
		if(convToBase(base,s,primes[idx])==0)return primes[idx];
		idx++;
	}
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("C-large.in", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	sieve();
	scanf("%d",&T);
	for(int C=1;C<=T;C++){
		printf("Case #%d:\n",C);
		scanf("%d%d",&n,&m);
		arr.clear();
		go("");
		int cnt=0;
		for(int i=0;i<sz(arr)&&cnt<m;i++){
			while(sz(arr[i])<n)arr[i].insert(arr[i].begin()+1,'0');
			vector<int> divs;
			for(int j=2;j<=10;j++){
				divs.push_back(getDiv(j,arr[i]));
				if(divs.back()==-1)break;
			}
			if(count(all(divs),-1)==0){
				cout<<arr[i];
				for(int j=0;j<9;j++)
					printf(" %d",divs[j]);
				printf("\n");
				cnt++;
			}
		}
	}
}
