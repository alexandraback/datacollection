#include<bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define MP make_pair
#define PB push_back

#define N 1000

int a[N][N];
char ch[] = {'.', '*', 'c'};
int r, c, m;

inline void rot(){
    for(int i = 0; i < r; i++){
        for(int j = i + 1; j < c; j++){
            swap(a[i][j], a[j][i]);
        }
    }
}

inline bool pos(){
    int i, j, rem;
    if(r == 1){
        a[0][0] = 2;
        for(i = 1; i < c - m; i++){
            a[0][i] = 0;
        }
        for(i = c - m; i < c; i++){
            a[0][i] = 1;
        }
        return true;
    }
    if(m == r * c - 2){
        return false;
    }
    if(m == (r * c) - 1){
        a[0][0] = 2;
        for(j = 1; j < c; j++){
            a[0][j] = 1;
        }
        for(i = 1; i < r; i++){
            for(j = 0; j < c; j++){
                a[i][j] = 1;
            }
        }
        return true;
    }
    if(r == 2){
        if(m % 2 == 0){
            a[0][0] = 2;
            a[1][0] = 0;
            m /= 2;
            for(i = 1; i < c - m; i++){
                a[0][i] = 0;
                a[1][i] = 0;
            }
            for(i = c - m; i < c; i++){
                a[0][i] = 1;
                a[1][i] = 1;
            }
            return true;
        }
        else{
            return false;
        }
    }
    rem = r * c - m;
    if(rem % 2 == 1 && rem < 8){
        return false;
    }
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            a[i][j] = 1;
        }
    }
    if(rem <= c * 2){
        if(rem & 1){
            rem -= 3;
            a[2][0] = 0;
            a[2][1] = 0;
            a[2][2] = 0;
        }
        for(j = 0; j < c; j++){
            if(rem == 0){
                break;
            }
            a[0][j] = 0;
            a[1][j] = 0;
            rem -= 2;
        }
    }
    else{
        for(j = 0; j < c; j++){
            a[0][j] = 0;
            a[1][j] = 0;
            rem -= 2;
        }
        for(i = 2; i < r; i++){
            if(rem == 1){
                if(i == 2){
                    a[i][0] = 0;
                    a[i][1] = 0;
                    a[i][2] = 0;
                    a[i - 1][c - 1] = 1;
                    a[i - 2][c - 1] = 1;
                }
                else{
                    a[i][0] = 0;
                    a[i][1] = 0;
                    a[i - 1][c - 1] = 1;
                }
                break;
            }
            else{
                for(j = 0; j < c; j++){
                    if(rem == 0){
                        break;
                    }
                    a[i][j] = 0;
                    rem--;
                }
            }
        }
    }
    a[0][0] = 2;
    return true;
}

inline void solve(){
    bool flag;
    cin>>r>>c>>m;
    if(r > c){
        swap(r, c);
        flag = true;
    }
    else{
        flag = false;
    }
    if(!pos()){
        printf("Impossible\n");
    }
    else{
        if(flag == true){
            rot();
            swap(r, c);
        }
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                printf("%c", ch[a[i][j]]);
            }
            printf("\n");
        }
    }
    return;
}

int main(){
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t = 1;
    cin>>t;
    for(int i = 0; i < t; i++){
        printf("Case #%d:\n", i + 1);
        solve();
    }
    return 0;
}
