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
int intlen(int num)
{
    int length=0,temp=num;
    while(temp)
    {
        temp/=10;
        length++;
    }
    return length;
}

int rotate(int num, int l)
{
    int last=num%10,i=1;
    last=last*pow(10,l-1);
    return (last + (num/10));
}

int main()
{
    //COMMENT THIS LINE BEFORE POSTING!
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    //COMMENT THIS LINE BEFORE POSTING!
    int t,x,a,b,num,i,temp1,temp2;
    scanf("%d",&t);
    x=t;
    while(t--)
    {
        scanf("%d",&a);
        scanf("%d",&b);
        set <int> sets;
        int count=0;
        for(num=a;num<=b;num++)
        {
            int length=intlen(num);
            temp1=num;
            temp2=num;
            for(i=0;i<length;i++)
            {
                temp2=rotate(temp2, length);
                if(temp1==temp2) break;
                if((temp2>=a&&temp2<=b))
                {
                    int final=temp1*pow(10,length-1)+temp2;
                    if(sets.count(final)==0)
                    {
                        sets.insert(final);
                        //cout<<final<<endl;
                        count++;
                    }

                }

            }
        }
        cout<<"Case #"<<x-t<<": "<<(count/2)<<endl;
    }
}
