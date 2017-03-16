#include <iostream>
#include <vector>
#include <deque>
#include <cstdio>
#include <map>
#include <set>
#include <sstream>
using namespace std;

char buf[102420];
int main()
{
    int T;
    gets(buf);
    sscanf(buf, "%d", &T);
    for(int tcase=1; tcase<=T; ++tcase)
    {
        int n;
        gets(buf);
        sscanf(buf, "%d", &n);
        map<int, vector<int> > go;
        map<int, int> back;
        set<int> cs;
        for(int i=1; i<=n; ++i){
            gets(buf);
            istringstream is(buf);
            int x;
            is >> x;
            cs.insert(i);
            for(int j=1; j <= x; ++j){
                int c2;
                is >> c2;
                go[i].push_back(c2);
                back[c2]=i;
                cs.insert(c2);
            }
        }

        bool ok=false;
        for(set<int>::iterator iter=cs.begin(); iter!=cs.end(); ++iter)
        {
            int c=*iter;
            if(back[c] != 0) continue;
            
            map<int,bool> visited;
            deque<int> q;
            q.push_back(c);
            while(!q.empty()){
                int c1 = q.front(); q.pop_front();
                if(visited[c1]){
                    ok=true;
                    break;
                }
                visited[c1]=true;
                for(int i=0; i < go[c1].size(); ++i){
                    if(visited[go[c1][i]]){
                        ok=true;
                        break;
                    }
                    q.push_back( go[c1][i] );
                }
                if(ok) break;
            }
            if(ok) break;
        }
        if(!ok) printf("Case #%d: No\n", tcase);
        else printf("Case #%d: Yes\n", tcase);
    }

    return 0;
}


