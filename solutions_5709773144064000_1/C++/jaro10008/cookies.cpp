#include<fstream>
#include<iomanip>

using namespace std;

int main(){
    int T;
    long double X,F,C,przychod,A,czas;
    ifstream od("input");
    ofstream zap("output");
    zap<<std::fixed;
    zap.precision(7);
    od>>T;
    for(int licznik=1;licznik<=T;++licznik){
        przychod=2.0;
        czas=0.0;
        od>>C>>F>>X;
        while(true){//if A=C
            if(przychod*C<F*(X-C)){
                czas+=C/przychod;
                przychod+=F;
            }
            else break;
        }
        czas+=X/przychod;

        zap<<"Case #"<<licznik<<": "<<czas<<endl;
    }
    od.close(); zap.close();


}
