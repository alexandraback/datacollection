#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

struct qua {
	bool sign;
	char c;
	qua() {c='1'; sign=true;};
	qua(char _c, bool _sign = true) :
		c(_c), sign(_sign) {};
		
	qua mult(qua o) {
		qua ret;
		ret.sign = sign;
		if (!o.sign) ret.sign = !ret.sign;
		
		switch(c) {
			case '1':
				switch(o.c) {
					case '1':
						ret.c = '1';
						break;
					case 'i':
						ret.c = 'i';
						break;
					case 'j':
						ret.c = 'j';
						break;
					case 'k':
						ret.c = 'k';
						break;
					default:
						assert(false);
				}
				break;
			case 'i':
				switch(o.c) {
					case '1':
						ret.c = 'i';
						break;
					case 'i':
						ret.c = '1';
						ret.sign = !ret.sign;
						break;
					case 'j':
						ret.c = 'k';
						break;
					case 'k':
						ret.c = 'j';
						ret.sign = !ret.sign;
						break;
					default:
						assert(false);
				}
				break;
			case 'j':
				switch(o.c) {
					case '1':
						ret.c = 'j';
						break;
					case 'i':
						ret.c = 'k';
						ret.sign = !ret.sign;
						break;
					case 'j':
						ret.c = '1';
						ret.sign = !ret.sign;
						break;
					case 'k':
						ret.c = 'i';
						break;
					default:
						assert(false);
				}
				break;
			case 'k':
				switch(o.c) {
					case '1':
						ret.c = 'k';
						break;
					case 'i':
						ret.c = 'j';
						break;
					case 'j':
						ret.c = 'i';
						ret.sign = !ret.sign;
						break;
					case 'k':
						ret.c = '1';
						ret.sign = !ret.sign;
						break;
					default:
						assert(false);
				}
				break;
			default:
				assert(false);
		}
		
		sign = ret.sign;
		c = ret.c;
		return ret;
	}
	
	static qua pow(qua q, int p) {
		qua ret;
		p = p%4;
		
		for (int i=0; i<p; i++) {
			ret.mult(q);
		}
		return ret;
	}
	
	void print() {
		if (!sign) {
			cout << "-";
		}
		cout << c << endl;
	}
};

qua reduce(string in, int p) {
	int index = 0;
	qua ret = qua(in[index++]);
	while (index < in.length()) {
		ret.mult(qua(in[index++]));
	}
	return qua::pow(ret, p);
}

int iPrefixPos(string in) {
	int index = 0;
	qua tar = qua(in[index++]);
	if (tar.c == 'i') return 0;
	while (index < in.length()) {
		tar.mult(qua(in[index]));
		if (tar.c == 'i') return index;
		index++;
	}
	return -1;
}

bool hasKSuffix(int pos, string in) {
	int index = in.length();
	qua tar = qua(in[--index]);
	if (tar.c == 'k') return true;
	while (index-1 > pos) {
		qua dum(in[--index]);
		dum.mult(tar);
		tar.c = dum.c;
		if (tar.c == 'k') return true;
	}
	return false;
}

void formatOutput(int nCase, bool b) {
	string msg = b? "YES": "NO";
	cout << "Case #" << nCase+1 << ": " << msg << endl;
}

void solve(int nCase) {
	int L, X;
	cin >> L >> X;
	
	string input;
	cin >> input;
	
	qua q = reduce(input, X);
	bool isReducible = (!q.sign && q.c=='1');
	if (!isReducible) {
		formatOutput(nCase, false);
		return;
	}
	
	int pos = iPrefixPos(X>1? input+input: input);
	if (pos<0) {
		formatOutput(nCase, false);
		return;
	}
	
	string kInput;
	if (pos<input.length()+1) {
		if (X>2) {
			pos = 0;
			kInput = input + input;
		} else if (X == 2) {
			kInput = input + input;
		} else {
			kInput = input;
		}
	} else {
		if (X>3) {
			pos = 0; 
			kInput = input + input;
		} else if (X == 3) {
			kInput = input + input;
		} else {
			kInput = input;
		}
	}
	if (!hasKSuffix(pos, kInput)) {
		formatOutput(nCase, false);
		return;	
	}
	
	formatOutput(nCase, true);
}

int main() {
	int nCase = 0;
	cin >> nCase;

	for (int i=0; i<nCase; i++) {
		solve(i);
	}
}
