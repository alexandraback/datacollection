#include <fstream>
#include <cstdio>
#include <set>
using namespace std;

set<int> s;
void digit(int n){
    while(n){
        s.insert(n%10);
        n/=10;
    }
    return ;
}
int main(){
    ofstream fout;
    fout.open("outout.out");
    int T,N,copyN,mult;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        scanf("%d",&N);
        if(N==0){
            fout<<"Case #"<<i<<": INSOMNIA\n";
            continue;
        }
        else{
            mult=1;
            while(1){
                copyN=mult*N;
                digit(copyN);
                if(s.size()==10){
                    fout<<"Case #"<<i<<": "<<mult*N<<"\n";
                    break;
                }
                mult++;
            }
        }
        s.clear();
    }
}