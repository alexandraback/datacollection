#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <vector>
#include <iomanip>

using namespace std;

int a[110][110];
int colmax[110];
int rowmax[110];

typedef long long LL;

const int N = 10000010;

LL low_sqrt(LL val)
{
    LL l = 0, r = N;
    while (l + 1 < r){
        LL mid = (l + r) / 2;
        if (mid * mid >= val){
            r = mid;
        }
        else l = mid;
    }
    return r;
}

LL high_sqrt(LL val)
{
    LL l = 0, r = N;
    while (l + 1 < r){
        LL mid = (l + r) / 2;
        if (mid * mid <= val){
            l = mid;
        }
        else r = mid;
    }
    return l;
}

char bits[20];
bool check (LL val)
{
    int n = 0;
    while (val){
        bits[n++] = val % 10;
        val /= 10;
    }
    int i = 0, j = n - 1;
    while (i < j){
        if (bits[i] != bits[j]) return false;
        i++, j--;
    }
    return true;
}

bool flag[N];
int main()
{
    string file;
    cin>>file;
   
    FILE* fp_in = fopen(file.c_str(), "r");
    FILE* fp_out = fopen("c_out.txt", "w");
    int T;
    fscanf(fp_in, "%d", &T);
    
    for (LL i = 1; i < N; i++)
        flag[i] = (check(i) && check(i * i));
    
    for (int cas = 1; cas <= T; cas++){
        LL A, B;
        fscanf(fp_in, "%lld%lld", &A, &B);
        LL a = low_sqrt(A), b = high_sqrt(B);
        int ans = 0;
        for (LL i = a; i <= b; i++){
            if (A <= i * i && i * i <= B)
                ans += flag[i];
        }
        
        //cout<<"A = "<<A<<" "<<"B = "<<B<<endl;
        //cout<<"a = "<<a<<" "<<"b = "<<b<<endl;
        
        fprintf(fp_out, "Case #%d: %d\n", cas, ans);
    }
    fclose(fp_in);
    fclose(fp_out);
    return 0;
}
