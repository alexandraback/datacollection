#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool match(const string &s1, const string &s2)
{
    int n1 = s1.size(), n2 = s2.size();
    if(n1 != n2){
        cerr << "error" << endl;
        return false;
    }
    for(int i = 0; i < n1; i++){
        if(s1[i] == '?'){
            continue;
        }
        if(s2[i] == '?'){
            continue;
        }
        if(s1[i] != s2[i]){
            return false;
        }
    }
    return true;
}
int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);
    //1 200
    int T;
    cin >> T;
    for(int cas = 1; cas <= T; cas ++){
        cout << "Case #" << cas << ": ";
        //len 1 3
        string sc, sj;
        cin >> sc >> sj;
        int nc = sc.size(), nj = sj.size();
        int min_diff = 1000, best_c, best_j;
        string best_c_str, best_j_str;
        for(int x = 0; x < 1000; x++){
            int z = x;
            string tc;
            while(z){
                tc.push_back((z%10) + '0');
                z /= 10;
            }
            if(tc.size() > nc){
                continue;
            }
            while(tc.size() < nc){
                tc.push_back('0');
            }
            reverse(tc.begin(), tc.end());
            if(!match(sc, tc)){
                continue;
            }
            for(int y = 0; y < 1000; y++){
                string tj;
                int z = y;
                while(z){
                    tj.push_back((z%10) + '0');
                    z /= 10;
                }
                if(tj.size() > nj){
                    continue;
                }
                while(tj.size() < nj){
                    tj.push_back('0');
                }
                reverse(tj.begin(), tj.end());
                if(match(sj, tj)){
                    int diff = abs(x - y);
                    if(diff < min_diff){
                        min_diff = diff;
                        best_c = x;
                        best_j = y;
                        best_c_str = tc;
                        best_j_str = tj;
                    }else if(diff == min_diff){
                        if(x < best_c){
                            best_c = x;
                            best_j = y;
                            best_c_str = tc;
                            best_j_str = tj;
                        }else if(x == best_c){
                            if(y < best_j){
                                best_j = y;
                                best_c_str = tc;
                                best_j_str = tj;
                            }
                        }
                    }
                }
            }
        }
        cout << best_c_str << " " << best_j_str << endl;
    }
    return 0;
}
