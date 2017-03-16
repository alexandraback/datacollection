#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include <cstring>


using namespace std;
int haha[2000001][7];
void span(int n){
    int kk = 10;
    int sum = 0;
    while(n / kk != 0){
        kk *= 10;
    }
    int k = 10;
    while(n / k != 0){
        int z = n / k;
        int zz = n % k;
        if(zz / (k / 10) == 0){
            k *= 10;
            continue;
        }
        else {
            int num = z + zz * (kk / k);
            if(num == n)return;
            else if(num > 2000000);
            else if(num > n)haha[n][sum ++] = num;
        }
        k *= 10;
    }
}

int main(){
    memset(haha,-1,sizeof(haha));

    for(int i = 1;i <= 2000000;i ++){
        span(i);
    }
    //ifstream in("C:\\Users\\Administrator\\Desktop\\slyar.in");
    int T;
    //cout << T << endl;
    cin >> T;
    //cout << T << endl;
    for(int i = 1;i <= T;i ++){
        int a,b;
        cin >> a >> b;
        int sum = 0;
        for(int j = a;j <= b;j ++){
            for(int z = 0;z < 7 && haha[j][z] != -1;z ++){
                if(haha[j][z] <= b)sum ++;
            }
        }
        cout << "Case #" << i << ": " << sum << endl;
    }
    //in.close();
}
