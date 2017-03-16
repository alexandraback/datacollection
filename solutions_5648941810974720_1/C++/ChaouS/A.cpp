#include <bits/stdc++.h>

using namespace std;

const int maxN = 2005;
const int mod = 1e9 + 7;

string cad[10] =  {"ZERO" , "TWO", "SIX" , "FOUR" , "FIVE" , "ONE", "THREE", "SEVEN", "EIGHT", "NINE"};
int val[10] = {0 , 2 , 6 , 4 , 5 , 1 , 3 , 7 , 8 , 9};
char f[10] = {'Z', 'W','X','U','F','O','R','S','G','E'};
int main(){

    freopen("A-large.in","r",stdin);
    freopen("on.c","w",stdout);

    int tc;
    cin >> tc;
    for(int tt = 1; tt <= tc; tt++){
        string s;

        cin >> s;
        vector<int> c(26 , 0);
        for(char elem : s){
            c[elem - 'A']++;
        }

        vector<int> answer;
        for(int i = 0; i < 10; ++i){
            int rep = c[f[i] - 'A'];
            while(rep--){
                for(char x : cad[i]){
                    c[x - 'A']--;
                }
                answer.push_back(val[i]);
            }
        }

        for(int i = 0; i < 26; ++i){
            assert(c[i] == 0);
        }

        sort(answer.begin() , answer.end());
        printf("Case #%d: ",tt);
        for(int x : answer){
            printf("%d",x);
        }
        cout << endl;

    }






    return 0;
}
