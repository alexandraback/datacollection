#include <algorithm>
#include <bitset>
#include <deque>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <iomanip>
#include <vector>
#include <ctime>
 
#define fst first
#define snd second
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define clr(a, v) memset( a , v , sizeof(a) )
#define pb push_back
#define mp make_pair
#define sz size()
#define FORN( i , s , n ) for( int i = (s) ; i < (n) ; i++ )
#define FOR( i , n ) FORN( i , 0 , n )
#define FORIT( i , x ) for( typeof x.begin() i = x.begin() ; i != x.end() ; i++ )
#define trace(x)    cout << #x << ": " << x << endl;
#define trace2(x, y) cout << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define read ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
using namespace std;
 
typedef long long int64;
typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector <string> vs;
typedef vector <ii> vii;
typedef pair<ii,int> tri;



int M[55][55];

int main(){
    int n;
    long long int m;
    int T,caso=1;
    cin>>T;
    
    long long int E[50];
    E[2]=1;
    FOR(i,48) E[i+3]=E[i+2]*2;
    
    while(T--){
        long long int temp;
        scanf("%d %lld",&n,&m);
        
        
        
        
        printf("Case #%d: ",caso++);
        if(E[n]<m){
            printf("IMPOSSIBLE\n");
            continue;
        }
        printf("POSSIBLE\n");
        FOR(i,n)FOR(j,n) M[i][j]=0;
        FOR(i,n)FORN(j,i+1,n-1)M[i][j]=1;
        
        temp=m;
        for(int i=n-3;i>=0;i--){
            if( temp >= 1<<i ){
                M[i+1][n-1]=1;
                temp -= 1<<i;
            }         
        }     
        if(temp) M[0][n-1]=1;        
        
        FOR(i,n){
            FOR(j,n)printf("%d",M[i][j]);
            printf("\n");
        }                   
    }    
    

    return 0;
}




