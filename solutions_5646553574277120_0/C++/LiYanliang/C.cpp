#include <iostream>

using namespace std;

int q[35], c, d, v;;
bool val[35];

void qwe(int pos, int vcur){
	if (pos == d){
		if (vcur < 35){
			val[vcur] = true;
		}
		return;
	}
	qwe(pos + 1, vcur + q[pos]);
	qwe(pos + 1, vcur);
}

int main(){
	int T;
	cin >> T;
	for (int k = 1; k <= T; k++){
		cin >> c >> d >> v;
		for (int i = 0; i <= v; i++) val[i] = false;
		for (int i = 0; i < d; i++){
			cin >> q[i];
			val[q[i]] = true;
		}
		qwe(0, 0);
		int cou = 0;
		for (int i = 1; i <= v; i++){
			if (!val[i]){
				val[i] = true;
				q[d] = i;
				cou++;
				d++;
				qwe(0, 0);
			}
		}
		cout << "Case #" << k << ": " << cou << endl;
	}
	
	return 0;
}
