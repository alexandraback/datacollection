#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

const int Maxn = 1010;
deque<char> deq;
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int N;
    string s;
    cin>>N;
    for(int cas = 1;cas <= N;cas ++)
    {
        cin>>s;
        int len = s.length();
        deq.clear();
        cout<<"Case #"<<cas<<": ";
        deq.push_back(s[0]);
        for(int i = 1;i < len;i ++)
        {
            if(s[i] >= deq.front())
                deq.push_front(s[i]);
            else
                deq.push_back(s[i]);
        }
        while(!deq.empty())
        {
            cout<<deq.front();
            deq.pop_front();
        }

        cout<<endl;

    }

    return 0;
}
