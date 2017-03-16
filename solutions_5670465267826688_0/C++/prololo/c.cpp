#include <cstdio>
#include <cassert>
#include <string>

using namespace std;
typedef long long ll;

class qtm
{
private:
  int sgn;              // pos -> 1, neg -> 1
  int num;              // '1' -> 0, 'i' -> 1, 'j' -> 2, 'k' -> 3
public:
  qtm(char c);
  qtm(int s, int n);
  int getSign();
  int getNum();
  qtm operator*(qtm x);
  bool operator==(qtm x);
  void print();
};

qtm::qtm(char c)
{
  sgn = 1;
  switch(c){
  case '1':
    num = 0; break;
  case 'i':
    num = 1; break;
  case 'j':
    num = 2; break;
  case 'k':
    num = 3; break;
  }
}

qtm::qtm(int s, int n)
{
  assert(0 <= n && n <= 3);
  assert(s == 1 || s == -1);
  sgn = s;
  num = n;
}

int qtm::getSign()
{
  return sgn;
}

int qtm::getNum()
{
  return num;
}

qtm qtm::operator*(qtm x){
  int xs = x.getSign();
  int xn = x.getNum();
  int s, n;
  int res[4][4] = 
    {{0, 1, 2, 3},
     {1, 0, 3, 2},
     {2, 3, 0, 1},
     {3, 2, 1, 0}};
  int sgnRes[4][4] =
    {{1, 1, 1, 1},
     {1, -1, 1, -1},
     {1, -1, -1, 1},
     {1, 1, -1, -1,}};
  n = res[num][xn];
  s = sgnRes[num][xn] * xs * sgn;
  assert(0 <= n && n <= 3);
  assert(s == 1 || s == -1);
  return qtm(s, n);
}

bool qtm::operator==(qtm x){
  int xs = x.getSign();
  int xn = x.getNum();
  return (sgn == xs) && (num == xn);
}

void qtm::print(){
  string table[2][4] = 
    {{"1", "i", "j", "k"},
     {"-1", "-i", "-j", "-k"}};
  printf("%s", table[sgn < 0][num].c_str());
  return ;
}

bool search_k(ll l, ll x_max, string str, ll i_init, ll x_init){
  qtm q = qtm('1');
  for (ll x = x_init; x < x_max; x++){
    for (ll i = i_init; i < l; i++){
      q = q * qtm(str.at(i));
    }
  }  
  return q == qtm('k');
}

bool search_j(ll l, ll x_max, string str, ll i_init, ll x_init){
  qtm q = qtm('1');
  for (ll x = x_init; x < x_max && x < x_init + 5; x++){
    for (ll i = 0; i < l; i++){
      q = q * qtm(str.at((i + i_init) % l));
      if (q == qtm('j')){
        return true;
      }
    }
  }
  return false;
}

bool search_i(ll l, ll x_max, string str, ll i_init, ll x_init){
  qtm q = qtm('1');
  ll i_next, x_next = x_init;
  for (ll x = x_init; x < x_max && x < x_init + 4; x++){
    for (ll i = 0; i < l; i++){
      q = q * qtm(str.at((i + i_init) % l));
      if (q == qtm('i')){
        if (i == l - 1){
          i_next = 0;
          x_next = x + 1;
        }else{
          i_next = i + 1;
        }
        return search_j(l, x_max, str, i_next, x_next);
      }
    }
  }
  return false;
}

qtm str_multiply(string str)
{
  qtm ans = qtm('1');
  ll l = str.length();
  for (ll i = 0; i < l; i++){
    ans = ans * qtm(str.at(i));
  }
  return ans;
}

qtm pow(qtm q, ll n){
  qtm ans = qtm('1');
  for(int i = 0; i < n % 4; i++){
    ans = ans * q;
  }
  return ans;
}


string solve_problem()
{
  string ans;            // the answer ("YES" or "NO")
  char chrs[10001];      // to take the inputs
  string str;            // the given string
  ll l, x;        // l is the length of str, x is the repeat time
  qtm mul_str = qtm('1');
  
  assert(scanf("%lld %lld\n%s\n", &l, &x, chrs) != EOF);
  str = chrs;

  mul_str = str_multiply(str);
  
  if (pow(mul_str, x) == qtm(-1, 0)){
    if (search_i(l, x, str, 0, 0)){
      ans = "YES";
    }else{
      ans = "NO";
    }
  }else{
    ans = "NO";
  }
  return ans;
}

int main()
{
  int t;                  // the number of cases
  string ans;
  assert(scanf("%d\n", &t) != EOF);
  for (int i = 0; i < t; i++){
    ans = solve_problem();
    printf("Case #%d: %s\n", i + 1, ans.c_str());
  }
  return 0;
}
