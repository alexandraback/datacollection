#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
    int T,c=1;
    cin>>T;
    while(T--){
        int A,B;
        cin>>A>>B;
        vector<double> p(A);
        vector<double> cp(A);
        for(int i=0;i<A;i++){
            cin>>p[i];
            if(i==0)
                cp[i]=p[i];
            else cp[i]=p[i]*cp[i-1];
        }
        double m;
        for(int k=0;k<=A;k++){
            double prod = A==k ? 1.0 : cp[A-k-1];
            double tmin = (double)(B-A+1+2*k) + (double)(B+1)*(1 - prod);
            if(k==0 || tmin < m)
                m = tmin;
        }
        if(1+B+1 < m)
            m=B+1+1;
        printf("Case #%d: %.6f\n",c,m);
        c++;
    }
    return 0;
}
