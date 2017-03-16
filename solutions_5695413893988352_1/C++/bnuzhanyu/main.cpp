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
typedef long long ll;

//a > b
ll resa, resb, diff;
void cmp(ll dif, ll a,ll b, bool afirst)
{
    //cout << "diff:" << dif << " a: " << a << " b:" << b << " " << afirst << std::endl;
    if (afirst && (diff > dif
        || (diff == dif && resa > a)
        || (diff == dif && resa == a && resb > b))){
        diff = dif;
        resa = a;
        resb = b;
    }
    if (!afirst && (diff > dif
        || (diff == dif && resa > b)
        || (diff == dif && resa == b && resb > a))){
        diff = dif;
        resa = b;
        resb = a;
    }
}

void dfs(ll ra, ll rb, string &a, string& b, int depth, bool issame, bool afirst)
{
    if (depth == a.size()){
        ll dif = ra - rb;
        cmp(dif, ra, rb, afirst);
        return;
    }
    if (a[depth] == '?' && b[depth] == '?'){
        if (issame){
            //0, 0
            dfs(ra*10, rb*10, a, b, depth+1, issame,afirst);
            dfs(ra*10 + 1, rb * 10, a, b, depth+1, false,afirst);
        }
        else{
            //0, 9
            dfs(ra*10 + 0, rb * 10 + 9, a, b, depth + 1, false,afirst);
        }

    }else if (a[depth] == '?'){
        int pb = b[depth] - '0';
        if (issame){
            dfs(ra*10 + pb, rb*10 + pb, a, b, depth+1, issame,afirst);
            if (pb != 9)
                dfs(ra*10 + pb + 1, rb*10 + pb, a, b, depth+1, false,afirst);

        }else{
            dfs(ra*10, rb*10 + pb, a, b, depth+1, false,afirst);
        }
    }else if (b[depth] == '?'){
        int pa = a[depth] - '0';
        if (issame){
            dfs(ra*10 + pa, rb*10 + pa, a, b, depth+1, issame,afirst);
            if (pa != 0)
                dfs(ra*10 + pa, rb*10 + pa - 1, a, b, depth+1, false,afirst);
        }else{
            dfs(ra*10 + pa, rb*10 + 9, a, b, depth+1, issame,afirst);
        }
    }else{
        int pa = a[depth] - '0';
        int pb = b[depth] - '0';
        if (issame && pb > pa){
            return;
        }
        dfs(ra*10 + pa, rb*10 + pb, a, b, depth+1, issame && (pa == pb),afirst);
    }
}

std::string output(ll i, int s)
{
    string str;
    for (int j = 0; j < s; j++){
        str.push_back(i % 10 + '0');
        i /= 10;
    }
    reverse(str.begin(), str.end());
    return str;
}

int main() {
    use_file("B2");
    int T, N;
    cin >> T;

    std::string a, b;
    for(int ca = 1; ca <= T; ca++){
        cin >> a >> b;
        diff = 1000000000000000000LL;
        dfs(0, 0, a, b, 0, true, true);
        dfs(0, 0, b, a, 0, true, false);

        cout << "Case #" << ca << ": "  << output(resa, a.size()) << " "  << output(resb, b.size())<< std::endl;
    }
	return 0;
}
