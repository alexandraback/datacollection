#include <iostream>
#include <fstream>

using namespace std;
int heights[2501];

int main()
{
    ifstream infile("B-large.in");
    ofstream outfile("B-large.out");

    int T,N,num;
    infile>>T;

    for(int t=1;t<=T;t++){
        infile>>N;
        for(int i=0;i<2501;i++) heights[i] = 0;
        for(int i=0;i<2*N-1;i++){
            for(int j=0;j<N;j++){
                infile>>num;
                heights[num]++;
            }
        }
        outfile<<"Case #"<<t<<":";
        for(int i=0;i<2501;i++){
            if(heights[i]>0 && (heights[i] & 1)==1){
                outfile<<" "<<i;
            }
        }
        outfile<<endl;
    }

    infile.close();
    outfile.close();
    return 0;
}
