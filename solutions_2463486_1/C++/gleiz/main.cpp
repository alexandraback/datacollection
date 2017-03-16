#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int isvalid(long long x){
    char buff[128] = {0};
    int len = 0;

    while (x){
        buff[len++] = x%10;
        x/=10;
    }

    for (int i = 0; i<len/2; i++){
        if (buff[i] != buff[len-i-1]){
            return 0;
        }
    }
    return 1;
}

int main()
{
    int T = 0;
    long long A = 0, B = 0;
    long long storge[128] = {0};
    int cnt = 0;

    for (long long i = 1; i<=50000000LL; i++){
        if (isvalid(i) && isvalid(i*i)){
            storge[cnt++] = i*i;
            cerr << i << " " << (i*i) << endl;
        }
    }

    cerr << "READY" << endl;

    cin >> T;
    for (int cas = 1; cas <= T; cas++){
        cin >> A >> B;
        int res = 0;
        for (int i = 0; i<cnt; i++){
            if (storge[i] >= A && storge[i] <= B)
                res++;
        }
        cout << "Case #" << cas << ": " << res << endl;
    }
    return 0;
}
