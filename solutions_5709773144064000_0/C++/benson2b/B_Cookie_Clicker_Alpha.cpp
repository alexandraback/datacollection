#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;
int main(void){
    //ifstream fin("B-small-attempt0.in");
    //ifstream fin("bex.in");
    //ofstream fout("Bs.txt");

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
        double C,F,X;
        string Cs,Fs,Xs;
        double ans=0.0d;
        cin >> C >> F >> X;
/*
        fin >> Cs >> Fs >> Xs;
        //cout << Cs << " " << Fs << " " << Xs << endl;
        ss.str(Cs);
        ss.clear();
        ss >> C;
        ss.str(Fs);
        ss.clear();
        ss >> F;
        ss.str(Xs);
        ss.clear();
        ss >> X;
*/
        //cout << C << " " << F << " " << X << endl;
        double nT = X/2.0d , buyT = C/2.0d+X/(2.0d+F);
        double preT = C/2.0d;
        for(int i = 1 ; buyT < nT ; i++){
            nT = buyT;
            preT += C/(2.0d+i*F);
            buyT = preT + X/(2.0d+(i+1)*F);
        }
        cout << "Case #" << t+1 << ": " << fixed  <<  setprecision(7) << nT << "\n";
        //cout.unsetf( ios::fixed );
        //fout << "Case #" << t+1 << ": " << fixed  <<  setprecision(7) << nT << "\n";

    }
/*
    fin.close();
    fout.close();
*/
    return 0;
}
