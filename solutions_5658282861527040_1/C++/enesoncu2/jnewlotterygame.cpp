#include<bits/stdc++.h>

#define lli long long int
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define all(gg)	gg.begin(),gg.end()
#define foreach( gg,it )	for( typeof(gg.begin())	it=gg.begin();it!=gg.end();it++ )
#define FP( ii,aa,bb )	for( int ii=aa;ii<=bb;ii++ )
#define FM( ii,aa,bb )	for( int ii=aa;ii>=bb;ii-- )

using namespace std;

lli a,b,k,dp[45][4][4][4],A[45],B[45],C[45];

lli bul( int ind,int a,int b,int c ){
	lli &ret = dp[ind][a][b][c];
	if( ret!=-1 )	return ret;
	if( ind==41 )	return ret=1;
	ret = 0;
	ret += bul( ind+1,(a==0?0:A[ind]==1?0:1),(b==0?0:B[ind]==1?0:1),(c==0?0:C[ind]==1?0:1) );
	if( ( !a or A[ind]==1 ) )	ret += bul( ind+1,(a==0?0:1),(b==0?0:B[ind]==1?0:1),(c==0?0:C[ind]==1?0:1) );
	if( ( !b or B[ind]==1 ) )	ret += bul( ind+1,(a==0?0:A[ind]==1?0:1),(b==0?0:1),(c==0?0:C[ind]==1?0:1) );
	if( ( !a or A[ind]==1 ) and ( !b or B[ind]==1 ) and ( !c or C[ind]==1 ) )	
		ret += bul( ind+1,(a==0?0:1),(b==0?0:1),(c==0?0:1) );
	return ret;
}

int main(){
	int t;
	cin >> t;
	FP( CASE,1,t ){
		cin >> a >> b >> k;
		a--;
		b--;
		k--;
		FP( i,1,40 )
			A[i] = ((a&(1LL<<40-i))!=0);
		FP( i,1,40 )
			B[i] = ((b&(1LL<<40-i))!=0);
		FP( i,1,40 )
			C[i] = ((k&(1LL<<40-i))!=0);
		memset( dp,-1,sizeof dp );
		cout << "Case #" << CASE << ": " << bul( 1,1,1,1 ) << endl;
	}
}
