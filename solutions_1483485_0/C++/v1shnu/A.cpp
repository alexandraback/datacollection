// #define GOD DJ
using namespace std;

// HEADER FILES
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <iomanip>
#include <iterator>
#include <sstream>
#include <fstream>
#include <cassert>

// CONSTANTS
#define INF (1<<31)-1
#define PI 3.14159265358979323846264338327950288419716939937510
#define MAXV 100001

// FUNCTIONS
#define MAX(x,y) (x)>(y)?(x):(y)
#define MIN(x,y) (x)<(y)?(x):(y)
// gcd(a,b){ return (b==0)?a:gcd(b,a%b); }
// lcm(a,b){ return a*b/gcd(a,b); }

typedef long long LL;
typedef long double LD;
typedef long long unsigned int LLU;

// END TEMPLATE BY DJ

int main()
{
    // COMMENT THIS LINE BEFORE POSTING!
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    // COMMENT THIS LINE BEFORE POSTING!
    string dec2="YHESOCVXDUIGLBKRTNWJPFMAQ";
    string dec3="yhesocvxduiglbkrztnwjpfmaq";
    string str;
    int t,i,l,n;
    scanf("%d",&t);
    n=t;
    cin.ignore();
    while(t--)
    {
        getline(cin,str);
        l=str.length();
        cout<<"Case #"<<n-t<<": ";
        for(i=0;i<l;i++)
        {
            if(str[i]>='A'&&str[i]<='Z')
                printf("%c",dec2[(int)str[i]-65]);
            else if(str[i]>='a'&&str[i]<='z')
                printf("%c",dec3[(int)str[i]-97]);
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}
