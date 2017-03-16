#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

struct hiker{
    int start; int speed;
    hiker(int s, int e){start = s; speed = e;}
};

struct functor{
    bool operator()(hiker *a, hiker *b){
        if (a->start==b->start) return (a->speed>b->speed);
        return (a->start<b->start);
    }
};

void find_collision(int h, vector<hiker*> hikers, double t, int * h_out, double * t_out){
    *h_out = -1;
    *t_out = 999999999999;
    for(int i=0;i<hikers.size();i++){
        if (hikers[i]->speed==hikers[h]->speed) continue;
        int loops = 0;
        int dloops = 1;
        if (hikers[i]->speed < hikers[h]->speed) dloops =-1;
        while((hikers[i]->start*1./360-hikers[h]->start*1./360+loops)*1./(1./hikers[h]->speed-1./hikers[i]->speed)<=t) loops+=dloops;
        if ((hikers[i]->start*1./360-hikers[h]->start*1./360+loops)*1./(1./hikers[h]->speed-1./hikers[i]->speed)<*t_out){
            *t_out = (hikers[i]->start*1./360-hikers[h]->start*1./360+loops)*1./(1./hikers[h]->speed-1./hikers[i]->speed);
            *h_out = i;
        }
    }
}

int solve(vector<hiker *> hikers, double t, int h, int layer, bool behind){
    if (layer>10) return 20;
    int soln = 0;
    int h_out=0;
    double t_out;
    find_collision(0, hikers, t, &h_out, &t_out);
    //cout<<t_out<<" "<<hikers[h]->start*1./360+t_out*1./hikers[h]->speed<<endl;
    if(h_out==-1) return 0;
    if(hikers[h]->start*1./360+t_out*1./hikers[h]->speed>1) return 0;
    t_out *=1.000001;
    if (behind){
        if (hikers[h]->speed<hikers[h_out]->speed) {//your hiker overtaking
            return min(solve(hikers, t_out, h_out, layer+1, 1), 1+solve(hikers, t_out, h, layer+1, 1));
        }
        else{
            return min(1+solve(hikers, t_out, h_out, layer+1, 0), 1+solve(hikers, t_out, h, layer+1, 1));
        }
    }
    else{
        if (hikers[h]->speed<hikers[h_out]->speed) {//your hiker overtaking
            return min(1+solve(hikers, t_out, h_out, layer+1, 1), 1+solve(hikers, t_out, h, layer+1, 0));
        }
        else{
            return min(1+solve(hikers, t_out, h_out, layer+1, 0), 1+solve(hikers, t_out, h, layer+1, 0));
        }
    }
}

int main() {
    int T; cin>>T;
    for(int case_id = 1;case_id<=T;case_id++){
        int N; cin>>N;
        vector<hiker*> hikers;
        for(int i=0;i<N;i++){
            int D, H, M;
            cin>>D; cin>>H; cin>>M;
            while(H){
                H--;
                hiker *h = new hiker(D, M);
                hikers.push_back(h);
                M++;
            }
            
        }
        sort(hikers.begin(), hikers.end(), functor());
        //for(int i=0;i<hikers.size();i++) cout<<hikers[i]->start<<" "<<hikers[i]->speed<<endl;
        printf("Case #%d: %d\n", case_id, solve(hikers, 0, 0, 0, 1));
    }
}