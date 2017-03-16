#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main() {
    FILE* f;
    f = fopen("PA.txt", "w");
    int T, Count = 1;
    int ck[1010] ,s[2020];
    int i;
    double X, N, value, num, total;
    bool tt;
    cin >> T;
    while(T--) {
        cin >> N;
        num = N;
        X = 0;
        tt = 0;
        memset(ck, 0, sizeof(ck));
        for(i = 1;i <= N;i++) {
            cin >> s[i];
            X += s[i];
        }
        value = X * 2 / num;
        total = value * num;
        for(i = 1;i <= N;i++) {
            if(s[i] > value) {
                num--;
                ck[i] = 1;
                total -= s[i];
            }
        }
        value = total / num;
        fprintf(f, "Case #%d:", Count++);
        for(i = 1;i <= N;i++) {
            if(ck[i]) fprintf(f, " 0.000000");
            else fprintf(f, " %f", (value-s[i]) / (X) * 100);
        }
        fprintf(f, "\n");
        cout << X << " " << num;
    }
}
