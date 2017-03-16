#include<fstream>
#include<string.h>
using namespace std;

int n,j,cnt=0;
void check(char* s,int i,ofstream& fout){
	if(cnt>=j)return;
	if(i+3>=n){
		fout<<s<<" 3 7 5 6 31 8 27 5 77"<<endl;
		cnt++;
		return;
	}
	else{
		int j=i+1;
		while(j<n&&s[j]=='1')j++;
		check(s,j,fout);
		char s1[100];
		strcpy(s1,s);
		if(i+3<n&&s1[i+3]=='0'){
			s1[i]='1';
			s1[i+3]='1';
			j=i+1;
			while(j<n&&s1[j]=='1')j++;
			check(s1,j,fout);
		}
	}
}
int main(){
	ifstream fin("C-large.in");
	ofstream fout("C-large.out");
	int t=0;
	fin>>t;
	char s[100];
	for(int k=1;k<=t;k++){
		fin>>n>>j;
		fout<<"Case #"<<k<<":"<<endl;
		for(int i=0;i<n;i++)s[i]='0';
		s[n]=0;
		s[0]='1';
		s[3]='1';
		s[n-4]='1';
		s[n-1]='1';
		check(s,1,fout);
		//fout<<"Case #"<<k<<": "<<ans<<endl;
	}
	return 0;
}