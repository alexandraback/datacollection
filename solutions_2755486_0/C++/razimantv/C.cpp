# include <cstdio>
# include <map>
# include <algorithm>
# include <vector>

using namespace std;

struct attack
{
  int day,west,east,strength;
  attack(int d,int w,int e,int s)
  {
    day=d;
    west=w;
    east=e;
    strength=s;
  }
  bool operator<(const attack& a)const
  {
    return day<a.day;
  }
};

map<int,int>heightmap;
vector<attack> attacks;

int main()
{
  int T;
  scanf("%d",&T);
  for(int t=1;t<=T;t++)
  {
    heightmap.clear();
    attacks.clear();

    int N;
    scanf("%d",&N);

    for(int i=0;i<N;i++)
    {
      int d,n,w,e,s,dd,dp,ds;
      scanf("%d%d%d%d%d%d%d%d",&d,&n,&w,&e,&s,&dd,&dp,&ds);
      for(int j=0;j<n;j++)
      {
        attacks.push_back(attack(d+j*dd,2*(w+j*dp),2*(e+j*dp),s+j*ds));
      }
    }
    sort(attacks.begin(),attacks.end());

    int ret=0;
    for(int i=0,j=0;i<attacks.size();i=j)
    {
      for(j=i+1;(j<attacks.size())&&(attacks[j].day==attacks[i].day);j++);

      for(int k=i;k<j;k++)
      {
        bool flag=false;
        for(int x=attacks[k].west;x<=attacks[k].east;x++)
        {
          int curh;
          if(heightmap.count(x))curh=heightmap[x];
          else curh=0;
          if(curh<attacks[k].strength)
          {
            flag=true;
            break;
          }
        }
        //printf("%d %d %d %d : %d\n",attacks[k].day,attacks[k].west,attacks[k].east,attacks[k].strength,flag);
        if(flag)ret++;
      }

      for(int k=i;k<j;k++)
      {
        for(int x=attacks[k].west;x<=attacks[k].east;x++)
        {
          int curh;
          if(heightmap.count(x))curh=heightmap[x];
          else curh=0;
          if(curh<attacks[k].strength)heightmap[x]=attacks[k].strength;
        }
      }
    }

    printf("Case #%d: %d\n",t,ret);
  }
  return 0;
}
