#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int testcase(){
	int smax;
	cin >>smax;
	int t=0;
	vector<int> p(smax,0);
	int add=0;
	string s;
	cin >> s;
	for(int i=0; i<s.size(); i++){
		t+= (s[i]- '0');
		if (t == i){
			add++;
			t++;
		}
	}
	return add;
}


int main(){
	int nb;
	cin >>nb;
	for(int i=0; i<nb; i++)
		cout << "Case #"<<i+1<<": "<< testcase()<<endl;;
	return 0;
}
