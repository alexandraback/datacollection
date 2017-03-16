#include <bits/stdc++.h>
using namespace std;

long long int ans = 0;

void calc(long long int n)
{
  if(n <= 10)
    ans += n;
  else
  {
    string temp3 = to_string(n);
    int sz = temp3.size();
    long long int temp2 = n % (int)pow(10,sz/2);
    if(temp2 == 0)
    {
      n--;
      ans++;
    }
    string temp = to_string(n);
    sz = temp.size();
    ans += n % (int)pow(10,sz/2);
    for(int i = 0; i < sz/2; i++)
    {
      temp[sz - 1 - i] = temp[i]; 
    }
    std::string::size_type siz = 0; 
    long long int temp1 = stoll (temp,&siz,0);
    if((temp1 % (int)pow(10,sz/2)) == 1)
      ans--;
    ans += temp1 % (int)pow(10,sz/2);
    if(sz % 2 != 0)
      ans += (temp[sz/2] - '0')* pow(10,sz/2);
   
    n = (long long int) pow(10,sz - 1);
    n--;
    ans++;
    calc(n);
  }
  
  return;
}

int main()
{
  int t;
  cin>>t;
  for(int i = 1; i <= t; i++)
  {
    ans = 0;
    long long int n;
    cin>>n;
    calc(n);
    cout<<"Case #"<<i<<": "<<ans<<endl;
  }
  return 0;
}   