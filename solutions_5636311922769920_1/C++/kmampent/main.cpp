#include <bits/stdc++.h>

using namespace std;

long long int myPow(long long int k, long long int c){
    long long int res = 1;
    int i;
    for(i=1;i<=c;i++){
        res = res * k;
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    ifstream fin;
    fin.open("in.txt");
    ofstream fout;
    fout.open("out.txt");
    int t, T;
    long long int i;
    fin>>T;
    for(t=0;t<T;t++){
        long long int K,C,S;
        fin>>K>>C>>S;
        fout << "Case #" << t + 1 << ": ";
        if(C == 1){
            if(S < K) fout<<"IMPOSSIBLE"<<endl;
            else{
                for(i=1;i<=K;i++) fout<<i<<" ";
                fout<<endl;
                continue;
            }
        }
        else {
            long long int up;
            if(K%2 == 0) up = K/2;
            else up = (K-1)/2 + 1;
            if(S < up){
                fout<<"IMPOSSIBLE"<<endl;
            }
            else {
                fout << 2 << " ";
                long long int cur = 3;
                for (i = 2; i <= up; i++) {
                    long long int tmp = (cur - 1) * myPow(K, C - 1) + cur + 1;
                    if(tmp > myPow(K, C)){
                        tmp = myPow(K,C);
                    }
                    fout << tmp << " ";
                    cur += 2;
                }
                fout << endl;
            }
        }
    }
    fin.close();
    fout.close();
}