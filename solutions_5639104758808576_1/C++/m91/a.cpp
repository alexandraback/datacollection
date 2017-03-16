#include<vector>
#include <utility>
#include<iostream>
#include <algorithm>

using namespace std;
char s[2000];

int main(){
int T,i,j;

cin>>T;

for(i=0;i<T;i++){
	int m;
	cin>>m;
	cin>>s;
	int am=0,som=0;
	for(j=0;j<=m;j++){
		if(j>som){am++;som++;}
		//if(j>som && s[j]!='0')am+=(j-am);
		som+=(s[j]-'0');
	}
	cout<<"Case #"<<(i+1)<<": "<<am<<endl;
	}






return 0;
}
