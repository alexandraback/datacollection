#include <bits/stdc++.h>
using namespace std;

int T, TC = 1;
string C, J;
pair<int, pair<string, string> > small(int x, string sc, string sj){
	if(x >= (int)C.size()){
		int haha = 0, lala = 0;
		for(int i = 0; i < (int)sc.size(); i++){
			haha = haha*10+(sc[i]-'0');
			lala = lala*10+(sj[i]-'0');
		}
		return make_pair(abs(haha-lala), make_pair(sc, sj));
	}
	pair<int, pair<string, string> > ret = make_pair(2123123123, make_pair("999999", "999999"));
	if(C[x] == '?' && J[x] == '?'){
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < 10; j++){
				string next_c = sc, next_j = sj;
				next_c.push_back(i+'0');
				next_j.push_back(j+'0');
				pair< int, pair<string, string> > cari = small(x+1, next_c, next_j);
				if(cari.first < ret.first) ret = cari;
				else if(cari.first == ret.first){
					if(cari.second.first < ret.second.first) ret = cari;
					else if(cari.second.first == ret.second.first){
						if(cari.second.second < ret.second.second) ret = cari;
					}
				}
			}
		}
	}
	else if(C[x] == '?'){
		for(int i = 0; i < 10; i++){
			string next_c = sc, next_j = sj;
			next_c.push_back(i+'0');
			next_j.push_back(J[x]);
			pair< int, pair<string, string> > cari = small(x+1, next_c, next_j);
			if(cari.first < ret.first) ret = cari;
			else if(cari.first == ret.first){
				if(cari.second.first < ret.second.first) ret = cari;
				else if(cari.second.first == ret.second.first){
					if(cari.second.second < ret.second.second) ret = cari;
				}
			}
		}
	}
	else if(J[x] == '?'){
		for(int i = 0; i < 10; i++){
			string next_c = sc, next_j = sj;
			next_c.push_back(C[x]);
			next_j.push_back(i+'0');
			pair< int, pair<string, string> > cari = small(x+1, next_c, next_j);
			if(cari.first < ret.first) ret = cari;
			else if(cari.first == ret.first){
				if(cari.second.first < ret.second.first) ret = cari;
				else if(cari.second.first == ret.second.first){
					if(cari.second.second < ret.second.second) ret = cari;
				}
			}
		}
	}else{
		string next_c = sc, next_j = sj;
		next_c.push_back(C[x]);
		next_j.push_back(J[x]);
		pair<int, pair<string, string> > cari = small(x+1, next_c, next_j);
		ret = cari;
	}
	return ret;
}
int main(){
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		cin >> C >> J;
		pair< int, pair<string, string> > ans = small(0, "", "");
		printf("Case #%d: ", TC++);
		cout << ans.second.first << " " << ans.second.second << endl;
	}
	return 0;
}
