/*
	Author: chnlich
*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cmath>
#include<cctype>
#include<climits>
#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<numeric>
#include<functional>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>
#include<string>
#include<list>
#include<deque>
#include<utility>

using namespace std;

typedef long long llint;
typedef unsigned long long ull;
typedef pair<int,int> ipair;
#define debug(x) cerr<<#x<<'='<<x<<endl;
#define fi first
#define se second
#define mp make_pair
#define pb push_back

void read(int &k)
{
	char x=getchar(); k=0;
	while(x<'0'||x>'9') x=getchar();
	while(x>='0'&&x<='9') { k=k*10-48+x; x=getchar(); }
}

char s1[100],s2[100],a[128];
int n;

int main()
{
	//freopen("A.in","r",stdin);
	//freopen("A.out","w",stdout);
	
	FILE *fin1=fopen("A1.in","r"),*fin2=fopen("A2.in","r");
	while(fscanf(fin1,"%s",s1)>0)
	{
		fscanf(fin2,"%s",s2);
		printf("%s %s\n",s1,s2);
		n=strlen(s1);
		for(int i=0;i<n;i++) a[s2[i]]=s1[i];
	}
	for(char i='a';i<='z';i++) if (a[i]>='a'&&a[i]<='z') printf("%c",a[i]); else printf(" ");
	
	return 0;
}

