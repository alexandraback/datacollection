//!
///

/**============= Approach =================**
@Author: A Asif Khan Chowdhury
@Category:
/**========================================**/


/**................ Headers ................**/
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <list>
#include <queue>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <sstream>
#include <bitset>
#include <set>

using namespace std;

/**................ Macros ................**/
#define Set(N, j) (N|(1<<j))
#define reset(N, j) (N&~(1<<j))
#define Check(N, j) (bool)(N&(1<<j))
#define toggle(N, j) (N^(1<<j))
#define turnOff(N, j) (N & ~(1<<j))
#define CLEAR(A, x) ( memset(A,x,sizeof(A)) )
#define pi 3.141592653589793
#define pii pair <int, int>
#define pb push_back
#define pf printf
#define S(x) scanf("%d", &x)
#define SL(x) scanf("%ld", &x)
#define out(C) printf("Case #%d: ", C);
#define FOR(i, x, y) for(int i=x; i<=y; i++)
#define open freopen("E:/a.txt", "r", stdin);
#define write freopen("E:/b.txt","w", stdout);
#define MAX (1+(1<<5))
#define inf 0x7fffffff
#define ll long long
#define mod 100000007
#define mx 1010
int gcd(int a, int b) { return b?gcd(b,a%b):a; }

int main()
{
	cin.tie(NULL);
	open
	write
    int test;
    S(test);
    double arr1[mx];
    double arr2[mx];
    FOR(C, 1, test){
        int N;
        cin>>N;
        for(int i=0; i<N; i++)cin>>arr1[i];
        for(int i=0; i<N; i++)cin>>arr2[i];
        out(C);
        sort(arr1, arr1+N);
        sort(arr2, arr2+N);

        int vis1[mx], vis2[mx];
        CLEAR(vis2,0);CLEAR(vis1, 0);
        int winMax=0, winMin=0;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(arr1[i]>arr2[j] and !vis1[i] and !vis2[j]){
                    winMax++;
                    vis1[i]=true;
                    vis2[j]=true;
                    break;
                }
                if(arr1[i]<arr2[j]) break;
            }
        }
        CLEAR(vis2,0);CLEAR(vis1, 0);
        for(int i=N-1; i>=0; i--){
            bool flag=false;
            for(int j=0; j<N; j++){
                if(arr1[i]<arr2[j] and !vis2[j]){
//                    winMin++;
//                    vis1[i]=true;
                    vis2[j]=true;
                    flag=true;
                    break;
                }
            }
            if(!flag) winMin++;
        }
        cout<<winMax<<" "<<winMin<<endl;
    }
    return 0;
}





