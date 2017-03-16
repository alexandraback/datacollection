#include <stdio.h>
int main()
{
 int T, N, M;
 int i, j, k, l, m, n;
 int inherit_path[1000][1000];
 FILE *fin = fopen("input.txt", "r");
 fscanf(fin, "%d", &T);
 for (i = 0;i < T;i++)
 {
  fscanf(fin, "%d", &N);

  for (k = 0;k < N;k++)
   for (l = 0;l < N;l++)
    inherit_path[k][l] = 0;

  for (j = 0;j < N;j++)
  {
   fscanf(fin, "%d", &M);
   for (k = 0;k < M;k++)
   {
     int destination;
     fscanf(fin, "%d", &destination);
     inherit_path[j][destination-1] = 1; 
   }
  }
   for (l = 0;l < N;l++)
   {
    for (m = 0;m < N;m++)
    {
     for (n = 0;n < N;n++)     
     {
      inherit_path[m][n] += inherit_path[m][l] * inherit_path[l][n];
     }
    } 
   } 
   
   bool diamond = false;
   for (l=0;l < N;l++)
    for (m=0;m < N;m++)
     if (inherit_path[l][m] > 1)
      diamond = true;
   
   if (diamond)
    printf("Case #%d: Yes\n", i+1);
   else
    printf("Case #%d: No\n", i+1);

 }
 fclose(fin);
 return 0;
}
