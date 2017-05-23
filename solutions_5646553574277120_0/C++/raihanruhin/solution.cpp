///     Raihan Ruhin
///     CSE, Jahangirnagar University.
///     Dhaka-Bangladesh.
///     id: raihanruhin (topcoder / codeforces / codechef / hackerrank / uva / uvalive / spoj), 3235 (lightoj)
///     mail: raihanruhin@ (yahoo / gmail / facebook)
///     blog: ruhinraihan.blogspot.com

#include<bits/stdc++.h>
using namespace std;

#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define PI acos(-1.0)

#define MOD 1000000007
#define MX 100010

#define READ freopen("C-small-attempt5.in", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)

bool taken[35];
int main()
{
    READ;
    WRITE;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc,kk=1, n, c, d, v, arr[10];

    cin>>tc;
    while(tc--)
    {
        CLR(taken);
        cin>>c>>d>>v;
        for(int i=0; i<d; i++)
        {
            cin>>arr[i];
            taken[arr[i]]=true;
        }
        set<int>st;
        if(d>=1)
        {
            for(int i=0; i<d; i++)
            {
                if(arr[i]>v) continue;
                //taken[arr[i]]=true;
                st.insert(arr[i]);
            }
        }
        if(d>=2)
        {
            for(int i=0; i<d; i++)
                for(int j=i+1; j<d; j++)
                {
                    if((arr[i]+arr[j])>v) continue;
                    //taken[arr[i]+arr[j]]=true;
                    st.insert(arr[i]+arr[j]);
                }
        }
        if(d>=3)
        {
            for(int i=0; i<d; i++)
                for(int j=i+1; j<d; j++)
                    for(int k=j+1; k<d; k++)
                    {
                        int num=arr[i]+arr[j]+arr[k];
                        if(num>v) continue;
                        //taken[num]=true;
                        st.insert(num);
                    }
        }
        if(d>=4)
        {
            for(int i=0; i<d; i++)
                for(int j=i+1; j<d; j++)
                    for(int k=j+1; k<d; k++)
                        for(int l=k+1; l<d; l++)
                        {
                            int num=arr[i]+arr[j]+arr[k]+arr[l];
                            if(num>v) continue;
                            //taken[num]=true;
                            st.insert(num);
                        }
        }
        if(d==5)
        {
            int num=arr[0]+arr[1]+arr[2]+arr[3]+arr[4];
            if(num<=v)
            {
                //taken[num]=true;
                st.insert(num);
            }
        }
        int mn=1e9;
        /*for(set<int>::iterator it=st.begin();it!=st.end();it++)
            cout<<*it<<endl;*/
        set<int>orig=st;
        int bit=255;
        for(int bit=512; bit>=0; bit--)
        {
            int ans=0;
            st=orig;
            vector<int>vv;
            for(int i=0;i<8;i++)
                if(bit & (1<<i))
                    vv.push_back(i+1);
            set<int>st2;
            st2=st;
            for(int ii=0; ii<vv.size(); ii++)
            {
                int i=vv[ii];
                if(taken[i]==true) continue;
                int psz=st.size();

                //bool chk=false;
                st2.insert(i);
                for(set<int>::iterator it=st.begin(); it!=st.end(); it++)
                {
                    int num=*it;
                    if((num+i)<=v)
                        st2.insert(num+i);
                }
                if(st.size()!=st2.size())
                {
                    //taken[i]=true;
                    ans++;
                }
                st=st2;

            }
            if(st.size()==v) mn=min(mn, ans);
        }
        /*for(set<int>::iterator it=st.begin();it!=st.end();it++)
            cout<<*it<<endl;*/

        cout<<"Case #"<<kk++<<": "<< mn <<"\n";
    }
    return 0;
}

