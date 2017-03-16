#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int main(int argc, char *argv[]){
	fstream fin (argv[1], fstream::in);
	map <char, char> mp;

	string	in ("ejp mysljylc kd kxveddknmc re jsicpdrysi"
			"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
			"de kr kd eoya kw aej tysr re ujdr lkgc jv"),
		out("our language is impossible to understand"
			"there are twenty six factorial possibilities"
			"so it is okay if you want to just give up");
	mp['y'] = 'a';
	mp['e'] = 'e';
	mp['q'] = 'z';
	mp['z'] = 'q';
	for(int j = 0; j != in.length(); ++j){	
		mp[in[j]] = out[j];
	}

	int T;
	fin >> T;
	string G;
	getline(fin, G);
	for (int i = 0; i != T; ++i){
		getline(fin, G);
		for(int j = 0; j != G.length(); ++j){	
			G[j] = mp[G[j]];
		}
		cout << "Case #" << i+1<< ": " << G << endl;
	}

	fin.close();
	return 0;
}
