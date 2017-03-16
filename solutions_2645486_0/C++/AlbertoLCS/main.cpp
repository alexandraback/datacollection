#include <iostream>
#include <fstream>

using namespace std;

int casos, energy, recharge, N, act[10], gain, cEnergy, Max;

void getEnergy(int C)
{
    if(C == N){
        if(gain > Max)
            Max = gain;
        return;
    }
    for(int use = 0; use <= cEnergy; use++){
        int aux = cEnergy;
        cEnergy = cEnergy + recharge - use;
        if(cEnergy > energy)
            cEnergy = energy;
        gain = gain + use*act[C];
        getEnergy(C+1);
        cEnergy = aux;
        gain = gain - use*act[C];
    }
}
int main()
{
    ifstream in;
    ofstream out;
    in.open("input.txt");
    out.open("output.txt");
    in >> casos;
    for(int x = 1; x <= casos; x++){
        in >> energy >> recharge >> N;
        for(int i = 0; i < N; i++)
            in >> act[i];
        if(recharge >= energy){
            gain = 0;
            for(int i = 0; i < N; i++)
                gain += act[i];
            out << "Case #" << x << ": " << gain*energy << endl;
            continue;
        }
        cEnergy = energy;
        Max = 0;
        gain = 0;
        getEnergy(0);
        out << "Case #" << x << ": " << Max << endl;
    }
    return 0;
}
