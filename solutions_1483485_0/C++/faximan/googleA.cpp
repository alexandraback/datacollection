//
//  googleA.cpp
//  Uva
//
//  Created by Alexander Faxå on 2012-04-14.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>

using namespace std;

char sub[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

int main()
{
	int t;
	string s;
	cin >> t;
	getline(cin,s);
	for(int tt = 1; tt <= t; tt++)
	{
		cout << "Case #" << tt << ": ";
		getline(cin,s);
		for (int i = 0; i < s.size(); i++) {
			if(s[i]==' ')
				cout << " ";
			else
				cout << sub[(s[i]-'a')];
		}
		cout << endl;
	}
	return 0;	
}