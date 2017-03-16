//satyaki3794
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define MOD (1000000007LL)
#define LEFT(n) (2*(n))
#define RIGHT(n) (2*(n)+1)

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

ll pwr(ll base, ll p, ll mod = MOD){
ll ans = 1;while(p){if(p&1)ans=(ans*base)%mod;base=(base*base)%mod;p/=2;}return ans;
}


int cnt[30], digs[11];


int main()
{
    ios_base::sync_with_stdio(0);

    freopen("A-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t, x = 1;
    cin>>t;
    while(t--){

    	cout<<"Case #"<<x++<<": ";
    	string str;
    	cin>>str;

    	memset(cnt, 0, sizeof(cnt));
    	memset(digs, 0, sizeof(digs));
    	for(int i=0;i<(int)str.length();i++)
    		cnt[str[i]-'A']++;


    	while(cnt['Z'-'A'] > 0){
    		digs[0]++;
    		cnt['Z'-'A']--;
    		cnt['E'-'A']--;
    		cnt['R'-'A']--;
    		cnt['O'-'A']--;
    	}

    	while(cnt['W'-'A'] > 0){
    		digs[2]++;
    		cnt['T'-'A']--;
    		cnt['W'-'A']--;
    		cnt['O'-'A']--;    		
    	}

    	while(cnt['U'-'A'] > 0){
    		digs[4]++;
    		cnt['F'-'A']--;
    		cnt['O'-'A']--;
    		cnt['U'-'A']--;
    		cnt['R'-'A']--;
    	}

    	while(cnt['R'-'A'] > 0){
    		digs[3]++;
    		cnt['T'-'A']--;
    		cnt['H'-'A']--;
    		cnt['R'-'A']--;
    		cnt['E'-'A']--;
    		cnt['E'-'A']--;    		
    	}


    	while(cnt['F'-'A'] > 0){
    		digs[5]++;
    		cnt['F'-'A']--;
    		cnt['I'-'A']--;
    		cnt['V'-'A']--;
    		cnt['E'-'A']--;
    	}

    	while(cnt['X'-'A'] > 0){
    		digs[6]++;
    		cnt['S'-'A']--;
    		cnt['I'-'A']--;
    		cnt['X'-'A']--;
    	}

    	while(cnt['V'-'A'] > 0){
    		digs[7]++;
    		cnt['S'-'A']--;
    		cnt['E'-'A']--;
    		cnt['V'-'A']--;
    		cnt['E'-'A']--;
    		cnt['N'-'A']--;
    	}

    	while(cnt['G'-'A'] > 0){
    		digs[8]++;
    		cnt['E'-'A']--;
    		cnt['I'-'A']--;
    		cnt['G'-'A']--;
    		cnt['H'-'A']--;
    		cnt['T'-'A']--;
    	}

    	while(cnt['O'-'A'] > 0){
    		digs[1]++;
    		cnt['O'-'A']--;
    		cnt['N'-'A']--;
    		cnt['E'-'A']--;
    	}

    	while(cnt['I'-'A'] > 0){
    		digs[9]++;
    		cnt['N'-'A']--;
    		cnt['I'-'A']--;
    		cnt['N'-'A']--;
    		cnt['E'-'A']--;
    	}

    	for(int i=0;i<10;i++)
    		while(digs[i] > 0){
    			digs[i]--;
    			cout<<i;
    		}
    	cout<<endl;
    }

    return 0;
}







