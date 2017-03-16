// =====================================================================================
//       Filename:  Osmos.cpp
//    Description:  
//        Created:  05/04/2013 09:41:17 PM
//         Author:  BrOkEN@!
// =====================================================================================

#include<fstream>
#include<iostream>
#include<sstream>
#include<bitset>
#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
#include<iterator>
#include<string>
#include<cassert>
#include<cctype>
#include<climits>
#include<cmath>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>

#define FOR(i,a,b) for(typeof((a)) i=(a); i <= (b) ; ++i)       
#define FOREACH(it,x) for(typeof((x).begin()) it=(x).begin(); it != (x).end() ; ++it)   
#define NMAX 100


using namespace std;

typedef pair<int,int> PI;
typedef vector<PI> VI;

int m[NMAX];
int a=0,n=0,A=0;
int oper=0;

int dp[NMAX][NMAX];

int func(int A,int x)
{
    while(A<=x)
        {
                A=A+A-1;
                oper++;
        }
        return A;
}


int solve(){

	if(a==1){
		return n;
	}

	sort(m,m+n);
	
	int M=INT_MAX;
        for(int i=0;i<=n;i++) {
                        oper=0;
                        A=a;
                        for(int j=0;j<n-i;j++)
                        {
                                if(m[j]<A)
                                	A+=m[j];
                                else
                                {
                                        A=func(A,m[j])+m[j];
                                }
                        }
                        oper+=i;
                        M=min(M,oper);
			//printf("%d\n",M);
        }

	return M;
}


int main(){
	

	int T=0;
	scanf("%d",&T);
	FOR(t,1,T){
		scanf("%d %d",&a,&n);	
		FOR(i,0,n-1){scanf("%d",&m[i]);}	
		printf("Case #%d: %d\n",t,solve());
	}

	return 0;
}

