#include <iostream>
#define TASK "C"
#define Small "-small-attempt"
#define NUM "0"
#include <string>
#include <map>
#include <set>

using namespace std;

#define N 200

int test;

int f[1500000];


long long a[510];
int n;
int Ans_a,Ans_b;
map<long long,int> H;

void readinput(){
    scanf("%i",&n);
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    H.clear();       
}

void solve(){
    Ans_a = 0;
    Ans_b = 0;
    for (int i=1;i<(1<<n);i++){
        int f = i;
        long long sum = 0;
        for (int j=0;j<n;j++){
            if (f&1){
                sum = sum + a[j];                       
            }    
            f = f/2;
        }
        if (H.find(sum)==H.end()){
            H[sum] = i;    
        }else{
            int aa = i;
            int bb = H[sum];
            if (!(aa&bb)){
                Ans_a = i;
                Ans_b = H[sum];
            }
        }    
    }
    
}

void writeoutput(int t){
    printf("Case #%i:\n",t+1);
    if (!Ans_a || !Ans_b){
        printf("Impossible\n");        
    }else{   
        long long sA = 0;         
        long long sB = 0;         
        for (int j=0;j<n;j++){
            if (Ans_a&1){
                cout<<a[j]<<" ";
                sA=sA+a[j];
            }    
            Ans_a = Ans_a/2;
        }
        printf("\n");
        for (int j=0;j<n;j++){
            if (Ans_b&1){
                cout<<a[j]<<" ";
                sB=sB+a[j];
            }    
            Ans_b = Ans_b/2;
        }
        printf("\n");
        //cout<<sA<<" = "<<sB<<endl;
    }
    
}

int main(void){
    //freopen("input.txt","r",stdin);    
    freopen(TASK""Small""NUM".in","r",stdin);
    //freopen(TASK"-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%i\n",&test);
    for (int i=0;i<test;i++){
        readinput();
        solve();
        writeoutput(i);
    }
    
    return 0;    
}
