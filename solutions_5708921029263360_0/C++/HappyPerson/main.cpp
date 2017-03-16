#include <cstdio>
#include <vector>

using namespace std;

const int MAXC=27;

int cases, rep, oSize, totes;
int cLim[5], cNum[5], cList[MAXC+5][5], cCount[5][5][5], wList[MAXC+5], fList[MAXC+5];

void dfs(int o, int w)
{
  if(o>oSize)
  {
    if(w>totes)
    {
      totes=w;
      for(int i=1; i<=w; i++)
        fList[i]=wList[i];
    }
    return; 
  }

  dfs(o+1, w);

  cCount[cList[o][1]][cList[o][2]][1]++;
  cCount[cList[o][1]][cList[o][3]][2]++;
  cCount[cList[o][2]][cList[o][3]][3]++;
  if(cCount[cList[o][1]][cList[o][2]][1]<=rep && cCount[cList[o][1]][cList[o][3]][2]<=rep && cCount[cList[o][2]][cList[o][3]][3]<=rep)
  {
    wList[w+1]=o;
    dfs(o+1, w+1);
  }
  cCount[cList[o][1]][cList[o][2]][1]--;
  cCount[cList[o][1]][cList[o][3]][2]--;
  cCount[cList[o][2]][cList[o][3]][3]--;
}

int main()
{
  scanf("%d", &cases);
  for(int q=1; q<=cases; q++)
  {
    totes=0, oSize=0;
    scanf("%d%d%d%d", &cLim[1], &cLim[2], &cLim[3], &rep);

    for(int i=1; i<=cLim[3]; i++)
      for(int j=1; j<=cLim[2]; j++)
        for(int k=1; k<=cLim[1]; k++)
        {
          oSize++;
          cList[oSize][3]=i, cList[oSize][2]=j, cList[oSize][1]=k;
        }

    dfs(1, 0);

    printf("Case #%d: %d\n", q, totes);
    for(int i=1; i<=totes; i++)
      printf("%d %d %d\n", cList[fList[i]][1], cList[fList[i]][2], cList[fList[i]][3]);
  }
}
