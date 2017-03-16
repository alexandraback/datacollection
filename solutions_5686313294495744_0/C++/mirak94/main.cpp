#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int n;

int T ;
typedef pair<string, string> ss;
int main(){
    freopen("/Users/Masoud/Desktop/C-small-attempt2.in.txt", "r", stdin);
    freopen("/Users/Masoud/Desktop/out.txt", "w", stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        scanf("%d",&n);
        vector<ss>v(n);
        for(int i =0;i<n;i++){
            char first[120],second[120];
            scanf("%s %s",first,second);
            string f =first, s = second;
            v[i]={f,s};
        }
        sort(v.begin(),v.end());
        vector<vector<ss> >strs;
        vector<ss>unq;
        for(int i =0;i<v.size();i++){
            int j =i+1;
            while (j<v.size()&&v[j].first==v[i].first) {
                j++;
            }
            vector<ss>tmp;
            for (int k=i; k<j; k++) {
                tmp.push_back(v[k]);
            }
            i=j-1;
            if (tmp.size()==1) {
                unq.push_back(v[i]);
                continue;
            }
            strs.push_back(tmp);
        }
        vector<int>nums;
        for (int i =0; i<strs.size(); i++) {
            nums.push_back(i);
        }
        int mx = -1;
        do{
            int cheaters=0;
            map<string, bool>first;
            map<string,bool>second;
            for (int i=0; i<unq.size(); i++) {
                first[unq[i].first]=true;
                second[unq[i].second]=true;
            }
            for (int i =0; i<strs.size(); i++) {
                for (int j=0; j<strs[nums[i]].size(); j++) {
                    ss front = strs[nums[i]][j];
                    if (first[front.first]&&second[front.second]) {
                        cheaters++;
                    }else{
                        first[front.first]=true;
                        second[front.second]=true;
                    }
                }
            }
            mx = max(mx,cheaters);
        }while(next_permutation(nums.begin(),nums.end()));
        printf("Case #%d: %d\n",t,mx);
    }
    return 0;
}

