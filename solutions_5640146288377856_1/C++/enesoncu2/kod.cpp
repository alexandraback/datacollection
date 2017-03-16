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

int main(){
	freopen("inp.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int	t,id=0;
	cin >> t;
	while( t-- ){
		int	a,b,c;
		cin >> a >> b >> c;
		int	res;
		if( b==c )	res = a+b-1;
		else if( b%c==0 )	res = (b/c)*a+c-1;
		else	res = (b/c)*a+c;

		printf("Case #%d: %d\n",++id,res);
	}
}
