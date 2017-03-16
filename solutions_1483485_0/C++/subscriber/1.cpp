#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define AL(x) x.begin(),x.end()
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;
typedef vector<int> vt;

map<char,char>g;
char s[1111];
int w=0;

int main(){
	freopen("1.in","r",stdin);	
	freopen("1.out","w",stdout);	
	string a="ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
	string b="our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";
	for (int i=0;i<a.size();i++)g[a[i]]=b[i];
	g['q']='z';
	g['z']='q';
	int t=0;
	scanf("%d\n",&t);
	for (int e=1;e<=t;e++){
		gets(s);
		for (int i=0;i<strlen(s);i++)s[i]=g[s[i]];
		cout << "Case #" << e << ": ";
		puts(s);
	}
	return 0;
}


