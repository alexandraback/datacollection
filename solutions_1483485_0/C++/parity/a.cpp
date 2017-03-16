#include<sys/types.h>
#include<dirent.h>

#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<sstream>
#include<cmath>
#include<fstream>
#include<map>
#include<set>

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define ABS(x) ((x) > 0 ? (x) : -(x))
#define lt(x, y)	((x) >= 0 && ((x) < (y) || (y) < 0))

#define SWAP(x, y) {(x) += (y); (y) = (x) - (y); (x) -= (y);}

#define EPS 1e-6
#define PI 3.14159265358979323846

using namespace std;

int table[26];

int used[26];

int rem;

void init(string x, string y){

	int len = x.size();

	assert((int)y.size() == len);

	for(int i = 0; i < len; i++){

		if(x[i] == ' ')	continue;

		if(table[x[i] - 'a'] >= 0)
			assert(table[x[i] - 'a'] == y[i] - 'a');
		else{
			table[x[i] - 'a'] = y[i] - 'a';
			used[y[i] - 'a'] = 1;
			rem--;
		}
	}
}

int T;

int main()
{
	
	for(int i = 0; i < 26; i++)
		table[i] = -1;

	memset(used, 0, sizeof(used));
	string a0 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
	string a1 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	string a2 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
	string a3 = "y qee";

	string b0 = "our language is impossible to understand";
	string b1 = "there are twenty six factorial possibilities";
	string b2 = "so it is okay if you want to just give up";
	string b3 = "a zoo";

	rem = 26;
	init(a0, b0);
	init(a1, b1);
	init(a2, b2);
	init(a3, b3);

	for(int i = 0; i < 26; i++){
		if(table[i] < 0){
			for(int j = 0; j < 26; j++){
				if(!used[j]){
					table[i] = j;
					goto done;
				}
			}
		}
	}
done:

	string str;

	getline(cin, str);

	T = atoi(str.c_str());

	for(int i = 1; i <= T; i++){

		getline(cin, str);

		printf("Case #%d: ", i);
		for(unsigned j = 0; j < str.size(); j++){
			if(str[j] == ' ')	printf(" ");
			else	printf("%c", table[str[j] - 'a'] + 'a');
		}
		printf("\n");
	}

	return 0;
}

// vi: ts=2 sw=2
