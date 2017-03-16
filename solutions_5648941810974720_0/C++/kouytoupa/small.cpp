#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const char *digit_to_str[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);
    //1 100
    int T;
    cin >> T;
    for(int cas = 1; cas <= T; cas ++){
        cout << "Case #" << cas << ": ";
        string S;
        cin >> S;
        //n 3 20
        int n = S.size();
        sort(S.begin(), S.end());
        //20/3 = 6. 
        int m = n/3;
        for(int x = 0; x < 1000000; x++){
            //to string
            vector<int> d;
            int y = x;
            while(y){
                d.push_back(y%10);
                y /= 10;
            }
            //sort(d.begin(), d.end());
            if(d.size() > m){
                //will not reach here
                cerr << "fail to find" << endl;
                break;
            }
            string s;
            for(int i = 0; i < d.size(); i++){
                s += digit_to_str[d[i]];
            }
            sort(s.begin(), s.end());
            while(s.size() < n){
                s += digit_to_str[0];
                d.push_back(0);
            }
            if(s.size() != n){
                continue;
            }
            sort(s.begin(), s.end());
            if(s == S){
                sort(d.begin(), d.end());
                for(int i = 0; i < d.size(); i++){
                    cout << d[i];
                }
                cout << endl;
                break;
            }
        }
    }
    return 0;
}
