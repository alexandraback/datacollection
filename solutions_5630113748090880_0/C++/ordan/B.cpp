#include <bits/stdc++.h>

using namespace std;

int main(){

    int t, c = 1;
    scanf ("%d", &t);

    while (t--){

        printf ("Case #%d:", c++);
        int n;
        scanf ("%d", &n);
        map <int, int> qtd;
        for (int i = 0; i < 2 * n - 1; i++)
            for (int j = 0; j < n; j++){
                int x;
                scanf ("%d", &x);
                qtd[x]++;
            }
        vector <int> ans;
        for (auto i: qtd){
            if (i.second % 2)
                ans.push_back(i.first);
        }
        sort (ans.begin(), ans.end());

        for (auto t : ans)
            printf (" %d", t);
        printf ("\n");

    }

    return 0;
}
