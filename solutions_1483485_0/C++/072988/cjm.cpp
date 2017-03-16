#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

char a[] = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
char b[] = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

map <char, char> Map;
char s1[1000010];
string s2;

int main(){
	Map.clear();
	int len = strlen(a);
	for(int i = 0; i < len; i ++){
		Map[a[i]] = b[i];
	}
	Map['z'] = 'q';
	Map['q'] = 'z';
	int T;

	scanf("%d", &T);
	getchar();
	for(int t = 1; t <= T; t ++){
		cin.getline(s1, 1000010);
		s2 = "";
		int len = strlen(s1);
		for(int i = 0; i < len; i ++){
			if(Map.find(s1[i]) != Map.end()){
				s2 += Map[s1[i]];
			}else{
				s2 += s1[i];
			}
		}
		printf("Case #%d: %s\n", t, s2.c_str());
	}

	return 0;
}