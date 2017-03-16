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
#define rep(a,b,c) for(long long(a)=(b);(a)<(c);(a)++)
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



//ll memo[
//ll A[


void solveTest(int test){
//memset(memo,0,sizeof(memo));
//memset(A,0,sizeof(A));
//fill levels
double ans=0;
double d;
int n, a;
double t, x;
vector<double>tim,pos;
double sp;
scanf("%lf %d %d\n", &d, &n, &a);
rep(e1,0,n){
scanf("%lf %lf\n", &t, &x);
tim.pb(t);
pos.pb(x);}

rep(e1,0,n){
if(pos[e1]>d){
if(e1==0){
pos.clear();
tim.clear();
}
else{
tim[e1]=tim[e1-1]+(((tim[e1]-tim[e1-1])*(d-pos[e1-1]))/(pos[e1]-pos[e1-1]));
//printf("%lf",tim[e1]);
pos[e1]=d;
tim.resize(e1+1);
pos.resize(e1+1);
}

goto out;
}
}

out:;

printf("Case #%d:\n",test);
rep(e1,0,a){
scanf("%lf",&sp);
ans=0;
rep(e2,0,s(pos)){
ans=max(ans,tim[e2]-sqrt(((2*pos[e2])/sp)));
}
ans+=sqrt(2*d/sp);

printans:;
printf("%.8lf\n",ans);

scanf("\n");
}
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
