#include <stdio.h>

int max(unsigned int energy, unsigned int v[], unsigned int i);

unsigned int max_energy;
unsigned int recovery;
unsigned int N;
int first;

int main()
{
  int T;
  int v[10];
  scanf("%d", &T);
  for(int t = 1; t <= T; t++)
  {
    first = 1;
    scanf("%d %d %d", &max_energy, &recovery, &N);
    for(int n = 0; n < N; n++)
    {
      scanf("%d", &v[n]);
    }

    printf("Case #%d: %d\n", t, max(max_energy, v, 0));
  }

  return 0;

}


int max(unsigned int energy, unsigned int v[], unsigned int i)
{
  static int found[5][10][5];
  if(first)
  {
    for(int i = 0; i < 5; i++)
      for(int j = 0; j < 10; j++)
        for(int k = 0; k < 5; k++)
          found[i][j][k] = -1;

    first = 0;
  }
  
  //check to see if we already found it
  if(found[energy-1][i][recovery-1] != -1)
  {
    return found[energy-1][i][recovery-1];
  }

  if(i == N-1)
  {
    found[energy-1][i][recovery-1] = v[i] * energy;
    return found[energy-1][i][recovery-1];
  }

  int m = -1; 
  for(unsigned int e = 0; e <= energy; e++)
  {
    int new_energy = energy - e + recovery;
    if(new_energy > max_energy)
      new_energy = max_energy;
    int new_m = e * v[i] + 
          max(new_energy, v, i+1);
    if(new_m > m)
    {
      m = new_m;
    }
  }

  found[energy-1][i][recovery-1] = m;
  return m;
}

