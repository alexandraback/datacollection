#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<ctime>
#include<assert.h>

#include<cmath>
#include<iostream>
#include<fstream>

#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
#include<limits.h>

using namespace std;

#define MAX(a,b) ((a)>(b) ? (a) : (b))
#define MIN(a,b) ((a)<(b) ? (a) : (b))
#define EPS 1e-9
#define asdf exit(0);
#define AB(a) ((a)<(0) ? (-(a)) : (a))
#define EQ(a,b) ( (fabs((a)-(b))<EPS) ? (1) : (0))





typedef long long LL;
//typedef __int64 LL;




string keyboard;
string target;
int K,L,S;
//K= keyboard len
//L=target word
//S=finalrandomword

string now;



double lob,hor;
int score;
int mxScore;

int isScore(int pos)
{
  if (pos >= (L - 1)) {
    int i;
    int j = pos - L + 1;
    for (i = 0; i < L; i++, j++) {
      if (target[i] != now[j])
        return 0;
    }
    return 1;
  }
  return 0;
}



void bttk(int pos)
{
  if(pos==S)
  {
    lob+=score;
    mxScore=max(mxScore,score);
    hor++;
    return;
  }

  int i;
  for(i=0;i<K;i++)
  {
    now[pos]=keyboard[i];
    int added=isScore(pos);
    score+=added;
    bttk(pos+1);
    score-=added;
  }
}



int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int i,j,k,T,cs,n,m,len;
    scanf("%d",&T);

    for(cs=1;cs<=T;cs++)
    {
      printf("Case #%d: ",cs);

      scanf("%d %d %d",&K,&L,&S);
      cin>>keyboard;
      cin>>target;
      hor=0;
      lob=0;
      score=0;
      mxScore=0;
      now.resize(S,'0');

      bttk(0);




      printf("%.12lf\n",mxScore-(lob/hor));
    }


    return 0;
}
