#include<stdio.h>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int N;
int M;
map<string, int> idx[2];
int topics[1000][2];
int check[2000][2000], h[2000], v[2000];

void process(){
    int i,j;
    for(i=0;i<M;i++){
        for(j=0;j<M;j++) check[i][j]=0;
        h[i]=0; v[i]=0;
    }
    for(i=0;i<N;i++){
        check[topics[i][0]][topics[i][1]]++;
        h[topics[i][1]]++; v[topics[i][0]]++;
    }
    int cnt;
    for(cnt=0;;cnt++){
        int f = -1;
        for(i=0;i<N;i++){
            if(h[topics[i][1]] > 1 && v[topics[i][0]] > 1){
                f = i;
                break;
            }
        }
        if(f == -1) break;
        h[topics[f][1]]--; v[topics[f][0]]--;
    }
    printf("%d\n",cnt);
}

int f(int t){
    char temp[21];
    scanf("%s",temp);
    string temp_str(temp);
    if(idx[t].find(temp_str) == idx[t].end()){
        idx[t][temp_str] = M++;
    }
    return idx[t][temp_str];
}

int main(){
    int T, t, i;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%d",&N);
        M = 0; idx[0].clear(); idx[1].clear();
        for(i=0;i<N;i++){
            topics[i][0] = f(0);
            topics[i][1] = f(1);
        }
        printf("Case #%d: ", t);
        process();
    }
    return 0;
}
