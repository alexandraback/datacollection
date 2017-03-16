#include <fstream>
#include <iostream>

using namespace std;

int main(){
    ifstream fin ("inputC.txt");
    ofstream fout ("outputC.txt");
    int T, L, curval, val2, newval;
    unsigned long long X;
    double minrep, minrep2;
    char ijk[10002];
    //1 i j k -1 -i -j -k = 0 1 2 3 4 5 6 7
    //there's probably some better way to do this.
    int multtable[8][8] =  {{0, 1, 2, 3, 4, 5, 6, 7}
                        ,   {1, 4, 3, 6, 5, 0, 7, 2}
                        ,   {2, 7, 4, 1, 6, 3, 0, 5}
                        ,   {3, 2, 5, 4, 7, 6, 1, 0}
                        ,   {4, 5, 6, 7, 0, 1, 2, 3}
                        ,   {5, 0, 7, 2, 1, 4, 3, 6}
                        ,   {6, 3, 0, 5, 2, 7, 4, 1}
                        ,   {7, 6, 1, 0, 3, 2, 5, 4}};
    fin >> T;
    for(int a = 1; a <= T; a++){
        fin >> L >> X;
        for(int pos = 0; pos < L; pos++) fin >> ijk[pos];
        bool i = false, k = false;
        int hit[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
        curval = 0;
        for(int pos = 0; pos < L; pos++){
            curval = multtable[curval][ijk[pos]-'h'];   //h makes i = 1
            if(curval == 1){
                i = true;
            }
            if(hit[curval]==-1)
                hit[curval] = pos+1;
        }
        newval = 0;
        for(int pos = 0; pos < X%4; pos++){ //check that string^X = ijk = -1, noting that anything ^ 4 = 1
            newval = multtable[newval][curval];
        }
        minrep = ((double)hit[1])/L;
        if(!i){
            minrep = 5;
            for(int pos = 0; pos < 8; pos++){
                if(hit[pos]>=0){
                    val2 = pos;
                    for(int rep = 1; rep <= 3; rep++){
                        val2 = multtable[curval][val2];
                        if(val2 == 1){
                            i = true;
                            if((double) rep + ((double)hit[pos])/L < minrep){
                                minrep = (double) rep + ((double)hit[pos])/L;
                            }
                        }
                    }
                }
            }
            if(!i){
                fout << "Case #" << a << ": NO\n";
                continue;
            }
            if(minrep >= X){
                fout << "Case #" << a << ": NO\n";
                continue;
            }
        }
        if(newval != 4){
            fout << "Case #" << a << ": NO\n";
            continue;
        }
        for(int pos = 0; pos < 8; pos++) hit[pos] = -1;
        curval = 0;
        for(int pos = L-1; pos >= 0; pos--){
            curval = multtable[ijk[pos]-'h'][curval];   //h makes i = 1
            if(hit[curval] == -1){
                hit[curval] = pos;
            }
            if(curval == 3){
                k = true;
                break;
            }
        }
        /*cout << ijk << '\n';
        cout << L << '\n';
        for(int pos = 0; pos < 8; pos++) cout << hit[pos] << " ";
        cout << "\n\n";*/
        minrep2 = (double) 1 - ((double)hit[3])/L;
        if(!k){
            minrep2 = 5;
            for(int pos = 0; pos < 8; pos++){
                if(hit[pos]!= -1){
                    val2 = pos;
                    for(int rep = 1; rep <= 3; rep++){
                        val2 = multtable[val2][curval];
                        if(val2 == 3){
                            k = true;
                            if(rep+1-((double)hit[pos])/L < minrep2)
                                minrep2 = rep + 1-((double)hit[pos])/L;
                        }
                    }
                }
            }
            if(!k){
                fout << "Case #" << a << ": NO\n";
                continue;
            }
        }
        if(minrep + minrep2 < X){
            //cout << minrep << ' ' << minrep2 << '\n';
            fout << "Case #" << a << ": YES\n";
        }else{
            fout << "Case #" << a << ": NO\n";
        }
    }
}
