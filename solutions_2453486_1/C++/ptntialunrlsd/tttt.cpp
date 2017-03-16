#include<iostream>
#include<map>
#include<fstream>

using namespace std;

int main()
{
    ifstream cin("input");
    ofstream cout("output");
    int t,i,j,k=1;
    char ch;

    cin>>t;

    for(k=1;k<=t;k++)
    {
        string s[4];

        for(i=0;i<4;i++)
            cin>>s[i];

        map<char,int> m;
        for(i=0;i<4;i++)
        {
            m.clear();
            for(j=0;j<4;j++)
                if(s[i][j]!='T')
                {
                m[s[i][j]]++;
                ch=s[i][j];
                }
            if(m.size()==1&&ch!='.')
            {
                cout<<"Case #"<<k<<": "<<ch<<" won\n";
                break;
            }
        }
        if(i<4)
            continue;

        for(j=0;j<4;j++)
        {
            m.clear();
            for(i=0;i<4;i++)
                if(s[i][j]!='T')
                {
                m[s[i][j]]++;
                ch=s[i][j];
                }
            if(m.size()==1&&ch!='.')
            {   
                cout<<"Case #"<<k<<": "<<ch<<" won\n";
                break;
            }   
        }
        if(j<4)
            continue;

        m.clear();
        for(i=0,j=0;i<4;i++,j++)
        {
            if(s[i][j]!='T')
            {
            m[s[i][j]]++;
            ch=s[i][j];
            }
        }
        if(m.size()==1&&ch!='.')
        {
            cout<<"Case #"<<k<<": "<<ch<<" won\n";
            continue;
        }

        m.clear();
        for(i=0,j=3;i<4;i++,j--)
        {   
            if(s[i][j]!='T')
            {
            m[s[i][j]]++;
            ch=s[i][j];
            }
        }
        if(m.size()==1&&ch!='.')
        {   
            cout<<"Case #"<<k<<": "<<ch<<" won\n";
            continue;
        }

        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)
                if(s[i][j]=='.')
                    break;
            if(j<4)
                break;
        }

        if(i<4)
        {
            cout<<"Case #"<<k<<": "<<"Game has not completed\n";
            continue;
        }

        cout<<"Case #"<<k<<": "<<"Draw\n";
    }
    return 0;
}


