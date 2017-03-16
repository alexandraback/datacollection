#include <iostream>
#include <cstdlib>
using namespace std;

int main( int argc, const char* argv[] )
{
    int casex, casen;
    cin >> casex;
    for (int casen = 1; casen<casex+1; casen++)
    {
        int n, stars=0, turns=0;
        int sets[4][1000];
        cin >> n;
        for (int j=0; j < n; j++)
        {
            cin >> sets[0][j] >> sets[1][j];
            sets[2][j]=0;
        }
        bool edit;
        do 
        {
            edit = false;
            for (int j=0; j < n; j++)
            {
                if (sets[1][j]<=stars && sets[2][j]!=2)
                {
                    stars+=sets[2][j]==1?1:2;
                    sets[2][j]=2;
                    turns++;
                    edit=true;
                }
            }
            if (edit) continue;
            int min=-1, id;
            for (int j=0; j < n; j++)
            {
                if (sets[0][j]<=stars && sets[2][j]==0 && sets[1][j]>min)
                {
                    id = j;
                    min = sets[1][j];
                }
            }
            if (min!=-1)
            {
                stars+=1;
                sets[2][id]=1;
                turns++;
                edit=true;
                continue;
            }
        } while (edit==true);
        for (int j=0; j < n; j++)
        {
            if (sets[2][j]!=2)
            {
                cout << "Case #" << casen << ": Too Bad" << endl;
                goto die;
            }
        }
        
        cout << "Case #" << casen << ": " << turns << endl;
        die:
        continue;
    }
}