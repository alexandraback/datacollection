#include <iostream>
#include <map>

using namespace std;

int main(){
	map<int, map<int, int> > MUL;
	MUL[1][-1] = MUL[-1][1] = -(MUL[1][1] = MUL[-1][-1] = 1);
	MUL[1][-'i'] = MUL[-1]['i'] = -(MUL[1]['i'] = MUL[-1][-'i'] = 'i');
	MUL[1][-'j'] = MUL[-1]['j'] = -(MUL[1]['j'] = MUL[-1][-'j'] = 'j');
	MUL[1][-'k'] = MUL[-1]['k'] = -(MUL[1]['k'] = MUL[-1][-'k'] = 'k');
	
	MUL['i'][-1] = MUL[-'i'][1] = -(MUL['i'][1] = MUL[-'i'][-1] = 'i');
	MUL['i'][-'i'] = MUL[-'i']['i'] = -(MUL['i']['i'] = MUL[-'i'][-'i'] = -1);
	MUL['i'][-'j'] = MUL[-'i']['j'] = -(MUL['i']['j'] = MUL[-'i'][-'j'] = 'k');
	MUL['i'][-'k'] = MUL[-'i']['k'] = -(MUL['i']['k'] = MUL[-'i'][-'k'] = -'j');
	
	MUL['j'][-1] = MUL[-'j'][1] = -(MUL['j'][1] = MUL[-'j'][-1] = 'j');
	MUL['j'][-'i'] = MUL[-'j']['i'] = -(MUL['j']['i'] = MUL[-'j'][-'i'] = -'k');
	MUL['j'][-'j'] = MUL[-'j']['j'] = -(MUL['j']['j'] = MUL[-'j'][-'j'] = -1);
	MUL['j'][-'k'] = MUL[-'j']['k'] = -(MUL['j']['k'] = MUL[-'j'][-'k'] = 'i');
	
	MUL['k'][-1] = MUL[-'k'][1] = -(MUL['k'][1] = MUL[-'k'][-1] = 'k');
	MUL['k'][-'i'] = MUL[-'k']['i'] = -(MUL['k']['i'] = MUL[-'k'][-'i'] = 'j');
	MUL['k'][-'j'] = MUL[-'k']['j'] = -(MUL['k']['j'] = MUL[-'k'][-'j'] = -'i');
	MUL['k'][-'k'] = MUL[-'k']['k'] = -(MUL['k']['k'] = MUL[-'k'][-'k'] = -1);
	
	int n;
	cin >> n;
	for (int k = 1; k <= n; k++){
		int a;
		cin >> a;
		string NUM;
		cin >> NUM;
		int num, len;
		len = NUM.length();
		if (len == 1) num = NUM[0] - '0';
		else num = NUM[len - 1] - '0' + (NUM[len - 2] - '0') * 10;
		string L;
		cin >> L;
		int mul = 1;
		for (int i = 0; i < a; i++){
			mul = MUL[mul][L[i]];
		}
		int allmul = 1;
		for (int i = 0; i < num; i++){
			allmul = MUL[allmul][mul];
		}
		if (allmul != -1){
			cout << "Case #" << k << ": NO" << endl;
			continue;
		}
		int loop, cur = 1, pos, posi, posk;
		bool findi = false, findk = false;
		for (loop = 0; loop <= 4; loop++){
			for (pos = 0; pos < a; pos++){
				cur = MUL[cur][L[pos]];
				if (cur == 'i'){
					findi = true;
					break;
				}
			}
			if (findi) break;
		}
		posi = loop * a + pos + 1;
		cur = 1;
		for (loop = 0; loop <= 4; loop++){
			for (pos = a - 1; pos >= 0; pos--){
				cur = MUL[L[pos]][cur];
				if (cur == 'k'){
					findk = true;
					break;
				}
			}
			if (findk) break;
		}
		posk = loop * a + a - pos;
		if (!findi || !findk){
			cout << "Case #" << k << ": NO" << endl;
			continue;
		}
		int len_L;
		if (len == 1 || NUM == "10") {
			len_L = num * a;
			if (len_L > posi + posk){
				cout << "Case #" << k << ": YES" << endl;
			}
			else cout << "Case #" << k << ": NO" << endl;
		}
		else{
			cout << "Case #" << k << ": YES" << endl;
		}
	}
	
	return 0;
} 
