#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <locale>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <climits>
#include <cfloat>
#include <map>
#include <functional>
using namespace std;
const double PI=acos(-1);

int k, l, s, longest_banana, case_cnt, banana_cnt;
string candi, goal, makeStr;

void howManyBanana()
{
    int cnt = 0;
    for(int stt=0; stt<=s-l; stt++)
    {
        string tmp = "";
        for(int i=stt, cnt=0; cnt<l; i++, cnt++) tmp += makeStr[i]; // l만큼 만들어봐서
        if(tmp == goal)
        {
            banana_cnt++;
            cnt++;
        }
    }
    longest_banana = max(longest_banana, cnt);
}

void dfs(int idx)
{
    if(idx==s) // 다 만들었다
    {
        case_cnt++;
        howManyBanana();
        return;
    }
    
    for(int i=0; i<k; i++)
    {
        makeStr += candi[i];
        dfs(idx+1);
        makeStr.erase(makeStr.end()-1);
    }
}

int main() // Google Codejam 1C Round
{
    freopen ("B-small-attempt0.in.txt", "r", stdin);
    freopen ("output-small.txt", "w", stdout);
    
    int tc_N;
    scanf("%d", &tc_N);
    for(int tc=0; tc<tc_N; tc++)
    {
        scanf("%d %d %d\n", &k, &l, &s);
        cin >> candi >> goal;
        makeStr = "";
        longest_banana = case_cnt = banana_cnt = 0; // 초기화
        
        dfs(0);

        printf("Case #%d: %lf\n", tc+1, (double)longest_banana - (double)banana_cnt/(double)case_cnt);
    }
    
    fclose(stdin);
    fclose(stdout);
    
    return 0;
}