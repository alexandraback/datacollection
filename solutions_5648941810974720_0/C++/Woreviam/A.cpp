
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)
#define cout2(x, y) cout << x << " " << y << endl
#define N 100005

using namespace std;

int frec[26];
char s[N];

int main(){
	
	int tc = 0, caso = 1;
	scanf("%d", &tc);
	
	while(tc--){
		
		scanf("%s", s);
		int n = strlen(s);
		
		memset(frec, 0, sizeof frec);
		
		vector<int>ans;
		for(int i = 0; i < n; i++)frec[s[i] - 'A']++;
		
		if(frec['G' - 'A'] > 0){
			
			for(int i = 0; i < frec['G' - 'A']; i++)ans.pb(8);
			frec['E' - 'A'] -= frec['G' - 'A'];
			frec['I' - 'A'] -= frec['G' - 'A'];
			frec['H' - 'A'] -= frec['G' - 'A'];
			frec['T' - 'A'] -= frec['G' - 'A'];
			frec['G' - 'A'] = 0;
		}
			
		if(frec['X' - 'A'] > 0){
			
			for(int i = 0; i < frec['X' - 'A']; i++)ans.pb(6);
			frec['S' - 'A'] -= frec['X' - 'A'];
			frec['I' - 'A'] -= frec['X' - 'A'];
			frec['X' - 'A'] = 0;
		}		
		
		if(frec['W' - 'A'] > 0){
			
			for(int i = 0; i < frec['W' - 'A']; i++)ans.pb(2);
			frec['T' - 'A'] -= frec['W' - 'A'];
			frec['O' - 'A'] -= frec['W' - 'A'];
			frec['W' - 'A'] = 0;
		}
		
		if(frec['U' - 'A'] > 0){
			
			for(int i = 0; i < frec['U' - 'A']; i++)ans.pb(4);
			frec['F' - 'A'] -= frec['U' - 'A'];
			frec['O' - 'A'] -= frec['U' - 'A'];
			frec['R' - 'A'] -= frec['U' - 'A'];
			frec['U' - 'A'] = 0;
		}
		
		if(frec['Z' - 'A'] > 0){
			
			for(int i = 0; i < frec['Z' - 'A']; i++)ans.pb(0);
			frec['E' - 'A'] -= frec['Z' - 'A'];
			frec['R' - 'A'] -= frec['Z' - 'A'];
			frec['O' - 'A'] -= frec['Z' - 'A'];
			frec['Z' - 'A'] = 0;
		}
		
		if(frec['T' - 'A'] > 0){
			
			for(int i = 0; i < frec['T' - 'A']; i++)ans.pb(3);
			frec['H' - 'A'] -= frec['T' - 'A'];
			frec['R' - 'A'] -= frec['T' - 'A'];
			frec['E' - 'A'] -= 2 * frec['T' - 'A'];
			frec['T' - 'A'] = 0;
		}
		
		if(frec['O' - 'A'] > 0){
			
			for(int i = 0; i < frec['O' - 'A']; i++)ans.pb(1);
			frec['N' - 'A'] -= frec['O' - 'A'];
			frec['E' - 'A'] -= frec['O' - 'A'];
			frec['O' - 'A'] = 0;
		}
		if(frec['F' - 'A'] > 0){
			
			for(int i = 0; i < frec['F' - 'A']; i++)ans.pb(5);
			frec['I' - 'A'] -= frec['F' - 'A'];
			frec['V' - 'A'] -= frec['F' - 'A'];
			frec['E' - 'A'] -= frec['F' - 'A'];
			frec['F' - 'A'] = 0;
		}
		if(frec['S' - 'A'] > 0){
			
			for(int i = 0; i < frec['S' - 'A']; i++)ans.pb(7);
			frec['E' - 'A'] -= frec['S' - 'A'];
			frec['V' - 'A'] -= frec['S' - 'A'];
			frec['E' - 'A'] -= frec['S' - 'A'];
			frec['N' - 'A'] -= frec['S' - 'A'];
			frec['S' - 'A'] = 0;
		}
		if(frec['E' - 'A'] > 0){
			
			for(int i = 0; i < frec['E' - 'A']; i++)ans.pb(9);
		}
		
		sort(all(ans));
		printf("Case #%d: ", caso++);
		
		for(int i = 0; i < ans.size(); i++)putchar(char(ans[i] + '0'));
		puts("");
	}

}

