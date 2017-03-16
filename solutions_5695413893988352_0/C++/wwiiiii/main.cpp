#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

char str1[20];
char str2[20];

int bestdiff;
vector<pair<int, int> > bestans;
void brute(int left, vector<int> &now)
{
    if(left == 0)
    {
        string a = string(str1);
        string b = string(str2);
        int nowidx = 0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i] == '?') {a[i] = now[nowidx] + '0'; nowidx++;}
        }
        for(int i=0;i<b.size();i++)
        {
            if(b[i] == '?') {b[i] = now[nowidx] + '0'; nowidx++;}
        }
        int c = atoi(a.c_str()); int d = atoi(b.c_str());
        int diff = c-d;
        if(diff < 0)diff = -diff;
        if(diff == bestdiff) bestans.push_back(make_pair(c,d));
        if(diff < bestdiff){
            bestdiff = diff;
            //printf("%d %d diff %d\n",c,d,diff);
            bestans.clear();
            bestans.push_back(make_pair(c,d));
        }
        return;
    }
    for(int i=0;i<=9;i++)
    {
        now.push_back(i);
        brute(left-1,now);
        now.pop_back();
    }
}

void solve(int testn)
{
    bestdiff = 987654321;
    int unknown = 0;
    scanf("%s %s\n",str1, str2);
    int len = strlen(str1);
    for(int i=0;i<len;i++)
    {
        if(str1[i] == '?') unknown++;
        if(str2[i] == '?') unknown++;
    }
    vector<int> temp;
    brute(unknown, temp);
    sort(bestans.begin(), bestans.end());
    char ans1[25]; itoa(bestans[0].first, ans1, 10);
    char ans2[25]; itoa(bestans[0].second, ans2 , 10);
    printf("Case #%d: ",testn);
    for(int i=strlen(ans1);i<len;i++)printf("0");
    printf("%d ",bestans[0].first);
    for(int i=strlen(ans2);i<len;i++)printf("0");
    printf("%d\n",bestans[0].second);

}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t; scanf("%d",&t);
    for(int i=1;i<=t;i++) solve(i);
    return 0;
}
