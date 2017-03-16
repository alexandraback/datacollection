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
    fin>>T;
    for(t=0;t<T;t++){
        long long int K,C,S;
        fin>>K>>C>>S;
        //S == K
        fout<<"Case #"<<t+1<<": ";
        long long int i;
        fout<<1<<" ";
        for(i=2;i<=S;i++){
            fout<<(i-1)*myPow(K,C-1)+1<<" ";
        }
        fout<<endl;
    }
    fin.close();
    fout.close();

}