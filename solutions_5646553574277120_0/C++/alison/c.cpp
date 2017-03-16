#include<bits/stdc++.h>
using namespace std;
vector <int> V;
bool B[50];
int main()
{
  B[0] = true;
  int t; scanf("%d",&t);
  for(int z = 1; z <= t; z++)
  {
      int c,d,v;
      V.clear();
      scanf("%d%d%d", &c, &d, &v);
      for(int i = 1; i <= v; i++) B[i] = false;
      
      for(int i = 0; i < d; i++)
      {
	 int a; scanf("%d", &a);
	 V.push_back(a);
      }
      for(int i = 0; i < V.size(); i++)
      {
	  int nowy = V[i];
	//  printf("nowu = %d\n", nowy);
	  for(int j = v; j >= 0; j--)
	  {
	    if(B[j] == true) B[j+nowy] = true;
	   // printf("%d\n", j + nowy);}
	  }
      }
      
      int suma = 0;
      while(true)
      {
	bool czy = true;
	int dod;
	for(int i = 1; i <= v; i++)
	{
	  if(B[i] == false) 
	  {
	    czy = false;
	    dod = i;
	    break;
	  }
	}
	if(czy) break;
	//printf("dod = %d\n", dod);
	suma++;
	int nowy = dod;
	  for(int j = v; j >= 0; j--)
	    if(B[j] == true) B[j+nowy] = true;
      }
      
      printf("Case #%d: %d\n", z,suma);
  }

return 0;
}