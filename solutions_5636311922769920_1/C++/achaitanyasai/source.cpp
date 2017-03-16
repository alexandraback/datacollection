#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sz size()
#define all(a)  a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define fill(a, x) memset(a, x, sizeof(a));
#define mod 1000000007
#define _for(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)

using namespace std;

vector<string> genbase(int K, int C){
   int Total = 1 << K;
   vector<string> res;
   for(int mask = 0; mask < Total; ++mask){
      int k = mask;
      string tmp = "";
      for(int i = 0; i < K; ++i){
         if(k & 1){
            tmp += 'L';
         }
         else{
            tmp += 'G';
         }
         k >>= 1;
      }
      while(tmp.sz != K){
         tmp += 'G';
      }
      res.pb(tmp);
   }
   return res;
}

string getbrute(string base, int K, int C){
   string res = base;
   --C;
   while(C--){
      string tmp = "";
      for(int n = 0; n < res.sz; ++n){
         if(res[n] == 'G'){
            for(int i = 0; i < K; ++i){
               tmp += 'G';
            }
         }
         else{
            tmp += base;
         }
      }
      res = tmp;
   }
   return res;
}

vector<string> gen(int K, int C, int S){
   vector<string> base = genbase(K, C);
   vector<string> res;
   for(int n = 0; n < base.sz; ++n){
      res.pb(getbrute(base[n], K, C));
   }
   return res;
}

vector<int> get(int K, int C, int S){
   if(C >= K) return vector<int>{K};
   int diff = K - C + 1;
   if(diff > S) return vector<int>{-1};
   vector<int> res;
   for(int n = K; n >= 1; --n){
      if(res.sz == diff) break;
      res.pb(n);
   }
   return res;
}

bool check(vector<string> res, vector<int> obtained, int S){
   sort(all(res));
   if(obtained[0] == -1){
      long long Total = 1ll << (long long)res[0].sz;
      for(int mask = 1; mask < Total; ++mask){
         int k = mask;
         vector<int> p;
         for(int n = 0; n < res[0].sz; ++n){
            if(k & 1){
               p.pb(n);
            }
            k >>= 1;
         }
         long long x = 1ll;
         //cout << "p.sz : "<< p.sz << << endl;
         if(p.sz > S) continue;
         for(int n = 0; n < p.sz; ++n){
            string y = "";
            for(int m = 0; m < res.sz - 1; ++m){
               if(res[m][p[n]] == 'L'){
                  y += '1';
               }
               else{
                  y += '0';
               }
            }
            x &= stoi(y, nullptr, 2);
         }
      }
      return 1;
   }
   for(int n = 0; n < obtained.sz; ++n){
      obtained[n]--;
   }
   long long x = 1ll;
   for(int n = 0; n < obtained.sz; ++n){
      string p = "";
      for(int m = 0; m < res.sz - 1; ++m){
         if(res[m][obtained[n]] == 'L'){
            p += '1';
         }
         else{
            p += '0';
         }
      }
      x &= stoi(p, nullptr, 2);
   }
   if(x == 0) return 1;
   return 0;
}

bool brute(){
   int K = rand() % 4 + 1;
   int C = rand() % 4 + 1;
   int S = rand() % 3 + 1;
   S = min(S, K);
   vector<string> res = gen(K, C, S);
   vector<int> obtained = get(K, C, S);
   if(check(res, obtained, S)){
      cout << "OK" << " | ";
      _for(it, obtained){
         cout << (*it) << " ";
      } 
      cout << endl;
      return 1;
   }
   else cout << "Wrong Answer" << endl;
   cout << "Input : " << K << " " << C << " " << S << endl;
   cout << "Obtained : ";
   _for(it, obtained){
      cout << (*it) << " ";
   } 
   cout << endl;
   cout << "--------------\n";
   cout << "Other information :\n";
   _for(it, res){
      cout << "<" << (*it) << ">" << endl;
   }
   return 0;
}

void test(){
   int tmp = 1;
   while(true){
      cout << "Test #: " << tmp << " ";
      if(!brute()) exit(0);
      ++tmp;
   }
}

int main() {
   srand(time(NULL));
   //test();
   int T;
   cin >> T;
   int K, C, S;
   for(int test = 1; test <= T; ++test){
      scanf("%d%d%d", &K, &C, &S);
      vector<int> res = get(K, C, S);
      printf("Case #%d: ", test);
      if(res[0] == -1){
         printf("IMPOSSIBLE\n");
      }
      else{
         for(int n = 0; n < res.sz; ++n){
            if(n == res.sz - 1) printf("%d\n", res[n]);
            else printf("%d ", res[n]);
         }
      }
   }
   return 0;
}