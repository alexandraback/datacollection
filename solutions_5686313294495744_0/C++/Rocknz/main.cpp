#include<stdio.h>
#include<string.h>
#include<memory.h>
#include<vector>
using namespace std;
FILE *fo = fopen("/Users/JungRockJoon/Desktop/Rock/Algorithm/Codejam2016/Round1B/3/input.txt","r");
FILE *fp = fopen("/Users/JungRockJoon/Desktop/Rock/Algorithm/Codejam2016/Round1B/3/output.txt","w");
int n,fc,sc;
bool visited;
int in[1010][2],checked[2][1010];
int check[2020],cnt;
vector<int> vec[2020];
char input[1010][2][22],first[1010][22],second[1010][22];
void find(int now){
    if(now == fc+sc+1){
        visited = true;
        return;
    }else{
        int i;
        for(i=0;i<vec[now].size();i++){
            if(check[vec[now][i]] == 0){
                check[vec[now][i]] = 1;
                find(vec[now][i]);
                if(visited){
                    int next = vec[now][i];
                    if(next == fc+sc+1){
                        checked[1][now-fc-1] = 1;
                    }
                    vec[now][i] = vec[now][vec[now].size()-1];
                    vec[now].pop_back();
                    vec[next].push_back(now);
                    return;
                }
            }
        }
    }
}
int main(){
    int t,T;
    fscanf(fo,"%d",&T);
    for(t=1;t<=T;t++){
        memset(input,0,sizeof(input));
        memset(in,0,sizeof(in));
        memset(first,0,sizeof(first));
        memset(second,0,sizeof(second));
        vec->clear();
        fc = sc = 0;
        fscanf(fo,"%d",&n);
        int i,j,pos[2];
        for(i=0;i<n;i++){
            fscanf(fo,"%s %s",input[i][0],input[i][1]);
            bool check = true;
            for(j=0;j<fc;j++){
                if(strcmp(input[i][0],first[j]) == 0){
                    check = false;
                    pos[0] = j;
                    break;
                }
            }
            if(check){
                pos[0] = fc;
                strcpy(first[fc],input[i][0]);
                fc ++;
            }
            check = true;
            for(j=0;j<sc;j++){
                if(strcmp(input[i][1],second[j]) == 0){
                    check = false;
                    pos[1] = j;
                    break;
                }
            }
            if(check){
                pos[1] = sc;
                strcpy(second[sc],input[i][1]);
                sc ++;
            }
            in[i][0] = pos[0];
            in[i][1] = pos[1];
        }
        for(i=1;i<=fc;i++){
            vec[0].push_back(i);
        }
        for(j=fc+1;j<=fc+sc;j++){
            vec[j].push_back(fc+sc+1);
        }
        for(i=0;i<n;i++){
            vec[in[i][0]+1].push_back(in[i][1]+fc+1);
        }
        cnt = 0;
        memset(checked,0,sizeof(checked));
        while(true){
            bool isvisit = false;
            memset(check,0,sizeof(check));
            for(i=0;i<vec[0].size();i++) {
                check[0] = 1;
                check[vec[0][i]] = 1;
                visited = false;
                find(vec[0][i]);
                if(visited){
                    isvisit = true;
                    checked[0][vec[0][i]-1] = 1;
                    int next = vec[0][i];
                    vec[0][i] = vec[0][vec[0].size()-1];
                    vec[0].pop_back();
                    vec[next].push_back(0);
                    cnt ++;
                    i --;
                }
            }
            if(!isvisit)
                break;
        }
        int cnt2 = 0;
        if(t == 23){
            int g = 7;
            g = 3;
        }
        for(i=0;i<n;i++){
            if(checked[0][in[i][0]] == 1 &&
                    checked[1][in[i][1]] == 1){
                cnt2 ++;
            }
            checked[0][in[i][0]] = 1;
            checked[1][in[i][1]] = 1;
        }
        if(cnt2 < cnt) cnt2 = cnt;
        fprintf(fp,"Case #%d: %d\n",t,cnt2 - cnt);
    }
    return 0;
}