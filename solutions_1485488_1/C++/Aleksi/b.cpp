#include<iostream>
#include<cassert>
#include<iomanip>
#include<vector>
#include<queue>
using namespace std;


int fl[120][120];
int cl[120][120];
int h;
int n,m;

struct State{
    int x;
    int y;
    double t;
    bool operator<(const State& s)const
    {
        return s.t<t;
    }
};

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
double wait_time(double t,int x,int y,int d){
    double wl = h-t*10;
    int x2 = x+dx[d];
    int y2 = y+dy[d];
    if(x2<0 ||x2>=n ||y2<0 ||y2>=m)return -1;

    double ml = max(wl,double(fl[x][y]));
    ml = max(ml,double(fl[x2][y2]));

    if(cl[x2][y2]-fl[x2][y2]<50)return -1;
    if(cl[x2][y2]-fl[x][y]<50)return -1;

    if(cl[x][y]-fl[x2][y2]<50)return -1;

    if(cl[x2][y2]-ml>=50)return 0;
    //wl-z*10=cl[x2][y2]-50
    double z = -(cl[x2][y2]-50-wl)/10;
    //cout<<"wait "<<z<<"\n";
    return z;
}

double dist[130][130];
priority_queue<State> pq;

void dfs(State s){
    if(dist[s.x][s.y]<1)return;
    dist[s.x][s.y]=0;
    pq.push(s);
    for(int i=0;i<4;i++){
        if(wait_time(0,s.x,s.y,i)==0){
            State s2;
            s2.x=s.x+dx[i];
            s2.y=s.y+dy[i];
            s2.t=0;
            dfs(s2);
        }
    }
}

double search(){

    pq=priority_queue<State>();
    
    State start;
    start.x=0;
    start.y=0;
    start.t=0;
    dfs(start);
    //cout<<"foo\n";
    
    while(pq.size()){
        State s = pq.top();
        pq.pop();
        //cout<<"s "<<s.t<<" "<<s.x<<" "<<s.y<<"\n";

        if(dist[s.x][s.y]<s.t){
            continue;
        }
        assert(dist[s.x][s.y]==s.t);
        if(s.x==(n-1) && s.y==(m-1)){
            return s.t;
        }
        for(int i=0;i<4;i++){
            double wt = wait_time(s.t,s.x,s.y,i);
            double wl = h-10*(s.t+wt);
            if(wt<0)continue;//never to be possible
            if(wt>0){
                /*
                cout<<"wait "<<wt<<" "<<
                    (s.x+dx[i])<<" "<<
                    (s.y+dy[i])<<"\n";
                    */
            }

            State s2;
            s2.x = s.x+dx[i];
            s2.y = s.y+dy[i];

            if( //wl-fl[s2.x][s2.y]<20 || 
                wl-fl[s.x][s.y]<20
                )
                s2.t = s.t+10+wt;
            else
                s2.t = s.t+1+wt;

            if(dist[s2.x][s2.y]>s2.t)
            {
                pq.push(s2);
                dist[s2.x][s2.y]=s2.t;
            }
        }
    }
    return -1;
}

int main(){
    int t;
    cin>>t;
    for(int cn=1;cn<=t;cn++){
        cin>>h>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>cl[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>fl[i][j];
                dist[i][j]=1e9;
            }
        }
        double d = search();
        cout<<"Case #"<<cn<<": "<<setprecision(7)<<d<<"\n";
    }
}
