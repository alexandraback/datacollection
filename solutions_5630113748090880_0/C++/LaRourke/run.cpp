#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

int main(){
    int T; cin>>T;
    for(int t=0;t<T;t++){
        int N; cin>>N;
        int heights[2501] = {};
        for(int i=0;i<2*N*N-N;i++){
            int x; cin>>x;
            heights[x]++;
        }
        cout<<"Case #"<<t+1<<": ";
        for(int i=1;i<=2500;i++){
            if (heights[i]%2==1) cout<<i<<' ';
        }
        cout<<endl;
    }
}