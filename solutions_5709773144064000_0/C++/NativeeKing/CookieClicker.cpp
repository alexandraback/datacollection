// Project: Google Code Jam 2014: Cookie Clicker
// Author:  Kévin Moisy-Mabille
// Date:    2014/04/12

#include <iostream>
#include <fstream>

using namespace std;



int main(int argc, char ** argv){
    if (argc != 2)
        cout << "usage: ./CookieClicker input.txt" << endl;
    cout.precision(6);
    cout.setf(ios::fixed);

    ifstream fichier(argv[1], ios::in);
    if(fichier) {
        int T;
        fichier >> T;
        for (int i=1; i<=T; i++){
            double C, F, X, t1, t2, t3, time = 0.0, income = 2.0;
            fichier >> C >> F >> X;
            while(true){ 
                t1 = X/income;
                t2 = C/income;
                t3 = X/(income+F);
                
                if (t2 + t3 < t1){
                    time += t2;
                    income += F;
                } else {
                    time += t1;
                    break;
                }
            }
            cout << "Case #" << i << ": " << time << endl;
        }
        fichier.close();
    } else 
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    return 0;
}

