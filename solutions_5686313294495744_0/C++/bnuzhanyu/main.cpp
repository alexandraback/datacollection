#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <random>
#include <map>
#include <functional>
using namespace std;

void use_file(const std::string& s = "")
{
    if (s != "std" && s != "") {
        freopen((s+".in").c_str(), "r", stdin);
        freopen((s+".out").c_str(), "w", stdout);
    }
}

map<string, int> mpa, mpb;
vector<pair<int, int> > vp;

int calc(int n)
{
    int ans = 0;
    for (int i = 1; i < (1<<n); i++){
        set<int> seta, setb;
        int cheat = 0;
        for (int k = 0; k < n; k++){
            if ((i >> k) & 1){ //no cheat
                seta.insert(vp[k].first);
                setb.insert(vp[k].second);
            }else{
                cheat++;
            }
        }
        if (seta.size() == mpa.size() && setb.size() == mpb.size()){
            ans = max(ans, cheat);
        }
    }
    return ans;
}

int main() {
    use_file("C1");
    int T, N;
    cin >> T;

    std::string a, b;
    for(int ca = 1; ca <= T; ca++){
        cin >> N;
        mpa.clear();
        mpb.clear();
        int ida = 0, idb  = 0;
        vp.clear();
        for (int i = 0; i < N; i++){
            cin >> a >> b;
            if (mpa.count(a) == 0){
                mpa[a] = ida++;
            }
            if (mpb.count(b) == 0){
                mpb[b] = idb++;
            }
            vp.push_back(make_pair(mpa[a], mpb[b]));
        }
        cout << "Case #" << ca << ": "  << calc(N) << std::endl;
    }
	return 0;
}
