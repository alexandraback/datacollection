#include <iostream>
#include <fstream>

using namespace std;
long long p(int x){
    long long r = 1;
    for(int i=0;i<x;i++) r *= 2;
    return r;
}

int main()
{
    ifstream infile("B-large.in");
    ofstream outfile("B-large.out");

    int T, B;
    long long M;

    infile>>T;
    for(int t=1;t<=T;t++){
        infile>>B>>M;
        if(p(B-2)<M){
            outfile<<"Case #"<<t<<": "<<"IMPOSSIBLE"<<endl;
            continue;
        }
        //cout<<B<<M<<endl;
        int counter = 0;
        int matrix[B][B];
        for(int i=0;i<B;i++){
            for(int j=0;j<B;j++){
                matrix[i][j] = 0;
            }
        }
        for(long long i=1;i<=M;i*=2){
            counter++;
        }

        for(int i=0;i<counter;i++){
            for(int j=i+1;j<counter;j++){
                matrix[i][j] = 1;
            }
            matrix[i][B-1] = 1;
        }
        M -= p(counter-1);

        for(int i=counter-1;i>=1;i--){
            if(p(i-1)<=M){
                matrix[i][counter] = 1;
                matrix[counter][B-1] = 1;
                M -= p(i-1);
            }
        }

        outfile<<"Case #"<<t<<": "<<"POSSIBLE"<<endl;
        for(int i=0;i<B;i++){
            for(int j=0;j<B;j++){
                outfile<<matrix[i][j];
            }
            outfile<<endl;
        }
    }

    infile.close();
    outfile.close();
    return 0;
}
