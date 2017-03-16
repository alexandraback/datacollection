#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define mod 1000000007
#define maxi 1000006
int main()
{
    freopen("ina.txt","r",stdin);
    freopen("outa.txt","w",stdout);
    int t;
    cin>>t;
    for(int ii=1;ii<=t;ii++)
    {
        string tmp;
        cin>>tmp;
        //cout<<tmp;
        list<char> ls;
        ls.push_back(tmp[0]);
        for(int i=1;i<tmp.size();i++)
        {
            if(ls.front()<=tmp[i]){
                ls.push_front(tmp[i]);
            }
            else{
                ls.push_back(tmp[i]);
            }
        }
        cout<<"Case #"<<ii<<": ";
        while(!ls.empty()){
            cout<<ls.front();
            ls.pop_front();
        }
        cout<<endl;

    }
}
