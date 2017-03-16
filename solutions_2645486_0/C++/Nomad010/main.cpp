#include <cstdio>
#include <vector>

using namespace std;

int E;
int R;
int N;
vector<int> V;

int TotalGain(int position, int energy)
{
    if(position == N)
        return 0;
    
    int best = 0;
    
    for(int i = 0; i <= energy; ++i)
    {
        int newEnergy = min(E, energy - i + R);
        best = max(best, V[position]*i + TotalGain(position + 1, newEnergy));
    }
    
    return best;
}

int main(int argc, char** argv)
{
    int T;
    scanf("%d", &T);
    
    for(int t = 1; t <= T; ++t)
    {
        scanf("%d %d %d", &E, &R, &N);
        V.clear();
        V.resize(N);
        for(int i = 0; i < N; ++i)
            scanf("%d", &V[i]);
        
        printf("Case #%d: %d\n", t, TotalGain(0, E));
    }
    
    return 0;
}