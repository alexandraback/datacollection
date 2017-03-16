#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(){
	freopen("Astd.in", "r", stdin);
	freopen("A.out", "w", stdout);

	char raw[200];
	char tr[200];
	char match[26];
	for(int i=0;i<3;i++){
		cin.getline(raw, 200);
		cin.getline(tr, 200);
		for(int j=0;j<strlen(raw);j++){
			if(raw[j]==' ') continue;
			match[raw[j]-'a'] = tr[j];
		}
	}
	match['y'-'a'] = 'a';
	match['e'-'a'] = 'o';
	match['q'-'a'] = 'z';
	int cs;
	freopen("A.in", "r", stdin);
	scanf("%d\n", &cs);
	for(int css=1;css<=cs;css++){
		cin.getline(raw, 200);
		for(int j=0; j<strlen(raw); j++){
			if(raw[j]==' ') tr[j]=raw[j];
			else{
				tr[j] = match[raw[j]-'a'];
			}
		}
		tr[strlen(raw)] = '\0';
		printf("Case #%d: %s\n", css, tr);
	}
	return 0;
}
