#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<sstream>
using namespace std;

int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");
    int T;
    in >> T;
    int wall[1000];
    int temp[1000];
    vector<  pair< pair<int,int> , pair<int , int > > > attacks;
    for(int t = 1; t <= T; t++)
    {
        memset(wall, 0, sizeof(wall));
        memset(temp, 0, sizeof(temp));
        int N;
        in >> N;
        attacks.clear();
        for(int j = 0; j < N; j++)
        {
          int d, n, w, e, s, di, pi, si;
          in >> d >> n >> w >> e >> s >> di >> pi >> si;
          for(int i = 0; i < n; i++)
          {
            attacks.push_back( make_pair ( make_pair( d + i*di, s + i*si ) , make_pair(w + i * pi+500, e + i * pi+500) ));
          }
        }
        sort(attacks.begin(),attacks.end());
        int suc = 0;
        int prevDay = -1;
        for(int i =0; i < attacks.size(); i++)
        {
            int D = attacks[i].first.first;
            if(D != prevDay)
            {
                for(int j = 0; j < 1000; j++)
                    wall[j] = temp[j];
            }
            int S = attacks[i].first.second;
            int W = attacks[i].second.first;
            int E = attacks[i].second.second;
     
            int good = 0;
            for(int k = W; k < E; k++)
            {
                if(wall[k] < S) good = 1;
                temp[k] = max(temp[k], S);
            }
     
            if(good) 
            {
                suc++;
            }
            prevDay = D;
        }
       out<<"Case #"<<t<<": "<<suc<<endl;   
    }
}
