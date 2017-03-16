#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <utility>
#include <cmath>

#define M 1000000007

#define FOR(i,n) for(long long i = 0, _n = (n); i < _n; i++)

using namespace std;

vector<long long> fact(1000);

//template <typename T> void updatemax(T &a, T b) { if(b>a) a = b;}
//template <typename T> void updatemin(T &a, T b) { if(b<a) a = b;}

string reduce(string s){
	string ss;
	ss += s[0];
	FOR(i, s.length()){
		if(s[i] != ss[ss.length()-1]) ss += s[i];
	}
	return ss;
}

int check(vector<string> a){
	FOR(i, a.size()){
		string s = reduce(a[i]);
		sort(s.begin(), s.end());
		
		if(s.compare(reduce(s)) != 0) return false;
		
		s = reduce(a[i]);
		if(s.length() > 2)
			for(int k = 2; k < s.length()-1; k++)
				FOR(j, a.size()) if(j!=i)
					FOR(l, a[j].length())
						if(s[k] == a[j][l]) 
							return false;
							
		if(s.length() > 1){
			FOR(j, a.size()) if(j!=i)
				FOR(l, a[j].length()-1)
					if(s[0] == a[j][l] || s[s.length()-1] == a[j][l+1]) 
						return false;			
		}
	}
	
	return true;
}


int find_parent(vector<int> &pre, vector<int> &visit, char c){
	if(visit[c]==1) return pre[c];
	if(visit[c]==2) return -2;
	
	visit[c] = 2;
	if(pre[c] == -1) pre[c] = c;
	else{
		//cout<<"** "<<char(c+'a')<<" "<<char(pre[c]+'a')<<visit[pre[c]]<<endl;
		if(visit[pre[c]] == 2) pre[c] = -2;
		else pre[c] = find_parent(pre, visit, pre[c]);
		//cout<<"** "<<char(c+'a')<<" "<<pre[c]<<visit[pre[c]]<<endl;
	}
	visit[c] = 1;
	return pre[c];
}


int process(vector<string> a){
	if(!check(a)) return 0;
	
	//FOR(i, a.size()) cout<<a[i]<<" "; cout<<endl;
	
	vector<int> pre(30, -1), own(30);
	vector<int> visit(30, false);

	FOR(i, a.size())
		if(a[i][0] == a[i][a[i].length()-1]) own[a[i][0]-'a']++;
		else{
			if(pre[a[i][a[i].length()-1]-'a'] >= 0) return 0;
			else pre[a[i][a[i].length()-1]-'a'] = a[i][0] - 'a';
		}
		
	//FOR(c, 26) cout<<own[c]<<" "; cout<<endl;
	//FOR(c, 26) if(pre[c] != -1) cout<<"pre_"<<char(c+'a')<<" = "<<pre[c]<<" "; cout<<endl;
		
	vector<int> parent(pre);
	FOR(c, 26) if(pre[c] != -1) if(find_parent(parent, visit, c)==-2) return 0;
	
	FOR(c, 26) if(pre[c] == -2) return 0;
	vector<long> count(30,0);
	
	FOR(c, 26){
		if(parent[c] != -1) {
			if(count[parent[c]] == 0) count[parent[c]] = 1;
			if(own[c] >= 1){
				count[parent[c]] = (fact[own[c]]*count[parent[c]]) % M;
				own[c] = 0;
			}
		}
	}

	//FOR(c, 26) if(parent[c] >= 0) cout<<char(c+'a')<<char(parent[c]+'a')<<" "; cout<<endl;	
	//FOR(c, 26) if(count[c] > 0) cout<<char(c+'a')<<count[c]<<" "; cout<<endl;
	//FOR(c, 26) if(own[c] > 0) cout<<char(c+'a')<<own[c]<<" "; cout<<endl;

	int n = 0;
	FOR(c, 26) if(count[c] > 0) n++;
	FOR(c, 26) if(own[c] > 0) n++;
	
	//cout<<"n = "<<n<<endl;
	
	long long prod = fact[n];
	FOR(c, 26) if(count[c] > 0) prod = (prod*count[c]) % M;
	FOR(c, 26) if(own[c] > 0) prod = (prod*fact[own[c]]) % M;
	
	return prod;
}

int main(){
	fact[0] = 1;
	fact[1] = 1;
	for(int i = 2; i < 1000; i++) fact[i] = (fact[i-1]*i)%M;
	
	int T, N;
	cin>>T;
	
	FOR(caseno, T){
		cin>>N;
		vector<string> a(N);
		FOR(i, N) cin>>a[i];
		FOR(i, N) a[i] = reduce(a[i]);
		
		cout<<"Case #"<<caseno+1<<": "<<process(a)<<endl;
	}
	
	return 0;
}