#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define popb pop_back
#define del erase
#define sz size
#define ins insert
#define FOR(a,b,c) for(int a = b; a < c; a++)
#define FORS(a,b,c) for(int a = b; a <= c; a++)
#define FORN(a,b) for(int a = 0; a < b; a++)
#define FORD(a,b,c) for (int a = b; a >= c; a--)
#define RES(a,b) memset(a,b,sizeof(a))
#define LL long long
#define PII pair<int,int>
#define PLL pair<long long,long long>
#define PDD pair<double,double>
#define PCC pair<char,char>
#define PSS pair<string,string>
using namespace std;
int A,B,T,angka,pengali,ans;
vector <int> temp;
vector <int>::iterator SR;
int main () {
	scanf("%d",&T);
	for(int k=1;k<=T;k++)	{
		ans=0;
		scanf("%d %d",&A,&B);
		for (int i=A;i<=B;i++)	{
			temp.clear();
			angka=i;pengali=1;
			for (int j=0;j<(int)log10(i);j++)	pengali*=10;
			for (int j=0;j<(int)log10(i);j++)	{
				angka=(angka%10)*pengali+(angka/10);
				if (angka>i && angka<=B) {
					SR= find(temp.begin(), temp.end(),angka);
					if (SR==temp.end())	{
						temp.pb(angka);
						ans++;
					}
				}
			}
		}
		printf("Case #%d: %d\n",k,ans);
	}
return 0;}
