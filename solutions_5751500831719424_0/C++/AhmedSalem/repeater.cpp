#include<bits/stdc++.h>
using namespace std ;

const int MAXN = 100;
const int oops = 1e8;

typedef pair<char,int> Token;
#define ch first
#define freq second

vector<Token> parts[MAXN+5];
string str[MAXN+5];
int n;

vector<Token> tokenize(string str){
    vector<Token> ret;
    ret.push_back(Token(str[0],1));
    for (int i=1;i<str.size();i++){
        if (str[i] == str[i-1])
            ret.back().freq++;
        else ret.push_back(Token(str[i],1));
    }
    return ret;
}
int solve(){
    int ret = 0;
    for (int j=0;j<parts[0].size();j++){
        int maxi = 0;
        for (int i=0;i<n;i++)
            maxi = max(maxi, parts[i][j].freq);
        int cur = oops;
        for (int howmany = 1; howmany <= maxi ; howmany++){
            int cost = 0;
            for (int i=0;i<n;i++)
                cost += abs(parts[i][j].freq - howmany);
            cur = min(cur, cost);
        }
        ret += cur;
    }
    return ret;
}


int main(){
    freopen("repeater.in","r",stdin);
    freopen("repeater.out","w",stdout);
    int c,c2;
    int tests;
    scanf("%d",&tests);
    for (int test=1;test<=tests;test++){
        printf("Case #%d: ",test);
        scanf("%d",&n);
        for (c=0;c<n;c++){
            char temp[MAXN+5];
            scanf("%s",temp);
            str[c] = temp;
            parts[c] = tokenize(temp);
        }
        bool fegla = false;
        for (c=1;c<n;c++)
            fegla |= parts[c].size() != parts[0].size();
        if (!fegla){
            for (int j=0;j<parts[0].size();j++)
                for (int i=0;i<n;i++)
                    fegla |= parts[i][j].ch != parts[0][j].ch;
        }
        
        if (fegla)
            printf("Fegla Won\n");
        else printf("%d\n",solve());
    }
}
