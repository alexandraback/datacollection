#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

//notes, if we remove a mote, we always want to remove the largest,
//otherwise, we need to add a mote, if we add a mote, we want to add the
//largest mote he can absorb in the limit,

typedef long long ll;

int nmotes;
ll start_mote;
ll mote_sizes[100];//sorted list
int steps_needed[100];//steps needed to absorb the n-th mote

#define REMOVE_TOP

//how many steps needed to absorb all
void steps_needed_comp(){
    int step_count = 0;
    ll curr_mote = start_mote;
    for(int i=0;i<nmotes;i++){
        while(curr_mote<=mote_sizes[i]){
            curr_mote += (curr_mote-1);//make bigger
            step_count++;
        }
        //absorb and move on
        curr_mote += mote_sizes[i];
        steps_needed[i] = step_count;
    }
}

int do_stuff(){
    if(start_mote<2){
        //impossible to expand
        return nmotes;
    }
    steps_needed_comp();
    //printf("S: %lld\n",start_mote);
    int min = nmotes;
    for(int i=0;i<nmotes;i++){
        int remain = nmotes - (i+1);
        int test = steps_needed[i] + remain;
        //printf("%d ",steps_needed[i]);
        if(test<=min)
            min = test;
    }
    //printf("\n");
    return min;
}

int main(){
    int ncases;
    cin >> ncases;
    for(int k=0;k<ncases;k++){
        cin >> start_mote >> nmotes;
        for(int i=0;i<nmotes;i++){
            cin >> mote_sizes[i];
        }
        sort(mote_sizes,mote_sizes+nmotes);
        int res = do_stuff();
        printf("Case #%d: %d\n",k+1,res);
    }
}
