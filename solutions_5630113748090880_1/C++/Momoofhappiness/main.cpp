#include <bits/stdc++.h>
#include <fstream>
int rekt[2500];

using namespace std;
int main(){
    int t=0, n=0, temp=0;
    fstream potato;
    ofstream optato;
    optato.open("Answer.txt");
    potato.open("B-large.in");
    potato >> t;
    for(int bah=0; bah<t; bah++){
        vector<int> ans;
        potato >> n;
        for(int i=0; i<(2*n-1)*n; i++){
            potato >> temp;
            rekt[temp-1]++;
        }
        for(int i=0; i<2500; i++){
            if(rekt[i]%2==1){
                ans.push_back(i+1);
            }
            rekt[i]=0;
        }
        sort(ans.begin(), ans.end());
        optato << "Case #" << bah+1 << ":";
        for(int i=0; i<ans.size(); i++){
            optato << " " << ans[i];
        }
        optato << "\n";
    }
optato.close();
}
