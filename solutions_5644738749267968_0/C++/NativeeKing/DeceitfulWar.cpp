// Project: Google Code Jam 2014: Deceitful War
// Author:  Kévin Moisy-Mabille
// Date:    2014/04/13

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

// sort function (merge algorithm)
void sort(float* in, int first, int last, float* out){
    if (first > last-2)
	return;
    int mid = first + (last-first)/2;
    sort(out, first, mid, in);
    sort(out, mid, last, in);
    int i, i1 = first, i2 = mid;
    for (i=first; i<last; i++)
	if (i2 == last || (i1 < mid && in[i1] < in[i2]))
	    out[i]=in[i1++];
	else 
	    out[i]=in[i2++];
}



int main(int argc, char ** argv){
    if (argc != 2)
        cout << "usage: ./DeceitfulWar input.txt" << endl;

    ifstream fichier(argv[1], ios::in);
    if (fichier){
        int T;
        fichier >> T;
        for (int i=1; i<=T; i++){
            int N, y=0, z=0, y_count=0, z_count=0, pos1=0, pos2=0;
            fichier >> N;
            float* P1  = (float*) malloc(sizeof(float) * N+1);
            float* P2  = (float*) malloc(sizeof(float) * N+1);
            float* P1s = (float*) malloc(sizeof(float) * N+1);
            float* P2s = (float*) malloc(sizeof(float) * N+1);
            for (int j=0; j<N; j++){
                 fichier >> P1[j];
                 P1s[j] = P1[j];
            }
            for (int j=0; j<N; j++){
                 fichier >> P2[j];
                 P2s[j] = P2[j];
            }
            sort(P1, 0, N, P1s);
            sort(P2, 0, N, P2s);
            P1s[N] = 1.0;
            P2s[N] = 1.0;
            for (int j=0; j<2*N; j++) {
                if (P1s[pos1] > P2s[pos2]){
                    pos2++;
                    y_count++;
                    if (z_count > 0){
                        z_count--;
                        z++;
                    }
                } else {
                    pos1++;
                    z_count++;
                    if (y_count > 0){
                        y_count--;
                        y++;
                    }
                }
            }
            cout << "Case #" << i << ": " << y << " " << N-z << endl;
        }
        fichier.close();
    } else 
        cerr << "Impossible d'ouvrir le fichier !" << endl;
    return 0;
}


