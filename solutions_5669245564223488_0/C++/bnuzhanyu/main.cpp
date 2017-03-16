#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cmath>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <map>
#include <string>
using namespace std;


const int MOD = 1000000007;
const int MAXN = 110;
struct STR{
    bool isAllSame;
    char st, ed;
    string str;
    bool exist[26];

    void input(){
        cin>>str;
        st = str[0];
        ed = str[str.size() - 1];
        isAllSame = true;
    }

    bool judge(){
        memset(exist, 0, sizeof(exist));
        int x = str[0] - 'a';
        exist[x] = true;
        for(int i=1; i<str.size(); i++){
            while(i<str.size() && str[i] == str[i-1]) i++;
            if(i == str.size()) break;
            x = str[i] - 'a';
            if(exist[x]) return false;
            exist[x] = true;
            isAllSame = false;
        }
        return true;
    }
};


struct Node{
    long long num;
    char st, ed;
};

long long fact[MAXN];
void init(){
    fact[0] = 1;
    for(int i=1; i<MAXN; i++){
        fact[i] = fact[i-1] * i;
        fact[i] %= MOD;
    }
}


vector<vector<int> > Graph;
vector<Node> vec;

void findAll(vector<STR>& strvec, char c)
{
    int ans = 0;
    int n = strvec.size();
    for(int i=0; i<n; i++){
        if(strvec[i].st == c && strvec[i].isAllSame){
            ans++;
        }
    }
    if(ans != 0){
        Node node;
        node.st = node.ed = c;
        node.num = fact[ans];
        vec.push_back(node);
    }
}


bool Judge(vector<STR>& strvec){

    int n = strvec.size();
    for(int i=0; i<n; i++)
        if(!strvec[i].judge()) return false;
    for(char c='a'; c<='z'; c++)
        findAll(strvec, c);

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){

            if(strvec[i].st == strvec[j].st && !strvec[i].isAllSame && !strvec[j].isAllSame)
                return false;
            if(strvec[i].ed == strvec[j].ed && !strvec[i].isAllSame && !strvec[j].isAllSame)
                return false;

            for(int k = 0; k < 26; k++){
                if(strvec[i].exist[k] && k!=strvec[i].st-'a' && k!= strvec[i].ed-'a' && strvec[j].exist[k])
                    return false;
                if(strvec[j].exist[k] && k!=strvec[j].st-'a' && k!= strvec[j].ed-'a' && strvec[i].exist[k])
                    return false;
            }
        }
    }
    return true;
}



int in[MAXN];
int out[MAXN];
long long curNum[MAXN];
void BuildGraph(vector<STR>& strvec)
{
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    Graph.clear();
    int n = strvec.size();
    for(int i=0; i<n; i++){
        if(strvec[i].isAllSame) continue;
        else {
            Node node;
            node.st = strvec[i].st;
            node.ed = strvec[i].ed;
            node.num = 1;
            vec.push_back(node);
        }
    }
    n = vec.size();

    for(int i=0; i<n; i++)
        curNum[i] = vec[i].num;
    Graph.resize(n);
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(vec[i].st == vec[j].ed)
                Graph[j].push_back(i), in[i]++, out[j]++;
            if(vec[i].ed == vec[j].st)
                Graph[i].push_back(j), in[j]++, out[i]++;
        }
    }
}



long long calc(){
    long long ans = 1;
    int n = Graph.size();
    queue<int> q;
    int inq = 0;
    for(int i=0; i<n; i++){
        if(in[i] == 0) q.push(i), inq++;
    }
    ans = fact[inq];

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0 ; i < Graph[u].size(); i++){
            int v = Graph[u][i];
            if(in[v] == 0) continue;
            in[v]--;
            if(in[v] == 0) {
                q.push(v); inq++;
                curNum[v] *= curNum[u];
                curNum[v] %= MOD;
                curNum[u] = 1;
            }
        }
    }
    if(inq < n) return 0;
    else{
        for(int i=0; i<n; i++){
            ans = ans * curNum[i];
            ans %= MOD;
        }
    }
    return ans;
}

void ReadAndSolve(){
    int T;
    init();
    scanf("%d", &T);
    STR tmp;
    int N;
    for(int ca=1; ca<=T; ca++){
        scanf("%d", &N);
        vec.clear();
        vector<STR> vecstr;
        for(int i=0; i<N; i++){
            tmp.input();
            vecstr.push_back(tmp);
        }
        printf("Case #%d: ", ca);
        if(!Judge(vecstr)) printf("0\n");
        else{
            BuildGraph(vecstr);
            long long ans  = calc();
            printf("%lld\n", ans);
        }

    }
}


void UseStdIO(){
    ReadAndSolve();
}

void UseFileIO(){
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    ReadAndSolve();
}


int main()
{
    bool toSubmit = 1;
    if(!toSubmit) UseStdIO();
    else UseFileIO();
    return 0;
}
