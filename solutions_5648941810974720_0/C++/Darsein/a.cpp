#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define all(a) (a).begin(),(a).end()
#define INIT(a) memset((a),0,sizeof(a))
#define chmin(a,b) ((a) = min((a),(b)))
#define chmax(a,b) ((a) = max((a),(b)))
#define fs first
#define sc second
#define pb push_back
#define sz size() 
using namespace std;
typedef long long ll;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<string> vs;

const static int INF = 1e8;
const static D EPS = 1e-8;

string digit[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

string check = "ZWUFXVGOTN";
int id[] = {0,2,4,5,6,7,8,1,3,9};

int main(){
  int testcase;

  cin >> testcase;
  for(int casenum=1;casenum<=testcase;casenum++){
    string s;
    cin >> s;

    map<char,int> c;
    rep(i,s.sz) c[s[i]]++;

    vi ans;
    rep(i,10){
      while(c[check[i]]){
	ans.pb(id[i]);
	for(char a : digit[id[i]]) c[a]--;
      }
    }

    cout << "Case #" << casenum << ": ";

    sort(all(ans));
    for(int a :ans) cout << a; cout << endl;
  }
}
