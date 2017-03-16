#include<fstream>
#include<string.h>
using namespace std;

int main(){
	ifstream fin("B-large.in");
	ofstream fout("B-large.out");
	int t=0;
	fin>>t;
	int ans;
	char s[100];
	int len;
	for(int k=1;k<=t;k++){
		fin>>s;
		len=strlen(s);
		ans=0;
		int i=0;
		if(s[0]=='-'){
			ans=1;
			while(i<len&&s[i]=='-')i++;
		}
		while(i<len){
			if(s[i]=='+')i++;
			else{
				ans+=2;
				while(i<len&&s[i]=='-')i++;
			}
		}
		fout<<"Case #"<<k<<": "<<ans<<endl;
	}
	return 0;
}