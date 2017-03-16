#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

    
vector<string> table;
int m;
int R,C,M;

template<class T>
int check(T const & t)
{
  if( m < M ) {
    cout << "Impossible" << endl;
    return 1;
  }
  else if( m == M ) {
    for(int i=0;i<t.size();i++)
      cout << t[i] << endl;
    return 1;
  }
  return 0;
}

#define CK if( check(table) ) goto CTN;

int main(int argc, char *argv[])
{
  int T;
  cin >> T;
  for(int t=1;t<=T;t++) {
    cin >> R >> C >> M;
    cout << "Case #" << t << ":" << endl;

    m = R*C;
    table = vector<string>(R,string(C,'*'));

    table[0][0] = 'c'; m--;
    CK

    if( R == 1 && C == 1 ) {
      CK
    }
    else if( R == 1 ) {
      table[0][1] = '.'; m--;
      CK
      for(int i=2;i<C;i++) {
	table[0][i] = '.'; m--;
	CK
      }
    }
    else if( C == 1 ) {
      table[1][0] = '.'; m--;
      CK
      for(int i=2;i<R;i++) {
	table[i][0] = '.'; m--;
	CK
      }
    }
    else {
      table[1][0] = table[0][1] = table[1][1] = '.'; m -= 3;
      CK;
      
      if( C >= 3 ) {
	table[0][2] = table[1][2] = '.'; m -= 2;
	CK;
      }

      if( R >= 3 ) {
	table[2][0] = table[2][1] = '.'; m -= 2;
	CK;
      }

      for(int i=3;i<C;i++)
	if( m-M >= 2 ) {
	  table[0][i] = table[1][i] = '.'; m -= 2;
	  CK
	}
        else {
	  if( R == 2 )
	    m = -1;
	  else
	    table[2][2] = '.'; m -= 1;
	  CK
	}

      for(int i=3;i<R;i++)
	if( m-M >= 2 ) {
	  table[i][0] = table[i][1] = '.'; m -= 2;
	  CK
	}
        else {
	  if( C == 2 )
	    m = -1;
	  else
	    table[2][2] = '.'; m -= 1;
	  CK
	}

      for(int i=2;i<C;i++)
	for(int j=2;j<R;j++) {
	  table[j][i] = '.'; m--;
	  CK
	}
    }

CTN:
    continue;
  }
  return 0;
}
