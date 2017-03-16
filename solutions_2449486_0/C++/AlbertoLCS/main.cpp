#include <iostream>
#include <fstream>

using namespace std;

bool check(int tablero[100][100], int max[100][2], int n, int m)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if( tablero[i][j] != max[i][0] && tablero[i][j]!=max[j][1] )
                return false;
    return true;
}
int main()
{
    ifstream arc1;
    ofstream arc2;
    arc1.open("input.txt");
    arc2.open("output.txt");

    int casos, tablero[100][100], max[100][2], n, m;
    arc1 >> casos;
    for(int c = 1; c < casos+1; c++){
        arc1 >> n >> m;
        for(int i = 0; i < n; i++)
            max[i][0] = 0;
        for(int i = 0; i < m; i++)
            max[i][1] = 0;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                arc1 >> tablero[i][j];
                if(tablero[i][j] > max[i][0])
                    max[i][0] = tablero[i][j];
            }
        for(int j = 0; j < m; j++)
            for(int i = 0; i < n; i++)
                if(tablero[i][j] > max[j][1])
                    max[j][1] = tablero[i][j];
        if(check(tablero,max,n,m))
            arc2 << "Case #" << c << ": YES" << endl;
        else
            arc2 << "Case #" << c << ": NO" << endl;
    }

    arc1.close();
    arc2.close();
    return 0;
}
