#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define INF (1<<29)
#define min(x,y) (((x)<(y))?(x):(y))
#define max(x,y) (((x)>(y))?(x):(y))
#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define FOE(i,x,y) for(int i=(x);i<=(y);++i)
#define CLR(i) memset(i,0,sizeof(i))
#define ll long long
#define eps (1e-8)

char key[10],tar[10],tmp[10];

struct node{
    char s[10];

    node(){}
    node(char d[]){
        strcpy(s,d);
    }

    bool operator<(const node &d)const{
        return strcmp(s,d.s) < 0;
    }
};

map<node,int> q;

void f(char key[], int M, int N,int pos, char s[]){
    if (pos >= N){
        //printf("%s!\n",s);
        s[pos] = 0;
        node tmp = node(s);

        if (q.find(tmp) == q.end()) q[tmp] = 1;
        else ++q[tmp];
        
    }
    else{
        FOR(i,0,M){
            s[pos] = key[i];
            f(key,M,N,pos+1,s);
        }
    }
}

int check(int S, const char s[], int L, char tar[]){
    int ans = 0;
    FOR(i,0,S){
        bool ok = 1;
        FOR(j,0,L){
            if (i+j >= S){
                ok = 0;
                break;
            }
            if (s[i+j] != tar[j]){
                ok = 0;
                break;
            }
        }
        if (ok) ++ans;
    }
    return ans;
}

int main(){
    int T; scanf("%d",&T);
    FOE(t,1,T){
        q.clear();

        int K,L,S;
        scanf("%d%d%d",&K,&L,&S); gets(tmp);
        gets(key);
        gets(tar);

        f(key,K,S,0,tmp);

        int sum1,sum2,mm;
        sum1 = sum2 = 0;
        mm = 0;
        for (std::map<node,int>::iterator it=q.begin(); it!=q.end(); ++it){
            int cnt = check(S,(it->first).s,L,tar);
            mm = max(cnt,mm);
        }
        for (std::map<node,int>::iterator it=q.begin(); it!=q.end(); ++it){
            sum2 += it->second;
            int cnt = check(S,(it->first).s,L,tar);
            sum1 += (mm-cnt) * (it->second);
            //printf("%s %d %d\n",(it->first).s,mm-cnt, it->second);
        }
        //printf("%d %d %d!\n",mm,sum1,sum2);
        printf("Case #%d: %.10lf\n",t,(double)sum1/(double)sum2 + eps);
    }
    return 0;
}
