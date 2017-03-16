#include <bits/stdc++.h>

#define	st first
#define	nd second
#define	mp make_pair
#define	pb push_back
#define	lli long long int
#define	all( gg )	gg.begin(),gg.end()
#define	foreach( gg,itit )	for( typeof(gg.begin()) itit=gg.begin();itit!=gg.end();itit++ )
#define	FP( ii,aa,bb ) for( lli ii=aa;ii<=bb;ii++ )
#define	FM( ii,aa,bb ) for( lli ii=aa;ii>=bb;ii-- )
#define	debug(ccc)	cout << #ccc << " = " << ccc << endl;

#define	mod	1000000007LL

using namespace std;

int	k,l,n;
string	keyboard,target;

int	dpf[150][300];

int	f( int a,char c ){
	if( dpf[a][c]!=-1 )	return	dpf[a][c];
    string	p = target.substr( 0,a );
    if( c!=-1 )	p += c;
    while( p.size() and ( p.size()>target.size() or target.substr( 0,p.size() )!=p ) )	p.erase( p.begin() );
    return	dpf[a][c] = p.size();
}

int	vis[150][150];
pair< double,int >  dp[150][150];

pair< double,int >	bul( int n,int p ){
    if( n==0 )	return	mp( 0.0,0.0 );
    if( vis[n][p] )	return	dp[n][p];
    vis[n][p] = 1;
    double	sum=0.0;
    int	maxi=0;
    FP( i,0,keyboard.size()-1 ){
		int	g = f( p,keyboard[i] );
		maxi = max( maxi,bul( n-1,g ).nd+(g==target.size()) );
		sum += bul( n-1,g ).st+(g==target.size())*1.0;
    }
    sum /= keyboard.size()*1.0;
    return	dp[n][p] = mp( sum,maxi );
}

int main(){
	freopen("inp.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int	t,id=0;
	cin >> t;
	while( t-- ){
		cin >> k >> l >> n;
		cin >> keyboard >> target;
		memset( dpf,-1,sizeof dpf );
		memset( vis,0,sizeof vis );
        printf("Case #%d: %.12lf\n",++id,1.0*bul( n,0 ).nd-bul( n,0 ).st);
	}
}
