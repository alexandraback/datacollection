#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

#define LL long long

struct  str_attack{
    int day, str, west, east;
}attack[1000005];

bool operator  < (str_attack a, str_attack b){
    if (a.day < b.day)return 1;
    else return 0;
}

int main (){
    int t;
    cin>>t;
    int num_t = 1;
    while (num_t <= t){
        int num_tribe;
        int tot_attacks = 0;
        int day [1005];
        int num_att [1005];
        int west[1005];
        int east[1005];
        int str[1005];
        int del_day [1005];
        int del_dist [1005];
        int del_str [1005];
        cin>>num_tribe;
        for (int i=0;i<num_tribe;++i){
            cin>>day[i]>>num_att[i]>>west[i]>>east[i]>>str[i]>>del_day[i]>>del_dist[i]>>del_str[i];
            for (int j = 0 ; j < num_att[i] ; ++j){
                attack[tot_attacks].day = day[i] + del_day[i]*j;
                attack[tot_attacks].str = str[i] + del_str[i]*j;
                attack[tot_attacks].west = west[i] + del_dist[i]*j;
                attack[tot_attacks].east = east[i] + del_dist[i]*j;
                tot_attacks ++;
            }
        }
        sort (attack, attack + tot_attacks);

        LL height [1005]; // height[i] = height[i-250];
        for (int i=0;i<1005;++i){
            height[i] = 0;
        }
        int tot_succ = 0;
        vector <str_attack> mod ;
        int cur_day = -1;
        for (int i=0;i<tot_attacks ;++i){
            LL min = 10000000000000LL;

            if (attack[i].day != cur_day){
                for (int k=0;k<mod.size();++k){
                    for (int j=mod[k].west;j<mod[k].east;++j){
                        if (height[j + 250] < mod[k].str) height [j + 250] = mod[k].str;
                    }
                }
                vector <str_attack> new_;
                mod = new_;
            }
            else;
            for (int j=attack[i].west;j<attack[i].east;++j){
                if (height[j + 250] < min ) min = height [j + 250];
            }
            if (min >= attack[i].str);
            else{
                tot_succ++;
                str_attack new_mod;
                new_mod.east = attack[i].east;
                new_mod.west = attack[i].west;
                new_mod.str = attack[i].str;
                mod.push_back (new_mod);
            }
            cur_day = attack[i].day;
        }
        cout<<"Case #"<<num_t<<": "<<tot_succ<<"\n";
        num_t++;
    }
    return 0;
}
