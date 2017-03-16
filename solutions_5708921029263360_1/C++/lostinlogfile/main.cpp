#include <iostream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <ctime>
using namespace std;
const int CHERNOKALOV=10000;
class variant{
public:
    variant(int j,int p,int s):_j(j),_p(p),_s(s){}
    int _j;
    int _p;
    int _s;
    int checkjp(int j,int p)
    {
        if((_j==j)&&(_p==p))
            return 1;
        return 0;
    }
    int checkps(int p,int s)
    {
        if((_s==s)&&(_p==p))
            return 1;
        return 0;
    }
    int checkjs(int j,int s)
    {
        if((_s==s)&&(_j==j))
            return 1;
        return 0;
    }
    bool operator ==(const variant& v)
    {
        return ((_s==v._s)
                &&(_j==v._j)
                &&(_p==v._p));
    }
};
bool canI( vector<variant> &all,variant v,int k)
{
    int jp=0,js=0,ps=0;
    for(int i=0;i<all.size();i++)
    {
        jp+=all[i].checkjp(v._j,v._p);
        js+=all[i].checkjs(v._j,v._s);
        ps+=all[i].checkps(v._p,v._s);
        if(all[i]==v)
            return false;
    }
    if(jp>=k)return false;
    if(js>=k)return false;
    if(ps>=k)return false;
    return true;
}
vector<variant>  getRandom(vector<variant> all,int k)
{
    std::random_shuffle ( all.begin(), all.end() );
    vector<variant> out;
    for(int i=0;i<all.size();i++)
    {
        if(canI(out,all[i],k))
            out.push_back(all[i]);
    }
    return out;
}
void solve()
{
    int J,P,S,K;
    cin>>J>>P>>S>>K;
    vector<variant> use;
    vector<variant> all;
    for(int i=1;i<=J;i++)
        for(int j=1;j<=P;j++)
            for(int k=1;k<=S;k++)
            {
                variant tmp(i,j,k);
                all.push_back(tmp);
                if(canI(use,tmp,K))
                    use.push_back(tmp);
            }
    for(int i=0;i<CHERNOKALOV;i++){

        vector<variant> uset= getRandom(all,K);
        if(uset.size()>use.size()){
            cerr<<"bingo!\n";
            use=uset;
        }
    }
    cout<<use.size()<<"\n";
    for(int i=0;i<use.size();i++)
        cout<<use[i]._j<<" "<<use[i]._p<<" "<<use[i]._s<<endl;
}
int main()
{
    freopen("C-large.in","r",stdin);
    freopen("out4.txt","w+",stdout);
    srand(time(NULL));
    int T;
    cin>>T;

    for(int iT=0;iT<T;iT++)
    {
        cout<<"Case #"<<iT+1<<": ";
        cerr<<"Case #"<<iT+1<<": ";
        solve();
       cerr<<"\n";
    }
    return 0;
}
