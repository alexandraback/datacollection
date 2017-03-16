#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <fstream>
using namespace std ;

#define PB push_back

const int N = 521196 ;

int N1 , N2 ;
vector<int> W2 ;
vector<int> P12[30][30] ;
vector<int> P13[30][30] ;
vector<int> P23[30][30] ;

string W[N+1] , S ;
int F[5000][10] ;	
int Ans , Len ;
int P1[30] , P2[30][30] ;

void Init() {
	ifstream fin("Dir.txt") ;
	for ( int i = 0 ; i <= 25 ; i ++ ) P1[i] = N*2 ;
	for ( int i = 0 ; i <= 25 ; i ++ )
		for ( int j = 0 ; j <= 25 ; j ++ ) {
			P12[i][j].clear() ;
			P13[i][j].clear() ;
			P23[i][j].clear() ;
		}
	
	N1 = N2 = 0 ;
	for ( int i = 1 ; i <= N ; i ++ ) {
		fin >> W[i] ;
		if ( W[i].size() <= 2 ) {
			W2.PB(i) ;
		} else {
			P12[W[i][0]-'a'][W[i][1]-'a'].PB(i) ;
			P13[W[i][0]-'a'][W[i][2]-'a'].PB(i) ;
			P23[W[i][1]-'a'][W[i][2]-'a'].PB(i) ;
		}
	}
}

void Check(int i , int j , int k) {
//	if ( i == 0 && j == 4 ) cout << "k=" << k << "\n" ;
	
	vector<int> WA ; WA.clear() ;
	WA.PB(i-j) ;
	for ( int l = 1 ; l <= W[k].size() ; l ++ )
		if ( W[k][l-1] != S[i+l-1] )
			WA.PB(i+l) ;
	int pan = true ;
	
	for ( int l = 1 ; l < WA.size() ; l ++ )
		if ( WA[l] - WA[l-1] < 5 ) {
			pan = false ;
			break ;
		}
	if ( !pan ) return ;
	
	if ( i+(int)W[k].size()-WA[(int)WA.size()-1] > 4 ) {
		if ( F[i][j] + (int)WA.size() - 1 < F[ i+(int)W[k].size() ][4] )
			F[ i+W[k].size() ][4] = F[i][j] + WA.size() - 1 ;
	} else {
		if ( F[i][j] + (int)WA.size() - 1 < F[ i+(int)W[k].size() ][ i+(int)W[k].size()-WA[(int)WA.size()-1] ] )
			F[ i+W[k].size() ][ i+W[k].size()-WA[WA.size()-1] ] = F[i][j] + WA.size() - 1 ;
	}
}

void Solve() {
	Len = S.size() ;
	for ( int i = 0 ; i <= Len ; i ++ )
		for ( int j = 0 ; j <= 4 ; j ++ )
			F[i][j] = Len*2 ;
	F[0][4] = 0 ;
	for ( int i = 0 ; i < Len ; i ++ ) {
		for ( int j = 0 ; j <= 4 ; j ++ ) if ( F[i][j] < Len*2 ) {
			for ( int u = 0 ; u < W2.size() ; u ++ ) {
				int k = W2[u] ;
				if ( W[k].size() + i <= Len ) Check(i,j,k) ;
			}
			
			if ( i+2 > Len ) continue ;
			
			for ( int u = 0 ; u < P12[S[i]-'a'][S[i+1]-'a'].size() ; u ++ ) {
				int k = P12[S[i]-'a'][S[i+1]-'a'][u] ;
				if ( W[k].size() + i <= Len ) Check(i,j,k) ;
			}
			for ( int u = 0 ; u < P13[S[i]-'a'][S[i+2]-'a'].size() ; u ++ ) {
				int k = P13[S[i]-'a'][S[i+2]-'a'][u] ;
				if ( W[k].size() + i <= Len ) Check(i,j,k) ;
			}
			for ( int u = 0 ; u < P23[S[i+1]-'a'][S[i+2]-'a'].size() ; u ++ ) {
				int k = P23[S[i+1]-'a'][S[i+2]-'a'][u] ;
				if ( W[k].size() + i <= Len ) Check(i,j,k) ;
			}
		}
	}
	
	Ans = F[Len][0] ;
	for ( int i = 0 ; i <= 4 ; i ++ )
		Ans = min(Ans , F[Len][i]) ;
}

int main() {
	freopen("C.in" ,"r",stdin) ;
	ofstream fout("C.out") ;
	Init() ;
	int Test ; cin >> Test ;
	for ( int i = 1 ; i <= Test ; i ++ ) {
		cin >> S ;
		Solve() ;
		cout << "Case #" << i << ": " << Ans << "\n" ;
		fout << "Case #" << i << ": " << Ans << "\n" ;
	}
}












