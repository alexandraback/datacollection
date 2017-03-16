#include <bits/stdc++.h>
using namespace std;

vector<int> v1, v2;

void gen1(string s){
	long long t;
	t = s.find('?');
	if(t==-1) v1.push_back(stoi(s));
	else{
		int i;
		for(i=0;i<10;i++){
			s[t] = '0'+i;
			gen1(s);
		}
	}
}

void gen2(string s){
	long long t;
	t = s.find('?');
	if(t==-1) v2.push_back(stoi(s));
	else{
		int i;
		for(i=0;i<10;i++){
			s[t] = '0'+i;
			gen2(s);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long T, c, d, ans, i, j, cas, t, len;
	string a, b;
	cin >> T;
	for(cas=1;cas<=T;cas++){
		cin >> a >> b;
		v1.clear();
		v2.clear();
		gen1(a);
		gen2(b);
		ans = LLONG_MAX;
		for(i=0;i<v1.size();i++){
			for(j=0;j<v2.size();j++){
				if(abs(v1[i]-v2[j])<ans){
					ans = abs(v1[i]-v2[j]);
					c = v1[i];
					d = v2[j];
				}
				else if(abs(v1[i]-v2[j])==ans){
					if(v1[i]<c){
						c = v1[i];
						d = v2[j];
					}
					else if(v1[i]==c){
						if(v2[j]<d){
							v2[j] = d;
						}
					}
				}
			}
		}
		cout << "Case #" << cas << ": ";
		len = 0;
		t = c;
		if(t!=0){
			while(t){
				len++;
				t /= 10;
			}
		}
		else len=1;
		if(len<a.size()){
			len = a.size()-len;
			while(len--) cout << 0;
		}
		cout << c << ' ';
		len = 0;
		t = d;
		if(t!=0){
			while(t){
				len++;
				t /= 10;
			}
		}
		else len=1;
		if(len<b.size()){
			len = b.size()-len;
			while(len--) cout << 0;
		}
		cout << d << '\n';
		
	}
	return 0;
}
