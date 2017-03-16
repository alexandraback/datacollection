#include <cstdio>
using namespace std;

// -------------------------------
// -------- DEBUG include --------
#include <cassert>
#include <cstring> // strcmp
bool DEBUG = false;
// -------------------------------
// -------------------------------
#include <algorithm>    // std::unique, std::distance
#include <vector>
struct train{
    vector<char> letters;
    // ------
    train(char *chars){
        //if(DEBUG) { printf("creating TRAIN from  (%d) %s", chars, chars); }
        int len = strlen(chars);
        char *new_end = unique(chars, chars+len);
        *new_end = 0;
        //if(DEBUG) { printf("\t--> after UNIQUE --> %s\n", chars); }
        while(chars != new_end){
            letters.push_back(*chars);
            //if(DEBUG) { printf("%c ", letters.back()); }
            ++chars;
        }
        //if(DEBUG) { printf("\n"); }
    }
    void print(){
        for(int i=0;i<letters.size();i++){ printf("%c ", letters[i]); }
    }
    // ------
    bool starts_with(char c){
        return letters.front() == c;
    }
    bool ends_with(char c){
        return letters.back() == c;
    }
    bool is_inside(char c){
        for(int i=1;i<letters.size()-1;i++){
            if (letters[i] == c)
                return true;
        }
        return false;
    }
    void merge_with(train *x){
        assert(letters.back() == x->letters.front());
        letters.pop_back();
        for(int i=1;i<x->letters.size();i++){
            letters.push_back(x->letters[i]);
        }
    }
    void own_train(train *x){
        letters.swap(x->letters);
    }
    bool is_processed(char c){
        for(int i=0;i<letters.size();i++){
            if (letters[i] > c)
                return false;
        }
        return true;
    }
};

const int MOD = 1000000007; // 10^9 + 7

int mul_mod(long long val_a, long long val_b){
    return (val_a * val_b) % MOD;
}

vector<int> mod_fact_cache;
int mod_factorial(int num){
    if(!(num < mod_fact_cache.size())){ // not computed --> do this now!
        if(num == 0){
            mod_fact_cache.push_back(1); // 0! = 1
        }
        else {
            int prev = mod_factorial(num-1);
            mod_fact_cache.push_back(mul_mod(prev, num));
        }
    }
    assert(num < mod_fact_cache.size());
    return mod_fact_cache[num];
}

void report_trains(const vector<train*> &trains){
    printf("\n>>>>> TRAINS <<<<<\n");
    for(int i=0;i<trains.size();i++){
        printf("[%d]: ",i); trains[i]->print(); printf("\n");
    }
    printf("==================\n");
}

void remove_train(int num, vector<train*> &from){
    if(DEBUG) { printf("remove_train %d --> trains SIZE is %d\n", num, from.size()); }
    assert(0 <= num && num < from.size());
    delete from[num];
    if(num < from.size()-1) from[num] = from.back(); // num was not the last one
    from.pop_back();
    if(DEBUG) { printf("TRAINS after:\n"); report_trains(from); }
}


void test_case(){
    // ---------- LOAD & INIT DATA ----------
    if(DEBUG) { printf("\n"); }
    int n;
    vector<train*> trains;
    scanf("%d",&n);
    char trains_buffer[1000];
    for(int i=0;i<n;i++){
        scanf("%s", trains_buffer);
        trains.push_back(new train(trains_buffer));
    }
    // ---------- SOLVE CASE ----------
    long long result = 1; // long long for MUL operations (after MOD - back in INT)
    int independent_trains_num = 0;
    if(DEBUG){ report_trains(trains); } // REPORT TRAINS
    for(char let='a'; let <= 'z'; ++let){ // compute PART result for TRAINS with 'a'
        bool is_let_inside = false;
        int ones_num = 0;
        int start_tr = -1, end_tr = -1;
        for(int i=0;i<trains.size();i++){
            bool is_start = trains[i]->ends_with(let); // is_start -> train ENDS with this letter
            bool is_end = trains[i]->starts_with(let); // is_end -> train STARTS with this letter
            if(is_start && is_end){ // this train contains only letter let
                ++ones_num;
                remove_train(i, trains);
                --i;
            } else if(is_start){
                if(start_tr < 0){ start_tr = i; }
                else { result = 0; break; } // two starts -> no way to join
            } else if(is_end){
                if(end_tr < 0){ end_tr = i; }
                else { result = 0; break; } // two end -> no way to join
            } else if(trains[i]->is_inside(let)) {
                if(!is_let_inside){ is_let_inside = true; }
                else { result = 0; break; } // two times inside -> no way to join
            }
        }
        if(is_let_inside){
            if((ones_num>0) || (start_tr >= 0) || (end_tr >= 0)) result = 0;
            else continue;
        }
        // check if result 0
        if(result == 0) break; // nothing more to do
        // else - letter possible to join, no inner occurrences
        result = mul_mod(result, mod_factorial(ones_num));
        if(start_tr < 0 && end_tr<0){ // no endings, only ones
            if(ones_num>0) ++independent_trains_num; // ones joined - build one independent
        } else{
            int result_train;
            if(start_tr >= 0 && end_tr >= 0){ // two endings - merge!
                trains[start_tr]->merge_with(trains[end_tr]);
                if(start_tr < end_tr){
                    remove_train(end_tr, trains);
                    result_train = start_tr;
                } else {
                    trains[end_tr]->own_train(trains[start_tr]);
                    remove_train(start_tr, trains);
                    result_train = end_tr;
                }
            } else if(start_tr >= 0){ // only start
                result_train = start_tr;
            } else if(end_tr >= 0){ // only end
                result_train = end_tr;
            }
            if(trains[result_train]->is_processed(let)){
                ++independent_trains_num;
                remove_train(result_train, trains);
            }
        }
    }
    independent_trains_num += trains.size();
    result = mul_mod(result, mod_factorial(independent_trains_num));
    // --- print RESULT ---
    printf("%d\n", (int) result); // res under MOD so it is in INT range
    // ---------- CLEAR MEMORY ----------
    for(int i=0;i<trains.size();i++) delete trains[i];
    if(DEBUG) { printf("\n----------------\n----------------\n----------------\n\n"); }
}

// ----------------------------------------
// -------------- MAIN DRAFT --------------
// ----------------------------------------

const bool LINE_AFTER_CASE = false;
int main(int argc, char *argv[]) {
    // recognise running mode
    if(argc >= 2 && !strcmp(argv[1],"DEBUG")){
        printf("switch DEBUG ON!\n");
        DEBUG = true;
    }
    // -------------------
    int z;
    scanf("%d", &z);
    for(int t=1;t<=z;++t){
        printf("Case #%d:%s", t, LINE_AFTER_CASE ? "\n" : " ");
        test_case();
    }
    return 0;
}
