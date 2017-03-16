#include <bits/stdc++.h>

using namespace std;
int N,maxi = 0;
vector<string> v1,v2,sol1,sol2,left1,left2;


void Read(int k)
{
    cin >> N;
    string s1,s2;
    for(int i = 1; i <= N; ++i)
    {
        cin >> s1 >> s2;
        v1.push_back(s1);
        v2.push_back(s2);
    }
}

void check()
{
    int bad = 0;

    for(int i = 0; i < left1.size(); ++i)
        if(find(sol1.begin(),sol1.end(),left1[i]) == sol1.end() ||
           find(sol2.begin(),sol2.end(),left2[i]) == sol2.end())
                bad = 1;
    if(!bad)
        maxi = max(maxi,(int)left1.size());
}

void Back(int k)
{
    if(k == N)
    {
        check();
        return;
    }
    left1.push_back(v1[k]);
    left2.push_back(v2[k]);
    Back(k+1);
    left1.pop_back();
    left2.pop_back();


    sol1.push_back(v1[k]);
    sol2.push_back(v2[k]);
    Back(k+1);
    sol1.pop_back();
    sol2.pop_back();
}
void Clean()
{
    maxi = 0;
    v1.clear();
    v2.clear();
    sol1.clear();
    sol2.clear();
    left1.clear();
    left2.clear();
}

int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    int T;
    cin >> T;
    for(int tst = 1; tst <= T; ++tst)
    {
        Read(tst);
        Back(0);
        int k = maxi;
        Clean();
        printf("Case #%d: %d\n",tst,k);
    }
    return 0;
}
