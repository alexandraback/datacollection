#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
	vector<char> G(26), N(26);
	for(int i=0; i<26; i++){
		G[i] = '-';
		N[i] = '-';
	}
	G['y'-'a'] = 'a';
	N['a'-'a'] = 'y';
	
	G['e'-'a'] = 'o';
	N['o'-'a'] = 'e';
	
	G['q'-'a'] = 'z';
	N['z'-'a'] = 'q';
	
	string I[3], O[3];
	
	I[0] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
	O[0] = "our language is impossible to understand";
	
	I[1] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	O[1] = "there are twenty six factorial possibilities";
	
	I[2] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
	O[2] = "so it is okay if you want to just give up";
	
	for(int i=0; i<3; i++){
		for(int j=0; j<I[i].size(); j++){
			if(I[i][j] == ' ') continue;
			G[I[i][j]-'a'] = O[i][j];
			N[O[i][j]-'a'] = I[i][j];
		}
	}
	G['z'-'a'] = 'q';
	N['q'-'a'] = 'z';
	/* !CHECK!
	for(int i=0; i<26; i++){
		printf("G[%c] -> %c\tN[%c] -> %c\n", i+'a', G[i], i+'a', N[i]);
	}
	*/
	
	// Problem
	int T;
	cin >> T;
	cin.ignore();
	for(int i=0; i<T; i++){
		string in;
		getline(cin, in);
		
		printf("Case #%d: ", i+1);
		for(int n=0; n<in.size(); n++){
			putchar((in[n]==' '?' ':G[in[n]-'a']));
		}
		putchar('\n');
	}
	return 0;
}


/*
Input
3
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv

--------------------------------------------------------------------------------

Output 
Case #1: our language is impossible to understand
Case #2: there are twenty six factorial possibilities
Case #3: so it is okay if you want to just give up
*/
