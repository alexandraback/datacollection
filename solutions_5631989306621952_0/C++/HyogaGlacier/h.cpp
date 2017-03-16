#include <iostream>
#include <fstream>
using namespace std;
typedef long long ll;
int main(){
	ofstream ofs("out.txt");
	int t;	cin>>t;
	for(int cases=1;cases<=t;cases++){
		string s;	cin>>s;
		string ret=s.substr(0,1);
		for(int i=1;i<s.size();i++){
			if(s[i]>=ret[0])	ret=s[i]+ret;
			else ret=ret+s[i];
		}
		ofs<<"Case #"<<cases<<": "<<ret<<endl;
	}
	ofs.close();
	return 0;
}
