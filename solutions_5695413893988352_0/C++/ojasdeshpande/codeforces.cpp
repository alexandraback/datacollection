#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MOD 1000000007
int n;
pair<int,pair<string,string> > get(string a,string b, int i, int cur, int p){
	if(i==n){
		return {abs(cur),{a,b}};
	}
	if(a[i]=='?' && b[i]=='?'){
		//cout << cur << " " << endl;
		if(cur==0){
			a[i] = '0';
			b[i] = '0';
			pair<int,pair<string,string> > a1 = get(a,b,i+1,0,p/10);
			a[i] = '1';
			b[i] = '0';
			pair<int,pair<string,string> > a2 = get(a,b,i+1,p,p/10);
			a[i] = '0';
			b[i] = '1';
			pair<int,pair<string,string> > a3 = get(a,b,i+1,-p,p/10);
			if(a1.first <= a2.first && a1.first <=a3.first) return a1;
			if(a3.first <= a2.first && a3.first <=a1.first) return a3;
			return a2;
		}
		else if(cur<0){
			a[i] = '9';
			b[i] = '0';
			return get(a,b,i+1,cur + p*9,p/10);
		}
		else{
			a[i] = '0';
			b[i] = '9';
			return get(a,b,i+1,cur - p*9,p/10);
		}
	}
	else if(a[i]!='?' && b[i]!='?'){
		return get(a,b,i+1,cur + (a[i]-b[i])*p, p/10);
	}
	else if(a[i]=='?'){
		if(cur<0){
			a[i] = '9';
		}
		else if(cur>0){
			a[i] = '0';
		}
		else{
			a[i] = b[i];
			pair<int,pair<string,string> > a1 = get(a,b,i+1,0,p/10);
			pair<int,pair<string,string> > a2,a3;
			a3.first = INT_MAX;
			a2.first = INT_MAX;
			if(b[i]!='0'){
				a[i] = b[i]-1;
				a2 = get(a,b,i+1,-p,p/10);
			}
			if(b[i]!='9'){
				a[i] = b[i]+1;
				a3 = get(a,b,i+1,p,p/10);
			}
			if(a2.first <= a1.first && a2.first <=a3.first) return a2;
			if(a1.first <= a2.first && a1.first <=a3.first) return a1;
			return a3;
		}
		return get(a,b,i+1, cur + p*(a[i]-b[i]),p/10);
	}
	else{
		if(cur>0){
			b[i] = '9';
		}
		else if(cur<0){
			b[i] = '0';
		}
		else{
			b[i] = a[i];
			pair<int,pair<string,string> > a1 = get(a,b,i+1,0,p/10);
			pair<int,pair<string,string> > a2,a3;
			a3.first = INT_MAX;
			a2.first = INT_MAX;
			if(a[i]!='0'){
				b[i] = a[i]-1;
				a2 = get(a,b,i+1,p,p/10);
			}
			if(a[i]!='9'){
				b[i] = a[i]+1;
				a3 = get(a,b,i+1,-p,p/10);
			}
			if(a2.first <= a1.first && a2.first <=a3.first) return a2;
			if(a1.first <= a2.first && a1.first <=a3.first) return a1;
			return a3;
		}
		return get(a,b,i+1, cur + p*(a[i]-b[i]),p/10);
	}
}
signed main() {
	freopen("a.txt","r",stdin);
	freopen("out.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	for(int t=1;t<=tt;t++){
		cout << "Case #" << t << ": ";
		string a,b;
		cin >> a >> b;
		n = a.length();
		int c = 1LL;
		for(int i=0;i<n-1;i++) c *= 10;
		pair<int,pair<string,string> > p = get(a,b,0,0,c);
		cout << p.second.first << " " << p.second.second << "\n";
	}
    return 0;
}
