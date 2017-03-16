#include<iostream>
#include<fstream>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<list>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<climits>
#include<ctime>
#include<sstream>
#define mp       	make_pair
#define pb       	push_back
#define st       	first
#define nd       	second
#define wait     	getchar();getchar();
#define lint     	long long
#define KARE(a)	 	( (a)*(a) )
#define MAX(a,b) 	( (a)>(b) ? (a) : (b) )
#define MIN(a,b) 	( (a)<(b) ? (a) : (b) )
#define MAX3(a,b,c)	( MAX( a,MAX(b,c) ) )
#define MIN3(a,b,c)	( MIN( a,MIN(b,c) ) )
#define FILL(ar,a)	memset( ar,a,sizeof ar )
#define oo	 		1e9
#define pii       	pair<int,int>
#define pll			pair<lint,lint>
#define pdd			pair<double,double>
#define y1			yy1
#define eps      	(1e-9)
#define esit(a,b)  	( abs( (a)-(b) ) < eps )
#define sol(a)		( (a)<<1 )
#define sag(a)		( sol(a)|1 )
#define orta(a,b)	( ( (a)+(b) )>>1 )
#define mxn       	505
#define md			1000000007
#define mod(a)		( (a)%md )
using namespace std;

vector<string>dif;
string str[mxn];
lint id,test;
lint n;
lint sw[mxn];
lint ew[mxn];
lint fac[mxn];
bool v[mxn];
lint cnt[mxn];

void read(){
	
	cin>>n;
	for( lint i=1 ; i<=n ; i++ )		cin>>str[i];
	return;
	
}

lint check( string s ){
	
	for( lint i=1 ; i<s.size() ; i++ )		if( s[i] != s[i-1] )	return -1;
	return s[0];	
	
}

lint init(){
	
	lint c,i;
	for( i=1 ; i<=n ; i++ ){
		
		char f = check( str[i] );
		if( f==-1 )	dif.pb( str[i] );
		else		cnt[f]++,v[f] = 1;
		
	}
	
	for( i=0 ; i<dif.size() ; i++ ){
		
		string t = dif[i];
		
		if( sw[ t[0] ] != -1 )				return -1;
		if( ew[ t[ t.size()-1 ] ] != -1 )	return -1;
		
		sw[ t[0] ] = t[ t.size()-1 ];
		ew[ t[ t.size()-1 ] ] = t[0];
		
		v[ t[0] ] = 1;
		v[ t[ t.size()-1 ] ] = 1;
	}
	
	for( i=0 ; i<dif.size() ; i++ ){
		
		string t = dif[i];
		int k,j;
		
		for( j=0 ; j<t.size() ; j=k ){
			
			k = j;
			while( k<t.size() && t[k]==t[j] )	k++;
			
			if( j==0 || k==t.size() )	continue;
			
			if( v[ t[j] ]==true )	return -1;
			else 					v[ t[j] ] = true;
		}
		
	}
	
	fac[0] = 1;
	for( lint i=1 ; i<=200 ; i++ )	fac[i] = mod( i*fac[i-1] );
	
	return 1;	
	
}

void solve(){
	
	lint ans = 1;
	
	if( init()==-1 ){
		
		puts( "0" );
		return;
		
	}
	
	lint part=0;
	lint vis[mxn];
	memset( vis,0,sizeof vis );
	
	for( lint c='a' ; c<='z' ; c++ )
	if( sw[c] != -1 && ew[c]==-1 ){
				
		
		lint p;
		lint r=1;
		
		p = c;
		while( p!=-1 ){
			
			if( vis[p]==1 ){
				
				puts( "0" );
				return;
				
			}
			
			vis[p] = 1;
			r = mod( r*fac[ cnt[p] ] );
			p = sw[p];
			
		}		
		
		ans = mod( ans*r );
		part++;
		
	}
	
	for( lint i='a' ; i<='z' ; i++ )
	if( ( sw[i]!=-1 || ew[i]!=-1 ) && vis[i]==0 )	{
		
		puts( "0" );
		return;
	}
	
	for( lint i='a' ; i<='z' ; i++ )
	if( vis[i]==0 && cnt[i] ){
		
		ans = mod( ans*fac[ cnt[i] ] );
		part++;
		
	}
	
	ans = mod( ans*fac[part] );
	cout<<ans<<endl;
	
	return;	
	
}

int main(){
	
		freopen( "input.in" , "r" , stdin );
		freopen( "output.out" , "w" , stdout );
	
	cin>>test;
	for( id=1 ; id<=test ; id++ ){
		
		dif.clear();
		memset( sw ,-1, sizeof sw  );
		memset( ew ,-1, sizeof ew  );
		memset( v  , 0, sizeof v   );
		memset( cnt, 0, sizeof cnt );
		
		read();
		cout<<"Case #"<<id<<": ";
		solve();
	}
	return 0;
}
