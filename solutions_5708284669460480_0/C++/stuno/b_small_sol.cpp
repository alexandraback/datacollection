#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
string str = "";
int k,l,s;
string keyboard, target;
int occ_count[10000];
set<char> alphabet;
void f(int index){
    if(index == s){
        int occurences = 0;
        int pos = str.find(target, 0);
        while(pos != string::npos){
            occurences++;
            pos = str.find(target,pos+1);
        }
        occ_count[occurences]++;
    } else {
        for(int i=0; i<keyboard.size(); ++i){
            str+= keyboard[i];
            f(index+1);
            str.erase(str.size()-1);
        }
    }
}
int get_min(){
    bool possible = true;
    for(int i=0; i<target.size(); ++i){
        if(alphabet.find(target[i])==alphabet.end()){
            possible = false;
        }
    }
    if(possible == false){
        return 0;
    }
    int overlapping = 0;
    for(int i=1; i<target.size(); ++i){
        bool good = true;
        for(int j=i; j<target.size(); ++j){
            if(target[j] != target[j-i]){
                good = false;
                break;
            }
        }
        if(good){
            overlapping = target.size() - i;
            break;
        }
    }
    int max_times = 1;
    int len = target.size();
    while(len+target.size() - overlapping<=s){
        len+= target.size() - overlapping;
        max_times++;
    }
    return max_times;
}
int main(){
    //freopen("C:\\GCJ_1C\\in.txt", "r", stdin);
    freopen("C:\\GCJ_1C\\b_small.in", "r", stdin);
    freopen("C:\\GCJ_1C\\b_small.out", "w", stdout);
    int TC;
    scanf("%d", &TC);
    for(int test_case = 1; test_case<=TC; ++test_case){
        memset(occ_count, 0, sizeof(occ_count));
        cin >> k >> l >> s;
        cin >> keyboard;
        cin >> target;
        alphabet.clear();
        for(int i=0; i<keyboard.size();++i){
           alphabet.insert(keyboard[i]);
        }
        int bananas = get_min();
        f(0);
        long long all = 1;
        for(int i=0; i<s; ++i){
            all*=keyboard.size();
        }
        double expected = 0;
        for(int i=1; i<=s; ++i){
            double p = occ_count[i]/(double)all;
            expected += p*i;
        }
        cout << setprecision(10) << "Case #" << test_case << ": "<< bananas - expected << endl;
    }
    return 0;
}
