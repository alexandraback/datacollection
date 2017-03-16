#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

// -------------- PRINT TOOLS --------------
void print_vect(const vector<double> &v){
    for(int i=0;i<v.size();i++) printf("%lf ",v[i]);
    printf("\n");
}
// -----------------------------------------

void read_vect_from_input(int size, vector<double> &out){
    while(size--){
        double x;
        scanf("%lf",&x);
        out.push_back(x);
    }
}
// x cheats
int cheat_war_optimally(const vector<double> &x, const vector<double> &y){
    int wins = 0;
    int y_pos = 0;
    for(int i=0;i<x.size();i++){
        if(x[i] < y[y_pos]) // x loses this one
            continue;
        ++wins;
        ++y_pos;
    }
    return wins;
}
int play_war_optimally(const vector<double> &x, const vector<double> &y){
    int y_ind = 0;
    int x_ind = 0;
    while(x_ind < x.size()){
        double x_play = x[x_ind]; // play value
        //printf("X plays %lf (%d) -- ", x_play, x_ind);
        while(y_ind < y.size() && y[y_ind] < x_play)
            ++y_ind;
        if(y_ind == y.size()){
            //printf("X starts WINNING\n");
            return x.size() - x_ind;
        }
        //printf("Y plays %lf (%d)\n", y[y_ind], y_ind);
        ++y_ind; // y wins
        ++x_ind;
    }
    return 0;
}

void test_case(){
    int n;
    scanf("%d", &n);
    vector<double> n_val, k_val;
    n_val.reserve(n); k_val.reserve(n);
    read_vect_from_input(n,n_val);
    read_vect_from_input(n,k_val);
    sort(n_val.begin(), n_val.end());
    sort(k_val.begin(), k_val.end());
    //printf("\n"); print_vect(n_val); print_vect(k_val);
    printf("%d %d\n", cheat_war_optimally(n_val, k_val), play_war_optimally(n_val, k_val));
}

const bool LINE_AFTER_CASE = false;
int main(){
    int z;
    scanf("%d", &z);
    for(int t=1;t<=z;++t){
        printf("Case #%d:%s", t, LINE_AFTER_CASE ? "\n" : " ");
        test_case();
    }
    return 0;
}
