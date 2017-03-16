#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main (int argc, char const *argv[])
{
	int t;
	char input[255];
	
	char from[] = "ejp mysljylc kd kxveddknmc re jsicpdrysi\
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd\
de kr kd eoya kw aej tysr re ujdr lkgc jv";
	char to[] = "our language is impossible to understand\
there are twenty six factorial possibilities\
so it is okay if you want to just give up";

	char trans[256] = {0};
	for (int idx = 0; from[idx] != 0; idx++){
		if (trans[from[idx]] == 0){
			trans[from[idx]] = to[idx];
		}else if (trans[from[idx]] != to[idx]){
			cout << "Error" << endl;
			exit(1);
		}
	}
	
	trans['q'] = 'z';
	trans['z'] = 'q';	
	
	// for (int i = 0 ; i < 26 ; i++){
	// 	if (trans[i + 'a'] == 0){
	// 		cout << (char)(i + 'a') << endl;
	// 	}
	// }
	
	fgets(input,255,stdin);
	t = atoi(input);
	
	for (int casen = 1; casen <= t ; casen++){
		fgets(input,255,stdin);
		if (input[strlen(input) - 1] == '\n'){
			input[strlen(input) - 1] = 0;
		}
		
		cout << "Case #" << casen << ": ";
		for (int i = 0 ; i < strlen(input) ; i++){
			input[i] = trans[input[i]];
		}
		cout << input << endl;
	}
	
	return 0;
}