#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>  
#include <vector>
#include <limits>
#include <string>
#include <bitset>

using namespace std;


long long gcd (long long a, long long b){
    long long c;
    while ( a != 0 ) {
        c = a; a = b%a;  b = c;
    }
    return b;
}

double log2(double input){
    // log(n)/log(2) is log2.  
    return log(input) / log(2.0);  
}

vector<int> toBinary(long long input) {
    vector<int> O(64);  //The output array
    bitset<64> A=input;//A will hold the binary representation of N 
    for(int i=0,j=63;i<64;i++,j--)
    {
        //Assigning the bits one by one.
        O[i]=A[j];
    }
    return O;
}


int main (int argc, char* argv[])
{
    ifstream myfile ("A-large.in");
    ofstream outputfile ("output.txt");

    if (myfile.is_open()){
        int T_numTestCases;
        long long P, Q; //declarate variables here
        char slash;
        myfile >> T_numTestCases;
        for (int numTest = 0; numTest < T_numTestCases; numTest++){
            myfile >> P; //read in variables here
            myfile >> slash;
            myfile >> Q;
            //do things here:
            long long greatest_cd = gcd(P, Q);
            P /= greatest_cd;
            Q /= greatest_cd;

            bool is_possible = ((Q & (Q - 1)) == 0);
            long long biggest_summand;
            if (!is_possible){
                cout << "Case #" << numTest+1 << ": " << "impossible" << endl; 
                outputfile << "Case #" << numTest+1 << ": " << "impossible" << endl; //write in output here
            }
            else{
                if(P == 1){
                    long long result = (long long)log2((double)Q);
                    cout << "Case #" << numTest+1 << ": " << result << endl; 
                    outputfile << "Case #" << numTest+1 << ": " << result << endl; //write in output here
                }
                else{
                    vector<int> bin_P = toBinary(P);
                    for (int i = 0; i < bin_P.size(); i++){
                        if(bin_P[i] == 1){
                            biggest_summand = (long long)pow(2.0, double(bin_P.size()-i-1));
                            break;
                        }
                    }
                    long long next_gcd = gcd(biggest_summand, Q);
                    biggest_summand /= next_gcd;
                    Q /= next_gcd;
                    long long result = (long long)log2((double)Q);
                    outputfile << "Case #" << numTest+1 << ": " << result << endl; //write in output here
                    cout << "Case #" << numTest+1 << ": " << result << endl; 
                }
            }
        }
        myfile.close();
        outputfile.close();
    }
}

