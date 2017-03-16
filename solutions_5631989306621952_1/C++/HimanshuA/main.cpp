#include <iostream>
#include <list>

using namespace std;

int main()
{
    int T;
    string S;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        cin>>S;

        list<char> l;
        l.push_back(S[0]);
        char prev=S[0];

        for(int i=1;i<S.size();i++)
        {
            if(S[i]>=prev)
            {
                l.push_front(S[i]);
                prev=S[i];
            }
            else
                l.push_back(S[i]);
        }

        cout<<"Case #"<<t<<": ";
        while(!l.empty())
        {
            cout<<l.front();
            l.pop_front();
        }

        cout<<endl;
    }
    return 0;
}