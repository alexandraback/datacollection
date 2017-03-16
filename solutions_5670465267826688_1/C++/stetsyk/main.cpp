#include <bits\stdc++.h>
using namespace std;
typedef long long ll;
int cnt(int fir, int sec){
    if(fir == 3){
        return sec;
    }
    else if(sec == 3){
        return fir;
    }
    else if(fir == 0 && sec == 1){
        return 2;
    }
    else if(fir == 1 && sec == 0){
        return 2;
    }
    else if(fir == 1 && sec == 2){
        return 0;
    }
    else if(fir == 2 && sec == 1){
        return 0;
    }
    else if(fir == 0 && sec == 2){
        return 1;
    }
    else if(fir == 2 && sec == 0){
        return 1;
    }
    else{
        return 3;
    }
}
int sgn(int fir, int sec){
    if(fir == 3){
        return 1;
    }
    else if(sec == 3){
        return 1;
    }
    else if(fir == 0 && sec == 1){
        return 1;
    }
    else if(fir == 1 && sec == 0){
        return -1;
    }
    else if(fir == 1 && sec == 2){
        return 1;
    }
    else if(fir == 2 && sec == 1){
        return -1;
    }
    else if(fir == 0 && sec == 2){
        return -1;
    }
    else if(fir == 2 && sec == 0){
        return 1;
    }
    else{
        return -1;
    }
}
int tr(char c){
    if(c == 'i') return 0;
    if(c == 'j') return 1;
    if(c == 'k') return 2;
}
int main(){
    freopen("C-large.in", "r", stdin); freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for(int qr = 1; qr <= T; ++qr){
        string s;
        int l;
        ll x;
        cin >> l >> x;
        cin >> s;
        ll dlin = l * x;
        ll ost = min(dlin, (ll)20 * l);
        int sg = 1;
        int an = 3;
        for(int i = 0; i < l; ++i){
            if(!i){
                an = tr(s[i]);
            }
            else{
                sg *= sgn(an, tr(s[i]));
                an = cnt(an, tr(s[i]));
            }
        }
        if(x % 2 == 0) sg = 1;
        int flag = 0;
        if(an <= 2){
            if(x % 2 != 0){
                flag = 1;
            }
            else{
                if(x % 4 == 0){
                    if(sg == 1){
                        flag = 1;
                    }
                }
                else{
                    if(sg == -1){
                        flag = 1;
                    }
                }
            }
        }
        if(an == 3){
            if(sg == 1){
                flag = 1;
            }
        }
        if(flag){
            cout << "Case #" << qr << ": " << "NO" << "\n";
            continue;
        }
        ost = min(dlin, (ll)20 * l);
        sg = 1;
        an = 3;
        int flag0 = 1;
        int flag1 = 1;
        s = s + s + s + s + s;
        s = s + s;
        s = s + s;
        for(int i = 0; i < ost; ++i){
            if(!i){
                an = tr(s[i]);
            }
            else{
                sg *= sgn(an, tr(s[i]));
                an = cnt(an, tr(s[i]));
            }
            if(flag0 && sg == 1 && an == 0){
                flag0 = 0;
            }
            else if(!flag0 && sg == 1 && an == 2){
                flag1 = 0;
                break;
            }
        }
        if(!flag0 && !flag1)
            cout << "Case #" << qr << ": " << "YES" << "\n";
        else{
            cout << "Case #" << qr << ": " << "NO" << "\n";
        }
    }
    return 0;
}
