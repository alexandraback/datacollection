#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#define sz size()
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define fu(i,n) for(int i=0; i<(n); i++)
#define ALL(a) (a).begin(),(a).end()
#define cl(a,co) memset(a,co,sizeof a)
#define un(a) sort(ALL(a)),a.erase( unique(ALL(a)), a.end() )
typedef long long ll;
//istringstream is(s); is >> a;

using namespace std;

string from[] = { "aoz", "ejp mysljylc kd kxveddknmc re jsicpdrysi", "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "de kr kd eoya kw aej tysr re ujdr lkgc jv" };
string to[] =   { "yeq", "our language is impossible to understand", "there are twenty six factorial possibilities", "so it is okay if you want to just give up" };

bool v['z'-'a'+1];
char mapa['z'-'a'+1];
int ileTestow;

int main(){

	memset(v,0,sizeof v);
	memset(mapa,0,sizeof mapa);

	for(int i=0; i<4; i++){
		for(int j=0; j<from[i].size(); j++){
			mapa[from[i][j]-'a'] = to[i][j];
			v[ to[i][j]-'a' ] = true;
		}
	}
	
	for(int i=0; i<='z'-'a'; i++) 
		if( mapa[i] == 0 ){
			for(int j=0; j<='z'-'a'; j++) 
				if( v[j] == false ){
					mapa[i] = (char)(j+'a');
				}
		}

//	for(int i=0; i<='z'-'a'; i++) cerr << (char)('a'+i) << " -> " << mapa[i] << endl;

	scanf("%d",&ileTestow);

	for(int q=1; q<=ileTestow; q++){
		printf("Case #%d: ",q);
		
		char c;
		while( (c=getchar()) > 0 && (c<'a' || c>'z') );
		if( c >= 'a' && c <= 'z' ) cout << mapa[ c-'a' ];		

		while( (c=getchar()) > 0 && c != '\n' ){
			if( c >= 'a' && c <= 'z' ) cout << mapa[ c-'a' ];		
			else cout << c;
		}
		
		cout << endl;
	}

	return 0;
}
