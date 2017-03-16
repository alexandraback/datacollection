#include<iostream>
#include<set>
#include<utility>
#include<list>
#include<cstdio>

using namespace std;


bool f(int t, int sub, list<int> *S, set<int> *T)
{
  for(list<int>::iterator isup = S[sub].begin();isup!=S[sub].end();++isup)
  {
    pair<set<int>::iterator,bool > p =T[*isup].insert(t);
    if(!p.second)
      return false;
    if(!f(t,*isup,S,T))
      return false;
  }
  return true;
}


int main()
{
  int t;
  cin >> t;

  for(int ti=1;ti<=t;++ti)
  {
    int n;
    cin >> n;
    list<int> S[n];
    set<int> T[n];

   for(int i=0;i<n;++i)
   {
     int m;
     cin >> m;
     S[i]=list<int>();
     T[i]=set<int>();
     for(int j=0;j<m;++j)
     {
       int a;
       cin >> a;
       S[i].push_back(a-1);
     }
   }
    
   bool r=true;
   for(int i=0;r&&i<n;++i)
     r=f(i,i,S,T);

      cout << "Case #"<<ti<<": "<< (r?"No":"Yes") << endl;
  }
}

    


