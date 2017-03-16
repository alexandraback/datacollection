#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
using namespace std;
#define LLd long long int
map<map<int,vector<short> >,int > dp;
vector<short> v(41);
short key[21];
vector<int> vk[21];
set<vector<int> > st;
vector<int> res;
int rec(int bit,int n)
{
    if(bit==((1<<n)-1))
    {st.insert(res);return 1;}
    map<int,vector<short> > mp;
    mp[bit]=v;
    if(dp.count(mp)>0)
    return dp[mp];
    int ret=0;
    for(int i=0;i<n;i++)
    {
        if(((bit&1<<i)==0)&&v[key[i+1]]>0)
        {
            v[key[i+1]]--;
            for(int j=0;j<vk[i+1].size();j++)
            v[vk[i+1][j]]++;
            res.push_back(i+1);
            ret=max(ret,rec(bit|(1<<i),n));
            res.pop_back();
            v[key[i+1]]++;
            for(int j=0;j<vk[i+1].size();j++)
            v[vk[i+1][j]]--;
            if(ret==1)
            break;
        }
    }
    return dp[mp]=ret;
}
int main()
{
  fstream myf,f2;
  myf.open("input.txt",ios::in|ios::app);
  f2.open("output.txt",ios::out);
    string s[4];
    int t;
    if(myf.is_open())
    {
        myf>>t;
        //cin>>t;
        //getline(cin,line);
        int test=0;
        while(t--)
        {
            test++;
            int k,n;
            myf>>k>>n;
            for(int i=0;i<41;i++)
            v[i]=0;
            for(int i=0;i<k;i++)
            {
                int cc;
                myf>>cc;
                v[cc]++;
            }
            for(int i=1;i<=n;i++)
            {
                int tp,kt;
                myf>>tp>>kt;
                key[i]=tp;
                vk[i].clear();
                for(int j=0;j<kt;j++)
                {
                    myf>>tp;
                    vk[i].push_back(tp);
                }
            }
            dp.clear();
            st.clear();
            res.clear();
            int cnt=rec(0,n);
            cout<<"yes\n";
            //int flg=0;
            f2<<"Case #"<<test<<": ";
            if(cnt){
            set<vector<int> >::iterator it;
            it=st.begin();
            vector<int> sss=*it;
            for(int i=0;i<sss.size();i++)
            {

            f2<<sss[i]<<" ";
            }
            }
            else
            f2<<"IMPOSSIBLE";
            f2<<"\n";
        }
    }
    myf.close();
    f2.close();
    return 0;
}

