#include<bits/stdc++.h>
using namespace std;

typedef long long int lol;


#define cin fin
#define cout fout


int main()
{
    ifstream fin;
    fin.open("A-small-attempt0.in");
    ofstream fout;
    fout.open("output.txt");
    int test_case;
    cin>>test_case;
    for(int h=1;h<=test_case;h++)
    {
        int n;
        cin>>n;
        string str;
        cin>>str;
        int ans=0;
        int val=0;
        for(int i=0;i<str.length();i++)
        {
            if(val<i)
            {
                int temp=i-val;
                ans+=temp;
                val+=temp;
            }
            val=val+str[i]-'0';
        }
        cout<<"Case #"<<h<<": "<<ans<<"\n";
    }
    return 0;
}
