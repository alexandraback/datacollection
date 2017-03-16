#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;
#define forn(i,n) for(int i=0; i<(int)(n); i++)
#define pb push_back
#define eps 1e-10
int jug[256];

int main(){
    ifstream in("gcj.in");
    ofstream out("gcj.out");
    int t;
    in>>t;
    
    forn(k,t){
      out<<"Case #"<<k+1<<":";
      int n;
      in>>n;
      int sum=0;
      forn(i,n){
        in>>jug[i];
        sum+=jug[i];
        }
forn(i,n){
      double min = 0.0;
      double max = 1.0;
      while(max-min > 1e-9){
        double med = (max+min)/2;
        double cota = jug[i];
        cota = cota + (double)((double)med*(double)sum);
        double gano=0;
        forn(j,n){
          double aux = (double)(cota - (double)jug[j]) / (double)sum;
          if(aux>0.0+eps)gano+=aux;
          }
        if (gano < 1.0-eps)min=med;
        else max=med; 
        }
double res = max*100.0;
out<<' '<<setprecision(8)<<res;
}
out<<endl;
      }
    }
