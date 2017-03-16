#include <iostream>
#define TASK "A"
#define Small "-small-attempt"
#define NUM "2"
#include <string>
#include <map>
#include <set>
#include <cmath>

using namespace std;

#define N 200

int test;

int n;
int a[300];
double f[300];

double s;

void readinput(){
    scanf("%i",&n);
    s = 0;
    for (int i=0;i<n;i++){
        scanf("%i",&a[i]);        
        s=s+a[i];
    }       
}

void solve(){
    int q = 0;
    for (int i=0;i<n;i++){
        if (a[i]>a[q]) q=i;    
    }
    f[q]=(1.0-((n+0.0)*a[q]-s)/s)/n;
    //if (f[q]<0) f[q]=0;
    for (int i=0;i<n;i++){
        if (i!=q)
            f[i]=(a[q]-a[i])/s+f[q];    
    }
    for (int i=0;i<n;i++){
        if (f[i]<0){
            int cnt = 0;
            for (int j=0;j<n;j++){
                if (f[j]>0) cnt++;    
            }
            double delta = f[i]/cnt;
            for (int j=0;j<n;j++){
                if (f[j]>0){
                    f[j]=f[j]+delta;    
                }    
            }
            f[i]=0;    
        }    
    }    
    
}

void writeoutput(int t){
    printf("Case #%i:",t+1);            
    //printf("\n");
    for (int i=0;i<n;i++){
        printf(" %.5lf",(f[i])*100);    
    }
    printf("\n");
}

int main(void){
    //freopen("input.txt","r",stdin);    
    //freopen(TASK""Small""NUM".in","r",stdin);
    freopen(TASK"-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%i\n",&test);
    for (int i=0;i<test;i++){
        readinput();
        solve();
        writeoutput(i);
    }
    
    return 0;    
}
