#include <iostream>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>

#define TEST if(count>=n) break;

using namespace std;

int process(int nb) {
  int r, n, m, k;
  cin >> r >> n >> m >> k;
  
  int *products = new int[k];
  bool *numbers = new bool[m+1];
  int *sure = new int[m+1];

  cout << "Case #" << nb << ":" << endl;

  for(int i=0; i<r; i++) {
    bool test = false;
    int res = 0, count = 0;
    for(int j=0; j<k; j++) {
      cin >> products[j];
    }
    for(int j=0; j<=m; j++) {
      numbers[j] = false;
      sure[j] = 0;
    }

    for(int j=0; j<k && count < n; j++) {
      if(products[j] > 1) {
	//Primary
	if(products[j] == 2 || products[j] == 3 || products[j] == 5) {
	  if(sure[products[j]] == 0) {
	    sure[products[j]] = 1;
	    res = res*10 + products[j];
	    count++;
	  }
	}
	//Square
	else if(products[j] == 9 || products[j] == 16 || products[j] == 25) {
	  int s = (int) sqrt(products[j]);
	  if(sure[s] <= 1) {
	    sure[s]++;
	    res = res*10 + s;
	    count++; TEST
		       if(sure[s] == 1) {
			 sure[s]++;
	      res = res*10 + s;
	      count++; TEST
	    }
	  }
	}
	//Cube
	if(count < n)
	switch(products[j]) {
	case 6:
	  if(sure[3] == 0) {
	    sure[3] = 1;
	    res = res*10 + 3;
	    count++; TEST
	  }
	  if(sure[2] == 0) {
	    sure[2] = 1;
	    res = res*10 + 2;
	    count++; TEST
	  }
	  break;
	case 8:
	  if(sure[2] == 0) {
	    sure[2] = 1;
	    res = res*10 + 2;
	    count++; TEST
	  }
	  break;
	case 10:
	  if(sure[5] == 0) {
	    sure[5] = 1;
	    res = res*10 + 5;
	    count++; TEST
	  }
	  if(sure[2] == 0) {
	    sure[2] = 1;
	    res = res*10 + 2;
	    count++; TEST
	  }
	  break;
	case 15:
	  if(sure[5] == 0) {
	    sure[5] = 1;
	    res = res*10 + 5;
	    count++; TEST
	  }
	  if(sure[3] == 0) {
	    sure[3] = 1;
	    res = res*10 + 3;
	    count++; TEST
	  }
	  break;
	
	case 18:
	  if(sure[3] <= 1) {
	    sure[3]++;
	    res = res*10 + 3;
	    count++; TEST
	    if(sure[3] == 1) {
	      sure[3]++;
	      res = res*10 + 3;
	      count++; TEST
	    }
	  }
	  if(sure[2] == 0) {
	    sure[2] = 1;
	    res = res*10 + 2;
	    count++; TEST
	  }
	  break;
	case 20:
	  if(sure[5] == 0) {
	    sure[5] = 1;
	    res = res*10 + 5;
	    count++; TEST
	  }
	  break;
	case 24:
	  if(sure[4] == 0) {
	    sure[4] = 1;
	    res = res*10 + 4;
	    count++; TEST
	  }	  
	  if(sure[2] == 0) {
	    sure[2] = 1;
	    res = res*10 + 2;
	    count++; TEST
	  }
	  if(sure[3] == 0) {
	    sure[3] = 1;
	    res = res*10 + 3;
	    count++; TEST
	  }
	  break;
	case 27:
	  while(sure[3] <= 2) {
	    sure[3]++;
	    res = res*10 + 3;
	    count++; TEST
	  }
	  break;
	case 30:
	  if(sure[5] == 0) {
	    sure[5] = 1;
	    res = res*10 + 5;
	    count++; TEST
	  }	  
	  if(sure[3] == 0) {
	    sure[3] = 1;
	    res = res*10 + 3;
	    count++; TEST
	  }
	  if(sure[2] == 0) {
	    sure[2] = 1;
	    res = res*10 + 2;
	    count++; TEST
	  }
	  break;
	case 32:
	  if(sure[4] <= 1) {
	    sure[4]++;
	    res = res*10 + 4;
	    count++; TEST
	    if(sure[4] == 1) {
	      sure[4]++;
	      res = res*10 + 4;
	      count++; TEST
	    }
	  }
	  if(sure[2] == 0) {
	    sure[2] = 1;
	    res = res*10 + 2;
	    count++; TEST
	  }
	  break;
	case 36:
	  if(sure[3] <= 1) {
	    sure[3]++;
	    res = res*10 + 3;
	    count++; TEST
	    if(sure[3] == 1) {
	      sure[3]++;
	      res = res*10 + 3;
	      count++; TEST
	    }
	  }
	  if(sure[4] == 0) {
	    sure[4] = 1;
	    res = res*10 + 4;
	    count++; TEST
	  }
	  break;
	case 40:
	  if(sure[4] == 0) {
	    sure[4]++;
	    res = res*10 + 4;
	    count++; TEST
	  }
	  if(sure[2] == 0) {
	    sure[2] = 1;
	    res = res*10 + 2;
	    count++; TEST
	  }
	  if(sure[5] == 0) {
	    sure[5] = 1;
	    res = res*10 + 5;
	    count++; TEST
	  }
	  break;
	case 45:
	  if(sure[3] <= 1) {
	    sure[3]++;
	    res = res*10 + 3;
	    count++; TEST
	    if(sure[3] == 1) {
	      sure[3]++;
	      res = res*10 + 3;
	      count++; TEST
	    }
	  }
	  if(sure[5] == 0) {
	    sure[5] = 1;
	    res = res*10 + 5;
	    count++; TEST
	  }
	  break;
	case 64:
	  while(sure[4] <= 2) {
	    sure[4]++;
	    res = res*10 + 4;
	    count++; TEST
	  }
	  break;
	case 125:
	  while(sure[5] <= 2) {
	    sure[5]++;
	    res = res*10 + 5;
	    count++; TEST
	  }
	  break;

	}
	for(int l=2; l<=products[j]; l++) {
	  if(products[j]%l == 0) {
	    for(int u=l; u<=m && u<=products[j]; u+=l) {
	      numbers[u] = true;
	      test = true;
	    }
	  }
	}
      }
    }
      
    if(test && count < n) {
      while(count < n) {
	int tmp = (rand()%(m-1))+2;
	if(numbers[tmp]) {
	  res = res*10 + tmp;
	  count++; TEST
	}
      }
    }
    else if(!test) {
      for(int j=0; j<n; j++) {
	res = res*10 + (rand()%(m-1))+2;
	count++; TEST
      }
    }

    cout << res << endl;
  }
  delete[] products;
  delete[] numbers;
  delete[] sure;

  return nb;
}

int main() {
  srand (time(NULL));
  int nb;
  cin >> nb;
  for(int i=1; i<=nb; i++) {
    process(nb);
  }
  return 0;
}
