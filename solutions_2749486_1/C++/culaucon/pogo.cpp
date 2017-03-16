#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <fstream>
#include <cstring>

using namespace std;
typedef long long LL;

int x, y;
int ret[10010];
int br;

vector<int> build(int n, int t)
{
    vector<int> ret;
    int i, s=0;
    for (i=1;i<=n;i++)
    {
        s+=i;
        if (s>=t) break;
    }
    if (s==t) br=i;
    else br=s-t-1;
    for (int j=1;j<=i;j++)
        if (j!=s-t) ret.push_back(j);
    return ret;
}
int main()
{
    freopen("pogo.in","r",stdin);freopen("pogo.out","w",stdout);
    int nt, tt=1;
    cin>>nt;
    while (nt--)
    {
        cin>>x>>y;
        int orix=x, oriy=y;
        x=abs(x);
        y=abs(y);
        int n, s1, s2, s3;
        for (n=1;;n++)
        {
            s1=n*(n+1)/2;
            s2=(s1-x-y)/2;
            s3=s1-s2;
            if (s2<0 || s3<0) continue;
            if ((s1-x-y)%2!=0 || s1<abs(x)+abs(y)) continue;
            break;
        }
//        cout<<n<<"    "<<s1<<" "<<s2<<" "<<s3<<endl;
        memset(ret,-1,sizeof(ret));
        vector<int> r, rr;
        if (x<0) r=build(n,s2);
        else r=build(n,s3);
        
        
//        cout<<"     "<<orix<<" "<<oriy<<"     "<<x<<" "<<y<<endl;
//        for (int i=0;i<r.size();i++) cout<<r[i]<<" ";cin.get();cout<<endl;
        
        int dirx=1, diry=3;
        
        int nr=r.size();
        int num=1, pos=0;
        int cursum=0;
        while (1)
        {
            int tmp=x+cursum;
//            cout<<"   "<<tmp<<endl;
            for (int i=nr-1;i>=0;i--)
                if (tmp>=r[i])
                {
                    tmp-=r[i];
                    ret[r[i]]=dirx;
                }
            if (tmp==0) break;
///            cout<<"    "<<x<<" "<<tmp<<endl;cin.get();
            memset(ret,-1,sizeof(ret));
            while (num<n)
            {
                while (pos<nr && r[pos]<num) pos++;
                if (pos<nr && num==r[pos]) num++;
                else break;
            }
//            cout<<"      "<<num<<endl;cin.get();
            ret[num]=2;
            cursum+=num;
            num++;
        }
//for (int i=1;i<=n;i++) cout<<i<<" "<<ret[i]<<endl;
//        for (int i=0;i<rr.size();i++) cout<<rr[i]<<" ";cin.get();
        
        for (int i=0;i<rr.size();i++) ret[rr[i]]=dirx;
        for (int i=0;i<r.size();i++)
            if (ret[r[i]]==-1) ret[r[i]]=diry;
        for (int i=1;i<=n;i++)
            if (ret[i]==-1) ret[i]=(diry==4)?3:4;
        
//        cout<<ret[1]<<" "<<ret[2]<<"   "<<(orix==x)<<endl;cin.get();
        string sol="";
        for (int i=1;i<=n;i++)
            if (ret[i]==1) sol+=(orix==x)?"E":"W";
            else if (ret[i]==2) sol+=(orix==x)?"W":"E";
            else if (ret[i]==3) sol+=(oriy==y)?"N":"S";
            else if (ret[i]==4) sol+=(oriy==y)?"S":"N";
            else cout<<"hix"<<endl;
            
        int xx=0, yy=0;
        for (int i=0;i<sol.size();i++)
            if (sol[i]=='N') yy+=i+1;
            else if (sol[i]=='S') yy-=i+1;
            else if (sol[i]=='E') xx+=i+1;
            else if (sol[i]=='W') xx-=i+1;
        
        if (xx!=orix || yy!=oriy) cout<<"asdfasdfsdaifasdjfksdajkfjsdalkf   "<<xx<<" "<<yy<<endl;
        
        cout<<"Case #"<<tt++<<": "<<sol<<endl;
    }
}
