#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream infile("B-small-attempt0.in");
    ofstream outfile("B-small-attempt0.out");

    int T,D,result,min_result,maxp,tmp;
    int P[1000] = {0};

    infile>>T;
    for(int i=1;i<=T;i++){
        infile>>D;
        min_result = 0;
        for(int j=0;j<D;j++)
            infile>>P[j];

        maxp = P[0];
        for(int j=1;j<D;j++)
            if(P[j]>maxp) maxp = P[j];

        for(int floor=1;floor<=maxp;floor++){
            result = floor;
            for(int k=0;k<D;k++){
                tmp = P[k];
                while(tmp>floor){
                    tmp -= floor;
                    result++;
                }
            }
            if(result<min_result||min_result==0) min_result = result;
        }

        outfile<<"Case #"<<i<<": "<<min_result<<endl;
    }

    return 0;
}
