#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int idxCase;
long long int n;
int K,L,S;


string K_str;
string L_str;

int histogram[26];

int main () {

    freopen ("q1.in", "r", stdin); 
    freopen ("q1.out", "w", stdout);


  int idxCase;
  cin >> idxCase;
  for (int it = 1; it <= idxCase; it++) {
    cin >> K >> L >> S ;
    cin >> K_str >> L_str;

    for(int i=0; i<26;i++){
      histogram[i] = 0;
    }
    for(int i=0; i < K_str.length(); i++){
      histogram[ K_str[i] - 65]++;
    }
    long long permu = 1;
    for(int i=0; i<L_str.length(); i++){
      permu *= histogram[L_str[i]-65];
    }

    if((S < L)||(permu==0)){
      cout<<"Case #"<<it <<": "<<0.0 <<endl;
      continue;
    }

    //find max common string length
    int interval = L_str.length();
    for(int i=1; i<L_str.length();i++){
      string sub_match0 = L_str.substr(0,L_str.length()-i);
      string sub_match1 = L_str.substr(i,L_str.length()-i);
      if(sub_match0 == sub_match1){
        interval = i;
//        cout<<"substr: "<< sub_match0<<"sub2: "<< sub_match1 <<endl;
//        cout<<"L_str: "<< L_str<<endl;
        break;
      }
    }
    long double max = 1.0 + (S - L_str.length())/ interval;

//    cout <<"interva;: "<<interval<<endl;
    long double all_permu;
    all_permu = permu * (S-L+1);
    long double totol = pow(K,L);
//    cout <<all_permu<<" " << totol<<endl;
    //fill in answer
    cout<<"Case #"<<it <<": "<< max- all_permu/totol <<endl;
    fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, idxCase, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * idxCase) / CLOCKS_PER_SEC);
  }
  return 0;
}
