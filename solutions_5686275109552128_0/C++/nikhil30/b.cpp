#include<bits/stdc++.h>
using namespace std;

typedef long long int lol;


#define cin fin
#define cout fout

int look[1005];

int main()
{
    ifstream fin;
    fin.open("B-small-attempt5.in");
    ofstream fout;
    fout.open("output.txt");
    int test_case;
    cin>>test_case;
    for(int h=1;h<=test_case;h++)
    {
        cout<<"Case #"<<h<<": ";
        memset(look,0,sizeof(look));
        int d;
        cin>>d;
        int Max=-1;
        int max_pos;
        int p[1003];
        for(int i=0;i<d;i++)
            cin>>p[i],look[p[i]]++;
        int c_so_far=0;
        int ans=99999999;
        for(int i=1000;i>=1;i--)
        {
            if(look[i])
            {
                ans=min(ans,c_so_far+i);
                //cerr<<c_so_far<<" "<<i<<"\n";
                c_so_far+=look[i];
                if(i&1)
                {
                    look[(i+1)/2]+=look[i];
                    look[i/2]+=look[i];
                }
                else
                {
                    look[i/2]=look[i/2]+2*look[i];
                    //cout<<i/2<<" "<<look[i]<<"\n";
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
