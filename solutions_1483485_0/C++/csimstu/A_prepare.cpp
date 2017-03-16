#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;
int conv[26];
bool vis[26];
string str1, str2;

int main() {
	freopen("t.in", "r", stdin);
	memset(conv, -1, sizeof(conv));
	for ( int i = 0; i < 4; i ++ ) {
		getline(cin, str1);
		getline(cin, str2);
		int len = str1.size();
		for ( int i = 0; i < len; i ++ ) 
			if ( str1[i] != ' ' )
				conv[str1[i] - 'a'] = str2[i] - 'a';
	}

	int uncertain;
	for ( int i = 0; i < 26; i ++ ) 
		if ( conv[i] != -1 ) 
			vis[conv[i]] = true;
		else
			uncertain = i;
	for ( int i = 0; i < 26; i ++ ) 
		if ( !vis[i] ) 
			conv[uncertain] = i;
	for ( int i = 0; i < 26; i ++ )
		printf("%d, ", conv[i]);
}
