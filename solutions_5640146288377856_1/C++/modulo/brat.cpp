#include <iostream>
#include <vector>

using namespace std;

int brat(int R, int C, int W)
{
    if(W==1)
        return R*C;
    if(R*C == W)
        return W;
    
    int recherche = R*(C/W);
    int coule = min(W, C%W + W - 1);
    int sol = recherche + coule;
    
    if(sol < W)
        cout << "LOOOOL" << endl;
    
    return sol;
}

int main()
{
    int tests;
    cin >> tests;
    //cout << tests << endl;
    
    for(int i = 0; i < tests; i++)
    {
        //cerr << i << endl;
        int R, C, W;
        cin >> R >> C >> W;
        
        cout << "Case #" << i+1 << ": " << brat(R, C, W) << endl;
    }
    
    return 0;
}