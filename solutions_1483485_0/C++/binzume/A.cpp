#include <iostream>
#include <string>
using namespace std;


int main() {
	int N;
	string g;
	cin >> N;
	
	char map[128] = {0};
	string gg = "qz ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
	string en = "zq our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
	
	for (int i = 0;i < gg.size(); i++) {
		map[gg[i]] = en[i];
	}
	
	for (int i = 'a' ; i <= 'z' ; i++) {
		if (map[i] == 0) {
			cerr << "NOT FOUND " << (char)i << endl;
		} else {
			// cerr << map[i] << endl;
		}
	}
	
	
	cin.get(); // skip LF
	for (int i = 0; i< N; i++) {
		char g_[1024];
		cin.getline(g_,sizeof(g_));
		g = g_;
		
		string ans;
		for (int j=0; j < g.size(); j++) {
			ans.push_back(map[g[j]]);
		}


		cout << "Case #" << (i+1) << ": " << ans << endl;
	}
	
	
	return 0;
}


