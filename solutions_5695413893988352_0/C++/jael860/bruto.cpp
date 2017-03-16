#include <bits/stdc++.h>

#define NDEBUG
#ifdef NDEBUG
#include "debug.h"
#endif

#define mp make_pair
#define pb push_back
#define all(x) (x).begin() , (x).end()
#define rall(x) (x).rbegin() , (x).rend()
#define REP(i,x,y) for(int i=x;i<y;i++)
#define REPIT(it,A) for(typeof(A.begin()) it = (A.begin()); it!=A.end();it++)
#define fst first
#define snd second
#define sqr(x) ((x)*(x))

#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#define ones(x) __builtin_popcount(x)
using namespace std;

typedef pair<int,int> ii ;
typedef long long ll ;
typedef vector<int> vi;
typedef vector<ii> vii;

string s,t;

bool check(int a, int id){
	string ss;
	if(id == 0) ss = s;
	else ss = t;
	reverse(all(ss));
	int i = 0;
	while(a > 0){
		int d = a % 10;
		a /= 10;
		char e = d + '0';
		if(e == ss[i] || ss[i] == '?'){
			i++; continue;
		}else{
			return false;
		}	
	}

	REP(j,i,ss.length()){
		if(ss[j] == '0' || ss[j] == '?' ) continue;
		else return false;
	}
	return true;
}

bool isComp(int a, int b){
return	check(a,0) && check(b,1);
}

void pprint(int a , int n){
	int i = 0;
	string ss = "";
	while(a> 0 ){
		int d = a % 10;
		a /= 10;
		char e = d +'0';
		ss += e;
		i++;
	}
	REP(j,i,n) ss += "0";
	reverse(all(ss));
	cout<<ss;
}

int main(){
	fastio;
	int T;
	cin >> T;
	for(int test = 1; test <= T; test++){
		cin >> s >> t;
		int n = s.length();
		int tope = 1;
		int mindif = 100000000;
		int uno = 100000000;
		int dos = 100000000;
		REP(i,0,n) tope *= 10;
		//debug(tope);
		REP(c1, 0,tope){
			REP(c2, 0, tope){
				
				if(!isComp(c1,c2)) continue;
				int dif = abs(c1-c2);
				//cerr<<c1<< " " <<c2<<" "<<dif<<" "<<mindif<<endl;
				if(dif < mindif){
					mindif = dif;
					uno = c1;
					dos = c2;
				}	else if(dif == mindif){
					if(c1 < uno){
						uno = c1;
						dos = c2;
					}else if(c1 == uno){
						if(c2 < dos){
							dos = c2;
						}			
					}
				}
			}
		}
		cout<<"Case #"<<test<<": ";
		pprint(uno,n);
		cout<<" ";
		pprint(dos,n);
		cout<<endl;
	}

	return 0;
}

