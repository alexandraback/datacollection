#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;
string s;
int main(){
freopen("1.in","r",stdin);
freopen("1.out","w",stdout);
	s="yhesocvxduiglbkrztnwjpfmaq";
	int T;
	scanf("%d\n", &T);
	char a[10000];
	for (int t=1;t<=T;t++){
		printf("Case #%d: ", t);
		gets(a);
		for (int i=0;i<strlen(a);i++)
		if (a[i]==' ') printf(" ");else
		cout << s[a[i]-'a'];
		cout << endl;
	}
	return 0;
}
