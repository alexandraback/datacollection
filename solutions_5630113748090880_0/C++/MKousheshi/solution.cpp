#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i =0;i!=n;i++){
        int N;
        cin >> N;
        map<int,int> nums;
        vector<int> keys;
        for(int j=0;j!=(2*N-1)*N;j++){
            int x;
            cin >> x;
            if(nums.find(x)==nums.end()){
                keys.push_back(x);
                nums.insert(pair<int,int>(x,1));
                continue;
            }
            nums.find(x)->second++;
        }
        vector<int> ans;
        for(int j=0;j!=keys.size();j++){
            if(nums[keys[j]]%2 != 0){
                ans.push_back(keys[j]);
            }
        }
        sort(ans.begin(),ans.end());
        cout << "Case #" << i+1 << ":";
        for(int j=0;j!=ans.size();j++){
            cout << " " << ans[j];
        }
        cout << endl;

    }
    return 0;
}