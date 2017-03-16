#include <stdio.h>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <stdlib.h>
#include <math.h>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
 
using namespace std;
 
#define fi first
#define sc second
#define ff first.first
#define fs first.second
#define sf second.first
#define ss second.second
#define pb push_back
#define mp make_pair
#define ll long long
#define dl double
#define ison(a,b) (a&(1<<b))
#define bitcnt __builtin_popcount
#define MOD 1000000007 
#define INF 1000000000
 
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> wadj;

set<string> s1, s2;
bool check(string temp)
{
    for(auto i : temp){
      if(i == '?') 
      	return false;
    }
    return true;
}

void find1(string s){

  if(check(s))
  {
    s1.insert(s);
    return;
  }
for(int i = 0; i < s.size(); i++)
    if(s[i] == '?')
      for(int j = '0'; j <= '9'; j++){
        s[i] = j;
        find1(s);
      }
    
  
}
void find2(string s){

  if(check(s)){
    s2.insert(s);
    return;
  }
  for(int i = 0; i < s.size(); i++)
    if(s[i] == '?')
      for(int j = '0'; j <= '9'; j++){
        s[i] = j;
        find2(s);
      }
    
}

int differ(string a, string b){
  int a1 = stoi(a);
  int a2 = stoi(b);
  return abs(a1 - a2);
}


int main(int argc, char const *argv[])
{
//freopen("inp.txt","r",stdin);
 //freopen("out.txt","w",stdout);
	int t;
	cin>>t;
	for(int x=1;x<=t;x++)
	{
		printf("Case #%d: ",x);
		string c,j;
		cin>>c>>j;
		s1.clear();
		s2.clear();
		string a,b;
		find1(c);
		find2(j);
		int dif=1e9;
		for(auto i : s1)
		{
			for(auto j : s2)
			{
				if(differ(i,j)<dif)
				{
					a=i;
					b=j;
					dif=differ(i,j);
				}
			}
		}
		cout<<a<<" "<<b<<endl;
	}
 
    return 0;
}
 