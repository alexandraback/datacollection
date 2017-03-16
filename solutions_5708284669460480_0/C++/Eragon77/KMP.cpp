#include <iostream>
#include <vector>
#include <iomanip>

#define mod 1000000007

using namespace std;
typedef long double ld;

ld alpha[26];
ld dp[111][111];
int t, l, k, s;
string word, keys;
int dfa[30][111];
ld res;
bool pos;

int main(){
    cin>>t;
    cout<<fixed<<setprecision(10);
    for(int i=0; i<t; ++i){
        cin>>k>>l>>s;
        cin>>keys>>word;
        int x=0;
        for(int j=0; j<30; ++j){
            dfa[j][0]=0;
        }
        dfa[word[0]-'A'][0]=1;
        for(int k=1; k<word.size(); ++k){
            for(int j=0; j<30; ++j){
                dfa[j][k]=dfa[j][x];
            }
            dfa[word[k]-'A'][k]=k+1;
            x=dfa[word[k]-'A'][x];
        }
        int maxj=0;
        for(int j=0; j<30; ++j){
            dfa[j][word.size()]=dfa[j][x];
            maxj=max(maxj,dfa[j][x]);
        }
        for(int j=0; j<26; ++j){
            alpha[j]=0;
        }
        for(int j=0; j<keys.size(); ++j){
            alpha[keys[j]-'A']+=((ld)1)/keys.size();
        }
        //cout<<endl<<dfa[0][0]<<endl<<dfa[1][0]<<endl;
        pos=true;
        for(int j=0; j<word.size(); ++j){
            if(alpha[word[j]-'A']<0.001){
                pos=false;
            }
        }
        if(word.size()<=s && pos){
            res=1+(s-word.size())/(word.size()+1-maxj);
        }
        else{
            res=0;
        }
        for(int j=0; j<s+1; ++j){
            for(int k=0; k<word.size()+1; ++k){
                dp[j][k]=0;
            }
        }
        //cout<<res;
        dp[0][0]=1;
        for(int j=0; j<s; ++j){
            for(int k=0; k<word.size()+1; ++k){
                for(int m=0; m<26; ++m){
                    dp[j+1][dfa[m][k]]+=dp[j][k]*alpha[m];
                }
            }
            //cout<<dp[j+1][word.size()]<<endl;
            res-=dp[j+1][word.size()];
        }
        cout<<"Case #"<<i+1<<": "<<res<<"\n";
    }
}
