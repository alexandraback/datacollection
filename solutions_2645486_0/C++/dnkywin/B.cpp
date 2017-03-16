#include<iostream>
#include<fstream>
#include<stack>
#include<queue>
#include<assert.h>
using namespace std;

long long int v[10005];
int next[10005];
long long int best[10005];

long long int E,R;

struct ind{
    int k;
};

bool operator<(ind a, ind b){
    return v[a.k]>v[b.k];
}

priority_queue<ind> pq;



int main(){
    ifstream in("B.in"); ofstream out("B.out");
    int T;
    in>>T;
    for (int t=0;t<T;t++){
        while(!pq.empty()) pq.pop();
        out<<"Case #"<<t+1<<": ";
        long long int E,R,N;
        in>>E>>R>>N;
        if (R>E) R = E;
        for (int i=0;i<N;i++){
            in>>v[i];
            next[i] = -1;
            while(!pq.empty() && (v[pq.top().k]<=v[i])){
                next[pq.top().k] = i;
                pq.pop();
            }
            ind tmp = {i};
            pq.push(tmp);
            if (pq.top().k!=i){
                cout<<pq.top().k<<" "<<i<<" BADDDD\n";

            }
        }
        //for (int i=0;i<N;i++) cout<<next[i]<<" ";cout<<"\n";
        int i = 0; long long int val = 0, energy = E;
        while(i<N){
            if (next[i] == -1){
                val+=energy*v[i];
                i++;
                //cout<<energy<<" ";
                energy = R;
            }
            else{
                long long int gap = next[i]-i;
                long long int spend = energy+R*gap-E;
                if (spend>energy) spend = energy;
                if (spend<0) spend = 0;
                //cout<<spend<<" ";
                val+=spend*v[i];
                energy-=spend-R;
                i++;
            }

        }
        //cout<<"\n";





        out<<val<<"\n";
    }
}
