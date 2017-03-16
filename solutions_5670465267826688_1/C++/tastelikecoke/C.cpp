#include <iostream>
using namespace std;
long long quater[10][10] = {};
long long q(long long a, long long b){
    if(a < 0 and  b < 0){
        a = -a;
        b = -b;
        return quater[a][b];
    }
    else if(a < 0){
        a = -a;
        return -quater[a][b];
    }
    else if(b < 0){        
        b = -b;
        return -quater[a][b];
    }
    else{
        return quater[a][b];
    }
}
int main(){
    quater[2][3] = 4;
    quater[3][4] = 2;
    quater[4][2] = 3;
    quater[4][3] = -2;
    quater[2][4] = -3;
    quater[3][2] = -4;
    quater[4][4] = -1;
    quater[3][3] = -1;
    quater[2][2] = -1;
    quater[1][1] = 1;
    quater[2][1] = 2;
    quater[3][1] = 3;
    quater[4][1] = 4;
    quater[1][2] = 2;
    quater[1][3] = 3;
    quater[1][4] = 4;
    long long cases = 0;
    cin >> cases;
    for(long long c=0;c<cases;c++){
        long long len = 0, repeat = 0;
        cin >> len >> repeat;
        string s;
        cin >> s;
        cout << "Case #" << c+1 << ": ";
        if(repeat > 200) repeat = 100 + (repeat % 4);
        long long equiv = 1;
        for(long long i=0;i<len;i++){
            equiv = q(equiv,(s[i]-'i'+2));
        }
        long long vals[10] = {};
        vals[0] = 1;
        for(long long i=1;i<=4;i++){
            vals[i] = q(vals[i-1],equiv);
        }
        if(vals[repeat % 4] != -1){
            cout << "NO" << endl;
            continue;
        }
        long long minsi = -1;
        long long cur = 1;
        for(long long i=0;i<len;i++){
            cur = q(cur, (s[i]-'i'+2));
            for(long long j=0;j<=4;j++){
                long long app = q(vals[j],cur);
                if(app == 2){
                    if(minsi == -1) minsi = i+1+j*len;
                    minsi = min(minsi, i+1+j*len);
                }
            }
        }
        cur = 1;
        long long minsk = -1;
        for(long long i=len-1;i>=0;i--){
            cur = q((s[i]-'i'+2),cur);
            for(long long j=0;j<=4;j++){
                long long app = q(cur,vals[j]);
                if(app == 4){
                    if(minsk == -1) minsk = (len-i)+j*len;
                    minsk = min(minsk, (len-i)+j*len);
                }
            }
        }
        if(minsi == -1 or minsk == -1){
            cout << "NO" << endl;
        }
        else if(minsi+minsk < repeat*len){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }
}