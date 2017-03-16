//$CWD$\a.exe input >> output

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype>
#include <complex>
#include <cassert>
#include <string>
#include <valarray>
#include <queue>
#include <iterator>
using namespace std;
#define pb push_back
#define B begin()
#define E end()
#define s(a) ((long long)a.size())
#define vs vector<string>
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<long long>
#define vvll vector<vll>
#define vd vector<double>
#define vvd vector<vd>
#define rep(a,b,c) for(int(a)=(b);(a)<(c);(a)++)
#define repd(a,b,c) for(long long(a)=(b);(a)>=(c);(a)--)
#define ll long long

//create large input self

#define lim 55
char buff[lim];
string scanstr(){
cin.getline(buff,lim);
//fprintf(stderr,"%s\n",buff);
return string(buff);
}




class part{
      public:
             int a1;
             int a2;
		 double a3;
             };

bool compp1(part a,part b)
{
     return (a.a1<b.a1);
     }
bool compp2(part a,part b)
{
     return (a.a2<b.a2);
     }
//ll memo[
//ll A[
void solveTest(int test){
//memset(memo,0,sizeof(memo));
//memset(A,0,sizeof(A));
//fill levels
part temp;
vector<part> arr;
int ans=0,x=0,N;
double sum=0;
scanf("%d", &N);
rep(e1,0,N){
scanf("%d\n", &x);
temp.a1=x;
temp.a2=e1;
temp.a3=0;
arr.pb(temp);
sum+=x;}
double origsum=sum;
sum *=2;

sort(arr.B,arr.E,compp1);
rep(e1,0,N){
if((arr[N-1-e1].a1)*(N-e1)>sum) {
sum-=arr[N-1-e1].a1;
}
else{
rep(e2,0,N-e1){

//printf("Cas #%d: %lf, %d\n",e2,sum/(N-e1),arr[e2].a1);
arr[e2].a3=((sum/(N-e1)-arr[e2].a1)*100)/origsum;
}
break;
}
}

sort(arr.B,arr.E,compp2);

printans:;
printf("Case #%d:",test);
rep(e1,0,N)
printf(" %lf",arr[e1].a3);
printf("\n");
return;
printerr:;
printf("Case #%d: IMPOSSIBLE\n",test);//......................check if different case is not required i.e. Impossible
return;}


int main(int argc, char **argv)
{
    if(argc!=2){printf("usage: %s input_file\n", argv[0]);exit (1);}freopen(argv[1], "r", stdin);

	int T, t;
	scanf("%d\n", &T);
	rep(t, 1, T+1){

		//fprintf(stderr, "Solving %d/%d\n", t, T);
		solveTest(t);}
	return 0;
};
