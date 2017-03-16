// by shik
#include <cstdio>
#include <cstring>
#include <algorithm>
#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
char a[]="ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv",b[]="our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";
char t[130],s[110];
int main()
{
	for ( int i=0; a[i]; i++ ) t[(int)a[i]]=b[i];
	for ( int i='a'; i<='z'; i++ ) if ( !strchr(a,i) ) for ( int j='a'; j<='z'; j++ ) if ( i!=j && !strchr(b,j) ) t[i]=j;
	int T,cas=0;
	scanf("%d",&T); while ( getchar()!='\n' );
	while ( T-- ) {
		gets(s);
		printf("Case #%d: ",++cas);
		for ( int i=0; s[i]; i++ ) putchar(t[(int)s[i]]);
		puts("");
	}
	return 0;
}
