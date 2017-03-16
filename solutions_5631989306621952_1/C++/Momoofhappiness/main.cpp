#include <bits/stdc++.h>
#include <fstream>

using namespace std;
int main(){
    int n=0;
    string meh = "";
    string ans = "";
    fstream potato;
    ofstream optato;
    optato.open("Answer.txt");
    potato.open("A-large.in");
    potato >> n;
    for(int i=0; i<n; i++){
        potato >> meh;
        ans = "";
        for(int k=0; k<meh.size(); k++){
            if(meh[k]>= ans.front()){
                ans.insert(0, 1, meh[k]);
            }else{
                ans.push_back(meh[k]);
            }
        }
        optato << "Case #" << i+1 << ": " << ans << "\n";
    }
optato.close();
}
