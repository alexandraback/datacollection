#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>
#include <fstream>


using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                        
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }


int main(int argc, char *argv[]){
int t,x=1,len;
string g="";
ifstream in(argv[1],ios::in);
ofstream op("output.txt",ios::out);
in>>t;
getline(in,g);
while(t>0){
  getline(in,g);
  string s=g;
  len=g.length();
  for(int i=0;i<len;i++){
    switch(g[i]){
      case 'a' :
	      s[i]='y';
	      break;
      case 'b' :
	      s[i]='h';
	      break;
      case 'c' :
	      s[i]='e';
	      break;
      case 'd' :
	      s[i]='s';
	      break;
      case 'e' :
	      s[i]='o';
	      break;
      case 'f' :
	      s[i]='c';
	      break;
      case 'g' :
	      s[i]='v';
	      break;
      case 'h' :
	      s[i]='x';
	      break;
      case 'i' :
	      s[i]='d';
	      break;
      case 'j' :
	      s[i]='u';
	      break;
      case 'k' :
	      s[i]='i';
	      break;
      case 'l' :
	      s[i]='g';
	      break;
      case 'm' :
	      s[i]='l';
	      break;
      case 'n' :
	      s[i]='b';
	      break;
      case 'o' :
	      s[i]='k';
	      break;
      case 'p' :
	      s[i]='r';
	      break;
      case 'q' :
	      s[i]='z';
	      break;
      case 'r' :
	      s[i]='t';
	      break;
      case 's' :
	      s[i]='n';
	      break;
      case 't' :
	      s[i]='w';
	      break;
      case 'u' :
	      s[i]='j';
	      break;
      case 'v' :
	      s[i]='p';
	      break;
      case 'w' :
	      s[i]='f';
	      break;
      case 'x' :
	      s[i]='m';
	      break;
      case 'y' :
	      s[i]='a';
	      break;
      case 'z' :
	      s[i]='q';
	      break;
      case ' ':
	      s[i]=' ';
	      break;
      default : 
	    break;
  }
  
}
op<<"Case #"<<x<<": "<<s<<endl;
x++;t--;
}
in.close();
op.close();
return 0;
}