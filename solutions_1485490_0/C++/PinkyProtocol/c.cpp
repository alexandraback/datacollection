#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long int lli;

struct state
{
  lli count;
  lli toys;
  lli boxes;
  state() { count = boxes = toys = 0;}
};


int main()
{
  int T; cin >> T;
  for (int k = 1 ; k <= T; ++k)
  {
    lli N, M; cin >> N >> M;
    vector<lli> A;
    vector<vector<state> > nums(N+1, vector<state>(M+1, state()));
    for (int i = 0; i < N; ++i)
    {
      lli x,y; cin >> x >> y;
      nums[1+i][0].boxes = x; A.push_back(y);
    }
    vector<lli> B;
    for (int i = 0; i < M; ++i)
    {
      lli x,y; cin >> x >> y;
      nums[0][1+i].toys = x; B.push_back(y);
    }
    
    for (int box = 1; box <= N; ++box)
    {
      for (int toy = 1; toy <= M; ++toy)
      {
        state left = nums[box-1][toy];
        state below = nums[box][toy-1];  
        lli addition = 0;
        lli numboxes = below.boxes;
        lli numtoys = left.toys;
        //cout << A[box-1] << " == " << B[toy-1] << endl;
        if (A[box-1] == B[toy-1])
        {
          if (numboxes < numtoys)
          {
            addition = numboxes;
            numtoys -= numboxes;
            numboxes = 0;
          }
          else
          {
            addition = numtoys;
            numboxes -= numtoys;
            numtoys = 0;
          }
        }
        nums[box][toy].boxes = numboxes;
        nums[box][toy].toys = numtoys;
        nums[box][toy].count = std::max(left.count, below.count) + addition;
        
      }
    }
    /*for (int i = 0; i <= M; ++i)
    {
      for (int j = 0; j <= N; ++j)
        cout << "(" << nums[j][i].count << ", " << nums[j][i].boxes << ", " << nums[j][i].toys << ") ";
      cout << endl;
    }*/
    cout << "Case #" << k << ": " << nums[N][M].count << endl;
  }
}