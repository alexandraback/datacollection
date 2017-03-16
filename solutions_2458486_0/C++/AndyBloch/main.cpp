// code jam d
int verbose = 0 ;

#include <iostream>
using namespace std ;

void showKeys(int *haveKeys) {
  int i;
  cout << "Keys: " ;
  for (i = 0 ; i < 201 ; i++) {
    if (haveKeys[i])
      cout << i << ":" << haveKeys[i] << " " ;
  }
  cout << endl ;
}

int iterate(int K, int N, int *haveKeys, int **chests, int *T, int *Ki, int *moves, int chestsLeft, int *chestsOpened, int *neededKeys, int *numOwnKeys) {
  if (verbose)
    cout << "Chests left: " << chestsLeft << endl ;
  if (verbose) {
    showKeys(haveKeys);
  }
  if (chestsLeft == 0) {
    if (verbose)
      cout << "No chests left to open!" << endl;
    return 1 ;
  }
  if (N == 0) {
    if (verbose)
      cout << "No chests!" << endl;
    return 1 ;
  }
  if (K == 0)  {
    if (verbose)
      cout << "No keys to start!" << endl;
    return 0 ;
  }
  int c ;
  for (c = 0 ; c < N ; c++) {
    if (chestsOpened[c]) continue ;
    if (!haveKeys[T[c]]) continue ;
    if (verbose) {
      cout << chestsLeft << " chests left, chest " << c+1 << " num keys: " << Ki[c] << " needed " <<  neededKeys[T[c]] << " have " << haveKeys[T[c]] << endl ;
    }
    if ((!Ki[c]) && (haveKeys[T[c]]==1) && (neededKeys[T[c]] > 1) ) {
      if (verbose) {
        cout << chestsLeft << " chests left, chest " << c+1 << " does not have keys and keys are needed for same type " << T[c] << endl ;
      }
      continue ;
    }
    if (verbose) {
      cout << chestsLeft << " chests left, opening chest " << c+1 << " with key " << T[c] << endl ;
    }
      
    if (chestsLeft == 1) {
      moves[0] =  c ;
      return 1;
    }

    haveKeys[T[c]] -- ;
    neededKeys[T[c]] -- ;
    chestsOpened[c]= 1 ;
    int i;
    for (i = 0 ; i < Ki[c] ; i++)
      haveKeys[chests[c][i]] ++ ;
    
    int possible = iterate(K-1+Ki[c],N,haveKeys,chests,T,Ki,moves+1,chestsLeft-1,chestsOpened, neededKeys, numOwnKeys);

    for (i = 0 ; i < Ki[c] ; i++)
      haveKeys[chests[c][i]] -- ;
    chestsOpened[c]= 0 ;
    haveKeys[T[c]] ++ ;
    neededKeys[T[c]]++ ;

    if (possible) {
      moves[0] = c ;
      return 1 ;
    }

  }
  return 0 ;
}

int runTest() {
  int haveKeys[201];
  int allKeys[201];
  int neededKeys[201];
  int ownKeyTypes[201];
  
  int K ;
  int N ;
  cin >> K ;
  cin >> N ;
  int i;
  int keyTypes[K];
  for (i = 0 ; i < 201 ; i++) {
    haveKeys[i] = 0 ;
    allKeys[i] = 0 ;
    neededKeys[i] = 0 ;
    ownKeyTypes[i] = 0;
  }
  
  for (i = 0 ; i < K ; i++) {
    cin >> keyTypes[i];
    haveKeys[keyTypes[i]]++;
    allKeys[keyTypes[i]]++;
  }
  if (verbose) {
    showKeys(haveKeys);
  }
  int T[N] ;
  int Ki[N] ;
  int *chests[N];
  int numOwnKeys[N];
  
  for (i=0; i < N ; i++) {
    numOwnKeys[i] = 0 ;
    cin >> T[i] >> Ki[i] ;
    neededKeys[T[i]]++ ;
    if (verbose) {
      cout << "Chest " << i+1 << " type " << T[i] << " has " << Ki[i] << " keys:" ;
    }
    
    chests[i] = new int[Ki[i]] ;
    int j;
    for (j=0; j<Ki[i]; j++) {
      cin >> chests[i][j] ;
      if (verbose)
        cout << " " <<chests[i][j] ;
      allKeys[chests[i][j]]++;
      if (chests[i][j] == T[i]) {
        ownKeyTypes[T[i]]++;
        numOwnKeys[i]++;      
      }
    }
    if (verbose)
      cout << endl ;
  }

  if (verbose) {
    cout << "All    " ;
    showKeys(allKeys);
    cout << "Needed " ;
    showKeys(neededKeys);
    cout << "Own    " ;
    showKeys(ownKeyTypes);
  }

  // Check that there are enough keys
  for (i=0; i < 201 ; i++) {
    if (neededKeys[i] > allKeys[i]) {
      if (verbose)
        cout << "Not enough keys of type " << i << endl ;
      cout << "IMPOSSIBLE" << endl;
      return 1;
    }
    if (neededKeys[i] && (allKeys[i] == ownKeyTypes[i])) {
      if (verbose)
        cout << "No keys of type " << i << " outside of chests of that type." << endl ;
      cout << "IMPOSSIBLE" << endl;
      return 1;
    }
    
  }
  
  
  
  int chestsOpened[N];
  for (i = 0 ; i < N ; i++)
    chestsOpened[i] = 0;
  int moves[N] ;
  int possible = iterate(K, N, haveKeys, chests, T, Ki, moves, N, chestsOpened, neededKeys, numOwnKeys);
  if (possible) {
    for (i = 0 ; i < N ; i++) {
      cout << moves[i]+1 << " ";
    }
    cout << endl ;
  }
  else
    cout << "IMPOSSIBLE" << endl;
  return 1;
}

int main (int argc, const char * argv[])
{
  int testCases ;
  cin >> testCases ;
  if (verbose) {
    cerr << "Verbose is on!" << endl ;
    cout << "// Test cases: " << testCases << endl ;
  }
  int i;
  for (i=0 ; i < testCases ; i++) {
    if (verbose)
      cout << "// Running case #" << i+1 << endl ;
    cout << "Case #" << i + 1 << ": " ;
    int r = runTest();
    if (!r) {
      cerr << "test failed!" << endl ;
    }
  }
  
  return 0;
}

