// Anve$hi $hukla
#include <bits/stdc++.h>
using namespace std;
struct ${$(){ios_base::sync_with_stdio(false);cin.tie(NULL);}}$;

typedef long long LL;
const int Maxn = 200005;

template <class T> string toStr(const T &x){ 
  stringstream s;
  s << x; 
  return s.str(); 
}
template <class T> int toInt(const T &x){ 
  stringstream s; 
  s << x; 
  int r; 
  s >> r; 
  return r; 
}

int main() {
	int t;
	cin >> t;
	string Ans1, Ans2;
	for(int tt = 1; tt <= t; tt++) {
		Ans1 = "99999", Ans2 = "99999";
		string s1, s2;
		cin >> s1 >> s2;
		int n = s1.length();

		vector < pair <int, char> > v1, v2;
		v1.clear(), v2.clear();

		for(int i = 0; i < n; i++) {
			if(s1[i]!='?'){
				v1.push_back({i,s1[i]});
			}
			if(s2[i]!='?'){
				v2.push_back({i, s2[i]});
			}
		}

		vector <string> t1, t2;
		for(int i = 0; i < (pow(10, n)); i++) {
			string temp = toStr(i);
			while(temp.length() != n)
				temp = '0' + temp;
			t1.push_back(temp);
			t2.push_back(temp);
		}

		int Ans = 1000000;
		Ans1 = "", Ans2 = "";

		for(int i = 0; i < t1.size(); i++) {
			for(int j = 0; j < t2.size(); j++) {
				string temp1 = t1[i], temp2 = t2[j];
				
				int a1 = toInt(temp1);
				int a2 = toInt(temp2);
				
				if(abs(a1 - a2) > Ans)
					continue;

				bool ok = true;
				for(int k = 0; k < v1.size(); k++) {
					if(temp1[v1[k].first]!= v1[k].second){
						ok =  false;
						break;
					}
					break;
				}
				for(int k = 0; k < v2.size(); k++) {
					if(temp2[v2[k].first]!= v2[k].second){
						ok =  false;
						break;
					}
				}
				if(ok){
					if(abs(a1 - a2) < Ans){
						Ans = abs( a1 - a2);
						Ans1 = temp1, Ans2 = temp2;
					}
					else if(abs(a1 - a2) == Ans){

						pair <string, string> p1, p2;
						p1 = { Ans1, Ans2};
						p2 = {temp1, temp2};
						if(p1 > p2){
							Ans1 = p2.first;
							Ans2 = p2.second;
						}
					}

				}
			}
		}
		cout << "Case #" << tt << ": " << Ans1 << " " << Ans2 << endl;
	}

	return 0;
}
