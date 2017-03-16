#include <iostream>
#include <string>
#include <math.h>
#include <fstream>

using namespace	std;

int main(){
	int Test,cnt;
	ifstream in("A-small-attempt0.in");
	ofstream out("A-small-attempt0.out");
	in>>Test;
	for (cnt=1;cnt<=Test;cnt++){
		string str;
		in>>str;
		string ans="";
		for (int i=0;i<str.length();i++){
			if (i==0 || ans[0]>str[i]){
				ans+=str[i];
			}else{
				ans.insert(ans.begin(),str[i]);
			}
		}
		out<<"Case #"<<cnt<<": ";
		out<<ans<<endl;
	}
	in.close();
	out.close();
}
