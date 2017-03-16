#include <bits/stdc++.h>
using namespace std;

string a,b;
int lim;
vector<string> cand1,cand2;

void back1(int pos, string ans)
{
    if(pos >= lim)
    {
        cand1.push_back(ans);
        return;
    }

    if(a[pos] != '?')
    {
        string nuevo = ans;
        nuevo.push_back(a[pos]);
        back1(pos + 1, nuevo);
    }
    else
    {
        for(int i = 0; i < 10; i++)
        {
            string nuevo = ans;
            nuevo.push_back(i + '0');
            back1(pos + 1, nuevo);
        }
    }
}

void back2(int pos, string ans)
{
    if(pos >= lim)
    {
        cand2.push_back(ans);
        return;
    }

    if(b[pos] != '?')
    {
        string nuevo = ans;
        nuevo.push_back(b[pos]);
        back2(pos + 1, nuevo);
    }
    else
    {
        for(int i = 0; i < 10; i++)
        {
            string nuevo = ans;
            nuevo.push_back(i + '0');
            back2(pos + 1, nuevo);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T,ntest=1,ans,besti,bestj,top;
    string ansi,ansj;
    cin >> T;
    while(T--)
    {
        cin >> a >> b;
        lim = a.size();
        ans = 10000;
        cand1.clear(); cand2.clear();
        back1(0, ""); 
        back2(0, "");

        for(int i = 0; i < (int)cand1.size(); i++)
            for(int j = 0; j < (int)cand2.size(); j++)
            {
                int ni = atoi(cand1[i].c_str());
                int nj = atoi(cand2[j].c_str());
                int dif = abs(ni - nj);
                if(dif < ans || (dif == ans && ni < besti) || (dif == ans && ni == besti && nj < bestj))
                {
                    ans = dif;
                    besti = ni;
                    bestj = nj;
                    ansi = cand1[i];
                    ansj = cand2[j];
                } 
            }
        cout << "Case #" << ntest++ << ": " << ansi << " " << ansj << '\n';
    }
    return 0;
}