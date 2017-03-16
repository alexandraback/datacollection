#include<bits/stdc++.h>
#include <unistd.h>

#define IT(a,it) for(auto it=a.begin(); it != a.end(); it++)
#define REV_IT(a,it) for(auto it=a.rbegin(); it != a.rend(); it++)
#define LL long long
#define LD long double
#define MP make_pair
#define FF first
#define SS second
#define PB push_back
#define INF (int)(1e9)
#define EPS (double)(1e-9)

#ifndef ONLINE_JUDGE
#  define LOG(x) cerr << #x << " = " << (x) << endl
#else
#  define LOG(x) 0
#endif

#define MAXX 500005

using namespace std;

typedef pair <int, int> pi_i;
typedef pair<int, pi_i> pi_ii;

bool cmp(int a, int b){ return a>b; }
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a * b / gcd(a, b); }

LL n, tot, d[2000], h[2000], m[2000];

int main(){
	ios_base::sync_with_stdio(false);
	
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	int T, casee = 1;
	cin >> T;
	for(casee=1;casee<=T;casee++){	
		cin >> n;
		tot = 0;int h11, h22, d11, d22;
		for(int i = 0;i<n;i++){
			cin >> d[i] >> h[i] >> m[i];
			tot += h[i];
		}
		cout << "Case #" << casee << ": " ;
		if(tot <= 1){
			cout << 0 << endl;
		}else{
			if(n == 1) h11 = m[0], h22 = m[0]+1, d11 = d[0], d22 = d[0];
			else h11 = m[0], h22 = m[1], d11 = d[0], d22 = d[1];
			
			if(h11 < h22){
				swap(h11, h22);swap(d11, d22);
			}
			
			int ans = 1;
			//take h11 speed
			long double t1 = 0.0;
			t1 = h11;
			//LOG(h11);LOG(h22);
			//LOG(t1);
			long double t2 = (360.0 * t1) / (long double)h22;
			//LOG(t2);
			if(t2 < (360.0+360.0-d22)) ans = 0;
			
			swap(h11, h22);swap(d11, d22);
			/*
			t1 = 0.0;
			t1 = h11;
			LOG(t1);
			t2 = (360.0 * t1) / (double)h22;
			LOG(t2);
			if(t2 < (360.0+360.0-d22)) ans = 0;
			*/
			cout << ans << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
return 0;	
}

