#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <stdio.h>

#define pb push_back
#define mp make_pair

using namespace std;


int main(){

long long T,E,R,N,steps;
long long dat;
long long points,energy;;
vector<long long> data,backup;
cin >> T;

    for(int i = 0; i < T; i++){
        cin >> E >> R >> N;
        points = 0;
        energy = E;
        data.clear();
        backup.clear();
        if (R > E)
            R = E;

        for(int j = 0; j < N; j++){
            cin >> dat;
            data.pb(dat);
            backup.pb(0);
        }

        for(int z = 0; z < data.size(); z++){
            energy+= R;
            if (energy > E)
                energy = E;
            points += data[z]*energy;
            backup[z] += energy;
            energy = 0;



            for(int zz = 0; zz < z; zz++){
                if (backup[zz] > 0 && data[z] >= data[zz]){
                    points = points  + data[z]*backup[zz] - data[zz]*backup[zz];
                    backup[z] += backup[zz];
                    if(backup[z] > E){
                        dat = backup[z]-E;
                        backup[z] = E;
                         points = points + data[zz]*dat - data[z]*dat;


                    }
                    backup[zz]=0;
                }
            }

            for(int zz = 0; zz < data.size(); zz++){
                backup[zz] -= R;
                if (backup[zz] < 0)
                    backup[zz] = 0;
            }



        }


            cout << "Case #" << i+1 << ": " << points << endl;



    }
return 0;
}
