//Done by Grey Matter
//Fet per Ferran Alet

#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>
#include<map>
#include<queue>
#include<fstream>
#include<algorithm>
#include<string>
#include<stack>
#include<numeric>
#include<set>
#include<sstream>
#include<list>

#define INF 2147483647
#define LINF 1000000000000000000LL
#define EPS 1e-9
#define debug(x) cerr << #x << " = " << x << endl
#define FOR(x,y) for(int x=0;x<y;x++)
#define FORU(x,y) for(int x=1;x<=y;x++)
using namespace std;


typedef long long ll;
typedef pair<int,int> PII;
typedef vector<long long> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<string> VS;
typedef map<int,int> MII;
typedef MII::iterator iMII;

ifstream fin("B-small.in");
ofstream fout("B-small.out");


int main(){
 // ios_base::sync_with_stdio(false);
  int casos;
  fin>>casos;
  for(int cas=1;cas<=casos;++cas){
    int a,b;
    fin>>a>>b;
    fout<<"Case #"<<cas<<": ";
    if(a<0) for(int i=0;i<-a;++i) fout<<"EW";
    else for(int i=0;i<a;++i) fout<<"WE";
    if(b<0) for(int i=0;i<-b;++i) fout<<"NS";
    else for(int i=0;i<b;++i) fout<<"SN";
    fout<<endl;
  }  
  system("pause");
}  
