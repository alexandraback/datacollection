#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;
ofstream bug;
const bool DEBUG = true; 
const int MAXN = 2000+1;
const char PROBLEM[] = {"bs3"}; 
char *PROB;

int tests, test; 
int i, j, k, r, x, y, m, n, ans; 
int S, P; 
int use[MAXN]; 
string s; 

struct Node{
    int x;
    int y; 
    int id; 
};
int a[MAXN], b[MAXN];

template <class T> void debug(T t){ if (DEBUG) bug << "[" << t << "]"; }
template <class T> void debug(T t, T t2){ if (DEBUG) bug << "[" << t << "," << t2 << "]"; }
template <class T> void debug(T t, T t2, T t3){ if (DEBUG) bug << "[" << t << "," << t2 << "," << t3 << "]"; }
bool sort_asc(Node a, Node b) { return  a.x < b.x; }
bool sort_asc2(Node a, Node b) { return  a.y > b.y; }

int main(){
if (DEBUG) {
    PROB = new char[10];
    strcpy(PROB, PROBLEM); freopen(strcat(PROB, ".in"), "r", stdin); 
    strcpy(PROB, PROBLEM); freopen(strcat(PROB, ".out"), "w", stdout);
    strcpy(PROB, PROBLEM); bug.open(strcat(PROB, ".txt")); 
}
    
    scanf("%d", &tests);
    
for (test = 1; test <= tests; ++test){
    if (DEBUG) bug << endl << "Case #" << test << ": " << endl; 
    scanf("%d", &n);
    ans = 0; 
    for (i = 0; i < n; ++i ) {
        scanf("%d %d", &a[i], &b[i]); 
    }
    memset(use, 0, sizeof(use)); 
    for (i = 0; i < n; ++i ){
        //debug(b[i].id, b[i].x);
    }
    //sort(a, a+n, sort_asc2);
    //sort(b, b+n, sort_asc);
    for (i = 0; i < n; ++i ){
        //debug(b[i].id, b[i].x);
    }
    int own = 0; 
    bool fail = false; 
    
    while (true){
	   bool fail = false;
	   for (int j = 0; j < n; ++j)
	       if (use[j] != 2 && b[j] <= own){
		      ++ans;
			  own += 2 - use[j];
			  use[j] = 2;					
			  fail = true;
			  debug(own); 
		   }
		debug(ans); 
        if (!fail){
		   int v = -1;
		   for (int i = 0; i < n; ++i)
		   if (use[i] == 0 && a[i] <= own && ( b[i] > b[v] || v == -1 ))
		      v = i;
		   if (v == -1) break;
		   use[v] = 1;
		   debug(ans); 
		   ++ans;
		   ++own;
		}
	}
    
    if (own != (n<<1)) 
        printf("Case #%d: Too Bad\n", test); 
    else
        printf("Case #%d: %d\n", test, ans); 
}   
     
    return 0;  
}
