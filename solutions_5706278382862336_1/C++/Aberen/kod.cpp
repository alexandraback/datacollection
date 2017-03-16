#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define fill(x,y) memset((x),(y) ,sizeof(x))
#define type(x) __typeof(x.begin())
#define sz(x) x.size()
#define o ((f+l)/2)
#define umax(x,y) (x)=max((x),(y))
#define NEW(x) (x *)calloc(1,sizeof(x))
#define umin(x,y) (x)=min((x),(y));
#define tmax(x,y,z) max((x),max((y),(z))) 
#define tmin(x,y,z) min((x),min((y),(z))) 
#define PI (acos(-1)) 

using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef long long int Lint;
int T,flag=0,K;
Lint A,B,maxa,maxb;
int main ()
{
	//~ freopen("in","r",stdin);
	//~ freopen("out","w",stdout);
	char ch;
	scanf("%d",&T); K=T;
	while( T-- ){
		scanf("%lld%c%lld",&A,&ch,&B);
		printf("Case #%d: ",K-T);
		Lint ebob=__gcd( A , B );
		//~ printf("%lld\n",ebob);
		A/=ebob;
		B/=ebob;
		ebob=1;
		flag=0;
		while( A ){
				maxa=A;
			if( A & ebob )	
				A-=ebob;
			ebob*=2;
		}
		ebob=1;
		while( B ){
			maxb=B;
			if( B&ebob ){
				B-=ebob;
				flag++;
				//~ printf("~~~~%lld\n",ebob);
			}
			ebob*=2;	
		}
		//~ printf("------%lld %lld\n",maxa,maxb);
		if( flag>1 )
		printf("impossible\n");
		else{ 
			maxb/=maxa;
			int i=1;
			ebob=1;
			while( maxb ){
				if( maxb & ebob ){
					printf("%d\n",i-1);
					break;
				}
				i++;	
				ebob*=2;
			}
		}
	}
	return 0;
}
		
