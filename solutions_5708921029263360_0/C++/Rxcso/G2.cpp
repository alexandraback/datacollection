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


int main(){
    
    int T,caso=1;
    cin>>T;
    
    while(T--){
        int a,b,c,k;  
        scanf("%d %d %d %d",&a,&b,&c,&k);
        
        printf("Case #%d: ",caso++);
        if( k>=c ){
            printf("%d\n",a*b*c);
            FOR(i,a)FOR(j,b)FOR(l,c){
                printf("%d %d %d\n",i+1,j+1,l+1);
            }
            continue;
        }
        
        
        printf("%d\n",a*b*k);
            FOR(i,a)FOR(j,b)FOR(l,k){
                printf("%d %d %d\n",i+1, j+1, (i*k+j*k+l)%c + 1);
            }
           
        
        

              
                    
    }    
    

    return 0;
}




