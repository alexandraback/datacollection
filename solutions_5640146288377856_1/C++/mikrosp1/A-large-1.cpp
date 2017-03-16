#include<fstream>
#include<cmath>
using namespace std;

int main(){
    long long int r,c,w;
    long long int t;
    ifstream fin("A-large-1.in");
    ofstream fout("A-large-1.out");
    fin>>t;
    for(int e=0;e<t;e++){
        fin>>r>>c>>w;
        long long int ans;
        //ans=r*ceil((double)(c-w)/w)+w;
        long long int f=c-w;
        long long int posa=1;
        while(f>0){
        f-=w;
        posa++;
        }
        posa*=r;
        ans=posa+w-1;
        fout<<"Case #"<<e+1<<": "<<ans<<'\n';
    }

    fin.close();
    fout.close();
    return 0;
}
