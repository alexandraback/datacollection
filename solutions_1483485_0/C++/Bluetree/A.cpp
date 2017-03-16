#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string S="ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjv";
string T="ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveup";
char a[256];
int Test;
string str;

int main()
{
	freopen("input.txt","r",stdin);
	a['y'-'a']='a',a['e'-'a']='o',a['q'-'a']='z',a['z'-'a']='q';
	for (int i=0;i<S.size();++i) a[S[i]-'a']=T[i];
	
/*	for (int i=0;i<26;++i)
	if (a[i]>='a' && a[i]<='z') printf("%c",a[i]);
	else printf("-_-");
	cout << endl;
	
	sort(a,a+26);
	for (int i=0;i<26;++i)
	if (a[i]>='a' && a[i]<='z') printf("%c",a[i]);
	else printf("-_-");
*/	
	
	
	scanf("%d",&Test);
	getline(cin,str);
	for (int t=1;t<=Test;++t) {
		str.clear();
		getline(cin,str);
		printf("Case #%d: ",t);
//		cout << str << endl;
		for (int i=0;i<str.size();++i) {
			if (str[i]>='a' && str[i]<='z') cout << a[str[i]-'a'];
			else cout << str[i];
		}
		cout << endl;
	}	
}
