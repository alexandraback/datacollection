/*aa.cpp @ 2013/04/13 11:57:27 BY dOMhOW*/
#include	<cstdlib>
#include	<cstdio>
#include	<cstring>
#include	<cmath>
#include	<map>
#include	<algorithm>
#include	<vector>
#include	<set>
#include	<queue>
#include	<iostream>
#include	<sstream>
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
#define forn(i,l,r) for(int i=(int)(l);i<(int)(r);i++)
#define rep(i,x) for(int i=0;i<(int)(x);i++)

typedef long long  LL;

int main ( int argc, char *argv[] )
{
	int T;cin>>T;
	for(int tt=1;tt<=T;tt++){
		char bd[4][10];
		cout<<"Case #"<<tt<<": ";
		for(int i=0;i<4;i++)
			cin>>bd[i];
		string win="";
		rep(i,4){
			bool yes = true;
			rep(j,4)if(!(bd[i][j]=='X'||bd[i][j]=='T'))yes=false;
			if(yes){win="X won";break;}
			yes = true;
			rep(j,4)if(!(bd[i][j]=='O'||bd[i][j]=='T'))yes=false;
			if(yes){win="O won";break;}
			yes = true;
			rep(j,4)if(!(bd[j][i]=='X'||bd[j][i]=='T'))yes=false;
			if(yes){win="X won";break;}
			yes = true;
			rep(j,4)if(!(bd[j][i]=='O'||bd[j][i]=='T'))yes=false;
			if(yes){win="O won";break;}
			yes = true;
			rep(j,4)if(!(bd[j][j]=='X'||bd[j][j]=='T'))yes=false;
			if(yes){win="X won";break;}
			yes = true;
			rep(j,4)if(!(bd[j][j]=='O'||bd[j][j]=='T'))yes=false;
			if(yes){win="O won";break;}
			yes = true;
			rep(j,4)if(!(bd[3-j][j]=='X'||bd[3-j][j]=='T'))yes=false;
			if(yes){win="X won";break;}
			yes = true;
			rep(j,4)if(!(bd[3-j][j]=='O'||bd[3-j][j]=='T'))yes=false;
			if(yes){win="O won";break;}
		}
		if(win!="")cout<<win<<endl;
		else{
			bool has=false;
			rep(i,4)rep(j,4)if(bd[i][j]=='.')has=true;
			if(has)cout<<"Game has not completed"<<endl;
			else cout<<"Draw"<<endl;
		}
	}
	return EXIT_SUCCESS;
}

