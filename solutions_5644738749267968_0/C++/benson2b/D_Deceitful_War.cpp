#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;
int main(void){
    //ifstream fin("D-small-attempt1.in");
    //ifstream fin("Dex.in");
    //ofstream fout("Ds.txt");

    int T;
    cin >> T;
/*
    string st;
    getline(fin,st);
    stringstream ss(st);
    ss >> T;
*/
    //cout << T << endl;
    for(int t = 0 ; t < T ; t++){
        int N,W=0,DW=0;

        cin >> N;
/*
        string Ns;
        fin >> Ns;
        ss.str(Ns);
        ss.clear();
        ss >> N;
*/
        double *Nblocks = new double[N];
        double *Kblocks = new double[N];
        for(int i = 0 ; i < N ; i++){
            cin >> Nblocks[i];
/*
            fin >> Ns;
            ss.str(Ns);
            ss.clear();
            ss >> Nblocks[i];
*/
            //cout << Nblocks[i] << " ";
        }
        //cout << endl;
        for(int i = 0 ; i < N ; i++){
            cin >> Kblocks[i];
/*
            fin >> Ns;
            ss.str(Ns);
            ss.clear();
            ss >> Kblocks[i];
*/
            //cout << Kblocks[i] << " ";
        }
        //cout << endl;
        sort(Nblocks,Nblocks+N);
        sort(Kblocks,Kblocks+N);

/*
        for(int i = 0 ; i < N ; i++){
            fout << Nblocks[i] << " ";
        }
        fout << endl;
        for(int i = 0 ; i < N ; i++){
            fout << Kblocks[i] << " ";
        }
        fout << endl;
*/
        int Nmin = 0;
        int Kmax = N-1;
        bool Dsuc = false;
        while(!Dsuc){
            Dsuc = true;
            for(int i = Nmin ; i < N ; i++){
                if(Nblocks[i] < Kblocks[Kmax-N+1+i]){
                    Dsuc = false;
                    Nmin += 1;
                    Kmax -= 1;
                    break;
                }
            }
        }
        DW = N-Nmin;
        bool *Kb = new bool[N];
        for(int i = 0 ; i < N ; i++)
            Kb[i] = false;
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                if(!Kb[j]){
                    if(Kblocks[j] > Nblocks[i]){
                        Kb[j] = true;
                        W += 1;
                        break;
                    }
                }
                if(j == N-1){
                    for(int z = 0 ; z < N ; z++){
                        if(!Kb[z]){
                            Kb[z] = true;
                            break;
                        }
                    }
                }
            }
        }
        delete[] Kb;
        cout << "Case #" << t+1 << ": " << DW << " " << N-W << "\n";
        //fout << "Case #" << t+1 << ": " << DW << " " << N-W << "\n";
        delete[] Nblocks;
        delete[] Kblocks;

    }
/*
    fin.close();
    fout.close();
*/
    return 0;
}
