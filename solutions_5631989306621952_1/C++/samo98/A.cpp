#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int t,b,n;
string s;
int main()
{
    cin>>t;
    for(int ij=1;ij<=t;ij++)
    {
        cin>>s;
        deque<char> D;D.push_back(s[0]);
        for(int i=1;i<s.size();i++)
        {
            if(D.front()>s[i])D.push_back(s[i]);
            else D.push_front(s[i]);
        }
        cout <<"Case #"<<ij<<": ";
        while(!D.empty()){cout <<D.front();D.pop_front();}
        cout <<endl;
    }
    return 0;
}
