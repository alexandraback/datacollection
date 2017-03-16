#include<cstdio>
#include<vector>
#include<iostream>
#include<queue>
#include<map>

using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;

int dr[] = {0,1,0,-1};
int dc[] = {-1,0,1,0};//W,N,E,S

int main(void){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int tc, casecounter = 1;
    scanf("%d",&tc);
    map<int,string> maps;
    maps[0] = "W";
    maps[1] = "N";
    maps[2] = "E";
    maps[3] = "S";
    while(tc--){
        map<iii,string> mapper;
        int x, y;
        scanf("%d %d",&x,&y);
        queue<iii>q;
        q.push(iii(ii(0,0),0));
        mapper[iii(ii(0,0),0)] = "";
        while(!q.empty()){
            iii xy = q.front();
            q.pop();
            if(xy.first.first == x && xy.first.second == y){
                cout<<"Case #"<<casecounter++<<": "<<mapper[xy]<<endl;
                break;
            }
            int jumps = xy.second + 1;
            for(int i=0;i<4;i++){
                int curx, cury;
                curx = xy.first.first;
                cury = xy.first.second;
                curx +=dc[i]*jumps;
                cury +=dr[i]*jumps;
                if(mapper.find(iii(ii(curx,cury),jumps))==mapper.end()){
                    q.push(iii(ii(curx,cury),jumps));
                    mapper[iii(ii(curx,cury),jumps)] = mapper[xy]+maps[i];
                }
            }

        }
        while(!q.empty())q.pop();
    }



    return 0;
}
