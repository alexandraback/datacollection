#include<iostream>
#include<string>
#include<cctype>

using namespace std;

bool isvowel(char a)
{
    a = tolower(a);
    return (a=='a'||a=='e'||a=='i'||a=='o'||a=='u');
}

bool countnv(string &s,int n,int start,int stop)
{
    int i,j,c=0;

    for(i=start;i<=stop;i++)
    {
        if(!isvowel(s[i]))
        {
            c=0;
            for(j=i;j<=stop && j<i+n;j++)
                if(!isvowel(s[j]))
                    c++;
                else
                    c=0;
            if(c >= n)
                return true;
        }
    }

    return false;
}

int main()
{
    int tt,T,n,i,j,l,ans;
    string str;


    cin >> T;
    for(tt=1;tt<=T;tt++)
    {
        cin >> str >> n;
        ans = 0;
        l = str.length();

        for(i=0;i<l;i++)
        {
            for(j=i+n-1;j<l;j++)
            {
                if(countnv(str,n,i,j))
                    ans++;
            }
        }

        cout << "Case #" << tt << ": " << ans << endl;
    }

    return 0;
}
