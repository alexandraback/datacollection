#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream in("s2.in"); ofstream out("s2.out");
    int T;
    int N,S,p;
    in>>T;
    int t[100];
    int dp[101][101];
    for (int i=0;i<T;i++){
        in>>N>>S>>p;
        for (int n=0;n<N;n++){
            in>>t[n];
        }
        for(int s=0;s<=S;s++) dp[0][s]=0;
        for (int n=1;n<=N;n++){
            if (t[n-1]>=3*p-2){
                for (int s=0;s<=S;s++){
                    dp[n][s]=dp[n-1][s]+1;
                    if (s>=1) dp[n][s]=max(dp[n][s],dp[n][s-1]);
                }
            }
            else if (t[n-1]>=max(3*p-4,p)){
                dp[n][0] = dp[n-1][0];
                for (int s=1;s<=S;s++){
                    dp[n][s]=max(dp[n-1][s-1]+1,dp[n-1][s]);
                    dp[n][s]=max(dp[n][s],dp[n][s-1]);
                }
            }
            else{
                for (int s=0;s<=S;s++){
                    dp[n][s]=dp[n-1][s];
                    if (s>=1) dp[n][s]=max(dp[n][s],dp[n][s-1]);
                }
            }
        }
        int m=-1;
        for (int s=0;s<=S;s++){
            m=max(m,dp[N][s]);
        }
        out<<"Case #"<<i+1<<": "<<m<<"\n";
    }
}
