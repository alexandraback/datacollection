#include<iostream>
#include<string>
#include<algorithm>
#define f first
#define s second
#define mp make_pair
using namespace std;

string choice[2] = {"09", "90"};

pair<string, pair<string, string> > generate(string &c, string &j, string curc, string curj, bool maximize) {
	pair<string, pair<string, string> > ret;
	ret.s = mp(curc, curj);
	
	for(size_t i=curc.length(); i < c.size();i++) {
		
		if(c[i] == '?')
			ret.s.f.push_back(choice[0][maximize]);
		else
			ret.s.f.push_back(c[i]);
			
		if(j[i] == '?')
			ret.s.s.push_back(choice[1][maximize]);
		else
			ret.s.s.push_back(j[i]);
	}
	
	//Finally generate the difference string
	for(size_t i=0;i<c.size();i++) {
		ret.f.push_back(ret.s.f[i] - ret.s.s[i]);
		if(maximize)
			ret.f.back() *= -1;
		
		for(size_t j=i;j>0 && ret.f[j] < 0; j--) {
			ret.f[j] += 10;
			ret.f[j-1]--;
		}
	}
	
	return ret;
}





int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	for(int TCASE = 1; TCASE <= T; TCASE++) {
		string c, j;
		cin >> c >> j;
		
		//Now make the choices for the letters
		pair<string, pair<string, string> > ret;
		ret.f = string(c.size(), 11);
		
		string current;
		
		for(size_t i=0;i<c.size();i++) {
			
			if(c[i] == '?' && j[i] == '?') {
				ret = min(ret, generate(c, j, current + "0", current + "1", true) );
				ret = min(ret, generate(c, j, current + "1", current + "0", false) );
				current += "0";
			}
			
			else if(c[i] == '?') {
				if('0' < j[i])
					ret = min(ret, generate(c, j, current + string(1, j[i]-1), current + string(1, j[i]), true) );
				if('9' > j[i])
					ret = min(ret, generate(c, j, current + string(1, j[i]+1), current + string(1, j[i]), false) );
				current.push_back(j[i]);
			}
			
			else if(j[i] == '?') {
				if(c[i] < '9')
					ret = min(ret, generate(c, j, current + string(1, c[i]), current + string(1, c[i]+1), true) );
				if(c[i] > '0')
					ret = min(ret, generate(c, j, current + string(1, c[i]), current + string(1, c[i]-1), false) );
				current.push_back(c[i]);
			}
			
			else {
				if(c[i] == j[i]) {
					current.push_back(c[i]);
					continue;
				}
				
				if(c[i] < j[i])
					ret = min(ret, generate(c, j, current + string(1, c[i]), current + string(1, j[i]), true) );
				if(c[i] > j[i])
					ret = min(ret, generate(c, j, current + string(1, c[i]), current + string(1, j[i]), false) );
				break;
			}
			
		}
		
		if(current.size() == c.size())
			ret = min(ret, mp(string(c.size(), 0), mp(current, current) ) );
			
		cout << "Case #" << TCASE << ": " << ret.s.f << ' ' << ret.s.s << '\n';
	}
	
	return 0;
}







































