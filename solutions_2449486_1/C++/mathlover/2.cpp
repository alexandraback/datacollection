#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<map>
#include<cstring>
#include<set>
#include<cmath>

using namespace std;
int N,M;
int grass[101][101];
int min_mask[101][101];
int solved[101][101];
int gao()
{
    memset(solved,0,sizeof(solved));
    while(1){
        int numsolve = 0;
        memset(min_mask,0,sizeof(min_mask));
        int _min = 100;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(solved[i][j]==0){
                    if(_min> grass[i][j])
                        _min = grass[i][j];
                }
                else numsolve++;
            }
        } 
        if(_min == 100) return 1;
        //cout << _min << " number solve " << numsolve << endl;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(solved[i][j]==0){
                    if(_min == grass[i][j])
                        min_mask[i][j]=1;
                }
            }
        }
        int found = 0;
        for(int i=0;i<N;i++){
            int line = 1;
            int ccc = 0;
            for(int j=0;j<M;j++){
                if(solved[i][j]==0 && min_mask[i][j] == 0){
                    line = 0;
                    break;
                } else if(solved[i][j]==0 && min_mask[i][j] == 1){
                    ccc = 1;
                }
            }
            if(line == 1 && ccc){
                found = 1;
                for(int j=0;j<M;j++){
                    solved[i][j]=1;
                }
                break;
            }
        }
        if(found) continue;
        for(int j=0;j<M;j++){
            int line = 1;
            int ccc = 0;
            for(int i=0;i<N;i++){
                if(solved[i][j]==0 && min_mask[i][j] == 0){
                    line = 0;
                    break;
                } else if(solved[i][j]==0 && min_mask[i][j] == 1){
                    ccc = 1;
                }
            }
            if(line == 1 && ccc){
                found = 1;
                for(int i=0;i<N;i++){
                    solved[i][j]=1;
                }
                break;
            }
        }
        if(found) continue;
        else return 0;
    }

}
int main()
{
    int T; cin >> T;
    int idx = 0;
    while(T--){
        idx ++;
        cin >> N >> M;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                scanf("%d", &grass[i][j]);
            }
        }
        int ret = gao();
        if(ret) cout << "Case #" << idx << ": YES" << endl;
        else cout << "Case #" << idx << ": NO" << endl;
    }
}
