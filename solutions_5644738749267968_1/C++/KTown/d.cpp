#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

#define K 1000

using namespace std;

int main(){
    int tests;
    cin >> tests;
    for(int i1 = 0; i1 < tests; i1++){
        int blocks;
        cin >> blocks;
        double tmp;
        vector<int> nBlocks;
        vector<int> kBlocks;
        for(int i2 = 0; i2 < blocks; i2++){
            cin >> tmp;
            nBlocks.push_back(tmp*K*K);
        }
        for(int i2 = 0; i2 < blocks; i2++){
            cin >> tmp;
            kBlocks.push_back(tmp*K*K);
        }
        sort(nBlocks.begin(), nBlocks.end());
        sort(kBlocks.begin(), kBlocks.end());

        cout << "Case #" << i1 + 1 << ": ";
        //deciet
        int kWins = 0;
        int nWins = 0;
        int i2 = 0; int i3 = 0;
        while(i2 < blocks && i3 < blocks){
            if(nBlocks[i2] < kBlocks[i3])
                i2++;
            else{
                i2++; i3++;
                nWins++;
            }
        }
        cout << nWins << " ";
        //regular
        kWins = 0;
        nWins = 0;
        i2 = 0; i3 = 0;
        while(i2 < blocks && i3 < blocks){
            if(kBlocks[i3] < nBlocks[i2])
                i3++;
            else{
                i2++; i3++;
                kWins++;
            }
        }
        cout << blocks - kWins << endl;
    }
}
