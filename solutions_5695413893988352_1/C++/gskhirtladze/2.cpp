#include <bits/stdc++.h>

using namespace std;

string s1,s2;
long long A,B,lst;

void check(long long a,long long b)
 {
  lst=b>a;

  if (A == -1)
   { A=a; B=b; return; }

  if (abs(b-a) > abs(A-B)) return;

  if (abs(b-a) < abs(A-B))
   { A=a; B=b; return; }

  if (A < a) return;

  if (a < A)
   { A=a; B=b; return; }

  if (b > B) return;

  if (b < B)
   { A=a; B=b; return; }
 }

void solve(int x,long long num1,long long num2)
 {
  if (x == s1.size())
   {
    check(num1,num2);
    return;
   }

  if (s1[x] == '?' && s2[x] == '?')
   {
    if (num1 > num2) solve(x+1,num1*10,num2*10+9); else
    if (num1 < num2) solve(x+1,num1*10+9,num2*10); else
    if (num1 == num2)
     {
      solve(x+1,num1*10,num2*10);
      if (lst)
       solve(x+1,num1*10+1,num2*10); else
       solve(x+1,num1*10,num2*10+1);
      lst^=1;
     }
    return;
   }

  if (s1[x] == '?')
   {
    if (num1 > num2) solve(x+1,num1*10,num2*10+s2[x]-'0'); else
    if (num1 < num2) solve(x+1,num1*10+9,num2*10+s2[x]-'0'); else
    if (num1 == num2)
     {
      solve(x+1,num1*10+s2[x]-'0',num2*10+s2[x]-'0');
      if (lst)
       {
        solve(x+1,num1*10+min(9,s2[x]-'0'+1),num2*10+s2[x]-'0');
        if (s2[x]-'0'+1 <= 9) lst^=1;
       } else
       {
        solve(x+1,num1*10+max(0,s2[x]-'0'-1),num2*10+s2[x]-'0');
        if (s2[x]-'0'-1 >= 0) lst^=1;
       }
     }
    return;
   }

  if (s2[x] == '?')
   {
    if (num1 > num2) solve(x+1,num1*10+s1[x]-'0',num2*10+9); else
    if (num1 < num2) solve(x+1,num1*10+s1[x]-'0',num2*10); else
    if (num1 == num2)
     {
      solve(x+1,num1*10+s1[x]-'0',num2*10+s1[x]-'0');
      if (lst)
       {
        solve(x+1,num1*10+s1[x]-'0',num2*10+max(0,s1[x]-'0'-1));
        if (s1[x]-'0'-1 >= 0) lst^=1;
       } else
       {
        solve(x+1,num1*10+s1[x]-'0',num2*10+min(9,s1[x]-'0'+1));
        if (s1[x]-'0'+1 <= 9) lst^=1;
       }
     }
    return;
   }

  solve(x+1,num1*10+s1[x]-'0',num2*10+s2[x]-'0');
  if (num1 == num2 && s1[x] > s2[x]) lst=0;
  if (num1 == num2 && s1[x] < s2[x]) lst=1;
 }

int main()
 {
  freopen("B.in","r",stdin);
  freopen("B.out","w",stdout);

  int t; cin>>t;
  for (int tt=1;tt<=t;tt++)
   {
    cin>>s1>>s2;

    A=B=-1;
    solve(0,0,0);

    string ans1="";
    while (A) ans1+=char(A%10+'0'),A/=10;
    while (ans1.size() < s1.size()) ans1+='0';
    reverse(ans1.begin(),ans1.end());


    string ans2="";
    while (B) ans2+=char(B%10+'0'),B/=10;
    while (ans2.size() < s2.size()) ans2+='0';
    reverse(ans2.begin(),ans2.end());

    cout<<"Case #"<<tt<<": "<<ans1<<" "<<ans2<<endl;
   }
 }
