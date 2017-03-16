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

const char A[]="ynficwlbkuomxsevzpdrjgthaq";

int n,T;
char s[110],B[30];

int main()
{
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	
	scanf("%d\n",&T);
	for(int i=0;i<26;i++) B[A[i]-'a']=i+'a';
	for(int i=1;i<=T;i++)
	{
		gets(s);
		n=strlen(s);
		printf("Case #%d: ",i);
		for(int j=0;j<n;j++) if (s[j]>='a'&&s[j]<='z') printf("%c",B[s[j]-'a']); else printf("%c",s[j]);
		puts("");
	}
	
	return 0;
}

