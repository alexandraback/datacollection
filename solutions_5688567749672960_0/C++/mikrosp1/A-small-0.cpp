#include<fstream>
#include<iostream>
#include<vector>

using namespace std;
int REVERSE(int n){
    int rev=0;
       while (n != 0)
   {
      rev = rev * 10;
      rev = rev + n%10;
      n       = n/10;
   }
   return rev;
}
int main(){
    int t,n;
    ifstream fin("A-small-0.in");
    ofstream fout("A-small-0.out");
    int dp[1000002];
    dp[0]=0;
    for(int i=1;i<=1000001;i++){
        int rev=0;
        n=i;
          while (n != 0)
   {
      rev = rev * 10;
      rev = rev + n%10;
      n       = n/10;
   }
   //cout<<i<<" "<<rev<<endl;
   if(rev>=i)dp[rev]=1000001;
   if(REVERSE(rev)!=i)rev=i-1;
        dp[i]=min(dp[i-1],dp[rev])+1;
   //       cout<<dp[i]<<" "<<rev<<" "<<i<<" "<<dp[i-1]<<endl;
    }



    fin>>t;
    for(int e=0;e<t;e++){
        fin>>n;
        fout<<"Case #"<<e+1<<": "<<dp[n]<<'\n';
    }
    fin.close();
    fout.close();
    return 0;
}
