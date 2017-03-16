#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

#define MOD 1000000007l

int a[50];
int o[50];
int m[50];

int g[26][26];
int p[26];
int pcc[26];

int f[27];

void fill(int i, int pc){
	//cerr << "c " << i << " " << pc << endl;
	p[i] = pc;
	for(int j=0; j<26; ++j){
		if((g[i][j] || g[j][i]) && p[j] == -1)
			fill(j, pc);
	}
}

int main(){
	f[1] = 1;
	for(int i=2; i<=26; ++i){
		f[i] = (f[i-1] * i) % MOD;
	}
	int tcs;
	scanf("%d", &tcs);
	for(int tc=1; tc<=tcs; ++tc){
		printf("Case #%d: ", tc);
		memset(a, 0, sizeof(a));
		memset(o, 0, sizeof(o));
		memset(m, 0, sizeof(m));
		memset(g, 0, sizeof(g));
		memset(p, -1, sizeof(p));
		int n;
		cin >> n;
		for(int i=0; i<n; ++i){
			string s;
			cin >> s;
			a[s[0]-'a']++;
			o[s[s.size()-1]-'a']++;
			g[s[0]-'a'][s[s.size()-1]-'a'] += 1;
			//cerr << (s[0]-'a') << " -> " << (s[s.size()-1]-'a') << endl;
			for(int j=1; j<s.size()-1; ++j){
				if(s[j] != s[j-1] && s[j] != s[j+1])
					m[s[j]-'a']++;
			}
		}
		bool ok = true;
		for(int i=0; i<26; ++i){
			if(m[i] > 1 || (m[i] == 1 && (a[i] > 0 || o[i] > 0)))
				ok = false;
		}
		if(!ok){
			puts("0");
			continue;
		}
		int pc = 0;
		for(int i=0; i<26; ++i){
			if(a[i] == 0 && o[i] == 0)
				continue;
			if(p[i] == -1)
				fill(i, pc++);
		}
		long long r = 1;
		//cerr << "pc " << pc << endl;
		for(int i=0; i<pc && r; ++i){
			r = (r * (i+1)) % MOD;
			int ap = -1;
			int op = -1;
			int co = 0;
			for(int j=0; j<26; ++j){
				if(p[j] != i)
					continue;
				if(a[j] == o[j]-1){
					if(ap == -1)
						ap = j;
					else
						r = 0;
				}else if(o[j] == a[j] -1){
					if(op == -1)
						op = j;
					else
						r = 0;
				}else if(o[j] != a[j]){
					r = 0;
				}
				if(o[j] >= 3)
					r = r * f[o[j] - 1] % MOD;
				co += a[j];
			}
			//cerr << "check " << ap << " " << op << " " << co << endl;
			if(ap == -1 && op == -1)
				r = (r * co) % MOD;
			else if(ap == -1 || op == -1)
				r = 0;
		}
		printf("%lld\n", r);
	}
}
