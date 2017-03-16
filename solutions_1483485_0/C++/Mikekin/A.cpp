#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

int t, n;
char f[30];
string st;

void work()
{
	n = st.size();
	for (int i = 0; i < n; i++) {
		if ((st[i] >= 'a') && (st[i] <= 'z')) 
			cout << f[st[i]-'a'];
		else
			cout << st[i];
	}
}

void pre()
{
	f[0] = 'y'; f[1] = 'h'; f[2] = 'e'; f[3] = 's';
	f[4] = 'o'; f[5] = 'c'; f[6] = 'v'; f[7] = 'x';
	f[8] = 'd'; f[9] = 'u'; f[10] = 'i'; f[11] = 'g';
	f[12] = 'l'; f[13] = 'b'; f[14] = 'k'; f[15] = 'r';
	f[16] = 'z'; f[17] = 't'; f[18] = 'n'; f[19] = 'w';
	f[20] = 'j'; f[21] = 'p'; f[22] = 'f'; f[23] = 'm';
	f[24] = 'a'; f[25] = 'q';
}

int main(){
	freopen("a.in","r",stdin);
	freopen("a.txt","w",stdout);
	pre();
	cin >> t;
	getchar();
	for (int i = 1; i <= t; i++) {
		getline(cin, st);
		printf("Case #%d: ", i);
		work();
		cout << endl;
	}
	return 0;
}

