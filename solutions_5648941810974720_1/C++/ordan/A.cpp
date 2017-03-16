#include <bits/stdc++.h>

using namespace std;

int main(){
    int TESTS;
    scanf ("%d", &TESTS);
    for (int CASE = 1; CASE <= TESTS; CASE++){
        printf ("Case #%d:", CASE);

        string s;
        cin >> s;
        string ans = "";

        while (s.size()){
            while (find(s.begin(), s.end(), 'Z') != s.end()){
                s.erase(find(s.begin(), s.end(), 'Z'));
                s.erase(find(s.begin(), s.end(), 'E'));
                s.erase(find(s.begin(), s.end(), 'R'));
                s.erase(find(s.begin(), s.end(), 'O'));
                ans += "0";
            }

            while (find(s.begin(), s.end(), 'W') != s.end()){
                s.erase(find(s.begin(), s.end(), 'T'));
                s.erase(find(s.begin(), s.end(), 'W'));
                s.erase(find(s.begin(), s.end(), 'O'));
                ans += "2";
            }

            while (find(s.begin(), s.end(), 'U') != s.end()){
                s.erase(find(s.begin(), s.end(), 'F'));
                s.erase(find(s.begin(), s.end(), 'O'));
                s.erase(find(s.begin(), s.end(), 'U'));
                s.erase(find(s.begin(), s.end(), 'R'));
                ans += "4";
            }

            while (find(s.begin(), s.end(), 'X') != s.end()){
                s.erase(find(s.begin(), s.end(), 'S'));
                s.erase(find(s.begin(), s.end(), 'I'));
                s.erase(find(s.begin(), s.end(), 'X'));
                ans += "6";
            }

            while (find(s.begin(), s.end(), 'F') != s.end()){
                s.erase(find(s.begin(), s.end(), 'F'));
                s.erase(find(s.begin(), s.end(), 'I'));
                s.erase(find(s.begin(), s.end(), 'V'));
                s.erase(find(s.begin(), s.end(), 'E'));
                ans += "5";
            }

            while (find(s.begin(), s.end(), 'G') != s.end()){
                s.erase(find(s.begin(), s.end(), 'E'));
                s.erase(find(s.begin(), s.end(), 'I'));
                s.erase(find(s.begin(), s.end(), 'G'));
                s.erase(find(s.begin(), s.end(), 'H'));
                s.erase(find(s.begin(), s.end(), 'T'));
                ans += "8";
            }

            while (find(s.begin(), s.end(), 'O') != s.end()){
                s.erase(find(s.begin(), s.end(), 'O'));
                s.erase(find(s.begin(), s.end(), 'N'));
                s.erase(find(s.begin(), s.end(), 'E'));
                ans += "1";
            }

            while (find(s.begin(), s.end(), 'S') != s.end()){
                s.erase(find(s.begin(), s.end(), 'S'));
                s.erase(find(s.begin(), s.end(), 'E'));
                s.erase(find(s.begin(), s.end(), 'V'));
                s.erase(find(s.begin(), s.end(), 'E'));
                s.erase(find(s.begin(), s.end(), 'N'));
                ans += "7";
            }

            while (find(s.begin(), s.end(), 'T') != s.end()){
                s.erase(find(s.begin(), s.end(), 'T'));
                s.erase(find(s.begin(), s.end(), 'H'));
                s.erase(find(s.begin(), s.end(), 'R'));
                s.erase(find(s.begin(), s.end(), 'E'));
                s.erase(find(s.begin(), s.end(), 'E'));
                ans += "3";
            }

            while (find(s.begin(), s.end(), 'N') != s.end()){
                s.erase(find(s.begin(), s.end(), 'N'));
                s.erase(find(s.begin(), s.end(), 'I'));
                s.erase(find(s.begin(), s.end(), 'N'));
                s.erase(find(s.begin(), s.end(), 'E'));
                ans += "9";
            }
        }

        sort(ans.begin(), ans.end());
        cout << " " <<  ans << endl;
    }
    return 0;
}


