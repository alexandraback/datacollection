#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[])
{
    ifstream input("input.txt");
    ofstream output("output.txt");
    int T;
    input >> T;
    for(int i=0;i<T;i++){
        cout << "Case: " <<  i+1 << endl;
        output << "Case #" << i+1 << ": ";

        int A,B;
        input >> A >> B;
        vector<double> p(A);
        for(int j=0;j<A;++j){
            input >> p[j];
        }
        double P = 1.0;
        for(int j=0;j<A;++j){
        	P*=p[j];
        }
        double Pk = 1.0;

        double res = 1+B+1;
        //cout << 0 << ": " << res << endl;


        for(int j=0;j<A+1;++j){
        	double tmp = Pk*(B-A+1+2*(A-j))+(1-Pk)*(B-A+1+2*(A-j)+B+1);
        	//cout << j << ": " << tmp << " " <<Pk <<" "<<(B-A+1+2*(A-j)) <<" "<<(1-Pk) <<" "<<(B-A+1+2*(A-j)+B+1)<< endl;
        	if(tmp < res){
        		res = tmp;
        	}
			if(j<A){
				Pk*=p[j];
        	}
        }

        output.precision(6);
        output <<  fixed<< res << endl;
        cout.precision(6);
        cout <<  fixed <<res << endl;
    }
    input.close();
    output.close();

    return 0;
}

