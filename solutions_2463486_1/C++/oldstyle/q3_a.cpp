//Joe Snider
//4/13
//
//Generate palindromes up to a given number
//
//compile with -lgmp

#include <iostream>
#include <string>
#include <math.h>
#include <gmp.h> //for bigints
#include <set>
#include <algorithm>

using namespace std;

class CComp{
public:
   bool operator()(const string& x, const string& y) const {
      mpz_t a;
      mpz_t b;
      mpz_init_set_str(a, x.c_str(), 10);
      mpz_init_set_str(b, y.c_str(), 10);
      bool ret = mpz_cmp(a,b)<0;
      mpz_clear(a);
      mpz_clear(b);
      return ret;
   }
};

//test for pali
bool isPali(const string& n) {
   int m = n.size();
   for(int i = 0; i < m/2; ++i) {
      if(n[i] != n[m-1-i]) {
         return false;
      }
   }
   return true;
}

//generate all 'fair square' up to digits digits
void genFairSquare(int digits, set<string, CComp>& all) {
   //special case for single digits
   mpz_t a;
   mpz_init(a);
   all.insert(string("0"));
   all.insert(string("1"));
   all.insert(string("4"));
   all.insert(string("9"));

   //all the rest with no 2's
   string dgt[] = {string("0"), string("1"), string("2")};
   mpz_t b;
   mpz_init(b);
   mpz_t c;
   mpz_init(c);
   char buf[1000]; //hack, but good luck with digits>500
   for(int d = 2; d <= digits; ++d) {
      //distinguish even and odd (sadly)
      int l = d/2;
      if(d%2 == 0) {
         mpz_ui_pow_ui(a, 2, l-1);
         mpz_ui_pow_ui(b, 2, l);
         while(mpz_cmp(a,b)<0) {
            mpz_get_str(buf, 2, a);
            string up(buf);
            string down = up;
            reverse(down.begin(), down.end());
            up += down;
            if(isPali(up)) {
               mpz_set_str(c, up.c_str(), 10);
               mpz_mul(c, c, c);
               mpz_get_str(buf, 10, c);
               if(isPali(string(buf))) {
                  all.insert(string(buf));
               }
            }
            mpz_add_ui(a, a, 1);
         }
      } else {
         mpz_ui_pow_ui(a, 2, l-1);
         mpz_ui_pow_ui(b, 2, l);
         while(mpz_cmp(a,b)<0) {
            mpz_get_str(buf, 2, a);
            string tup(buf);
            string down = tup;
            reverse(down.begin(), down.end());
            for(int i = 0; i < 3; ++i) {
               string up = tup;
               up += dgt[i];
               up += down;
               if(isPali(up)) {
                  mpz_set_str(c, up.c_str(), 10);
                  mpz_mul(c, c, c);
                  mpz_get_str(buf, 10, c);
                  if(isPali(string(buf))) {
                     all.insert(string(buf));
                  }
               }
            }
            mpz_add_ui(a, a, 1);
         }
      }

      //add on the 2's
      if(d%2==0) {
         mpz_ui_pow_ui(a, 10, l-1);
         mpz_mul_ui(a, a, 2);
         mpz_get_str(buf, 10, a);
         string up(buf);
         string down = up;
         reverse(down.begin(), down.end());
         up += down;
         if(isPali(up)) {
            mpz_set_str(c, up.c_str(), 10);
            mpz_mul(c, c, c);
            mpz_get_str(buf, 10, c);
            if(isPali(string(buf))) {
               all.insert(string(buf));
            }
         }
      } else {
         mpz_ui_pow_ui(a, 10, l-1);
         mpz_mul_ui(a, a, 2);
         mpz_get_str(buf, 10, a);
         string tup(buf);
         string down = tup;
         reverse(down.begin(), down.end());
         for(int i = 0; i < 3; ++i) {
            string up = tup;
            up += dgt[i];
            up += down;
            if(isPali(up)) {
               mpz_set_str(c, up.c_str(), 10);
               mpz_mul(c, c, c);
               mpz_get_str(buf, 10, c);
               if(isPali(string(buf))) {
                  all.insert(string(buf));
               }
            }
         }
      }
      cerr << "Finished " << d << " with up to " << all.rbegin()->size() << " digits\n" << flush;
   }

   mpz_clear(a);
   mpz_clear(b);
   mpz_clear(c);
}

//return the number of elements of x with a<=x<=b
//strings are holding the long ints
int countElements(const string& a, const string& b, const set<string, CComp>& x) {
   return distance(x.lower_bound(a), x.upper_bound(b));
}

int main() {
   set<string, CComp> all;
   genFairSquare(10, all);
   //for(set<string, CComp>::iterator it = all.begin(); it != all.end(); ++it) {
   //   cout << *it << "\n" << flush;
   //}

   //read input from cin
   int cases;
   string low, high;
   cin >> cases;
   for(int i = 0; i < cases; ++i) {
      cin >> low >> high;
      cout << "Case #" << i+1 << ": " << countElements(low, high, all) << "\n" << flush;
   }
   
   return 0;
}
