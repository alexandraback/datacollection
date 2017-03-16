/*
 * a.cpp
 *
 *  Created on: 2012-4-14
 *      Author: whimsy
 */

#include<iostream>
#include<cstdio>
#include<string>
#include<map>

using namespace std;

map<char,char> MAP;

int main(){
//	freopen("in.txt","r",stdin);
	freopen("a.txt","w",stdout);
	string a("ejp mysljylc kd kxveddknmc re jsicpdrysi");
	string A("our language is impossible to understand");
	string b("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
	string B("there are twenty six factorial possibilities");
	string c("de kr kd eoya kw aej tysr re ujdr lkgc jv");
	string C("so it is okay if you want to just give up");
	for (unsigned i = 0;i<a.size();++i) MAP[a[i]] = A[i];
	for (unsigned i = 0;i<b.size();++i) MAP[b[i]] = B[i];
	for (unsigned i = 0;i<c.size();++i) MAP[c[i]] = C[i];
	MAP['q'] = 'z';
	MAP['z'] = 'q';
//
//	for (map<char,char>::iterator it = MAP.begin();it!=MAP.end();++it){
//		cout << it->first << "  " << it->second << endl;
//	}
//	cout << MAP.size() << endl;
//	cin >> Test;
	int Test;
	cin >> Test;
	string temp;
	getline(cin,temp);
	for (int ii = 0;ii<Test;++ii){
		printf("Case #%d: ",ii+1);
		getline(cin,temp);
		for (unsigned i = 0;i<temp.size();++i){
			temp[i] = MAP[temp[i]];
		}
		cout << temp << endl;;
	}
	return 0;
}
