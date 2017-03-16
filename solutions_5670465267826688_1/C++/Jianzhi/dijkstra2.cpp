#include <iostream>
using namespace std;

//0 --- 'i';
//1 --- 'j';

string c;
string temp;
long long a, b;

pair<int, char> multi(pair<int, char> a, pair<int, char> b){
	
	if ((a.first == 1 && b.first == 1) || (a.first == -1 && b.second == -1)){
		
		if (a.second == '1' && b.second == '1'){
			return make_pair(1, '1');
		} else if (a.second == '1' && b.second == 'i'){
			return make_pair(1, 'i');
		} else if (a.second == '1' && b.second == 'j'){
			return make_pair(1, 'j');
		} else if (a.second == '1' && b.second == 'k'){
			return make_pair(1, 'k');
		} else if (a.second == 'i' && b.second == '1'){
			return make_pair(1, 'i');
		} else if (a.second == 'i' && b.second == 'i'){
			return make_pair(-1, '1');
		} else if (a.second == 'i' && b.second == 'j'){
			return make_pair(1, 'k');
		} else if (a.second == 'i' && b.second == 'k'){
			return make_pair(-1, 'j');
		} else if (a.second == 'j' && b.second == '1'){
			return make_pair(1, 'j');
		} else if (a.second == 'j' && b.second == 'i'){
			return make_pair(-1, 'k');
		} else if (a.second == 'j' && b.second == 'j'){
			return make_pair(-1, '1');
		} else if (a.second == 'j' && b.second == 'k'){
			return make_pair(1, 'i');
		} else if (a.second == 'k' && b.second == '1'){
			return make_pair(1, 'k');
		} else if (a.second == 'k' && b.second == 'i'){
			return make_pair(1, 'j');
		} else if (a.second == 'k' && b.second == 'j'){
			return make_pair(-1, 'i');
		} else if (a.second == 'k' && b.second == 'k'){
			return make_pair(-1, '1');
		}
		
	} else {
		
		if (a.second == '1' && b.second == '1'){
			return make_pair(-1, '1');
		} else if (a.second == '1' && b.second == 'i'){
			return make_pair(-1, 'i');
		} else if (a.second == '1' && b.second == 'j'){
			return make_pair(-1, 'j');
		} else if (a.second == '1' && b.second == 'k'){
			return make_pair(-1, 'k');
		} else if (a.second == 'i' && b.second == '1'){
			return make_pair(-1, 'i');
		} else if (a.second == 'i' && b.second == 'i'){
			return make_pair(1, '1');
		} else if (a.second == 'i' && b.second == 'j'){
			return make_pair(-1, 'k');
		} else if (a.second == 'i' && b.second == 'k'){
			return make_pair(1, 'j');
		} else if (a.second == 'j' && b.second == '1'){
			return make_pair(-1, 'j');
		} else if (a.second == 'j' && b.second == 'i'){
			return make_pair(1, 'k');
		} else if (a.second == 'j' && b.second == 'j'){
			return make_pair(1, '1');
		} else if (a.second == 'j' && b.second == 'k'){
			return make_pair(-1, 'i');
		} else if (a.second == 'k' && b.second == '1'){
			return make_pair(-1, 'k');
		} else if (a.second == 'k' && b.second == 'i'){
			return make_pair(-1, 'j');
		} else if (a.second == 'k' && b.second == 'j'){
			return make_pair(1, 'i');
		} else if (a.second == 'k' && b.second == 'k'){
			return make_pair(1, '1');
		}
		
	}
	
}

bool dp(int posi, int num){
	
	if (posi >= a*b) return false;
	pair<int, char> cur = make_pair(1, '1');
	
	if (num == 0){
		
		for (int i = posi; i < c.length(); i++){
			cur = multi(cur, make_pair(1, c[i]));
			if (cur == make_pair(1, 'i')){
				if (dp(i + 1, 1) == true) {
					return true;
				} else {
					return false;
				}
			}
		}
		
		return false;
	}
	
	if (num == 1){
		
		for (int i = posi; i < c.length(); i++){
			cur = multi(cur, make_pair(1, c[i]));
			if (cur == make_pair(1, 'j')){
				if (dp(i + 1, 2) == true) {
					return true;
				} else {
					return false;
				}
			}
		}
		
		return false;
		
		
	}
	
	for (int i = posi; i < c.length(); i++){
		cur = multi(cur, make_pair(1, c[i]));
	}
	
	if (cur == make_pair(1, 'k')) return true;
	
	return false;
	
}

int main(){
	
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++){
		cin >> a >> b;
		if (b > 4){
			b = b%4;
			b = b + 4;
		}
		cin >> c;
		temp = c;
		
		for (int j = 1; j < b; j++){
			c = c + temp;
		}
		
		
		if (dp(0, 0) == true){
			cout << "Case #" << i + 1 << ": YES" << endl; 
		} else {
			cout << "Case #" << i + 1 << ": NO" << endl;
		}
		
	}
	
}
