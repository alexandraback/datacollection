#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

int T,K,L,S,cnt[30],pi[102],to[102][30],tot;
char s[200];
long double dp[102][102][102];

int main(){
    ifstream fin("input.in");
    ofstream fout("output.txt");
    fin >> T;

    int i,k,j,p,x,t; char c;
    for (k=1; k<=T; k++){
        cout << k << "\n";
        fin >> K >> L >> S;
        fout << "Case #" << k << ": ";

        memset(cnt,0,sizeof(cnt));
        for (i=1; i<=K; i++){
            fin >> c;
            cnt[c-'A']++;
        }

        fin >> (s+1);
        memset(to,0,sizeof(to));
        pi[1]=0;
        int q=0;
        for (i=2; i<=L; i++){
            while (s[i]!=s[q+1] && q)
                q=pi[q];

            if (s[i]==s[q+1])
                q++;
            pi[i]=q;
        }

        for (i=0; i<=L; i++)
            for (j=0; j<26; j++){
                q=i;
                while (q && s[q+1]-'A'!=j)
                    q=pi[q];

                if (s[q+1]-'A'==j)
                    q++;
                to[i][j]=q;
            }

        tot=1;
        memset(dp,0,sizeof(dp));
        dp[0][0][0]=1;

        int MAX=(S-pi[L])/(L-pi[L]);
        if (S<L){
            fout << fixed << setprecision(10) << 0 << "\n";
            continue;
        }

        for (i=1; i<=L; i++)
            if (cnt[s[i]-'A']==0){
                fout <<fixed << setprecision(10) <<  0 << "\n";
                break;
            }

        if (i<=L) continue;

        for (i=1; i<=S; i++)
            for (j=0; j<=L; j++)
                for (p=0; p<=MAX; p++){
                    if (j==L){
                        if (p>0) dp[i][j][p]=1.0*cnt[s[L]-'A']/K*dp[i-1][j-1][p-1];
                        for (x=0; x<26; x++)
                            if (to[L][x]==L)
                                dp[i][j][p]+=1.0*cnt[x]/K*dp[i-1][L][p-1];
                    }
                    else{
                        for (t=0; t<=L; t++)
                            for (x=0; x<26; x++)
                                if (to[t][x]==j)
                                    dp[i][j][p]+=1.0*cnt[x]/K*dp[i-1][t][p];
                    }
                }

        long double aux=0,res=0;
        for (i=1; i<=MAX; i++){
            aux=0;
            for (j=0; j<=L; j++)
                aux+=dp[S][j][i];
            res+=aux*i;
        }

        fout << fixed << setprecision(10) << MAX-res << "\n";

    }


    return 0;
}
