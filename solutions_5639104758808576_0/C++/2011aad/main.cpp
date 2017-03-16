#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream infile("A-small-attempt0.in");
    ofstream outfile("A-small-attempt0.out");
    int T,S,result,sum;
    string str;
    infile>>T;
    for(int i=1;i<=T;i++){
        infile>>S>>str;
        sum = 0;
        result = 0;
        for(int j=0;j<S;j++){
            sum += (str[j]-'0');
            if(sum<(j+1)){
                result += (j+1-sum);
                sum = j+1;
            }
        }

        outfile<<"Case #"<<i<<": "<<result<<endl;
    }
    return 0;
}
