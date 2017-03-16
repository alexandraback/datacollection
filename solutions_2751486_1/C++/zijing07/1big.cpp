#include <iostream>
#include <cstring>

using namespace std;

int T, n;
char str[1000055];

bool is(char ch){
	if(ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u'){
		return true;
	}
	return false;
}

long long Compute(int e0, int b1, int e1, int n, int cnt, int len){
	long long ans = 0;
	//cout << e0 << " " << b1 << " " << e1 << " " << n << " " << cnt << " " << len << endl;
	e1 = b1 + n -1;
	if(cnt > n){
		int t = cnt-n;
		ans += t*(len-1)-e1*t-(1+t)*t/2+t;
	//cout << ans << endl;
	}
	ans += b1 - e0 + ( len - e1 -1 ) + (b1-e0)*(len-e1-1) + 1;
	//cout <<"2: " << ans << endl;
	return ans;
}

void Solve()
{
	long long ans = 0;
	cin >> str >>  n;
	//cout << strlen(str) << endl;
	int len = strlen(str);
	int e0=0, b1=0, e1=0;
	
	int cnt = 0;
	for(int i = 0; i < len; i++){
		if( is(str[i]) ){
			cnt += 1;
		}
		else{
			if(cnt >= n){
				e1 = i;
				ans += Compute(e0, b1, e1, n, cnt, len);
				e0 = b1+1+(cnt-n);
			}
			cnt = 0;
			b1 = i+1;
			//cout << "1: " << ans << endl;
		}
		if( is(str[i]) && i == len-1 && cnt >=n){
			e1 = i;
			ans += Compute(e0, b1, e1, n, cnt, len);
			e0 = b1+1;
			//cout << "2: " << ans << endl;
		}

	}

	cout << ans;
}

int main()
{
	cin >> T;
	for(int i = 1; i <= T; i++){
		cout << "Case #" << i << ": ";
		Solve();
		cout << endl;
	}

	return 0;
}
