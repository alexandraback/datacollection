#include<bits/stdc++.h>

using namespace std;

int a[26],c[10];
int main()
{
    freopen ("input1.txt","r",stdin);
	freopen ("output1.txt","w",stdout);
    int T;
    cin>>T;
    for(int t=1;t<=T;++t)
    {
        string s, z;
        int a=0;
        cin >> s >> z;
        for(int i=0; i < (int)s.size(); ++i)
        {
            if(a==0)
            {
                if(s[i] == '?')
                {
                    if(z[i] == '?')
                    {
                        s[i]='0';
                        z[i]='0';
                    }
                    else
                        s[i]=z[i];
                }
                else if(z[i] == '?')
                    z[i] = s[i];
                else if(s[i] > z[i])
                    a = 1;
                else
                    a = -1;
            }
            else if(a==1)
            {
                if(s[i] == '?')
                    s[i] = '0';
                if(z[i] == '?')
                {
                    if(i+1 < s.size() && (z[i+1]-'0') - (s[i+1]-'0') == 5)
                        z[i] = '8';
                    else
                        z[i] = '9';
                }
            }
            else
            {
                if(s[i] == '?')
                {
                    s[i] = '9';
                }
                if(z[i] == '?')
                    z[i] = '0';
            }
        }
        cout<<"Case #" <<t<<": " << s << " " << z << endl;
    }
    return 0;
}
