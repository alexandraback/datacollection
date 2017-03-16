#include <algorithm>
#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <numeric>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define IREP(it,array) for(vector<int>::iterator it=array.begin(); it!=array.end(); ++it)
#define PREP(it,array) for(vector<P>::iterator it=array.begin(); it!=array.end(); ++it)
#define SREP(it,array) for(vector<string>::iterator it=array.begin(); it!=array.end(); ++it)

#define MP       make_pair
#define PB       push_back
#define ALL(x)   (x).begin(),(x).end()

const int INF = 1<<29;
const double EPS = 1e-9;
double zero(double d){
  return d < EPS ? 0.0 : d;
}

typedef long long LL;
typedef pair<int,int> P;


int main()
{
  cout.setf(ios::fixed, ios::floatfield);
  cout.precision(7);

  int T;
  cin >> T;
  REP(targetNum,T){

    int A,N;
    cin>>A>>N;

    int motes[N];
    REP(i,N){
      int t;
      cin>>t;
      motes[i]=t;
    }

    sort(motes, motes+N);

    int myM = A;
    int res=0;
    int removed=0;
    int tmpRes = INF;
    REP(i,N){

      //      cout << res << " " << tmpRes << endl;

      //      if( i+removed >= N )
      //	break;


      if(motes[i] >= myM){  // add
	//	cout << myM << endl;
	int tmp = 0;
	while(motes[i] >= myM){
	  myM += (myM-1);
	  tmp++;
	  if(tmp>=N){
	    break;
	  }
	}
	myM += motes[i];
	
	if( tmp >= (N-i) ){
	  // remove
	  //	  removed += tmp;
	  res += N-i;
	  break;
	}
	else{
	  tmpRes = min(tmpRes, res + N-i);
	  res += tmp;
	}
	
      }
      else{
	myM += motes[i];
      }
    }


    cout << "Case #" << targetNum+1 << ": " ;
    cout << min(tmpRes,res);
    cout << endl;
  }


  return 0;
}
