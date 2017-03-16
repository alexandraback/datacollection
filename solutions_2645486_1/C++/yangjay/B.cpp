#include <iostream>
#include <cstdio>

using namespace std;
typedef long long ll;

ll optimize(int E,int R,int N,ll *gain){
    int curr_e = E;
    ll curr_gain = 0;

    for(int i=0;i<N;i++){
        //find the next highest (inefficient, but n is small
        int next = i+1;
        for(;next<N;next++){
            if(gain[next]>=gain[i]){
                break;
            }
        }
        int e_delta;
        if(next==N){
            e_delta = curr_e;
        }
        else{
            //hypothetical energy
            int hyp_e = curr_e+R*(next-i);
            e_delta = hyp_e - E;
            if(e_delta<0)
                e_delta = 0;
        }
        if(e_delta>curr_e){
            e_delta = curr_e;
        }
        //printf("Spend %lld %d\n",gain[i],e_delta);
        curr_e -= e_delta;
        curr_gain += e_delta*gain[i];
        e_delta = 0;

        if(curr_e+R>E){
            //forced to spend
            e_delta = curr_e+R-E;
            if(e_delta>curr_e){//can happen
                e_delta = curr_e;
            }
            //printf("Forced Spend %lld %d\n",gain[i],e_delta);
            curr_e -= e_delta;
            curr_gain += e_delta*gain[i];
        }
        curr_e += R;
        if(curr_e>E){//note, this can still happen
            curr_e=E;
        }
    }
    return curr_gain;
}


int main(){
    int T,E,R,N;
    cin >> T;
    for(int k=0;k<T;k++){
        cin >> E >> R >> N;
        ll * gain = new ll[N];
        for(int i=0;i<N;i++){
            cin >> gain[i];
        }
        ll res = optimize(E,R,N,gain);
        printf("Case #%d: %lld\n",k+1,res);
    }

}
