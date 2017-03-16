#include <bits/stdc++.h>
using namespace std;

string arr[1001];
set<string> st1, st2;
set<string>::iterator it;
vector<string> vec, vec2;
vector<string>::iterator vit, ait;

int main(){
	//ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	string a, b, s, x, y;
	long long T, cas, N, i, ans, t, ns;
	char c;
	cin >> T;
	for(cas=1;cas<=T;cas++){
		cin >> N;
		ans=0;
		cin >> noskipws >> c;
		for(i=0;i<N;i++){
			getline(cin, arr[i]);
		}
		sort(arr, arr+N);
		vec.clear();
		st1.clear();
		st2.clear();
		for(i=0;i<N;i++){
			s = arr[i];
			a = s.substr(0, s.find(' '));
			b = s.substr(s.find(' ')+1);
			it = st1.find(a);
			if(it==st1.end()){
				it = st2.find(b);
				if(it==st2.end()){
					st1.insert(a);
					st2.insert(b);
				}
				else{
					vec.push_back(s);
				}
			}
			else{
				vec.push_back(s);
			}
		}
		vec2.clear();
		for(i=0;i<vec.size();i++){
			s = vec[i];
			a = s.substr(0, s.find(' '));
			b = s.substr(s.find(' ')+1);
			it = st1.find(a);
			if(it!=st1.end()){
				it = st2.find(b);
				if(it!=st2.end()){
					ans++;
				}
				else{
					vec2.push_back(s);
				}
			}
			else{
				vec2.push_back(s);
			}
		}
		while(!vec2.empty()){
			ns = 0;
			for(vit=vec2.begin();vit!=vec2.end();vit++){
				t = 0;
				s = *vit;
				a = s.substr(0, s.find(' '));
				b = s.substr(s.find(' ')+1);
				for(i=0;i<vec2.size();i++){
					if(*vit!=vec2[i]){
						s = vec2[i];
						x = s.substr(0, s.find(' '));
						y = s.substr(s.find(' ')+1);
						it = st1.find(x);
						if(it!=st1.end() or x==a){
							it = st2.find(y);
							if(it!=st2.end() or y==b) t++;
						}
					}
				}
				if(t>=ns){
					ns = t;
					ait = vit;
				}
			}
			s = *ait;
			a = s.substr(0, s.find(' '));
			b = s.substr(s.find(' ')+1);
			st1.insert(a);
			st2.insert(b);
			ans += ns;
			vec2.erase(ait);
		}
		cout << "Case #" << cas << ": " << ans << '\n';
	}
	
	return 0;
}
