#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include<cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>

 
using namespace std;
  
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef double ld;
typedef vector<ld> vld;

   
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define fore(i, a, n) for(int i = (int)(a); i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define fornl(i,n)   for(ll i=0;i<n;i++)
#define len			  size()
#define s(n)          scanf("%d",&n);
#define slld(n)       scanf("%lld",&n);
#define sf(n)         scanf("%lf",&n);
#define ss(n)         scanf("%s",n);
#define maX(a,b)      (a>b?a:b)
#define miN(a,b)      (a<b?a:b)
#define MEM(a,b)      memset(a,(b),sizeof(a))  //memset(arr,0,sizeof(arr))
#define istr(S)       istringstream sin(S)
#define MOD           1000000007    
#define p(n) printf("%d",n);
#define nl printf("\n");
#define pl(n) printf("%ld",n);

    const long double EPS = 1E-9;
    const int INF = (int) 1E9;
    const ll INF64 = (ll) 1E18;
     int main()
     {
	int t;
	cin>>t;
	//cout<<t;
	int y=0;
	while(t--) {
		y++;
	//	cout<<y<<endl;
		char board[4][4];
		bool full=1;
		forn(i,4) {
			forn(j,4) {
				cin>>board[i][j];
				if(board[i][j]=='.') full=0;
			}
		}
		int f=0;
		forn(i,4) {
			char pr='1';	
			int tot=0;		
			forn(j,4) {
				if(pr=='1') {
					if(board[i][j]=='T') tot++;
					else if(board[i][j]=='X') tot++,pr='X';
					else if(board[i][j]=='O') tot++,pr='O';
				}
				else if(pr!='1') {
					if(board[i][j]!=pr && board[i][j]!='T') break;
					tot++;
				}
			}
			if(tot==4 && pr=='X') {f=2;break;}
			if(tot==4&& pr=='O') {f=1;break;}

		}
		if(f==0) {
			forn(j,4) {
				char pr='1';	
				int tot=0;		
				forn(i,4) {
					if(pr=='1') {
					if(board[i][j]=='T') tot++;
					else if(board[i][j]=='X') tot++,pr='X';
					else if(board[i][j]=='O') tot++,pr='O';
				}
				else if(pr!='1') {
					if(board[i][j]!=pr && board[i][j]!='T') break;
					tot++;
				}
			}
			if(tot==4 && pr=='X') {f=2;break;}
			if(tot==4&& pr=='O') {f=1;break;}

		}
		}
		int tot=0;
		char pr='1';
		if(f==0)  {
		forn(i,4) {	
			
			if(board[i][i]=='T' || board[i][i]==pr||pr=='1') {
				if(board[i][i]!='T') pr=board[i][i];
				tot++;
			}
		}
			if(tot==4 && pr=='X') {f=2;}
			if(tot==4&& pr=='O') {f=1;}

		}
		if(f==0) {
		 tot=0;
		 pr='1';
		forn(i,4) {
		
			
			if(board[i][4-i-1]=='T' || board[i][4-1-i]==pr||pr=='1') {
				if(board[i][3-i]!='T') pr=board[i][3-i];
				tot++;
			}
		}
			if(tot==4 && pr=='X') {f=2;}
			if(tot==4&& pr=='O') {f=1;}

		

	}
		if(f==1) { cout<<"Case #"<<y<<": O won\n"; }
		else if(f==2) { cout<<"Case #"<<y<<": X won\n"; }
		else if(full==1) { cout<<"Case #"<<y<<": Draw\n"; }
		else { cout<<"Case #"<<y<<": Game has not completed\n"; }
	

	}
     }

