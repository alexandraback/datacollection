#include<iostream>
using namespace std;

int main() {
	char map[300];
	for(int i=0;i<300;i++)
		map[i] = ' ';
	map['z'] = 'q';
	map['q'] = 'z';
	string q[3];
	string a[3];
	q[0] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
	q[1] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	q[2] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
	a[0] = "our language is impossible to understand";
	a[1] = "there are twenty six factorial possibilities";
	a[2] = "so it is okay if you want to just give up";
	for(int i=0;i<3;i++)
		for(int j=0;j<q[i].size();j++)
			map[q[i][j]] = a[i][j];
	int t;
	cin>>t;
	string line;
	getline(cin,line);
	for(int tn=0;tn<t;tn++) {
		getline(cin,line);
		for(int i=0;i<line.size();i++)
			line[i] = map[line[i]];
		cout<<"Case #"<<tn+1<<": "<<line<<endl;
	}

}
