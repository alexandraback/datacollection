#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int N;
vector <pair<string, string> > tot;

int res;

void dfs(int idx, vector <pair<string, string> > &tot2,  vector <pair<string, string> > &st, vector <string> &left, vector <string> &right) {
    int cnt = 0;
    //cout<<N<<"hh"<<endl;
    //for (auto x = st.begin(); x != st.end(); x++)
        //cout<<x->first<<" "<<x->second<<endl;
    for (int j = 0; j < tot2.size(); j++) {
        if (find(left.begin(), left.end(), tot2[j].first) != left.end() &&
            find(right.begin(), right.end(), tot2[j].second) != right.end() )
            cnt++;
    }
    res = max(res, cnt);
    if (idx >= N)   return;
    for (int i = idx; i < N; i++) {
        st.push_back(tot[i]);
        left.push_back(tot[i].first);
        right.push_back(tot[i].second);

        auto iter = find(tot2.begin(), tot2.end(), tot[i]);
        tot2.erase(iter);
        dfs(i + 1, tot2, st, left, right);
        /*auto iter = st.find(tot[i]);
        if (iter != st.end())
            st.erase(iter);
        auto iter2 = left.find(tot[i].first);
        if (iter2 != left.end())
            left.erase(iter2);
        auto iter3 = right.find(tot[i].second);
        if (iter3 != right.end())
            right.erase(iter3);*/
        st.pop_back();
        left.pop_back();
        right.pop_back();
        tot2.push_back(tot[i]);
        //cout<<"wa"<<endl;
        //dfs(i + 1, st, left, right);
    }
    return;
}

int main()
{
    int T;
    cin>>T;
    int cnt = 0;

    while (T--) {
        cnt++;
        cin>>N;
        tot.clear();
        for (int i = 0; i < N; i++) {
            string a, b;
            cin>>a>>b;
            //tot.insert(pair<string, string> (a, b));
            tot.push_back(pair<string, string> (a, b));
        }
        vector <pair<string, string> > st;
        vector <pair<string, string> > tot2(tot);
        vector <string> left;
        vector <string> right;
        res = 0;
        dfs(0, tot2, st, left, right);
        printf("Case #%d: %d\n", cnt, res);
    }
    return 0;
}

