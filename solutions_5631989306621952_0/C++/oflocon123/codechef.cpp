#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{


    int t,ti;
    cin>>t;
    ti=t;

    for(; t>0; t--)
    {
        string s;
        vector<char> v;
        cin>>s;

        v.push_back(s[0]);

        for(int i=1; i<s.size(); i++)
        {
            if(v[0]>s[i])
            {
                v.push_back(s[i]);
            }
            else
            {
                v.insert(v.begin(),s[i]);
            }
        }

        cout<<"Case #"<<(ti-t+1)<<": ";

        for(int i=0; i<v.size(); i++)
        {
            cout<<v[i];
        }
        cout<<endl;
    }


    return 0;
}
