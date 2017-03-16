#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<string>
#include<iostream>
#include<set>
#include<cstring>

using namespace std;

struct node{
    int x,time;
    node(int a,int b):x(a),time(b){};
    bool operator < (const node &oth) const{
        if(x!=oth.x) return x<oth.x;
        return time>oth.time;
    };
};

vector<node> v;

int getans(void) {
    sort(v.begin(),v.end());
    //for(int i=0;i<v.size();i++) cout<<v[i].x<<" "<<v[i].time<<endl;
    for(int i=0;i<v.size();i++) {
        for(int j=i+1;j<v.size();j++) {
            if(v[i].time>v[j].time) {
                int ta = (360-v[i].x)*v[i].time;
                int tb = (360-v[j].x+v[i].x)*v[j].time;
                //cout<<"ta: "<<ta<<" tb:"<<tb<<endl;
                if(ta>tb) return 1;

                ta = (v[i].x)*v[i].time;
                tb = (360-v[j].x)*v[j].time;
                if(ta<tb) return 1;
            }
        }
    }
    return 0;
}

int main()
{
    freopen("C-small-1-attempt1.in","r",stdin);
    freopen("c.out","w",stdout);

    int t,n,pos,h,time;
    cin>>t;
    for(int cas=1;cas<=t;cas++) {
        cin>>n;
        v.clear();
        for(int i=0;i<n;i++) {
            cin>>pos>>h>>time;
            for(int j=0;j<h;j++) {
                v.push_back(node(pos,time+j));
                //v.push_back(node(pos+360,time+j));
            }
        }

        cout<<"Case #"<<cas<<": "<<getans()<<endl;

    }
    return 0;
}
