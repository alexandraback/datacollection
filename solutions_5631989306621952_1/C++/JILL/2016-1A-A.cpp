#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;cin>>T;
	for(int ks=1;ks<=T;ks++)
    {
        string a;
        cin>>a;
        string b="";
        int sa=a.size();
        for(int i=0;i<sa;i++)
        {
            if(b=="") b+=a[i];
            else
            {
                if(a[i]>=b[0]) b=a[i]+b;
                else b=b+a[i];
            }
        }
        cout<<"Case #"<<ks<<": ";
        cout<<b<<'\n';
    }
	return 0;
}
