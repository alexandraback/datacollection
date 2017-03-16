#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
char a[101];
int n;
int res;
bool conso(char a){
	if(a=='a') return 0;
	if(a=='e') return 0;
	if(a=='i') return 0;
	if(a=='o') return 0;
	if(a=='u') return 0;
	return 1;
};
bool isok(int b, int e, int n){
	int con=0;
	for(int i=b;i<=e;i++){
		if(conso(a[i])) con++;
		else con=0;
		if(con==n) return 1;
	}
	return 0;
};
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		//todo
		cin>>a>>n;
		res=0;
		for(int j=0;j<strlen(a);j++)
		for(int k=j;k<strlen(a);k++){
			if(isok(j,k,n)) res++;
		}
		cout<<"Case #"<<i<<": "<<res<<endl;
	}
	return 0;
}