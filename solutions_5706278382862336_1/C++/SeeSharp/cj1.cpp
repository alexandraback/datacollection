#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

long long int getOBEB(long long int a,long long int b){
    long long int OBEB = 1;
    long long int yedek_a = a;
    long long int carpanlar[300];
    int c_s = 0;
    long long int sq = sqrt(a) + 1;
    for(long long int i=2;i<sq;i++){
        if(a%i == 0){
            carpanlar[c_s] = i;
            c_s++;
            a/=i;
            sq = sqrt(a) + 1;
            i--;
        }
    }
    if(a!=1){
        carpanlar[c_s] = a;
        c_s++;
    }
    a=yedek_a;

    for(int i=0;i<c_s;i++){
        if(b%carpanlar[i] == 0)
            OBEB*=carpanlar[i];
    }
    return OBEB;
}

bool isPowerOfTwo(long long int a){
    long long int temp = 1;
    for(int i=0;i<41;i++){
        if(a==temp)
            return true;
        if(a<temp)
            return false;
        temp*=2;
    }
    return false;
}

int main(){
    ifstream _if("in.txt");
    ofstream _of("out.txt");
    int n;
    _if >> n;
    for(int i=0;i < n; i++){
        string str = "";
        long long int p,q;
        int num = 0;
        _if >> str;
        string str1,str2;

        for(int j=0;j<str.length();j++){
            if(str[j]=='/'){
                str1 = str.substr(0,j);
                str2 = str.substr(j+1);
            }
        }
        string::size_type sz = 0;
        p=atoll(str1.c_str());
        q=atoll(str2.c_str());
        cout << p << " - " << q << endl;

        long long int ob = getOBEB(p,q);
        p/=ob;
        q/=ob;

        cout << ob << endl;
        cout << p << " - " << q << endl;

        if(!isPowerOfTwo(q))
        {
            _of << "Case #" << i+1 << ": impossible" << endl;
            continue;
        }
        for(int j=0;;j++){
            p*=2;
            if(p>=q){
                num = j+1;
                break;
            }
        }
        _of << "Case #" << i+1 << ": " << num << endl;
    }
}
