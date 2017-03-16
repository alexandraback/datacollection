#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include <iomanip>
#include<unordered_map>

using namespace std;

int T;

int n;

int a[20];
int b[20];

int ca;
int cb;

vector<int> atos[20];
vector<int> btos[20];
bool au[20];
bool bu[20];

int ans=0;

void cover(int ma,int tans) {
    if(ma<ca) {
        for(int i=0;i<atos[ma].size();i++) {
            int t=atos[ma][i];
            bool oldb=bu[b[t]];
            bu[b[t]]=true;
            cover(ma+1,tans-1);
            bu[b[t]]=oldb;
        }
    } else {
        for(int i=0;i<cb;i++) {
            if(!bu[i]) tans--;
        }
        ans=max(ans,tans);
    }
}

int main() {
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);

    cin>>T;
    for(int C=0;C<T;C++) {
        cin>>n;
        ca=0;
        cb=0;
        ans=0;
        unordered_map<string,int> am;
        unordered_map<string,int> bm;
        for(int i=0;i<20;i++) {
            atos[i].clear();
            btos[i].clear();
        }
        memset(au,0,sizeof(au));
        memset(bu,0,sizeof(bu));
        for(int i=0;i<n;i++) {
            string ta,tb;
            cin>>ta>>tb;
            unordered_map<string,int>::const_iterator it =am.find(ta);
            if(it==am.end()) {
                a[i]=ca;
                am.insert(make_pair(ta,ca));
                ca++;
            } else {
                a[i]=it->second;
            }

            it =bm.find(tb);
            if(it==bm.end()) {
                b[i]=cb;
                bm.insert(make_pair(tb,cb));
                cb++;
            } else {
                b[i]=it->second;
            }

            atos[a[i]].push_back(i);
            btos[b[i]].push_back(i);
        }
        cover(0,n);
        cout<<"Case #"<<C+1<<": "<<ans<<endl;
    }
}
