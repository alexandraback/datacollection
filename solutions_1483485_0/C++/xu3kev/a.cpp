#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;
int main(){
	ifstream in("A-small-attempt0.in");
	ofstream out("a.output");
	int count;
	char map[26]={0};
	char buffer[300]="ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
	char buffer2[300]="our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";

	count=0;
	map[25]='q';
	map[16]='z';
	for(int i=0;buffer[i];++i){
		if(buffer[i]!=' '){
			if(map[buffer[i]-97]==0){
				++count;
				map[buffer[i]-97]=buffer2[i];
			}
		}
	}
	cout<<count;
	for(int i=0;i<26;++i)
		if(map[i]==0)
			cout<<(i);
	int n;
	in>>n;
	in.getline(buffer,200);
	for(int i=1;i<=n;++i){
		in.getline(buffer,200);
		out<<"Case #"<<i<<": ";
		for(int j=0;buffer[j]!='\0';++j){
			if(buffer[j]!=' ')
				out<<map[buffer[j]-97];
			else
				out<<' ';
		}
		out<<"\n";
	}
	return 0;
}
