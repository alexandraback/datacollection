#include <iostream>
#include <vector>
#include <cassert>

#define D 676060 + 100
#define X 500
using namespace std;

int solve();

int W, E, S;

class Tribe
{
public:
  int t;
  int d, n, w, e, s, d_, p_, s_;
  Tribe(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)
  {
    d = a0;
    n = a1;
    w = a2;
    e = a3;
    s = a4;
    d_ = a5;
    p_ = a6;
    s_ = a7;
    t = 0;
  }
  int addTurn(int day)
  {
    if(t == n) return -1;
    if(day != d) return 0;
    t++;
    W = w;
    E = e;
    S = s;
    d += d_;
    w += p_;
    e += p_;
    s += s_;
    return 1;
  }
};

int main()
{
	int T;
	cin >> T;
  for(int i=1; i<=T; i++)
    cout << "Case #" << i << ": " << solve() << endl;
}	

int solve()
{
  //TODO :: minus!!!!!!!!!!!!!
  long ans = 0;
  int N;
  vector <Tribe> A;
  vector <int> H;
  cin >> N;
  for(int i=0; i<N; i++)
  {
    int temp[8];
    for(int j=0; j<8; j++)
      cin >> temp[j];
    A.push_back(Tribe(temp[0], temp[1], temp[2], temp[3], temp[4], temp[5], temp[6], temp[7]));
  }
  for(int i=0; i<2*2*X; i++)
    H.push_back(0);
  for(int i=0; i<D; i++)
  {
    vector <int> wallW;
    vector <int> wallE;
    vector <int> wallS;
    assert(wallW.size() == 0);
    for(int j=0; j<N; j++)
    {
      int sig = A[j].addTurn(i);
      if(sig > 0)
      {
        bool check = false;
        assert(X+W >= 0);
        for(int k=(X+W)*2; k<=(X+E)*2; k++)
        {
          if(H[k] < S)
            check = true;
            //H[k] = S;
        }
        if(check) ans ++;
        /*
        cout << "day : " << i << " \ttribe : " << j << "\tsucksex : " << check << endl;
        cout << "W : " << W << "\t\tE : " << E << "\t\tS : " << S << endl;
        */
       /* 
        cout << "Wall Printing" << endl;
        for(int i=0; i<20; i++)
          cout << H[2*X+i] << " ";
        cout << endl;
        */
        wallW.push_back((X+W)*2);
        wallE.push_back((X+E)*2);
        wallS.push_back(S);
      }
    }
    
    for(int j=0; j<wallW.size(); j++)
    {
      for(int k=wallW[j]; k<=wallE[j]; k++)
      {
        if(H[k] < wallS[j])
          H[k] = wallS[j];
      }
    }

  }
  return ans;
}

