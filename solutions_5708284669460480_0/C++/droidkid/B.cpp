/*
 * B.cpp
 * 
 * 
 * 
 */

#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int F[100004];
double dp[105][105][105];


void buildPrefix(string s){
    F[0] = 0;
    F[1] = 0;
    int n = s.size();
    for(int i=2; i<=n; i++){
        int j = F[i-1];
        char c = s[i-1];
        while(true){
            if(c==s[j]){
                F[i] = j+1;
                break;
            }
            if(j==0){
                F[i] = 0;
                break;
            }
            j = F[j];
        }
    }
}
int k,l,s;
string keyb, word;


void solve(int pos, int numWord, int upto){

//    cout<<pos<<" "<<numWord<<" "<<upto<<": "<<dp[pos][numWord][upto]<<endl;

    for(int i=0; i<k; i++){
        char K = keyb[i];
        int j = upto;
        while(true){
            if( K == word[j] ){
                if(j==l-1){
                    dp[pos+1][numWord+1][F[l]] += (1.0/k)*dp[pos][numWord][upto];
                }
                else{
                    dp[pos+1][numWord][j+1] += (1.0/k)*dp[pos][numWord][upto];
                }
                break;
            }
            if(j==0){
                dp[pos+1][numWord][0] += (1.0/k)*dp[pos][numWord][upto];
                break;
            }
            j = F[j];
        }
    }

}


int check(string s1, string s2){
    int c1[26];
    int c2[26];
    for(int i=0; i<26; i++){
        c1[i] = 0;
        c2[i] = 0;
    }
    for(int i=0; i<s1.size(); i++){
        c1[s1[i]-'A']++;
    }
    for(int j=0; j<s2.size(); j++){
        c2[s2[j]-'A']++;
    }

    for(int i=0; i<26; i++){
        if(c1[i]!=0 && c2[i]==0)return 0;
    }
    return 1;
}

int main(){
    int t;
    cin>>t;
    for(int T=1; T<=t; T++){
        cin>>k>>l>>s;
        cin>>keyb>>word;
        buildPrefix(word);
 
        int maxBanana = 0;
        if(s >= l && check(word, keyb)){
            int temp = s-l;
            int perWord = l-F[l];
            maxBanana = 1 + (temp/perWord);
        }
//        cout<<"max: "<<maxBanana<<endl;

        for(int i=0; i<103; i++){
            for(int j=0; j<103; j++){
                for(int k=0; k<103; k++){
                    dp[i][j][k] = 0;
                }
            }
        }

        double ans = 0;
        dp[0][0][0] = 1.0;
        for(int i=0; i<=s; i++){
            for(int j=0; j<=s; j++){
                for(int k=0; k<l; k++){
                    solve(i,j,k);
                }
            }
        }
        for(int i=0; i<=s; i++){
            for(int j=0; j<l; j++){
                ans = ans + (i)*(dp[s][i][j]);
            }   
        }
        ans = maxBanana- ans;
        printf("Case #%d: %.7lf\n",T, ans);
    }
}

