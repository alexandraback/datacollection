#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned ui;


int main()
{
  // OEIS A057136  
  ll fair[] = {0,1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,
               104060401l,121242121l,123454321l,125686521l,400080004l,
               404090404l,10000200001l,10221412201l,12102420121l,
               12345654321l,40000800004l};
  int T;
  
  cin >> T;

  for(ui t=1;t<=T;t++){
    ll A,B;
    cin >> A >> B;
    auto low = lower_bound(fair,fair+27,A);
    auto up = upper_bound(fair,fair+27,B);
    cout << "Case #" << t << ": " << up-low << endl;

  }
}
