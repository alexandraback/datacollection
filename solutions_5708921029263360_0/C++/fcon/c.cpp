#include <fstream>
#include <iostream>
using namespace std;


int main(int argc, char * argv[])
{
    if (argc != 2)
        return 1;
    
    ifstream fin(argv[1]);
    ofstream fout("output.txt");
    
    int T, t;
    int J, P, S, K;
    int j, p, s;
    int jp[100], js[100], ps[100];
    int solution[1000][3];
    int count;
    
    fin >> T;
    
    for (t = 1; t <= T; t++) {
        fin >> J >> P >> S >> K;
        
        count = 0;
        
        for (j = 0; j < 100; j++)
            jp[j] = js[j] = ps[j] = 0;
        
        for (j = 0; j < J; j++)
            for (p = 0; p < P; p++)
                for (s = 0; s < S; s++)
                    if (jp[j*10 + p] < K && js[j*10 + s] < K && ps[p*10 + s] < K) {
                        jp[j*10 + p]++;
                        js[j*10 + s]++;
                        ps[p*10 + s]++;
                        
                        solution[count][0] = j+1;
                        solution[count][1] = p+1;
                        solution[count][2] = s+1;
                        
                        count++;
                    }
        
        fout << "Case #" << t << ": " << count << endl;
        
        for (j = 0; j < count; j++)
            fout << solution[j][0] << ' ' << solution[j][1] << ' ' << solution[j][2] << endl;
    }
    
    fin.close();
    fout.close();
    
    return 0;
}
