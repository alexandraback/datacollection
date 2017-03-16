#include<fstream>
#include<string>
using namespace std;

ifstream fin("password.in");
ofstream fout("password.out");

int T;
int A, B;
long double p[100000];

int main()
{
    fin >> T;
    fout.precision(20);
    for(int t=0; t<T; t++){
        fin >> A >> B;
        for(int a=0; a<A; a++)
            fin >> p[a];
        long double best = B+2;
        long double p_right = 1;
        for(int use = 0; use<A; use++){
            p_right*=p[use];
            long double poss = p_right*(A-(use+1) + B-(use+1) + 1);
            poss += (1-p_right)*(A-(use+1) + B-(use+1) + B + 2);
            if(poss < best)
                best = poss;
        }
        fout << "Case #" << t+1 << ": " << best << endl;
    }
    return 0;
}
