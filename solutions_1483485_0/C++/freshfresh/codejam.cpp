// codejam.cpp : 定义控制台应用程序的入口点。
//

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

char ch[26]=
{
	'y','h','e','s','o',
	'c','v','x','d','u',
	'i','g','l','b','k',
	'r','z','t','n','w',
	'j','p','f','m','a',
	'q'
};

int main(){
	ifstream in;
	in.open("in.in");
	ofstream out;
	out.open("out.out");
	int t;
	in>>t;
	in.get();
	for(int i=0;i<t;i++){
		char g[200];
		in.getline(g,200);
		out<<"Case #"<<i+1<<": ";
		for(int j=0;g[j]!='\0';j++){
			if(g[j]!=' ') out<<ch[g[j]-'a'];
			else out<<" ";
		}
		out<<endl;
	}
	return 0;
}