#include <iostream>
#include <assert.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>
#include <queue>
#include <string>
#include <time.h>

using namespace std;


int f[100],a[100],p[100];
int f1[100],a1[100],p1[100],s2,n1,m1;
vector <int> g;
int time1 = 0;
bool try2()
{time1++;
	  for(int i(0);i<=m1;i++)
			f1[i] = 0;
	  f1[0] = 1;
		  for(int i(0);i<n1;i++)
		  { time1++;
			  for(int q(m1);q>=0;q--)
			  
				  if(f1[q] == 1) f1[q+a1[i]] = 1;
		  }
		  int fl = 0;
		  for(int i(1);i<=m1;i++)
			  if(f1[i] == 0)
			  {
				  return false;
			  }
		return true;
}

void dfs(int v,int pr)
{
	if(v == 6 || v >= s2 || time1 > 100000) return;
	if(try2()) {  s2 = min(v,s2); return;}
	
	for(int i(pr+1);i<g.size();i++)
	{time1++;
		a1[n1++] = g[i];
		dfs(v+1,i);
		n1--;
	} 
}
void try1( )
{  
	time1 == 0;
	for(int i(1);i<=m1;i++)
		if(p1[i] != 0  ){  g.push_back(i);}
	for(int i(0);i<g.size();i++)
	{ 
		a1[n1++] = g[i]; 
		dfs(1,i);
		n1--; 
		break;
	} 
}

int main() 
{ 
   // freopen("input.txt","r",stdin);
 //    freopen("output.txt","w",stdout); 
	  int t;s2 = 1000;
	  cin >> t;int j = 0;
	  while(t-- > 0)
	  {
		  j++;
		  for(int i(0);i<50;i++) p[i] = f[i] = 0;
		  int x,n,m,s = 0;
		  cin >> x >> n >> m;
		  f[0] = 1;
		  for(int i(0);i<n;i++)
		  {
			  cin >> a[i];
			  for(int q(m);q>=0;q--)
				  if(f[q] == 1) f[q+a[i]] = 1;
		  }
		  int fl = 0;
		  for(int i(1);i<=m;i++)
			  if(f[i] == 0)
			  {
				  fl = 1;
				  for(int q(0);q<i;q++)
					  p[i-q]++;
			  }
		  if(fl == 0) { cout << "Case #" << j << ": 0\n";continue;} 
		  for(int i(0);i<n;i++)
			  p[a[i]] = 0; 
		  for(int i(0);i<100;i++)
		  {
			  f1[i] = f[i];
			  p1[i] = p[i];
			  a1[i] = a[i];
		  }
		  n1 = n;m1 = m;
		   
		  fl = 0;
		  while(fl == 0)
		  {
				int mx = 0,nm = 0;
				for(int i(1);i<=m;i++)
				{
					if(p[i] > mx){ mx = p[i]; nm = i;}
					p[i] = 0;
				}
				a[n++] = nm;
			    for(int q(m);q>=0;q--)
				  if(f[q] == 1) f[q+nm] = 1;
				fl = 1;s++;
				for(int i(1);i<=m;i++)
					if(f[i] == 0)
					{
						fl = 0;
						for(int q(0);q<i;q++)
							 p[i-q]++;
					}
				for(int i(0);i<n;i++)
					p[a[i]] = 0;
		  } 
		 s2 = s;
		  try1();
		  cout << "Case #" << j << ": " << s2 << endl;		  	  
	  }
} 