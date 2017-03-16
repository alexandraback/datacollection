#include<stdio.h>
#include<math.h>
#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

        int n;
        string str[105];
        int order[105],used[105],passed[30];
        int countans;

void comb(int depth){
    if(depth+1>=n){
        for(int i=0;i<n;i++){
            if(!used[i]){
                order[depth] = i;
            }
        }
        for(int i=0;i<26;i++){
            passed[i]=0;
        }
        char lastc = 0;
        for(int i=0;i<n;i++){
            for(int j=0;str[order[i]][j];j++){
                //printf("%c",str[order[i]][j]);
                if(str[order[i]][j] != lastc){
                    if(passed[str[order[i]][j]-'a']){
                        //printf("+\n");
                        return;
                    }else{
                        passed[str[order[i]][j]-'a'] ++;
                    }
                }
                lastc = str[order[i]][j];
            }
        }
        countans++;
        countans = countans%1000000007;
        //printf("\n");
        return;
    }
    for(int i=0;i<n;i++){
        if(!used[i]){
            order[depth] = i;
            used[i] = 1;
            comb(depth+1);
            used[i] = 0;
        }
    }
}

int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int t;
    cin >> t;
    for(int zz=1;zz<=t;zz++){
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> str[i];
        }

        countans=0;
        comb(0);


        printf("Case #%d: %d\n",zz,countans);
    }

    return 0;
}
