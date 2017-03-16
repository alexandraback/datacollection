#include<queue>
#include<map>
#include<stdio.h>

using namespace std;

int rev(int x) {
    queue<int> q;
    while(x>0) {
        q.push(x%10);
        x/=10;
    }
    int ans=0;
    while(!q.empty()) {
        ans*=10;
        ans+=q.front();
        q.pop();
    }
    return ans;
}

int main()
{
    FILE* fin = fopen("A-small-attempt0.in","r");
    FILE* fout = fopen("out.txt","w");
    int t;
    fscanf(fin,"%d",&t);
    for(int tt=1;tt<=t;tt++) {
        queue<pair<int,int>> q;
        map<int,int> m;
        int x;
        fscanf(fin,"%d",&x);
        q.push(make_pair(1,1));
        m[1]=1;
        while(q.front().first != x) {
            int next = q.front().first+1;
            if(m[next]==0) {
                m[next]=1;
                q.push(make_pair(next,q.front().second+1));
            }
            int r = rev(q.front().first);
            if(m[r]==0) {
                m[r]=1;
                q.push(make_pair(r,q.front().second+1));
            }
            q.pop();
        }
        fprintf(fout,"Case #%d: %d\n",tt,q.front().second);
    }
    return 0;
}
