#include<iostream>
#include<string>
#include<memory.h>
#include<fstream>
#include<cstdio>
using namespace std;
int mp[256];
int main(){
	mp['a']='y';
	mp['b']='h';
	mp['c']='e';
	mp['d']='s';
	mp['e']='o';
	mp['f']='c';
	mp['g']='v';
	mp['h']='x';
	mp['i']='d';
	mp['j']='u';
	mp['k']='i';
	mp['l']='g';
	mp['m']='l';
	mp['n']='b';
	mp['o']='k';
	mp['p']='r';
	mp['q']='z';
	mp['r']='t';
	mp['s']='n';
	mp['t']='w';
	mp['u']='j';
	mp['v']='p';
	mp['w']='f';
	mp['x']='m';
	mp['y']='a';
	mp['z']='q';
	mp[' ']=' ';
	ifstream inputt("A-small-attempt3.in");
	ofstream out("A-small-attempt3.out");
	int T;
	inputt >> T;
	int tmp=T;
	inputt.get();
	char ch[101];
	while(T--){
		inputt.getline(ch,101,'\n');
		int i=0;
		int lent=strlen(ch);
		out << "Case #" << tmp-T <<": ";
		for(int i=0;i < lent;i++)
			out << (char)mp[ch[i]];
		out << endl;
	}
	return 0;
}