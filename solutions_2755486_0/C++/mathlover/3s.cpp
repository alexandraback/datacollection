/*************************************************************************
    > Fil:		3s.cpp
    > Author:quietsmile
    > Mail:	debingzhangchina@gmail.com
    > Created Time: Sun 12 May 2013 05:29:17 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

int T;
int para[15][10];
int wall[10001];
int print = 0;
int main(){
    cin >> T; int idx = 0;
    while(T--){
        memset(para,0,sizeof(para));
        memset(wall,0,sizeof(wall));
        int N; cin >> N;
        for(int i = 0; i< N;i ++){
            for(int j = 0; j<8;j++){
                cin >> para[i][j];
            }
        }
        int ret = 0;
        for(int d = 0; d<=676060;d++){
            int is_att = 0;
            int xiu[20][4]={};
            int xx = 0;
            for(int i = 0;i<N;i++){
                if(d>=para[i][0] && (d-para[i][0])%para[i][5]==0){
                    is_att = 1;
                    int ni = (d-para[i][0])/para[i][5];
                    if(ni>=para[i][1]) continue;
                    int si = para[i][4]+ni*para[i][7];
                    if(si<0) continue;
                    int fromi = (para[i][2] + ni * para[i][6])*2 + 5000;
                    int toi = (para[i][3] + ni * para[i][6])*2 + 5000;
                    int min = wall[fromi];
                    for(int j=fromi+1;j<=toi;j++){
                       if(min > wall[j]) min = wall[j]; 
                    }
                    if(si > min){
                        if(print){
                            cout << "d " << d << " i " << i << " fromi " << fromi << " toi " << toi << " si " << si << endl;
                        }
                        xx = 1;
                        ret++;
                        xiu[i][0]=fromi; xiu[i][1] = toi; xiu[i][2] = si;
                    }
                }
            }
            if(xx){
                for(int i = 0; i<N;i ++){
                    if(xiu[i][0]){
                        for(int j = xiu[i][0]; j<=xiu[i][1];j++){
                            wall[j] = wall[j] < xiu[i][2]? xiu[i][2]:wall[j];
                        }
                    }
                }
            }
        }
        idx++;
        cout << "Case #" << idx<<": " << ret << endl;
    }
	return 0;
}
