#include <iostream>
#include <fstream>
#include <iomanip>

#include <math.h>

#include <string>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <bitset>

#include <algorithm>

#include <utility>

using namespace std;

int main()
{
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    int t,k;
    fin >> t;   
    __int64 n,m,s,t1,t2;
    for (int j=1; j<=t; j++){
          s=0;
          fin >> n;
          while (n){
                k=0;
                m=n;
                while (m){
                      k++;
                      m/=10;
                }
                t1=t2=1;
                m=n/10;
                m*=10;
                if (n-m==0){
                   m-=9;
                   t1+=9;
                }
                else
                     m=n;  
                for (int i=0; i<k/2; i++){
                    t1+=t2*(m%10);
                    m/=10;
                    t2*=10;
                }
                if (k%2==0)
                   t2/=10;
                for (int i=k/2; i<k; i++){
                    t1+=t2*(m%10);
                    m/=10;
                    t2/=10;
                }
                m=0;
                t2=1;
                for (int i=0; i<k-1; i++){
                    m+=9*t2;
                    t2*=10;
                }
                s+=min(n-m,t1);
                n=m;
          }
          fout << "Case #" << j << ": " << s << endl;          
    }           
    fin.close();
    fout.close();
    return 0;
}
