#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node
{
    int v;
    int iter;
    int num;
};

bool operator <(Node a, Node b)
{
    if(a.num == b.num) return a.iter < b.iter;
    return a.num > b.num;
}

int main()
{
    //freopen("A.txt","r",stdin);
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    int T; cin>>T;
    for(int tt = 1; tt<= T; tt++)
    {
        int A, N;
        cin>>A>>N;
        vector<int> P(N);
        for(int i=0; i<N; i++)
        {
            cin>>P[i];
        }
        sort(P.begin(), P.end());
        priority_queue<Node> q;
        Node temp;
        temp.v = A;
        temp.iter = 0;
        temp.num = 0;
        q.push(temp);
        int ret = P.size();
        while(!q.empty())
        {
            Node t = q.top();
            //cout<<t.v<<" "<<t.iter<<" "<<t.num<<endl;
            q.pop();
            if (t.iter == P.size())
            {
                ret = min(ret, t.num);
                continue;
            }
            if(P[t.iter] < t.v)
            {
                t.v += P[t.iter];
                t.iter ++;
                q.push(t);
            }else
            {
                t.iter ++;
                t.num ++;
                q.push(t);
                if(t.v - 1 > 0)
                {
                    t.iter--;
                    t.num--;
                    int lnum = 0;
                    while(t.v <= P[t.iter])
                    {
                        t.v += t.v-1;
                        lnum ++;
                    }
                    t.v += P[t.iter];
                    t.iter ++;
                    t.num += lnum;
                    q.push(t);
                }
            }
        }
        cout<<"Case #"<<tt<<": "<<ret<<endl;
    }
    return 0;
}
