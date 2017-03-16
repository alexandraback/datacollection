#include <bits/stdc++.h>

using namespace std;

int p (string s){
    int position = -1;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '-'){
             position = i;
        }
    return position;

}

int solve (string s){
    int ans = 0;
    while (p (s) != -1){
        int k = p(s);
        stack <char> pilha;
        for (int i = 0; i <= k; i++){
            if (s[i] == '-') break;
            if (i == 0) ans++;
            s[i] = '-';
        }
        for (int i = 0; i <= k; i++){
            pilha.push(s[0]);
            s.erase(s.begin());
        }

        while (!pilha.empty()){
            s.insert(s.begin(), pilha.top() == '+'? '-':'+');
            pilha.pop();
        }

        ans++;
    }
    return ans;
}

int main(){

    int n, c = 1, t;

    scanf ("%d", &t);

    while (t--){

        string s;
        cin >> s;
        printf ("Case #%d: %d\n", c++, solve(s));
    }

    return 0;
}

