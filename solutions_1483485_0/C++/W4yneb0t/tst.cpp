#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
typedef long long ll;
char a[30]="yhesocvxduiglbkrztnwjpfmaq";
char st[200];
int main(){
	int t;
	cin>>t;
	cin.getline(st,10);
	for(int z=1;z<=t;z++){
		cin.getline(st,1000);
		cout<<"Case #"<<z<<": ";
		for(int i=0;st[i]!='\0';i++){
			if(st[i]==' ')
				cout<<" ";
			else
				cout<<a[st[i]-'a'];
		}
		cout<<endl;
	}
	return 0;
}
