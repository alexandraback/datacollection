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

char conn[1000][1000];

//FOR UNDIRECTED GRAPH
int mapsinforest(char conn[1000][1000],int sz){//no need to call trasitiveclosure ,complexity(n^2)
int ans=0;
vi covered(sz,0);
for(int e3=0;e3<sz;e3++){
queue<int> q;
int p;
q.push(e3);
rep(e2,0,sz){
covered[e2]=0;
}

while(!q.empty()){
p=q.front();
q.pop();
for(int e1=0;e1<sz;e1++){
if(conn[p][e1]=='y'){
q.push(e1);
covered[e1]++;
if(covered[e1]>1)goto found;}
}
}
}


return ans;

found:
return 1;
}





//ll memo[
//ll A[
void solveTest(int test){
//memset(memo,0,sizeof(memo));
//memset(A,0,sizeof(A));
//fill levels
rep(e1,0,1000)
rep(e2,0,1000)
conn[e1][e2]='n';


int ans=0;
int n,m,x;
scanf("%d\n", &n);
rep(e1,0,n){
scanf("%d", &m);
rep(e2,0,m){
scanf("%d",&x);
conn[e1][x-1]='y';
}
scanf("\n");
}
ans=mapsinforest(conn,n);





printans:;
if(ans)
printf("Case #%d: Yes\n",test);
else
printf("Case #%d: No\n",test);
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
