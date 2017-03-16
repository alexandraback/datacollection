#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

long long rec(long long e, long long gain, long long index, long long increase, vector<long long> &act, long long maxe){
    if(index >= act.size())
        return gain;
    else{
        long long maximum = -1;
        for(int i = 0; i <= e; i++){
            int temp = rec(min(maxe, e - i + increase), gain + i * act[index], index + 1, increase, act, maxe);
            if(temp > maximum){
                maximum = temp;
            }

        }
        return maximum;
    }
}

int main(){
    int t;
    cin>>t;
    for(int test = 0; test < t;test++){
        long long e, r, n , v;
        cin>>e>>r>>n;
        vector<long long> act(n, 0);
        for(long long i=0;i < n;i++){
            cin>>act[i];
        }
        cout<<"Case #"<<test+1<<": "<<rec(e, 0, 0, r, act, e)<<endl;


    }
}
