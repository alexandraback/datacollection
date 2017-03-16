#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <vector>
#include <numeric>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN=100001;
const int INF=0x7FFFFFFF;
const double eps=1e-10;
const double pi=acos(-1.0);

const string A="ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv"; 
const string B="our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

int ca;
char st[1000];
int word[1000];

int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	for (int i=0; i<A.size(); i++){
		if (A[i]==' ') continue;
		word[A[i]]=B[i];
	}
	word['q']='z'; word['z']='q';
	scanf("%d\n",&ca);
	for (int i=0; i<ca; i++){
		cout<<"Case #"<<i+1<<": ";
		gets(st);
		int len=strlen(st);
		for (int j=0; j<len; j++)
			if (st[j]==' ') putchar(' '); else{
				putchar(word[st[j]]);
			}
		puts("");
	}
	return 0;
}



