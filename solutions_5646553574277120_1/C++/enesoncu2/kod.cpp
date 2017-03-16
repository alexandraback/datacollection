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
		int	c,d,V;
		vector<int>	v;
        cin >> c >> d >> V;
        FP( i,1,d ){
			int	x;
			cin >> x;
			v.pb( x );
        }
        sort( all(v) );
        reverse( all(v) );
        int	can = 0 , res = 0;
        while( can<V ){
			if( !v.size() or v.back()>can+1 ){
				res++;
				can += (can+1)*c;
			}
			else{
				can += v.back()*c;
				v.pop_back();
			}
        }
        printf("Case #%d: %d\n",++id,res);
	}
}
