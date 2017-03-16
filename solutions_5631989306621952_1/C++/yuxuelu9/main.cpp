#include<fstream>
#include<string.h>
using namespace std;

int main(){
	ifstream fin("A-large.in");
	ofstream fout("A-large.out");
	int tt=0;
	fin>>tt;
	char s[1001],ans[1001];
	bool m[1000];
	for(int kk=1;kk<=tt;kk++){
		fin>>s;
		int len=strlen(s);
		int i=0,j=len-1;
		char max=0;
		for(int k=0;k<len;k++){
			if(s[k]>=max){
				max=s[k];
				m[k]=1;
			}
			else m[k]=0;
		}
		for(int k=len-1;k>=0;k--){
			if(m[k]==1){
				ans[i]=s[k];
				i++;
			}
			else{
				ans[j]=s[k];
				j--;
			}
		}
		ans[len]=0;
		fout<<"Case #"<<kk<<": "<<ans<<endl;
	}
	return 0;
}