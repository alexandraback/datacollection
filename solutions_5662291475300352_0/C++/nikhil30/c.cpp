#include<bits/stdc++.h>
using namespace std;

typedef long long int lol;
typedef unsigned long long int ull;


#define cin fin
#define cout fout
#define pb push_back
#define mp make_pair



bool between(int prev,int curr,int pos);



int main()
{
    ifstream fin;
    ofstream fout;
    fin.open("C-small-1-attempt0.in");
    fout.open("output.txt");
    int test_case;
    cin>>test_case;
    for(int h=1;h<=test_case;h++)
    {
        cout<<"Case #"<<h<<": ";
        int n;
        cin>>n;
        int cntr=0;
        int sa,sb,posa,posb;
        for(int i=0;i<n;i++)
        {
            int start,num,speed;
            cin>>start>>num>>speed;

            if(cntr==0)
            sa=speed,posa=start;
            else sb=speed,posb=start;
            cntr++;
        }

        if(cntr==1) sb=sa+1,posb=posa;
        int ans=0;
        int posx=posb-1;
        int prev=posa;

        for(int i=posx;i<=360;i+=sb)
        {

            int curr=(prev+sa)%360;
            //cerr<<i<<" "<<prev<<" "<<curr<<"\n";
            int temp=i%360;
            if(between(prev,curr,temp)) ans++;
            prev=curr;
        }
        ans=min(ans,2);

        int ans1=0;
        cerr<<"\n\n\n";
        posx=posb-1;
        prev=posb;

        for(int i=posx;i<=360;i+=sa)
        {
            int curr=(prev+sb)%360;
           // cerr<<i<<" "<<prev<<" "<<curr<<"\n";
            int temp=i%360;
            if(between(prev,curr,temp)) ans1++;
            prev=curr;
        }

        ans1=min(ans1,2);

        if(sa>=360 && sb>=360) ans=0;
        else if(max(sa,sb)>=360) ans=1;
        else ans=min(ans1,ans);
        cout<<ans<<"\n";
    }
    return 0;
}


bool between(int prev,int curr,int pos)
{
    if(pos>=prev && curr>=pos)
    {
        cerr<<prev<<" "<<curr<<" "<<pos<<"\n";
        return true;
    }
    if(pos<=curr && curr<=prev)
    {
        cerr<<prev<<" "<<curr<<" "<<pos<<"\n";
        return true;
    }
    if(pos>=prev && curr<prev)
    {
        cerr<<prev<<" "<<curr<<" "<<pos<<"\n";
        return true;
    }
    return false;
}
