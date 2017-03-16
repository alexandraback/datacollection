#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int t;
    fin >> t;
    int T=t;

    while(t--){
        fout<<"Case #"<<T-t<<": ";
        string s;
        fin>>s;
        deque<char> dq;
        dq.push_front(s[0]);
        for(int ctr1=1;ctr1<s.size();ctr1++){
            if(s[ctr1]>=dq.front())
                dq.push_front(s[ctr1]);
            else dq.push_back(s[ctr1]);
        }
        while(!dq.empty())
        {
            fout<<dq.front();
            dq.pop_front();
        }
        fout<<"\n";
    }

    fin.close();
    fout.close();
    return 0;
}
