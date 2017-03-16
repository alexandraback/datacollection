#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int k, l, s, lenk, lenl, take;
string kk, ll;
vector<int> cor;

void test(string cur){
	int ans = 0;
	for (int i = 0; i <= s - l; i++){
		for (int j = 0; j < l; j++){
			if (cur[i + j] != ll[j]) break;
			if (j == l - 1) ans++;
		}
	}
	cor.push_back(ans);
	take = max(take, ans);
}

void qwe(string cur, int pos){
	if (pos == s){
		test(cur);
		return;
	}
	pos++;
	for (int i = 0; i < lenk; i++)
		qwe(cur + kk[i], pos);
}

int main(){
	cout << setiosflags(ios::fixed) << setprecision(6);
	int T;
	cin >> T;
	for (int K = 1; K <= T; K++){
		cin >> k >> l >> s;
		cin >> kk >> ll;
		lenk = kk.length();
		lenl = ll.length();
		take = 0;
		cor.clear();
		qwe("", 0);
		double corr = 0, num = cor.size();
		for (int i = 0; i < num; i++) corr += take - cor[i];
		corr = corr / num;
		cout << "Case #" << K << ": " << corr << endl;
	}
	
	return 0;
}
