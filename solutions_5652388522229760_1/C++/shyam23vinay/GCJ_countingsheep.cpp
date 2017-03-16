#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main()
{
    ofstream fout ("A-large.out");
    ifstream fin ("A-large.in");
    int t;
    fin >> t;
    for(int i=1;i<=t;i++)
    {
        set<int>s;
        int n,temp,ans;
        fin >> n;
        if(n==0)
        {
            fout << "Case #" <<i<< ": " << "INSOMNIA" << endl;
        }
        else
        {
            for(int j=1;;j++)
            {
                temp=n*j;
                while(temp>0)
                {
                    s.insert(temp%10);
                    temp=temp/10;
                }
                if(s.size()==10)
                {
                    ans=n*j;
                    break;
                }
            }
            a[n]=ans;
            fout << "Case #" <<i<< ": " << ans << endl;
        }
    }
    return 0;
}
