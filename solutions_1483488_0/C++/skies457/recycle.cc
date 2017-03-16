#include <iostream>
#include <string>
using namespace std;

bool flag[2000001];

int count(int a, int b, int n)
{
	int result, len, i;
	char buf[20];

	result = 0;
	_itoa(n, buf, 10);
	len = strlen(buf);
	for(i = 0; i < len - 1; i++) {
		buf[i + len] = buf[i];
		buf[i + len + 1] = '\0';
		if(buf[i + 1] == '0') continue;
		int k = atoi(buf + i + 1);
		if(!flag[k] && k != n && k >= a && k <= b){
			flag[k] = true, result++;
		}
	}
	return result * (result + 1) / 2;
}

int main()
{
	int a, b, i, m, n, t;
	//freopen("recycle.in", "r", stdin);
	//freopen("recycle.out", "w", stdout);
	cin >> n;
	for(t = 1; t<=n; t++) {
		memset(flag, 0, sizeof(flag));
		cin >> a >> b;
		cout << "Case #" << t << ": ";
		m = 0;
		for(i = a; i <= b; i++) {
			if(!flag[i]) {
				flag[i] = true;
				m += count(a, b, i);
			}
		}
		cout << m << endl;
	}
	return 0;
}
	