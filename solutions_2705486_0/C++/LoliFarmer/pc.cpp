#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
map<string,int> dic;
int len;
char inp[10000];
int dp[10000];
int mn;
void DFS(char *nowstr, int frm,int cnt, int LL){
    if( cnt >= mn ) return;
    if( dic.find(nowstr) != dic.end()){
        mn = cnt;
        return;
    }
    if( frm >= LL ) return ;
    DFS(nowstr,frm+1,cnt,LL);
    char tmpchar = nowstr[frm];
    for(char i='a';i<'z';i++){
        if(nowstr[frm] == i) continue;
        nowstr[frm] = i;
        DFS(nowstr, frm+5,cnt+1,LL);
    }
    nowstr[frm] = tmpchar;
}

int Find(const char* ss, int LL){
    if( dic.find(ss) != dic.end() ){
        return 0;
    }
    char str[13];
    strcpy(str,ss);
    mn = 10000;
    DFS(str,0,0,LL);
    return mn;
}

int GO(int pos){
    if(pos == -1){
        return 0;
    }
//    fprintf(stderr,"+> %d\n", pos);
    if( dp[pos] != -1 ){
        return dp[pos];
    }
    char str[12];
    dp[pos] = 10000;
    for(int L=1;L<=11 && pos-L>=-1;L++){
        int pre = GO(pos-L);
        for(int i=0;i<L;i++){
            str[i] = inp[pos-L+1+i];            
        }
        str[L] = '\0';
        int tmp = pre + Find(str, L);
        if( tmp < dp[pos] ){
            dp[pos] = tmp;
        }
    }
    return dp[pos];
}
int main(){
    FILE* fp = fopen("garbled_email_dictionary.txt","r");
    int cc = 0;
    while(fscanf(fp,"%s",inp)!=EOF){
        dic[inp] = 1;
    }    
    fprintf(stderr,"Done!\n");
    int T;
    scanf("%d",&T);
    for(int f = 1; f<=T ; f++){
        scanf("%s",inp);
        memset(dp,-1,sizeof(dp));
        printf("Case #%d: %d\n",f,GO(strlen(inp)-1));
    }
    return 0;
}
