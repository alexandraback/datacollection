#include <iostream>
#include <string>
using namespace std;

#define MAX 1000

int main(){
	int res,tt,u,i,j,k,a,b;
	char s[2010],t[2010],*p,*q;
	cin>>tt; for (u=0; u<tt; u++){ cin>>s; 
		p=t+1005; q=p+1; *p=s[0];
		for (i=1; s[i]; i++) if (s[i]>=*p) *(--p)=s[i]; else *(q++)=s[i];
		*q=0;
		cout<<"Case #"<<(u+1)<<": "<<p<<endl;
	}
	return 0;
}