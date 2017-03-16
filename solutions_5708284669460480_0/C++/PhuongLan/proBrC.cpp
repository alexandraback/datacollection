#include <bits/stdc++.h>

using namespace std;

int t;
int kq, k, l, s, cw;
char word[200], key[200];
int c[100];
int countw(){
    for(int len = 1; len<=l; len++){
            bool ok = true;
            for(int i = 0; i < l-len; i++)
                if (word[i]!=word[i+len]){
                    ok = false;
                    break;
                }
            if (ok) return ((s-l)/len+1);
        }
}
double solve(){
    for(int i = 0; i<=26; i++) c[i] = 0;
    for(int i = 0; i < k; i++){
        c[key[i]-'A'+1]++;
        //cout << i-'a'+1;
    }
    double tmp  = 1;
    for(int i = 0; i<l; i++){
        tmp = tmp * c[word[i]-'A'+1]/k;
       // cout << c[word[i]-'A'+1] << "\n";
        if (c[word[i]-'A'+1] == 0) cw = 0;
    }
    return tmp;
}
int main(){
    #ifndef ONLINE_JUDGE
     freopen("B-small-attempt1.in","r",stdin);
     freopen("output.out","w",stdout);
    #endif // ONLINE_JUDGE
   scanf("%d",&t);
    for(int iT = 1; iT <= t; iT++){
        scanf("%d%d%d",&k,&l,&s);
        cin >> key;
        cin >> word;
        cw = countw();
        double still = cw - solve()*cw;
        //cout << "cw : " << cw << "\n" ;
        if (still < 0 || cw == 0) still = 0;
        //cout << still;
        printf("Case #%d: %.7f\n",iT,still);
    }
    return 0;
}
