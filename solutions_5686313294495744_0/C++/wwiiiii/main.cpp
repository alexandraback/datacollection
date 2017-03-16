#include <set>
#include <map>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
struct sp{string a, b;};
int n;
sp arr[1010];
int isFake[1010];
int best;
void brute(int now, vector<int>&con, int n)
{
    if(now == n)
    {
        set<string> first; set<string> second;
        for(int i=0;i<con.size();i++)
        {
            first.insert(arr[con[i]].a);
            second.insert(arr[con[i]].b);
        }
        for(int i=0;i<n;i++)
        {
            if(first.find(arr[i].a) == first.end()) return;
            if(second.find(arr[i].b) == second.end()) return;
        }
        if(best > con.size()) best = con.size();
        return;
    }
    brute(now+1, con, n);
    con.push_back(now);
    brute(now+1, con, n);
    con.pop_back();
}

void solve(int testn)
{
    int ans = 0;
    char str1[25]; char str2[25];
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s %s\n",str1,str2);
        string a = arr[i].a = string(str1);
        string b = arr[i].b = string(str2);
    }
    vector<int> temp; best = 435465;
    brute(0, temp, n);

    printf("Case #%d: %d\n",testn, n-best);
}

int main()
{
    freopen("C-small-attempt1.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t; scanf("%d\n",&t);
    for(int i=1;i<=t;i++) solve(i);
    return 0;
}
