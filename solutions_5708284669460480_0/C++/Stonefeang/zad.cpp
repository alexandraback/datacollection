#include <cstdio>
#include <algorithm>
using namespace std;

int t;
int kla, n, m;

char klaw[107];
char slo[107];

int szanse[500];

int czy;

int kmp[107];
int it;

int najw;

double dyn[107][107][107];

double oczek;

int main()
{
    scanf("%d", &t);
    for (int h=1; h<=t; h++)
    {
          scanf("%d%d%d", &kla, &n, &m);
          for (int i=0; i<=400; i++)
          {
              szanse[i]=0;
          }
          scanf("%s", klaw);
          for (int i=0; i<kla; i++)
          {
              szanse[klaw[i]]++;
          }
          czy=1;          
          scanf("%s", slo);     
          for (int i=n; i; i--)
          {
              slo[i]=slo[i-1];
          }
          slo[0]=0;
          for (int i=n+1; i<=102; i++)
          {
              slo[i]=0;
          }
          for (int i=0; i<=102; i++)
          {
              kmp[i]=0;
          }
          for (int i=2; i<=n; i++)
          {
              it=kmp[i-1];
              while(it && slo[i]!=slo[it+1])
              it=kmp[it];
              if (slo[i]==slo[it+1])
              kmp[i]=it+1;
          }
          najw=(m-kmp[n])/(n-kmp[n]);
          for (int i=0; i<=102; i++)
          {
              for (int j=0; j<=102; j++)
              {
                  for (int k=0; k<=102; k++)
                  {
                      dyn[i][j][k]=0.0;
                  }
              }
          }
          dyn[0][0][0]=1.0;
          for (int g=0; g<m; g++)
          {
              for (int j=0; j<n; j++)
              {
                  for (char l='A'; l<='Z'; l++)
                  {
                      it=j;
                      while(it && slo[it+1]!=l)
                      it=kmp[it];
                      if (slo[it+1]==l)
                      it++;
                      //dyn[g+1][j-(j%n)+it]+=((dyn[g][j]*szanse[l])/kla);
                      for (int o=0; o<=m; o++)
                      {
                          if (it==n)
                          {
                                    dyn[g+1][o+1][kmp[n]]+=(dyn[g][o][j]*szanse[l])/(1.0*kla);
                          }
                          else
                          {
                                    dyn[g+1][o][it]+=(dyn[g][o][j]*szanse[l])/(1.0*kla);
                          }
                      }
                  }
              }
          }
          oczek=0.0;
          for (int i=0; i<=m; i++)
          {
              for (int j=0; j<=m; j++)
              {
                  oczek+=dyn[m][i][j]*i;
                  //printf("%d %d   %lf\n", i, j, dyn[m][i][j]);
              }
          }
          printf("Case #%d: %.8lf\n", h, najw-oczek);
    }
    return 0;
}
