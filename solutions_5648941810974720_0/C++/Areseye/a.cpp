#include"cstdio"
#include"iostream"
#include"map"
#include"cmath"
#include"string"
#include"cstring"
#include"stdlib.h"
#include"vector"
#include"algorithm"
#include"utility"
#include"set"
#include"unordered_set"
#include"unordered_map"
#include"ctime"


using namespace std;

string DIG[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
bool can_dig(int*curcn,int dig){
    string &curdig = DIG[dig];
    int usech[26];
    for(int i = 0;i<26;i++)usech[i]=0;
    for(auto ch:curdig)usech[ch-'A']++;
    for(auto ch:curdig)if(curcn[ch-'A']<usech[ch-'A'])return false;
    for(auto ch:curdig)curcn[ch-'A']--;
    return true;
}
int lendig(int dig){
    return DIG[dig].size();
}
bool put_back_dig(int*curcn,int dig){
    string &curdig = DIG[dig];
    for(auto ch:curdig)curcn[ch-'A']++;
    return true;
}
int dfs(vector<int>&ret,int charleft,int *curcn){
    if(charleft==0){
        return 1;
    }
    for(int i = 0;i<=9;i++){
        if(can_dig(curcn,i)){
            ret.push_back(i);
            //printf("N_left = %d,dig=%d\n",charleft,i);
            int mark = dfs(ret,charleft - lendig(i),curcn);
            if(mark==1)return 1;
            ret.pop_back();
            put_back_dig(curcn,i);
        }
    }
    return 0;
}
int main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int T;
    scanf("%d",&T);
    int casenum(0);
    while(++casenum<=T){
        string phonestr;
        cin>>phonestr;
        //solve
        int charcnt[26];
        memset(charcnt,0,sizeof(charcnt));
        for(auto ch:phonestr){
            charcnt[ch-'A']++;
        }
        int N(phonestr.size());
        vector<int> ret;
        int cp_charnum[26];
        for(int i = 0;i<26;i++)cp_charnum[i] = charcnt[i];
        dfs(ret,N,cp_charnum);
        //output
        sort(ret.begin(),ret.end());
        printf("Case #%d: ",casenum);
        for(auto val:ret)printf("%d",val);
        puts("");
    }
}
