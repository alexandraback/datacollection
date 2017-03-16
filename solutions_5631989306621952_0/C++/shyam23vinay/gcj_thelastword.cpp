#include<bits/stdc++.h>
using namespace std;
int main()
{
    ofstream fout ("A-small-attempt0try1.out");
    ifstream fin ("A-small-attempt0try1.in");
    int t;
    fin >> t;
    for(int tc=1;tc<=t;tc++)
    {
        fout << "Case #"<<tc<<": ";
        string s;
        fin >>s;
        deque<char>q;
        char temp=s[0];
        q.push_back(temp);
        for(int i=1;i<s.size();i++)
        {
            temp=s[i];
            if(q.front()>temp)
                q.push_back(temp);
            else
                q.push_front(temp);
        }
        while(!q.empty())
        {
            temp=q.front();
            fout << temp;
            q.pop_front();
        }
        fout << endl;
    }
    return 0;
}
