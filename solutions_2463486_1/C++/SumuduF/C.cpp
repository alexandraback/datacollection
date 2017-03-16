#include <iostream>

using namespace std;

typedef long long int LL;

/* precalculated with a quick haskell program:
 *
 * isPal n = s == reverse s where s = show n
 * p7 = filter isPal [1..10^7]
 * filter isPal $ map (^2) p7
 * 
 * ended up finishing in ~16s (interpreted) so not strictly needed...
 */

const int NNUM = 39;
LL nums[NNUM] = {1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,
                 100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,
                 10000200001LL,10221412201LL,12102420121LL,12345654321LL,40000800004LL,1000002000001LL,
                 1002003002001LL,1004006004001LL,1020304030201LL,1022325232201LL,1024348434201LL,1210024200121LL,
                 1212225222121LL,1214428244121LL,1232346432321LL,1234567654321LL,4000008000004LL,4004009004004LL};
int main() {
  int nc; cin >> nc;
  for (int curC = 1; curC <= nc; ++curC) {
    LL a, b; cin >> a >> b;

    int ka = 0; while ((ka < NNUM) && nums[ka] < a) ++ka;
    int kb = ka-1; while ((kb+1 < NNUM) && nums[kb+1] <= b) ++kb;

    cout << "Case #" << curC << ": " << (kb - ka + 1) << '\n';
    }
  }

