#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
#include <map>

using namespace std;
string str[105];
int trans[27][27];
int in[27];
int out[27];
int self[27];
int valid(string s, map<char,int> cnt){
    int e = s[s.size() - 1] - 'a';
    int f = s[0] - 'a';
    map<char,int>c;
    for(unsigned j=1;j<s.size();j++)
        if(s[j] != s[j-1] && c.count(s[j]) > 0){
            return 0;
        }
        else
            c[s[j]]++;

    for(map<char,int>::iterator it = c.begin();it!=c.end();it++){
        char ch = it->first;
        int num = it->second;
        if(cnt[ch] > num && ch - 'a' != f && ch - 'a' != e){
            return 0;
        }
    }
    return 1;

}
long long cal(int p){
    long long ret = 1;
    while(p--){
       ret = ret * (p+1) % 1000000007;
    }
    return ret;
}
long long solve(int n){
    map<char,int>cnt;
    for(int i=0;i<n;i++){
        for(unsigned j=0;j<str[i].size();j++)
            cnt[str[i][j]]++;
    }
    for(int i=0;i<n;i++){
        int e = str[i][str[i].size() - 1] - 'a';
        int f = str[i][0] - 'a';
        if(!valid(str[i],cnt))
            return -1;
        trans[f][e]++;
        if(trans[f][e] >= 2 && f != e)
            return -1;
    }
    memset(in,-1,sizeof(in));
    memset(out,-1,sizeof(out));
    memset(self,0,sizeof(self));
    for(int i=0;i<27;i++)
        for(int j=0;j<27;j++)
            if(i!=j && trans[i][j]){
                if(in[j] == -1) in[j] = i;
                else { return -1;}

                if(out[i] == -1) out[i] = j;
                else { return -1;}
            }
            else if(trans[i][j] > 0 && i ==j)
                self[i] =trans[i][j];
    long long ans = 1;
    int part = 0;
    for(int i=0;i<27;i++)
        if(in[i] == -1){
            if(out[i] != -1){
                part++;
            }
            else if(self[i])
                part ++;
        }
   if(part == 0) return 0;
   ans = ans * cal(part) % 1000000007;
   for(int i=0;i<27;i++){
       ans = ans * cal(self[i]) % 1000000007;
   }
   return ans;
}
int main(){
    int T;
    cin >> T;
    int ca = 0;
    for(int ca = 0; ca < T; ca++){
        int n;
        cin >> n;
        for(int i=0;i<n;i++) cin >> str[i];
        memset(trans, 0, sizeof(trans));
        int ans = solve(n);
        if(ans == -1) ans = 0;

        printf("Case #%d: %d\n", 1+ca, ans);
    }
}
