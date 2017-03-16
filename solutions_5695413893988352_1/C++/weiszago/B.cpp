#include <bits/stdc++.h>
using namespace std;

string sol1, sol2;
string jo1, jo2;
string a, b;

long long szamma(string s)
{
  long long x = 0;
  for (char c:s)
  {
    x*=10;
    x+=(c-'0');
  }
  return x;
}

void legjobb()
{
  if (jo1=="")
  {
    jo1=sol1;
    jo2=sol2;
    return;
  }

  long long avolt=szamma(jo1);
  long long bvolt=szamma(jo2);
  long long a=szamma(sol1);
  long long b=szamma(sol2);

  if (abs(a-b)<abs(avolt-bvolt))
  {
    jo1=sol1;
    jo2=sol2;
    return;
  }

  if (abs(a-b)==abs(avolt-bvolt))
  {
    if (a<avolt)
    {
      jo1=sol1;
      jo2=sol2;
      return;
    }
    if (a==avolt)
    {
      if (b<bvolt)
      {
        jo1=sol1;
        jo2=sol2;
        return;
      }
    }
  }
}

// 0 ->ugyanaz, 1->1 kell nagy, 2->2 kell nagy
void rec(int tart, int state)
{
  if (tart==a.size())
  {
    legjobb();
    return;
  }
  if (a[tart]=='?' && b[tart]=='?') {
    if (state==0)
    {
      for (char egy='0';egy<='1';egy++)
      {
        for (char ketto=egy-1;ketto<=egy+1;ketto++)
        {
          if (ketto>='0'&&ketto<='1')
          {
            sol1[tart]=egy;
            sol2[tart]=ketto;
            if (egy<ketto) rec(tart+1, 1);
            if (egy==ketto) rec(tart+1, 0);
            if (egy>ketto) rec(tart+1, 2);
          }
        }
      }

    } else if (state==1)
    {
      sol1[tart]='9';
      sol2[tart]='0';
      rec(tart+1, 1);
    } else if (state==2)
    {
      sol1[tart]='0';
      sol2[tart]='9';
      rec(tart+1, 2);
    }
  } else if (a[tart]!='?' && b[tart]!='?')
  {
    sol1[tart]=a[tart];
    sol2[tart]=b[tart];
    if (state>0) rec(tart+1, state);
    else
    {
      if (a[tart]>b[tart]) rec(tart+1, 2);
      else if (a[tart]<b[tart]) rec(tart+1, 1);
      else if (a[tart]==b[tart]) rec(tart+1, 0);
    }
  } else if (a[tart]=='?')
  {
    sol2[tart]=b[tart];
    if (state==0) {
      char x=b[tart];
      x--;
      if (x>='0')
      {
        sol1[tart]=x;
        rec(tart+1, 1);
      }
        x++;
      sol1[tart]=x;
      rec(tart+1, 0);
      x++;
      if (x<='9')
      {
        sol1[tart]=x;
        rec(tart+1, 2);
      }
    } else if (state==1)
    {
      sol1[tart]='9';
      rec(tart+1, 1);
    } else if (state==2)
    {
      sol1[tart]='0';
      rec(tart+1, 2);
    }
  } else if (b[tart]=='?')
  {
    sol1[tart]=a[tart];
    if (state==0) {
      char x=a[tart];
      x--;
      if (x>='0')
      {
        sol2[tart]=x;
        rec(tart+1, 2);
      }
        x++;
      sol2[tart]=x;
      rec(tart+1, 0);
      x++;
      if (x<='9')
      {
        sol2[tart]=x;
        rec(tart+1, 1);
      }
    } else if (state==1)
    {
      sol2[tart]='0';
      rec(tart+1, 1);
    } else if (state==2)
    {
      sol2[tart]='9';
      rec(tart+1, 2);
    }
  }
}

void solve()
{
  cin >> a>>b;
  sol1=a;
  sol2=b;
  rec(0, 0);
}

int main()
{
  freopen("B-large (1).in", "r", stdin);
  freopen("B-large.out", "w", stdout);
  ios_base::sync_with_stdio(false);

  int test;
  cin >> test;
  for (int t = 1;t<=test;t++) {
    jo1="";
    cout << "Case #" << t<<": ";
    solve();
    cout << jo1<<" "<<jo2;
    cout << endl;
  }

  return 0;
}
