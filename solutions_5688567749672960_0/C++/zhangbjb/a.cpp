#include<iostream>
#include<map>
#include<fstream>
#include<iomanip>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<string.h>
#include<stack>
#include<sstream>
#include<math.h>

using namespace std;

int rev(int x) {
    int ans;
    stringstream os;
    os<<x;
    string t;
    t=os.str();
    ans=0;
    for (int i=t.size()-1;i>=0;i--) {
        ans=ans*10+(t[i]-'0');
    }
    return ans;
}

int main() {

    freopen("input.in","r",stdin);
    freopen("output.txt","w",stdout);
    map<int,int> visit;
    vector<int> q;
    q.push_back(1);visit[1]=1;
    int depth=1;
    int head=-1; int tail=0;
    while (head<tail) {
        head++;depth++;
        int thead=head;
        int ttail=tail;
        for (int i=thead;i<=ttail;i++) {
            int current=q[i];
            int next1=q[i]+1;
            int next2=rev(q[i]);
            if (!visit[next1] &&next1<1000001) {
                visit[next1]=depth;
                tail++;
                q.push_back(next1);
            }
            if (!visit[next2] && next2<1000001) {
                visit[next2]=depth;
                tail++;
                q.push_back(next2);
            }
        }
        head=ttail;
    }

    int t;
    cin>>t;
    for (int cas=1;cas<=t;cas++) {
        cout<<"Case #"<<cas<<": ";
        int n;
        cin>>n;
        cout<<visit[n]<<endl;
    }
    return 0;
}
