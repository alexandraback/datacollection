#include<fstream>
#include<string.h>
using namespace std;

int a[8][8]={{0,1,2,3,4,5,6,7},
	         {1,4,3,6,5,0,7,2},
	         {2,7,4,1,6,3,0,5},
	         {3,2,5,4,7,6,1,0},
	         {4,5,6,7,0,1,2,3},
	         {5,0,7,2,1,4,3,6},
	         {6,3,0,5,2,7,4,1},
	         {7,6,1,0,3,2,5,4}};
bool check(int *s,int l,int len){
	int ini=0;
	int i=0;
	while(i<len){
		ini=a[ini][s[i%l]];
		i++;
		if(ini==1)break;
	}
	if(i<len&&ini==1){
		ini=0;
		while(i<len){
			ini=a[ini][s[i%l]];
			i++;
			if(ini==2)break;
		}
		if(i<len&&ini==2){
			ini=0;
			while(i<len){
				ini=a[ini][s[i%l]];
				i++;
			}
			if(ini==3)return true;
		}
	}
	return false;
}

int main(){
	ifstream fin("C-small-attempt1.in");
	ofstream fout("C-small-attempt1.out");

	long long t,l,x;
	fin>>t;
	bool mark;
	char str[10001];
	int s[10001];
	for(int k=1;k<=t;k++){
		mark=false;
		fin>>l>>x;
		fin>>str;
		for(int i=0;i<l;i++){
			s[i]=str[i]-'h';
		}
		if(x>12)
			x=x%4+12;
		mark=check(s,l,l*x);
		if(mark)
			fout<<"Case #"<<k<<": YES"<<endl;
		else
			fout<<"Case #"<<k<<": NO"<<endl;
	}
	return 0;
}