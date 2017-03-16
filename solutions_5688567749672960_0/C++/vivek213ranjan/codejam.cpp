#include <bits/stdc++.h>
using namespace std;
#define INPUT ( { int a ; read(a) ; a; } )
#define forab(i, a, b)	for (__typeof (b) i = (a) ; i <= b ; ++i)
#define loopy(i, n)		forab (i, 0, (n) - 1)
typedef pair<int,int> ii;
template<class T>inline bool read(T &x){int c=getchar();int sgn=1;while(~c&&c<'0'||c>'9'){if(c=='-')sgn=-1;c=getchar();}for(x=0;~c&&'0'<=c&&c<='9';c=getchar())x=x*10+c-'0'; x*=sgn; return ~c;}
const int MAX = 1000010 ;
bool visited[MAX] ;
int func(int number);
int main()
{
	freopen ("input.txt", "r", stdin);
	freopen("output.txt","w",stdout);
     int  t = INPUT ;
     for (int  cases = 1 ; cases <= t ; cases++ )
     {
	int result=0;
         int n = INPUT ;
         queue < ii > bfs ;
         loopy(i,n+1 ) 
	 visited[i] = 0 ;
         bfs.push(make_pair(1,1)) ;
         visited[1]=1 ;
         while(!bfs.empty() )
         {
             int topa = bfs.front().first;
             int topb = bfs.front().second;
             bfs.pop();
             if(topa==n)
             {
                 result=topb;
                 break;
             }
             if(topa+1<=n && !visited[topa+1])
             {
                 visited[topa+1] = 1 ;
                 bfs.push( make_pair (topa+1 ,topb+1 ));
             }
             int r = func(topa);
             if(r<=n && !visited[r] )
             {
                 visited[r]=1 ;
                 bfs.push( make_pair (r,topb+1) );
             }
         }
         printf("Case #%d: %d\n",cases,result);
 }
    return 0;
}
int func(int number)
{
    vector <int> vec ;
    while(number)
    {
	int digit=number%10;
        vec.push_back(digit);
        number/=10;
    }
    reverse(vec.begin(),vec.end() );
    int i;
    int mul=1 ;
    int current=0 ;
    loopy(i,vec.size() )
    {
        current=current+(vec[i]*mul);
        mul*=10;
    }
    return current;
}

