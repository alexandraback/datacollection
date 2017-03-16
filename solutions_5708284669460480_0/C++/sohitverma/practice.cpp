#include <bits/stdc++.h>
using namespace std;

int k,l,s,remains,mx = 0;
string keybrd;
string wanted;
string mde;

int check()
{
  int count = 0;
  size_t nPos = mde.find(wanted, 0);
  while(nPos != string::npos)
  {
      count++;
      nPos = mde.find(wanted, nPos+1);
  }
  //cout<<count<<endl;
  return count;
}    

void calc(int i)
{
  if(i == s)
  {
   // cout<<mde;
    int te = check();
    remains += te;
    mx = max(mx,te);
    return;
  }

  for(int j = 0; j < k; j++)
  {
    mde[i] = keybrd[j];
    calc(i + 1);
  }
    
  return;  
}

int main()
{
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  int t;
  cin>>t;
  for(int i = 1; i <= t; i++)
  {
    mx = 0;
    cin>>k>>l>>s;
    cin>>keybrd;
    cin>>wanted;
    mde = "AAAAAAAA";
    mde.resize(s);
    remains = 0;
    calc(0);
    int num_cases = pow(k,s);
    float ans = 0;
    //cout<<mx<<" "<<num_cases<<" "<<remains<<endl;
    int ola = (num_cases * mx) - remains;
    ans = (float)ola/num_cases;
    printf("Case #%d: %.6f\n",i,ans);
    //cout<<"Case #"<<i<<": "<<ans<<endl;
  }
  return 0;
}   