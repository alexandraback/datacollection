//Akhilesh Gulati, NSIT
#include<bits/stdc++.h>
void printmat(int rs, int re, int cs, int ce, int ncol, int* a) {
    printf("   ");
    for(int j=cs; j<=ce; j++) {
        printf("%3d", j);
    }
    printf("\n");
    for(int i=rs; i<=re; i++) {
        printf("%3d", i);
        for(int j=cs; j<=ce; j++) {
            printf("%3d", a[i*ncol+j]);
        }
        printf("\n");
    }
}
#define ll long long int
#define gc getchar
void scan(int &x) { register int c = gc(); x = 0; for(;(c<48 || c>57);c = gc()); for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;} }
void scanll(ll &x) { register ll c = gc(); x = 0; for(;(c<48 || c>57);c = gc()); for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;} }
#define pii pair<int,int>
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define foreach(it, t) for(auto it = t.begin(); it!=t.end(); it++)  //it: pointer
#define vi vector<int>
#define pb push_back
#define in(n) scan(n)
#define inll(n) scanll(n)
#define out(n) printf("%d", n)
#define outll(n) printf("%lld", n)
#define outs(n) printf("%d ",n)   //with space
#define outsll(n) printf("%lld ",n)   //with space
#define newl printf("\n")
#define chk(a) cout << endl << #a << " : " << a << endl
#define chk2(a,b) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << endl
#define chk3(a,b,c) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << endl
#define chk4(a,b,c,d) cout << endl << #a << " : " << a << "\t" << #b << " : " << b << "\t" << #c << " : " << c << "\t" << #d << " : " << d << endl

using namespace std;


int dp[1000005];

int rev(int n) {
	int reverse=0;
	while (n != 0)
   {
      reverse = reverse * 10;
      reverse = reverse + n%10;
      n       = n/10;
   }
   return reverse;
}

int len(int n) {
	int l=0;
	while(n!=0) {
		l++;
		n /= 10;
	}
	return l;
}

void pre() {
	int i=2;
	dp[1] = 1;
	for(; i<=1000000; i++) {
		int r = rev(i);
		if(r<i && len(r)==len(i)) {
		    //cout<<r<<endl;
			dp[i] = min(dp[i-1], dp[r]) + 1;
		}
		else {
			dp[i] = dp[i-1] + 1;
		}
	}
}

int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
	//cout<< rev(3200);
	int t;
	cin>>t;
	int k;
	pre();
//	cout<<dp[10]<<endl;
	for(k=1; k<=t; k++) {
		int n;
		cin>>n;
		cout<<"Case #"<<k<<": "<<dp[n]<<endl;
	}
}
