#include<fstream>
#include<iomanip>
using namespace std;

int main(){
    ifstream in("B.in"); ofstream out("B.out");
    out<<setprecision(10);
    int T;
    in>>T;
    for (int t=0;t<T;t++){
        out<<"Case #"<<t+1<<": ";
        double C,F,X;
        in>>C>>F>>X;
        double ans = 1000000.0;
        double rate = 2.0;
        double time = 0.0;
        for(int i=0;i<100000;i++){
            double tmpans = time + X/rate;
            if (tmpans<ans) ans = tmpans;
            time += C/rate;
            rate += F;
        }
        out<<ans;
        out<<"\n";
    }

}
