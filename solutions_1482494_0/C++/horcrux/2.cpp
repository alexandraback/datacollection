//author : Parag Gupta
//accepted in : 
// contest :
/* algo: 
 */

#include<cstdio>
#include<stdlib.h>
#include<limits.h>
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<queue>
#include<vector>
#include<list>
#include<stack>
#include<queue>


using namespace std;
#define ll long long int
inline ll power(int base,int n);

#define MX 1005
#define f(x,y,z) for((x)=(y);(x)<(z);(x)++)
#define fe(x,y,z) for((x)=(y);(x)<=(z);(x)++)
#define fm(x,y,z) for((x)=(y) ; (x)>(z) ; (x)--)
#define FLUSH fflush(stdout)
#define copy(dest,src,size) memcpy(dest,src,size)
#define NL {printf("\n");}
#define DOUBLE 1.79769e+308
vector <pair <int,int> > one;
vector <pair <int,int> > two;
pair <int,int> temp;
bool func( pair <int,int> i , pair<int,int> j){
	if( i.first <= j.first ) return true;
	else return false;
}
int main(){
	int t,i,j,k,n;
	int a;
	int b;
	int coins;
	bool flag = 0;
	int x,y;
	int levels;
	int fc[MX];
	int sc[MX];
	scanf("%d",&t);
	for( k = 1; k<=t ;k++){
		scanf("%d",&n);
		coins = 0;
		one.clear();
		two.clear();
		for(i=0;i<n;i++){
			scanf("%d %d",&a,&b);
			temp = make_pair(a,i);
			one.push_back( temp );
			temp = make_pair( b, i);
			two.push_back( temp );
			fc[i] = 1;
			sc[i] = 2;
		}
		/*for(i=0;i<n;i++){
			//printf("%d %d\n",one[i].first,one[i].second);
		}*/
		sort(one.begin(), one.end(),func);
		sort(two.begin(),two.end(),func);
		/*for(i=0;i<n;i++){
			//printf("%d %d %d %d\n",one[i].first,one[i].second , two[i].first , two[i].second);
		}*/

		x=0;
		y=0;
		levels = 0;
		flag = 0;
		while( y<n ){
			if( coins >= two[y].first ){
				coins+= sc[two[y].second];
				fc[ two[y].second ] = 0;
				sc[ two[y].second ] = 0;
				y++;
				levels++;
			}
			else if(x < n && coins >= one[x].first){
				coins += fc[ one[x].second];
				sc[ one[x].second ] -= 1;
				fc[ one[x].second ] = 0;
				x++;
				levels++;
			}
			else {
				flag = 1;
				break;
			}
		}
		printf("Case #%d: ",k);
		if( y < n  ) printf("Too Bad\n");
		else printf("%d\n",levels);
	}


	return 0;
}
/* problem:
 */
inline ll power(int base,int n){
	ll ans=1;
	while(n){
		if(n&1==1) ans*=base;
		base*=base;
		n=(n>>1);
	}
	return ans;
}

