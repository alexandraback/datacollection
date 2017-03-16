#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <bitset>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define forall(i,c) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dforn(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define dforsn(i,s,n) for(int i=((int)(n)-1);i>=(int)(n);i--)
#define esta(i,c) ((c).find(i) != (c).end())
#define estal(i,c) (find((c).begin(),(c).end(),(i))!=(c).end())
#define all(c) (c).begin(),(c).end()

#define dbg(x) cerr << #x << " = " << x << endl;
#define raya cerr << string('=',80) << endl;

typedef long long tint;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;

const int N = 1024;
int one[N],two[N],a[N],b[N];
int main(){
	#ifdef JUAMPI
		freopen("test.in","r",stdin);
		freopen("test.out","w",stdout);
	#endif
	
	int testcases=0; scanf("%d",&testcases);
	forsn(testcase,1,testcases+1){
		int n;

		scanf("%d",&n);
		forn(i,n) 
			scanf("%d%d",&a[i],&b[i]);
		
		int cont = 0;
		memset(one,0,sizeof(one));
		memset(two,0,sizeof(two));
		
		while(true){
			bool end = true;
			forn(i,n) end = end && two[i];
			if(end) break;
			
			int stars = 0;
			forn(i,n) 
				if(two[i]) stars += 2; else if(one[i]) stars++;
			
			bool atLeast = false;
			forn(i,n)
				if(!two[i] && stars >= b[i]){
					two[i] = true;
					atLeast = true;

					stars += 2;
					cont++;
				}
			
			if(!atLeast){
				forn(i,n){
					if(!one[i] && stars >= a[i]){
						one[i] = true;
						atLeast = true;

						cont++;
						break;
					} 
				}
			}
			
			if(!atLeast){
				cont = -1; 
				break;
			}
		}
		
		if(cont == -1){
			fprintf(stderr,"Case #%d: Too Bad\n",testcase);
			printf("Case #%d: Too Bad\n",testcase);
		}else{
			fprintf(stderr,"Case #%d: %d\n",testcase,cont);
			printf("Case #%d: %d\n",testcase,cont);		
		}
	}
	return 0;
}
