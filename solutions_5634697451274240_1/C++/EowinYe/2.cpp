#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>

using namespace std;

int main(){
	string str;
	int Test,cnt;
	ifstream in("B-large.in");
	ofstream out("B-large.out");
	in>>Test;
	for (cnt=1;cnt<=Test;cnt++){
		in>>str;
		char now=str[0];
		int ans=0;
		for (int i=1;i<str.length();i++){
			if (now!=str[i]){
				ans++;
				now=str[i];
			}
		}
		if (now=='-')
			ans++;
		out<<"Case #"<<cnt<<": "<<ans<<endl;
	}
	in.close();
	out.close();
}
