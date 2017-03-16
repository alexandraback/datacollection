#include <bits/stdc++.h>

using namespace std;

vector<long long int> bits;
vector<long long int> bases(9);
ofstream fout;

bool check(){

    long long int base;
    int i = 0;
    int j;
    for(base=2;base<=10;base++){
        long long int tmp = 1;
        bases[i] = 0;
        for(j=bits.size()-1;j>=0;j--){
            bases[i] += tmp*bits[j];
            tmp *= base;
        }
        i++;
    }

    bool ok = true;
    for(i=0;i<9;i++){
        bool tmp = false;
        int stop = 0;
        for(j=2;j<bases[i];j++){
            if(bases[i]%j == 0){
                tmp = true;
                bases[i] = j;
                break;
            }
            stop++;
            if(stop==100){
                return false;
            }
        }
        if(tmp) continue;
        ok = false;
        break;
    }

    if(ok){
        for(i=0;i<bits.size();i++) fout<<bits[i];
        fout<<" ";
        for(i=0;i<9;i++){
            fout<<bases[i]<<" ";
        }
        fout<<endl;
    }

    return ok;

}

int main() {
    int J = 50;
    int N = 16;
    long long int one = 1;
    long long int bound = one<<N-1;
    bits.resize(N);
    bits[0] = 1;
    fout.open("out.txt",ios_base::out);
    fout<<"Case #1:"<<endl;
    bits[N-1] = 1;
    int n;
    int i;
    int end = 0;
    if(check()){
        end++;
    }
    for(n=1;n<=bound;n++){
        long long int x = n;
        i = N-2;
        while (x) {
            bits[i] = x%2;
            x = x / 2;
            i--;
        }
        if(check()){
            end++;
        }
        if(end == J) break;
    }
    fout.close();
}