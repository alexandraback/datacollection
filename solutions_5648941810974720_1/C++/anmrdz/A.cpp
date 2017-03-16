#include <bits/stdc++.h>

using namespace std;


int main() {


      freopen("d.in", "r", stdin);
      freopen("d.out", "w", stdout);

    string numbers [] = {"ZERO","EIGHT", "TWO", "SIX", "FOUR",
                         "FIVE", "THREE", "SEVEN",
                         "NINE","ONE"
                        };

    int pos [] = {0, 8, 2, 6, 4, 5, 3, 7, 9, 1};

    int t;
    string seq;
    cin >> t;
    vector<int> gl, temp;

    for(int ti = 1; ti <= t; ti++) {

        vector<int> frec(27);
        cin >> seq;

        for(int i = 0; i < seq.size(); i++) {
            frec[seq[i] - 'A']++;
        }

        cout <<"Case #"<< ti <<": ";

        vector<int> ans;
        for(int i = 0; i < 10; i++) {
            gl = frec;
            bool valid = true;


            while(valid) {
                temp = frec;
                for(int j = 0; j < numbers[i].size(); j++) {
                    if(temp[numbers[i][j] - 'A'] - 1 < 0) {
                        valid = false;
                        break;
                    }
                    temp[numbers[i][j] - 'A']--;
                }

                if(valid) {
                    frec = temp;
                    ans.push_back(pos[i]);

                }
            }
        }

        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i];
        }

        cout<<"\n";
    }

    return 0;
}

