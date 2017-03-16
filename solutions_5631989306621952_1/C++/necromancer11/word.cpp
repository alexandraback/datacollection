#include<bits/stdc++.h>
using namespace std;

string s;

int main()
{
    ifstream in ("A-large (1).in");
    ofstream out ("largeword.txt");

    int t;

    in>>t;
    getline(in,s);
    for(int ts=1;ts<=t;ts++){
        getline(in,s);
       // cin>>s;
        out<<"Case #"<<ts<<": ";

        deque<char> q;
        int n = s.length();
        q.push_back(s[0]);
        for(int i=1;i<n;i++){
            if(s[i]>=q.front())
                q.push_front(s[i]);
            else
                q.push_back(s[i]);
        }

        while(!q.empty()){
            out<<q.front();
            q.pop_front();
        }
        out<<endl;
    }

    return 0;
}
