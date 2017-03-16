#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <algorithm>

#define fii(x,y) for(int i=x;i<y;i++)
#define fjj(x,y) for(int j=x;j<y;j++)
#define fkk(x,y) for(int k=x;k<y;k++)
#define fi(x) fii(0,x)
#define fj(x) fjj(0,x)
#define fk(x) fkk(0,x)
#define eps 0.0000000001
#define inf 1<<28

using namespace std;

typedef long long ll;
typedef vector <int> VI;
typedef vector <VI> VVI;
typedef vector <VVI> VVVI;
typedef vector <ll> VL;
typedef vector <VL> VVL;
typedef vector <double> VD;
typedef vector <VD> VVD;
typedef vector <bool> VB;
typedef vector <VB> VVB;
typedef queue <int> QI;
typedef pair<int,int> PI;
typedef pair<int,PI> PT;
typedef queue<PI> QPI;
typedef priority_queue<PT> QPT;
typedef pair<double,double> PD;
typedef vector<string> VS;
typedef vector<VS> VVS;

bool pal (ll a)
{
  ll b = a;
  ll c = 0;
  while (b > 0)
  {
    c*=10;
    c+=b%10;
    b/=10;
  }
  return c == a;
}

string calc (string a)
{
  int n = a.size();
  int m = 2*n-1;
  string ans;
  fi (m) ans += '0';
  fi (n) fj (n) ans[i+j] += (a[i]-'0')*(a[j]-'0');
  return ans;
}

VVS v;
int m;
string par;
VI acum;
VVS cd;

int tot (string a)
{
  if (a == "") return 0;
  int n = a.size();
  int ans = acum[n-1];
  if (cd[n].size() == 0) return ans;
  ans += upper_bound(cd[n].begin(),cd[n].end(), a)-cd[n].begin();
  return ans;
  
}

void back (int a, int um, string it, VS& v)
{
  if (um < 0) return;
  if (a == m)
  {
    string aa;
    aa += "1";
    aa += par;
    aa += it;
    string bb = string(par.rbegin(),par.rend());
    aa += bb;
    aa += "1";
    v.push_back(aa);
    return;
  }
  while (par.size() <= a) par+='0';
  par[a] = '0';
  back(a+1,um,it,v);
  par[a] = '1';
  back(a+1,um-1,it,v);
}

void r1 (string &s)
{
  if (s == "1") {
    s = "";
    return;
  }
  int i = s.size()-1;
  while (s[i] == '0')
  {
    s[i] = '9';
    i--;
  }
  s[i]--;
}

int main()
{
  v = VVS (50);
  v[1]=VS(3);
  v[1][0] = "1";
  v[1][1] = "2";
  v[1][2] = "3";
  
  fii (2,50)
  {
    if (i%2 == 0)
    {
      m = i/2-1;
      string d;
      d+='2';
      fj (2*m) d+= '0';
      d+='2';
      v[i].push_back(d);
      
      par = "";
      back(0,3,"",v[i]);
    }
    else
    {
      m = (i-1)/2-1;
      string d1;
      d1+='2';
      fj (m) d1+= '0';
      d1+='0';
      fj (m) d1+= '0';
      d1+='2';
      v[i].push_back(d1);
      
      string d2;
      d2+='2';
      fj (m) d2+= '0';
      d2+='1';
      fj (m) d2+= '0';
      d2+='2';
      v[i].push_back(d2);
      
      par = "";
      back(0,3,"0",v[i]);
      par = "";
      back(0,3,"1",v[i]);
      par = "";
      back(0,1,"2",v[i]);
    }
    sort(v[i].begin(),v[i].end());
//     cout << i << endl;
//     fj (v[i].size()) cout << v[i][j] << endl;
  }
  cd = VVS (101);
  fi (v.size())
  {
    fj (v[i].size())
    {
      string s = calc(v[i][j]);
      cd[s.size()].push_back(s);
//       cout << v[i][j] << " " << s << endl;
    }
  }
  fi (cd.size()) sort(cd[i].begin(),cd[i].end());
//   fi (20) {
//     cout << i << endl;
//     fj (cd[i].size()) cout << cd[i][j] << endl;
//   }
  acum = VI (101,0);
  fii (1,acum.size()) acum[i] = acum[i-1] + cd[i].size();
  int T;
  cin >> T;
  for (int caso = 1; caso <= T; caso ++)
  {
    cout << "Case #" << caso << ": ";
    string a,b;
    cin >> a >> b;
    r1(a);
    cout << tot(b)-tot(a) << endl;
  }
}