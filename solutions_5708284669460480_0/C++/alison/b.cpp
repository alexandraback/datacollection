#include<bits/stdc++.h>
using namespace std;
char A[200],B[200];
string K,L;
int pref[200];
int praw[300];
string S;
int razem = 0;
int banany = 0;
int k,l,s;
int prefnext[200];
void generuj (int wsk)
{
    if(wsk == s)
    {
	razem++;
	
	
	string W = L + "%" + S;
	/*for(int i = 0; i < W.size(); i++)
	  printf("%c", W[i]);
	puts("");*/
	int q = 0;
	for(int i = 2; i < W.size(); i++)
      {
	 while(q && W[q+1] != W[i]) q = prefnext[q];
	 if(W[q+1] == W[i]) q++;
	 prefnext[i] = q;
	 if(i > L.size() && q == l) banany++;
	// printf("%d\n", prefnext[i]);
      }
      
      return;
    }
    
    for(int i = 1; i < K.size(); i++)
    {
	S.push_back(K[i]);
	generuj(wsk+1);
	S.pop_back();
    }
}
int main()
{
  int t; scanf("%d", &t);
  for(int z = 1; z <= t; z++)
  {
      L.clear(); K.clear();  S.clear();
      razem = 0; banany = 0;
      scanf("%d%d%d", &k, &l, &s);
      scanf(" %s ", A);
      scanf(" %s", B);
      string S1 = A, S2 = B;
      K = "#" + S1; 
      L = "#" + S2;
      
      int q = 0;
      for(int i = 2; i < L.size(); i++)
      {
	 while(q && L[q+1] != L[i]) q = pref[q];
	 if(L[q+1] == L[i]) q++;
	 pref[i] = q;
	// printf("%d\n", pref[i]);
      }
      int okres = l - pref[L.size()-1];
     // printf("okres = %d\n", okres);
      int ile = 0;
      for(int i = 0; i < s; i += okres)
      {
	if(i + l - 1 < s) ile++;
      }
      for(int i = 'A' - 'A'; i <= 'Z' - 'A'; i++)
	praw[i] = 0;
      
      int suma = 0;
      for(int i = 1; i < K.size(); i++)
      {
	 int co = K[i] - 'A';
	 if(praw[co] == 0) suma++;
	 praw[co]++;
      }
      generuj(0);
      
      for(int i = 1; i < L.size(); i++)
	if(praw[L[i] - 'A'] == 0) ile = 0;
      
     // printf("ile = %d ban = %d razem = %d\n", ile, banany, razem);
      printf("Case #%d: %.10lf\n",z, (double)ile - (double)banany / (double)razem);
  }

return 0;
}