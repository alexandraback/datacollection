#include <iostream>
#include <fstream>
using namespace std;

int iets(int i,int j,int b){
    int ans=(j-i+1+b)%b;
    if(ans==0)ans=b;
    return ans;
}

int main (){
    ifstream in("Cs.in");
    ofstream out("csoutput.txt");
    int testcases;
    in >> testcases;
    int testcasses = testcases;
    while (testcasses -->0){
        int a,b,c,k;
        in>>a>>b>>c>>k;
        out<<"Case #"<<testcases-testcasses<<": "<<a*b*min(c,k)<<endl;
        for(int h=0;h<a;h++){
            for(int i=0;i<b; i++){
                for(int j=0;j<min(c,k);j++){
                    int ans=(iets(h,i,c)+j)%c;
                    if(ans==0)ans=c;
                    out<<h+1<<' '<<i+1<<' '<<ans<<endl;
                }
            }
        }
    }
    return 0;
}
