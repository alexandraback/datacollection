#include <bits/stdc++.h>
using namespace std;

int T, TC = 1;
string C, J;
pair<int, pair<string, string> > small(int x, int y, string sc, string sj){
	if(x >= (int)C.size()){
		int haha = 0, lala = 0;
		for(int i = 0; i < (int)sc.size(); i++){
			haha = haha*10+(sc[i]-'0');
			lala = lala*10+(sj[i]-'0');
		}
		return make_pair(abs(haha-lala), make_pair(sc, sj));
	}
	pair<int, pair<string, string> > ret = make_pair(2123123123, make_pair("99999999999999999999999999999999", "99999999999999999999999999999999"));
	if(y == 0){
		if(C[x] == '?' && J[x] != '?'){
			if(J[x]-1 >= '0'){
				string next_c = sc, next_j = sj;
				next_c.push_back(J[x]-1);
				next_j.push_back(J[x]);
				pair< int, pair<string, string> > cari = small(x+1, -1, next_c, next_j);
				if(cari.first < ret.first) ret = cari;
				else if(cari.first == ret.first){
					if(cari.second.first < ret.second.first) ret = cari;
					else if(cari.second.first == ret.second.first){
						if(cari.second.second < ret.second.second) ret = cari;
					}
				}
			}
			if(J[x]+1 <= '9'){
				string next_c = sc, next_j = sj;
				next_c.push_back(J[x]+1);
				next_j.push_back(J[x]);
				pair< int, pair<string, string> > cari = small(x+1, 1, next_c, next_j);
				if(cari.first < ret.first) ret = cari;
				else if(cari.first == ret.first){
					if(cari.second.first < ret.second.first) ret = cari;
					else if(cari.second.first == ret.second.first){
						if(cari.second.second < ret.second.second) ret = cari;
					}
				}
			}
			{
				string next_c = sc, next_j = sj;
				next_c.push_back(J[x]);
				next_j.push_back(J[x]);
				pair< int, pair<string, string> > cari = small(x+1, 0, next_c, next_j);
				if(cari.first < ret.first) ret = cari;
				else if(cari.first == ret.first){
					if(cari.second.first < ret.second.first) ret = cari;
					else if(cari.second.first == ret.second.first){
						if(cari.second.second < ret.second.second) ret = cari;
					}
				}
			}
		}
		else if(C[x] != '?' && J[x] == '?'){
			if(C[x]-1 >= '0'){
				string next_c = sc, next_j = sj;
				next_c.push_back(C[x]);
				next_j.push_back(C[x]-1);
				pair< int, pair<string, string> > cari = small(x+1, 1, next_c, next_j);
				if(cari.first < ret.first) ret = cari;
				else if(cari.first == ret.first){
					if(cari.second.first < ret.second.first) ret = cari;
					else if(cari.second.first == ret.second.first){
						if(cari.second.second < ret.second.second) ret = cari;
					}
				}
			}
			if(C[x]+1 <= '9'){
				string next_c = sc, next_j = sj;
				next_c.push_back(C[x]);
				next_j.push_back(C[x]+1);
				pair< int, pair<string, string> > cari = small(x+1, -1, next_c, next_j);
				if(cari.first < ret.first) ret = cari;
				else if(cari.first == ret.first){
					if(cari.second.first < ret.second.first) ret = cari;
					else if(cari.second.first == ret.second.first){
						if(cari.second.second < ret.second.second) ret = cari;
					}
				}
			}
			{
				string next_c = sc, next_j = sj;
				next_c.push_back(C[x]);
				next_j.push_back(C[x]);
				pair< int, pair<string, string> > cari = small(x+1, 0, next_c, next_j);
				if(cari.first < ret.first) ret = cari;
				else if(cari.first == ret.first){
					if(cari.second.first < ret.second.first) ret = cari;
					else if(cari.second.first == ret.second.first){
						if(cari.second.second < ret.second.second) ret = cari;
					}
				}
			}
		}
		else if(C[x] == '?' && J[x] == '?'){
			{
				string next_c = sc, next_j = sj;
				next_c.push_back('0');
				next_j.push_back('1');
				pair< int, pair<string, string> > cari = small(x+1, -1, next_c, next_j);
				if(cari.first < ret.first) ret = cari;
				else if(cari.first == ret.first){
					if(cari.second.first < ret.second.first) ret = cari;
					else if(cari.second.first == ret.second.first){
						if(cari.second.second < ret.second.second) ret = cari;
					}
				}
			}
			{
				string next_c = sc, next_j = sj;
				next_c.push_back('1');
				next_j.push_back('0');
				pair< int, pair<string, string> > cari = small(x+1, 1, next_c, next_j);
				if(cari.first < ret.first) ret = cari;
				else if(cari.first == ret.first){
					if(cari.second.first < ret.second.first) ret = cari;
					else if(cari.second.first == ret.second.first){
						if(cari.second.second < ret.second.second) ret = cari;
					}
				}
			}
			{
				string next_c = sc, next_j = sj;
				next_c.push_back('0');
				next_j.push_back('0');
				pair< int, pair<string, string> > cari = small(x+1, y, next_c, next_j);
				if(cari.first < ret.first) ret = cari;
				else if(cari.first == ret.first){
					if(cari.second.first < ret.second.first) ret = cari;
					else if(cari.second.first == ret.second.first){
						if(cari.second.second < ret.second.second) ret = cari;
					}
				}
			}
		}
		else if(C[x] < J[x]){
			string next_c = sc, next_j = sj;
			next_c.push_back(C[x]);
			next_j.push_back(J[x]);
			pair< int, pair<string, string> > cari = small(x+1, -1, next_c, next_j);
			if(cari.first < ret.first) ret = cari;
			else if(cari.first == ret.first){
				if(cari.second.first < ret.second.first) ret = cari;
				else if(cari.second.first == ret.second.first){
					if(cari.second.second < ret.second.second) ret = cari;
				}
			}
		}
		else if(C[x] > J[x]){
			string next_c = sc, next_j = sj;
			next_c.push_back(C[x]);
			next_j.push_back(J[x]);
			pair< int, pair<string, string> > cari = small(x+1, 1, next_c, next_j);
			if(cari.first < ret.first) ret = cari;
			else if(cari.first == ret.first){
				if(cari.second.first < ret.second.first) ret = cari;
				else if(cari.second.first == ret.second.first){
					if(cari.second.second < ret.second.second) ret = cari;
				}
			}
		}else{
			string next_c = sc, next_j = sj;
			next_c.push_back(C[x]);
			next_j.push_back(J[x]);
			pair< int, pair<string, string> > cari = small(x+1, y, next_c, next_j);
			if(cari.first < ret.first) ret = cari;
			else if(cari.first == ret.first){
				if(cari.second.first < ret.second.first) ret = cari;
				else if(cari.second.first == ret.second.first){
					if(cari.second.second < ret.second.second) ret = cari;
				}
			}
		}
	}
	else if(y == -1){
		string next_c = sc, next_j = sj;
		if(C[x] == '?') next_c.push_back('9');
		else next_c.push_back(C[x]);
		if(J[x] == '?') next_j.push_back('0');
		else next_j.push_back(J[x]);
		pair< int, pair<string, string> > cari = small(x+1, -1, next_c, next_j);
		if(cari.first < ret.first) ret = cari;
		else if(cari.first == ret.first){
			if(cari.second.first < ret.second.first) ret = cari;
			else if(cari.second.first == ret.second.first){
				if(cari.second.second < ret.second.second) ret = cari;
			}
		}
	}
	else if(y == 1){
		string next_c = sc, next_j = sj;
		if(C[x] == '?') next_c.push_back('0');
		else next_c.push_back(C[x]);
		if(J[x] == '?') next_j.push_back('9');
		else next_j.push_back(J[x]);
		pair< int, pair<string, string> > cari = small(x+1, 1, next_c, next_j);
		if(cari.first < ret.first) ret = cari;
		else if(cari.first == ret.first){
			if(cari.second.first < ret.second.first) ret = cari;
			else if(cari.second.first == ret.second.first){
				if(cari.second.second < ret.second.second) ret = cari;
			}
		}
	}
	return ret;
}
int main(){
	freopen("B-large.in", "r", stdin);
	freopen("outputtestest.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		cin >> C >> J;
		pair< int, pair<string, string> > ans = small(0, 0, "", "");
//		cout << ans.first << " " << ans.second.first << " " << ans.second.second << endl;
		printf("Case #%d: ", TC++);
		cout << ans.second.first << " " << ans.second.second << endl;
	}
	return 0;
}
