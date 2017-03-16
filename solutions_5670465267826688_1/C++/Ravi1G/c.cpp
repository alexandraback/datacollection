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
string s,orgs;

enum D3D{
    O,I,J,K,NO,NI,NJ,NK
};

D3D mulTable[][4] = { {O,I,J,K},{I,NO,K,NJ},{J,NK,NO,I},{K,J,NI,NO}};

D3D operator*(D3D x,D3D y){
    int a,b,oop;
    a = x;
    b = y;
    int c = 0;
    c = (a>3?1:0) +(b>3?1:0);
    D3D op = mulTable[a%4][b%4];
    oop = op;
    c += (oop>3?1:0);
    if(oop>3) oop = oop-4;
    if(c%2==1) oop+=4;
    return (D3D)oop;

}

void print(D3D a){
    switch(a){
        case O: printf("1 "); break;
        case I: printf("i "); break;
        case J: printf("j "); break;
        case K: printf("k "); break;
        case NO: printf("-1 "); break;
        case NI: printf("-i "); break;
        case NJ: printf("-j "); break;
        case NK: printf("-k "); break;
    }
}

D3D power(D3D a,ll p){
    if(p==1) return a;
    else if(p%2==1) return a*power(a,p-1);
    else{
        D3D temp = power(a,p/2);
        return temp*temp;
    }
}


D3D chto3D(char c){
    switch(c){
        case 'i' : return I;
        case 'j' : return J;
        case 'k' : return K;
    }
}
int main(int argc, char const *argv[])
{   //Test table
    // F(i,0,4) F(j,0,4){
    //     D3D x,y;
    //     x = (D3D)i;
    //     y = (D3D)j;
    //     print(x*y);
    //     if(j==3) printf("\n");
    // }
    int tno=1;
    bool ans=false;
    int l,n;
    ll x;
    D3D fwd[40010],bak[40010];
    TESTS{
        cin>>l>>x;
        cin>>orgs;
        n = 4*l;
        s = (orgs+orgs+orgs+orgs);
        int p1=-1,p2=-1;
        //cout<<s;
        F(i,0,n){
            if(i==0) fwd[i] = chto3D(s[i]) , bak[n-1-i] = chto3D(s[n-1-i]);
            else{
                  fwd[i] = fwd[i-1]*chto3D(s[i]);
                bak[n-1-i] = chto3D(s[n-1-i])*bak[n-i];
            }
            if(p1==-1 && fwd[i]== I ) p1 = i;
            //print(fwd[i]);
            if(p2==-1 && bak[n-1-i]== K ) p2 = i;
            //print(bak[n-1-i]);

        }
        //cerr<<p1<<" "<<p2<<endl;
        if(p1!=-1 && p2!=-1 && (x*l - p1 - p2 -2)>0 && (power(fwd[l-1],x) == NO)){
            printf("Case #%d: YES\n",tno++);
        }else{
            printf("Case #%d: NO\n",tno++);
        }
    }


    return 0;
}