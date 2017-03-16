#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<stack>
#include<iostream>
using namespace std;

int N, M;
string Sol;
vector<string> zips;
vector<vector<int> > G;



struct State
{
 int vizited;
 vector<bool> viz;
 stack<int> posses;
 string cSol;
};

vector<int> X;

void bkt(State state)
{
 if(state.vizited == N)
 {
  if(state.cSol < Sol || Sol == "")
  {
   Sol = state.cSol;
  }
 }
 else
 {
  while(state.posses.empty() == false)
  {
   int pos = state.posses.top();

   for(vector<int>::iterator itr = G[pos].begin();
    itr != G[pos].end();
    itr++)
   {
    if(state.viz[*itr] == false)
    {
     string prevCsol = state.cSol;

     state.viz[*itr] = true;
     state.vizited ++;
     state.cSol.append(zips[*itr]);
     state.posses.push(*itr);

     bkt(state);

     state.posses.pop();
     state.viz[*itr] = false;
     state.vizited --;
     state.cSol = prevCsol;
    }
   }
   state.posses.pop();
  }
 }
}

int main()
{
 freopen("file.in","r",stdin);
 freopen("file.out","w",stdout);
 int T;
 scanf("%d",&T);
 for(int t = 1; t <= T; t++)
 {


  scanf("%d%d",&N,&M);
  Sol = "";

  zips.clear();
  zips.resize(N + 1);

  G.clear();
  G.resize(N + 1);

  for(int i = 1; i <= N; i++)
  {
    cin>>zips[i];
  }



  for(int i = 0; i < M; i++)
  {
   int x, y;
   scanf("%d%d",&x,&y);
   G[x].push_back(y);
   G[y].push_back(x);
  }


  for(int i = 1; i <= N; i++)
  {
   State state;

   state.cSol.append(zips[i]);
   state.vizited = 1;
   state.viz.resize(N + 1);
   state.viz[i] = true;
   state.posses.push(i);

   bkt(state);
  }
    printf("Case #%d: ",t);
    cout<<Sol<<"\n";

 }
    return 0;
}
