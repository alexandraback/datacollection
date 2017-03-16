#include <bits/stdc++.h>
#include <fstream>
int thingy[1050];
int used[1050];
int n;
using namespace std;
int checky(int k){
    int magx=0, tmep=0;
    for(int i=0; i<n; i++){
        if(thingy[i]==k && used[i]==0){
                tmep=0;
            if(used[i]==0){
                used[i]=1;
                tmep=1;
                }
            magx = max(magx, checky(i)+1);
        if(tmep==1){
            used[i]=0;
        }
        }
    }
    return magx;
}
int main(){
    int t=0, temp=0, starch=0, magx=0, prev = 0, arns=0;
    fstream potato;
    ofstream optato;
    optato.open("Answer.txt");
    potato.open("C-small-attempt0 (1).in");
    potato >> t;
    for(int bah=0; bah<t; bah++){
        potato >> n;
        for(int i=0; i<n; i++){
            potato >> temp;
            thingy[i] = temp-1;
        }
        magx=0;
        for(int i=0; i<n; i++){
                for(int k=0; k<1050; k++){
                    used[k]=0;
                }
                starch = i;
                temp = i;
                prev=i;
                arns=0;
            for(int k=0; k<n+1; k++){
                if(thingy[temp] == prev){
                    used[temp] = 1;
                    arns = k+checky(thingy[temp]);
                    break;
                }
                if(thingy[temp]==starch){
                    arns = k+1;
                    break;
                }
                if(used[thingy[temp]]==1){
                    break;
                }
                used[temp] = 1;
                prev=temp;
                temp = thingy[temp];
            }
        magx = max(magx, arns);
        }
        optato << "Case #" << bah+1 << ": " << magx << "\n";
    }
optato.close();
}
