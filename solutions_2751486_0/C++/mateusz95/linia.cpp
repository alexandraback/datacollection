#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#define LL long long
#define ff first
#define ss second
#define PB push_back
#define MP make_pair


using namespace std;
LL wynik;
int t;
string s;
int n;
int sp[1000005];
int git[1000005];
bool spolgloska(char x)
{
  if(x!='a'&&x!='e'&&x!='i'&&x!='o'&&x!='u')return 1;
  return 0;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin>>t;
  for(int z=1;z<=t;z++)
  {
    wynik=0;
    //printf("Case #%d: ",z);
    cout<<"Case #"<<z<<": ";
    s.clear();
    cin>>s;
    cin>>n;
    
    for(int i=0;i<s.size();i++)
    {
      sp[i+1]=sp[i];
      if(spolgloska(s[i]))sp[i+1]++;
    }
    
  
    
  for(int i=0;i<=s.size();i++){git[i]=0;}
  //for(int i=1;i<n;i++)cout<<"0 ";
  
  for(int i=n;i<=s.size();i++)
  {
    
    git[i-n+1]=git[i-n];
    if(sp[i]-sp[i-n]==n)
      git[i-n+1]++;
    
    
   //cout<<git[i-n+1]<<" ";
    
  }
  for(int i=s.size()-n+2;i<=s.size();i++)
  {
    git[i]=git[i-1];
   // cout<<git[i]<<" ";
  }
 // cout<<endl;
  
  int poc=0;
  
  for(int kon=n;kon<=s.size();kon++)
  {
    while(poc<=kon-n&&git[kon-n+1]-git[poc]>=1)
      poc++;
    
    wynik+=poc;
    //cout<<poc<<endl;
  }
  
  
  cout<<wynik<<"\n";
  
  }
  return 0;
}