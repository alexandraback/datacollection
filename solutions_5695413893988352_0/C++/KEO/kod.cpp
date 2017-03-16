#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>

#define fi first
#define se second
#define pb push_back
#define sz(a) (((int)a.size()))
#define dist(a,b) ((a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se))

using namespace std;

typedef pair<int,int> ii;
typedef long long int Lint;

const int MAXN=1e5+15;

int N,M,T,res=1e9;;
int ar[MAXN];

string s1,s2;
string res1,res2;

int turn( string str ){
	
	int num=0;
	int ten=1;
	
	for( int i=N-1 ; i>=0 ; i--,ten*=10 )
		num += (str[i]-'0')*ten;
	
	return num;
}

void f( int pl ){
	
	if(pl==N){
		
		int n = turn(s1);
		int m = turn(s2);
		
		//~ cerr << n << ' ' << m <<endl;
		
		
		if( abs(n-m)<res ){
			res = abs(n-m);
			res1=s1;
			res2=s2;
		}
		else if( abs(n-m)==res ){
			
			if( n<turn(res1) || ( n==turn(res1) && m<turn(res2)) ){
				res1=s1;
				res2=s2;
			}
		}
		
		return;
	}
	
	if( s1[pl] == '?' && s2[pl] == '?' ){
		
		for( int i=0 ; i<10 ; i++ )
			for( int j=0 ; j<10; j++ ){
				s1[pl] = i+'0';
				s2[pl] = j+'0';
				f(pl+1);
			}
		s1[pl] = s2[pl] = '?';
	}
	else if( s1[pl] == '?' ){
		for( int i=0 ; i<10 ; i++ ){
			s1[pl] = i+'0';
			f(pl+1);
		}
		s1[pl] = '?';
	}
	else if( s2[pl] == '?' ){
		for( int i=0 ; i<10 ; i++ ){
			s2[pl] = i+'0';
			f(pl+1);
		}
		s2[pl] = '?';
	}
	else
		f(pl+1);
	
}

int main(){
	
	scanf("%d",&T);
	
	for( int Case=1 ; Case<=T ; Case++ ){
		
		res = 1e9;
		res1 = res2 = "";
		cin >> s1 >> s2;
		N = sz(s1);
		
		f(0);
		
		cout << "Case #" << Case << ": " << res1 << ' ' << res2 << endl;
	}
	
	return 0;
}