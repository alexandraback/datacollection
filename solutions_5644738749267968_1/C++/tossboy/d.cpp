#include <iostream>
#include <algorithm>
using namespace std;

#define N 1005
int n;
double a[N], b[N];
double *(p[2])={a,b};

int main(int argc, const char * argv[])
{
    int nCase; cin>>nCase;
    for(int ca=1; ca<=nCase; ca++){
        cin>>n;
        for(int i=0; i<2; i++){
            for(int j=0; j<n; j++)
                cin>>p[i][j];
            sort(p[i], p[i]+n);
        }
        
        cout<<"Case #"<<ca<<":";
        int res;
        double *la, *lb, *ra, *rb;
        res=0; la=a; ra=a+n-1; lb=b; rb=b+n-1;
        while(la<=ra && lb<=rb){
            if(*la<*lb)
                la++, rb--;
            else{
                res++;
                la++, lb++;
            }
        }
        cout<<" "<<res<<" ";
        
        res=0; la=a; ra=a+n-1; lb=b; rb=b+n-1;
        while(la<=ra && lb<=rb){
            if(*ra>*rb){
                res++;
                ra--;
            }
            else{
                ra--,rb--;
            }
        }
        cout<<res<<endl;
        
    
    }
    return 0;
}

