#include<fstream>
#include<string>
using namespace std;

ifstream fin("dancing.in");
ofstream fout("dancing.out");

int T;
int N, S, p, t;

int SUM = 0;

int main()
{
    fin >> T;
    for(int x=0; x<T; x++){
        fin >> N >> S >> p;
        int h = 0;
        for(int n=0; n<N; n++){
            fin >> t;
            if(t >= (3*p-2)){
                h++;
                continue;
            }
            else if((S>0) && ((t == 3*p-3) || (t == 3*p-4)) && (t>=2 && t<=28)){
                h++;
                S--;
            }
        }
        fout << "Case #" << x+1 << ": " << h << endl;
        SUM += h;
    }
    //fout << SUM << endl;
    return 0;
}
