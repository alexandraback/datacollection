/*Q1.cpp @ 2012年04月14日 07时56分13秒 BY dOMhOW*/
/* 
 * status : AC  WA  TLE
 */
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<math.h>
#include	<map>
#include	<algorithm>
#include	<vector>
#include	<set>
#include	<iostream>
#include	<string>
using namespace std;
#define CC(x,i) do{memset(x,i,sizeof(x));}while(0)
#define inf 0x7f7f7f7f
#define PII pair<int,int>
#define VI vector<int>
#define mp make_pair
#define X first
#define Y second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(),x.end()
#define uniq(x) do{sort(all(x));x.resize(unique(all(x))-x.begin());}while(0)
#define two(x) (1ll<<(x))
typedef long long  LL;
char s[120],mapz[]="yhesocvxduiglbkrztnwjpfmaq";
int main ( int argc, char *argv[] )
{
	int T;cin>>T;
	fgets(s,120,stdin);
	for(int t=1;t<=T;t++)
	{
		fgets(s,120,stdin);
		for(int i=0;s[i];i++){
			if(s[i]>='a'&&s[i]<='z')s[i]=mapz[s[i]-'a'];
		}
		cout<<"Case #"<<t<<": "<<s;
	}
	return EXIT_SUCCESS;
}

