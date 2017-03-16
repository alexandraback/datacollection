#include <iostream>
#include <string>

using namespace std; 

int N,M;
int A[101][101];

bool NotOk(int x, int y)
{
    int v = A[x][y];
    bool xx = false;
    bool yy = false;
    for (int i = 1 ; i <= (N + M + 1); i++)
    {
        if ((i + x < N) && (v < A[i + x][y])) xx = true;
        if ((x - i >= 0) && (v < A[x - i][y])) xx = true;
        if ((i + y < M) && (v < A[x][i + y])) yy = true;
        if ((y - i >= 0) && (v < A[x][y - i])) yy = true;
         
        if (xx && yy) break;
    }
    
   
    return  (xx && yy);
}
bool slove()
{
    
  
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (NotOk(i,j))
            {
                return false;
            }
        }
    }
    
    return true;
}
int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int T = 0; 
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >>N>>M;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> A[i][j];
            }
        }
    
        cout << "Case #"<<t<<": "<<(slove() ? "YES" : "NO") <<endl;
 
    }
    
    //while(1);
}
