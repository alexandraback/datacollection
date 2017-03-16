#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream _if("in.txt");
    ofstream _of("out.txt");
    _of.precision(7);
    _of.setf( ios::fixed, ios::floatfield );
    int n;
    _if >> n;
    for(int j=0;j < n; j++){
        double t,f,i;
        _if >> f >> i >> t;
        int k = t/f - 2/i;
        double result = 0.0;
        for(int l = 0; l < k; l++)
            result += f/(2+l*i);

        if(k<0) k=0;
        result += t/(2+i*k);

        _of << "Case #" << j+1 << ": " << result << endl;
    }
}
