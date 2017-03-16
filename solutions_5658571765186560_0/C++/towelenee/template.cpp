#include<cassert>
#include<queue>
#include<cstring>
#include<cstdio>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include<iostream>
#include<algorithm>

typedef long long ll;

using namespace std;

int main()         
{
  int test_n;
  scanf("%d",&test_n);
  for(int test_id = 0; test_id < test_n; test_id++)
  {
    printf("Case #%d: ",test_id+1);
    int x, r, c;
    cin >> x >> r >> c;
/*    for (int x = 1; x <= 4; x++)
      for (int r = 1; r <= 4; r++)
	for (int c = 1; c <= 4; c++)*/
	  if ( x <= 6 && ((r * c) % x == 0) && (x <= min(r,c) + 1))
	  {
//	    cout << x << " " << r << " " << " " << c << endl;
	    cout << "GABRIEL" << endl;
	  }
	  else
	    cout << "RICHARD" << endl;
	    
  }
  return 0;
}

