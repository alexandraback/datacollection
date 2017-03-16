#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <iterator>
#include <queue>
#include <sstream>

using namespace std;

char s[1111];

int P[26];
void calc(string p,string q){
	for (int i=0;i<p.size();i++)
		if (islower(p[i])) P[p[i]-'a']=q[i]-'a';
}
bool v[26];

int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	memset(P,-1,sizeof(P));	
	string a  = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
	string aa = "our language is impossible to understand";
	string b  = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	string bb = "there are twenty six factorial possibilities";
	string c  = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
	string cc = "so it is okay if you want to just give up";
	calc(a,aa);calc(b,bb);calc(c,cc);
	P['z'-'a']='q'-'a';
	P[16]=25;
	int t;cin >> t;scanf("\n");
	for (int rt=1;rt<=t;rt++){
		gets(s);
		printf("Case #%d: ",rt);
		int l=strlen(s);
		for (int i=0;i<l;i++)
			if (islower(s[i])) printf("%c",'a'+P[s[i]-'a']);
			else putchar(s[i]);
		puts("");
	}
	return 0;
}
