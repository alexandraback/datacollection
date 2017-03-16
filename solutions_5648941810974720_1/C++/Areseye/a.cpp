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
void debug_char_stat(){
    string single = "ZXWUG";
    for(char ch = 'A';ch<='Z';ch++){
        printf("ch = %c:",ch);
        for(int i = 0;i<=9;i++){
            if(i==0||i==6||i==2||i==4||i==8)continue;
            bool have_ch = false;
            for(auto dig_ch:DIG[i])if(dig_ch==ch){
                have_ch = true;
                break;
            }
            if(have_ch){
                cout<<DIG[i]<<" ,";
            }
        }
        cout<<endl;
    }
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
    //stage 1
    while(1){
        if(curcn['Z'-'A']>0){
            int z_cnt = curcn['Z'-'A'];
            can_dig(curcn,0);
            ret.push_back(0);
        }else if(curcn['X'-'A']>0){
            int z_cnt = curcn['X'-'A'];
            can_dig(curcn,6);
            ret.push_back(6);
        }else if(curcn['W'-'A']>0){
            int z_cnt = curcn['W'-'A'];
            can_dig(curcn,2);
            ret.push_back(2);
        }else if(curcn['U'-'A']>0){
            int z_cnt = curcn['U'-'A'];
            can_dig(curcn,4);
            ret.push_back(4);
        }else if(curcn['G'-'A']>0){
            int z_cnt = curcn['G'-'A'];
            can_dig(curcn,8);
            ret.push_back(8);
        }else break;
    }
    //stage 2
    while(1){
        if(curcn['F'-'A']>0){
            int z_cnt = curcn['F'-'A'];
            can_dig(curcn,5);
            ret.push_back(5);
        }else if(curcn['H'-'A']>0){
            int z_cnt = curcn['H'-'A'];
            can_dig(curcn,3);
            ret.push_back(3);
        }else if(curcn['O'-'A']>0){
            int z_cnt = curcn['O'-'A'];
            can_dig(curcn,1);
            ret.push_back(1);
        }else if(curcn['S'-'A']>0){
            int z_cnt = curcn['S'-'A'];
            can_dig(curcn,7);
            ret.push_back(7);
        }else break;
    }
    // for 9
    while(1){
        if(curcn['N'-'A']>0){
            int z_cnt = curcn['N'-'A'];
            can_dig(curcn,9);
            ret.push_back(9);
        }else break;
    }

    return 0;
}
int main(){
    freopen("a.in","r",stdin);
    freopen("a_large.out","w",stdout);
    //debug_char_stat();
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
