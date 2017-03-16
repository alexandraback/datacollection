#include <bits/stdc++.h>

using namespace std;

char saida[1000000];

int main(){
    int t, c = 1;
    scanf ("%d", &t);
    while (t--){
        printf ("Case #%d: ", c++);
        string s;
        cin >> s;
        int i = 2000, j = 2002;
        saida[2001] = s[0];
        int k = 1;
        while (k < s.size()){
            if (s[k] >= saida[i + 1])
                saida[i--] = s[k];
            else
                saida[j++] = s[k];
            k++;
        }
        for (int k = i + 1; k < j; k++)
            printf ("%c", saida[k]);
        printf ("\n");
    }



    return 0;
}
