#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
#define MIN(a,b) (((a)<(b))?(a):(b))
char M[256];
int main(int argc, char *argv[]){
	string from="ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jvzq";
	string to="our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give upqz";
	for(unsigned i=0;i<from.size();++i){
		M[from[i]]=to[i];
	}
	int T;
	cin>>T;
	char buffer[256];
	cin.getline(buffer,256);
	for(int c=1;c<=T;++c){
		cin.getline(buffer,256);
		for(int i=0;buffer[i];++i){
			buffer[i]=M[buffer[i]];
		}
		cout<<"Case #"<<c<<": "<<buffer<<endl;
	}
	return 0;
}

