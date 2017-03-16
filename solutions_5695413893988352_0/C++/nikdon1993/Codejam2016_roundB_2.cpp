#include<bits/stdc++.h>
using namespace std;

vector<int> f(string str)
{
    vector<int>ans;
    ans.push_back(0);
    for(int i = 0; i<str.size() ; i++)
    {
        if(str[i] == '?')
        {
            vector<int>tmp;
            for(int k=0;k<10;k++)
            for(int j=0;j<ans.size();j++)
            {
                tmp.push_back(ans[j]*10+k);
            }
            ans = tmp;
        }
        else
        {
            vector<int>tmp;

            for(int j=0;j<ans.size();j++)
            {
                tmp.push_back(ans[j]*10+str[i] - '0');
            }
            ans = tmp;
        }
    }
    return ans;

}
int main()
{

    freopen("Codejam2016_roundB_1_input.txt", "r", stdin);
    freopen("Codejam2016_roundB_1_output.txt", "w", stdout);


    int t, tc;

    cin>>t;

    for(int tc=1; tc<=t ;tc++)
    {

        //long long ans=0, n;

        string a, b;
        cin>>a>>b;
       // cout<<a<<" "<<b<<endl;
        vector<int>x = f(a), y = f(b);
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        //cout<<x.size()<<" "<<y.size()<<endl;
        int ansx, ansy, mn = 100000;
        for(int i = 0; i<x.size() ; i++)
        {

            for(int j = 0 ;j<y.size() ; j++)
            {
                if(abs(x[i]-y[j]) < mn)
                {
                    mn = abs(x[i] - y[j]);
                    ansx = x[i];
                    ansy = y[j];
                }
            }
        }


        cout<<"Case #"<<tc<<": ";
        string ans = "";
        int p = 1;
        for(int i=0;i<a.size()-1;i++)p=p*10;
        int tmp = p;
        //cout<<tmp<<" "<<p<<endl;
        //cout<<ansx<<" "<<tmp<<endl;
        while(ansx<tmp && tmp>1)
        {
            tmp = tmp/10;
            ans = ans+'0';
        }
        cout<<ans<<ansx<<" ";
        tmp = p;
        ans = "";
        while(ansy<tmp && tmp>1)
        {
            tmp = tmp/10;
            ans = ans+'0';
        }
        cout<<ans<<ansy<<endl;


    }


}
