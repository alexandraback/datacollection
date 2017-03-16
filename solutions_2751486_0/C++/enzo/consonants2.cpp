#include <iostream>
#include <vector>
#include <string>
#include <array>

using namespace std;

char vowel [] = {'a', 'e', 'i', 'o', 'u'};

bool good(string a, int N){
	int cons = 0;
	for(int i=0;i<a.length();++i){
		bool isVow = false;
		for(int j=0;j<5;++j){
			if(a[i] == vowel[j]){
				cons = 0;
				isVow = true;
				break;
			}
		}
		//cout << a << " ";
		if(!isVow) {
			if(++cons == N) return true;
		}
		//cout << "sorry" << endl;
	}
	return false;
}

void getin(int T){
	for(int i=0;i<T;++i){
		string name;
		cin >> name;
		int N;
		cin >> N;
		
		int ans = 0;
		
		for(int j=0;j<name.length();++j){
			for(int k=1;k<=name.length()-j;++k){
				if(good(name.substr(j,k), N)) ++ans;
			}
		}
		
		
		
		cout << "Case #" << i+1 <<": " <<  ans << endl;
	}
}

int main(){
	int T;
	cin >> T;
	
	getin(T);
}