#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;


int main() {
    freopen("B-small-attempt3.in","r",stdin);
    freopen("output2.txt","w",stdout);
    int d,t,max,min;
    int p[1001];
   // int dp[1001][1001];
    string str;
    scanf ("%i",&t);
    /*for (int i=1;i<=500;i++) {
        dp[i][i]=0;
        for (int j=i+1;j<=i*2;j++) {
            dp[i][j]=1;
        }
        for (int j=i*2+1;j<=1000;j++) {
            dp[i][j]=37235;
            for (int k=i;k<=j-i;k++)
                if (dp[i][j]>dp[i][k]+dp[i][j-k]+1) dp[i][j]=dp[i][k]+dp[i][j-k]+1;
        }
    }*/
    for (int i=0;i<t;i++) {
        cin >> d;
        max=0;
        for (int j=0;j<d;j++) {
            cin >> p[j];
            if (max<p[j]) max=p[j];
        }
        min=37235;
        for (int j=1;j<=max;j++) {
            int tot =0;
            for (int k=0;k<d;k++)
                tot+=(p[k]+(j-1))/j-1;
            if (tot+j<min) min=tot+j;
        }
        cout << "Case #"<<i+1<<": "<< min<<endl;
        
    }
    
    return 0;
}