#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <set>
#include <functional>
#include <list>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
#define getI(a) scanf("%d", &a)
#define getII(a,b) scanf("%d%d", &a, &b)
#define getIII(a,b,c) scanf("%d%d%d", &a, &b, &c)
#define wez(n) int (n); scanf("%d",&(n))
#define TESTS wez(testow); while(testow--)
#define F(i,L,R) for (int i = L; i < R; i++) //next four are for "for loops"
#define FE(i,L,R) for (int i = L; i <= R; i++)
#define FF(i,L,R) for (int i = L; i > R; i--)
#define FFE(i,L,R) for (int i = L; i >= R; i--)
#define MAX(a,b) ( (a) < (b) ? (b) : (a) )
#define MIN(a,b) ( (a) < (b) ? (a) : (b) )
#define tr(i,t) for (typeof((t).begin()) i=(t).begin(); i!=(t).end(); i++) // traverse an STL data structure
#define ALL(c) (c).begin(),(c).end() //handy for function like "sort()"
#define PRESENT(c,x) ((c).find(x) != (c).end())
#define CPRESENT(c,x) (find(ALL(c),x) != (c).end())
#define REMIN(a,b) (a)=min((a),(b))
#define REMAX(a,b) (a)=max((a),(b)) // set a to the maximum of a and b
#define SZ(x) ((int)((x).size()))
#define lastEle(vec) vec[vec.size()-1]
#define pb push_back
#define mp make_pair

//Debug Macros
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl
#define printA(a,L,R) FE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printV(a) printA(a,0,a.size()-1)



#define MODN 1000000007

#define PI 3.1415926535897932384626
#define LSOne(S) (S & (-S))
#define MAXN 110
using namespace std;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef pair<int,int> ii;
typedef long long ll;


int main(int argc, char const *argv[])
{

    char s[1010];
    int smax,tno=1;
    TESTS{
        getI(smax);
        scanf("%s",s);
        int total=0, ans = 0;
        total = s[0]-'0';
        FE(i,1,smax){
            if(total < i)   ans++, total++;
            total += s[i]-'0';
        }
        printf("Case #%d: %d\n", tno++,ans);
    }


    return 0;
}