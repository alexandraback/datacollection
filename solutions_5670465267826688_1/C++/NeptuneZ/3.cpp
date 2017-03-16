#include<iostream>
#define A 0
#define I 1
#define J 2
#define K 3
#define _A 4
#define _I 5
#define _J 6
#define _K 7
using namespace std;

int runtime;
long long n, x;
string str;
int map[8][8] = {{A, I, J, K, _A, _I, _J, _K},
                 {I, _A, K, _J, _I, A, _K, J},
				 {J, _K, _A, I, _J, K, A, _I},
				 {K, J, _I, _A, _K, _J, I, A},
				 {_A, _I, _J, _K, A, I, J, K},
                 {_I, A, _K, J, I, _A, K, _J},
				 {_J, K, A, _I, J, _K, _A, I},
				 {_K, _J, I, A, K, J, _I, _A}};

int calc(string arg){
	int init = arg[0] - '0';
	for (int i = 1; i < arg.length(); i++)
		init = map[init][arg[i] - '0'];
	return init;
}

string find_ch(string arg, int ch){
	if (arg == ""){
		if (x == 0) return "NO";
		arg = str;
		x--;
	}
	int count = 0;
	int init = arg[0] - '0', pt = 1;
	if (init == ch){
		if (pt >= arg.length()) return "";
		return arg.substr(pt, arg.length());
	}
	while (init != ch){
		if (pt == arg.length()){
			if (x == 0) return "NO";
			if (count == 4) return "NO";
			arg = str;
			x--;
			count++;
			pt = 0;
		}
		//cout << arg << " " << pt << endl;
		//cout << init << " -> ";
		init = map[init][arg[pt] - '0'];
		//cout << init << endl;
		pt++;
	}
	if (pt >= arg.length()) return "";
	return arg.substr(pt, arg.length());
}

int main(){
//	freopen("3.in", "r", stdin);
//	freopen("3.out", "w", stdout);
	cin >> runtime;
	for (int run = 1; run <= runtime; run++){
		cin >> n >> x;
		cin >> str;
		for (int i = 0; i < str.length(); i++)
			if (str[i] == 'i') str[i] = '1';
			else if (str[i] == 'j') str[i] = '2';
			else if (str[i] == 'k') str[i] = '3';
		
		bool flag = false;
		string loc;
		if ((loc = find_ch("", I)) != "NO"){
			//cout << "find I: " << loc << endl;
			if ((loc = find_ch(loc, J)) != "NO"){
				//cout << "find J: " << loc << endl;
				if ((loc = find_ch(loc, K)) != "NO"){
					//cout << "find K: " << loc << endl;
					x %= 4;
					string temp = loc;
					for (int i = 0; i < x; i++) temp += str;
					if (temp != ""){
						int init = temp[0] - '0';
						for (int i = 1; i < temp.length(); i++)
							init = map[init][temp[i] - '0'];
						if (init == A) flag = true;
					}
					else flag = true;
				}
			}
		}
		
		if (flag) cout << "Case #" << run << ": " << "YES" << endl;
		else cout << "Case #" << run << ": " << "NO" << endl;
	}
}
