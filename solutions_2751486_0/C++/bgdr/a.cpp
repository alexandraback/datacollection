#include<iostream>
#include<algorithm>
#include<functional>
#include<string>
#include<vector>
using namespace std;

typedef long long ll;


int cs[1000005];
string s;
int n;

#define isc(x) (!((x)=='a' || (x) == 'e' || (x) == 'i' || (x) == 'o' || (x) == 'u'))

ll bf1(){
	ll ans = 0;
	for(int i = 0; i < s.size(); ++i)
		for(int j = i; j < s.size(); ++j){
			int cnt = 0, best = 0, k = i;
			while(k <= j){
				cnt = 0;
				while(k <= j && isc(s[k]))k++,cnt++;
				k++;
				if(cnt > best) best = cnt;
			}
			if(best >= n) ans ++;
		}
	return ans;
}
int main(){
	int T;
	cin >> T;
	for(int c = 1; c <= T; c++){
		cin >> s >> n;
		cout << "Case #" << c << ": " << bf1() << endl;
	}
	return 0;
}
