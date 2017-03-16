# include <iostream>
# include <cmath>
# include <vector>
# include <string>
# include <algorithm>
# include <ostream>
# include <fstream>
# include <queue>
# include <stack>
# include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<pair<int, int> > vp;
typedef vector<vd> vvd;


# define REP(i,a,b) for(int i = a; i < b; i++)
# define REVREP(i,a,b) for(int i = a; i >= b; i--)
# define newl cout << endl
# define debl(a) cout << a << " "
# define debl2(a,b) cout << a << " " << b << " "
# define debnl(a) cout << a << endl
# define debnl2(a,b) cout << a << " " << b << endl
# define minv(a) *min_element(a.begin(), a.end())
# define maxv(a) *max_element(a.begin(), a.end())
# define minvind(a) min_element(a.begin(), a.end())
# define maxvind(a) max_element(a.begin(), a.end())

//string CaseName = "prac";
string CaseName = "C-small-attempt2";
//string CaseName = "C-large";

// Input Stream for input data //
ifstream In;

// Opens output stream //
ofstream Out;

void Solve(void) {
  
  int J, P, S, K;
  
  In >> J >> P >> S >> K;
  
//  int total = min(J, K) * min(P, K) * min(S, K);
  int total = min( J*P*min(S,K), min(P*S*min(J,K), J*S*min(P,K)) );
  
  //cout << total << endl;
  //Out << total << endl;
  
  vvi JP(J, vi(P, 0));
  vvi JS(J, vi(S, 0));
  vvi PS(P, vi(S, 0));
  
  vi listJ, listP, listS;
  
  //cout << JP.size()  << endl;
  int ncount = 0;
  REP(i, 1, J+1) {
    
    REP (j, 1, P+1) {
      
      REP (k, 1, S+1) {
        
        if ((JP[i-1][j-1] < K) && (JS[i-1][k-1] < K) && (PS[j-1][k-1] < K)) {
        
          //cout << i << " " << j << " " << k <<  endl;
          //Out << i << " " << j << " " << k <<  endl;
          
          JP[i-1][j-1]++; JS[i-1][k-1]++; PS[j-1][k-1]++;
          
          listJ.push_back(i);
          listP.push_back(j);
          listS.push_back(k);
          ncount++;
        }
        
      }
    }  
  }
  
//  if (ncount != total) {
//    cout << "Something is wrong !!" << endl;
//  }
  
  Out << ncount << endl;
  cout << ncount << endl;
  
  REP(i, 0, ncount) {
    cout << listJ[i] << " " << listP[i] << " " << listS[i] << endl;
    Out << listJ[i] << " " << listP[i] << " " << listS[i] << endl;
  }  
  
  return;
}

int main() {

	int NCases; 
	
	In.open(CaseName+".in");
	
	// Reads Number of cases //
  In >> NCases;
  
  Out.open(CaseName+".out");
  
	
	int i,j;

  REP(i,1,NCases+1) {
  
		Out << "Case #" << i << ": ";
		cout << "Case #" << i << ": ";		
		
    Solve();
		
	}
	// Close Input and Output Files //
	In.close();
	Out.close();

	return 0;

}
