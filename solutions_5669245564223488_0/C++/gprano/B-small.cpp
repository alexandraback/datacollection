#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
using namespace std;

typedef unsigned long long ull;

ull prime = 1000000007;

char* t[1000];
int deleted[1000]; //0 nrmal, -1 delete, sinon sert pour le type
int ty[7];

int taille(char * s)
{
  int i = 0;
  while(s[i] != 0)
    i++;
  return i;
}

void perso_copy(char * s, char * d)
{
  int i =0;
  while(s[i] != 0)
    {d[i] = s[i];i++;}
  return;
}

int type(char a, char * mot)
{
  int i = 0;
  bool isbegin = false;
  bool isend = false;
 
  while(mot[i] != 0 && mot[i] != a)
    i++;
  if(mot[i] == 0)
    return 1; // no a in this word
  if(i == 0)
    isbegin=true;
  while(mot[i] == a)
    i++;
  if(mot[i] == 0)
    isend=true;
  while(mot[i] != 0 && mot[i] != a)
    i++;
  if(mot[i] != 0)
    return 6; // two blocks
  if(isbegin && isend)
    return 2;
  if(isbegin)
    return 3;
  if(isend)
    return 4;
  return 5;
}
      

int main()
{
  int nb_cas;
  scanf("%d",&nb_cas);
  for(int cas = 1; cas <= nb_cas; cas++)
    {
      printf("Case #%d: ",cas);
      int n;
      scanf("%d",&n);
      for(int i = 0; i < n; i++)
	{
	  t[i] = (char*) malloc(101);
	  scanf("%s",t[i]);
	}
      ull answ = 1;
      bool impossible = false;
      
      for(int i = 0;i<n;i++)
	deleted[i]=0;
      /*printf("Ste : ");
      for(int i = 0;i<n;i++)
	printf("%s ",t[i]);
	printf("\n");*/
      for(char a = 'a'; a <= 'z'; a++)
	{
	  for(int i = 0; i < 7; i++)
	    ty[i] = 0;
	  int deb=0;int fin=0;
	  for(int i = 0; i < n; i++)
	    {
	      if(deleted[i] != -1)
		{
		  int newtype= type(a,t[i]);
		  if(newtype==3)deb=i;
		  if(newtype==4)fin=i;
		  ty[newtype]++;
		  deleted[i]=newtype;
		}
	    }
	  if(ty[6]>0 || ty[3] > 1 || ty[4] > 1 || (ty[5] > 0 && ty[2]+ty[3]+ty[4]+ty[5]>1))
	    {
	      impossible=true;
	      break;
	    }
	  else
	    {
	      //find one, add 3 et 4 si ya sinon garde un des deux
	      bool keepmiddle = true;
	      if(ty[3] > 0 || ty[4] > 0)
		keepmiddle = false;
	      if(ty[3]>0&&ty[4]>0)
		{
		  int new_taille = taille(t[deb])+taille(t[fin]);
		  char * backup = (char*) malloc(taille(t[deb])+1);
		  perso_copy(t[deb],backup);
		  backup[taille(t[deb])]=0;
		  t[deb] = (char*) malloc(new_taille+1);
		  perso_copy(backup,t[deb]);
		  perso_copy(t[fin],backup+taille(t[deb]));
		  t[deb][new_taille]=0;
		  deleted[fin]=-1;
		}
	      for(int i=0;i<n;i++)
		{
		  if(deleted[i]==2)
		    {
		      if(keepmiddle)
			keepmiddle=false;
		      else
			deleted[i] = -1;
		    }
		}
	      for(ull i = 1; i <= ty[2]; i++)
		{
		  answ = answ * i;
		  answ = answ % prime;
		}
	      /*
	      if(ty[1]!=n)
		{
		  printf("after letter %c\n",a);
		  printf("set : ");
		  for(int i = 0;i< n; i++)
		    if(deleted[i] != -1)
		      printf("%s ",t[i]);
		  printf("\nscore so far %llu\n",answ);
		}
	      */

	    }
	}
      if(impossible)
	printf("0\n");
      else
	{
	  int nb_left=0;
	  for(int i = 0; i < n; i++)
	    if(deleted[i] != -1)
	      nb_left++;
	  for(ull i = 1; i <= nb_left; i++)
	    {
	      answ = answ *i;
	      answ = answ % prime;
	    }
	  printf("%llu\n",answ);
	}
    }
  return 0;
}
