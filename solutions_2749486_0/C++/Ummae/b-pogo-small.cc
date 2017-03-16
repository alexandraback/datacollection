#include <iostream>
#include <deque>
#include <vector>
#include <string>
using namespace std;

#define ABS(X) (X) < 0 ? -(X) : (X)
struct pos_t
{
    int x;
    int y;
    pos_t(int _x, int _y) : x(_x), y(_y) { }
    pos_t(){}
};

int dirs[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
char dirs_str[4] = { 'N', 'E', 'S', 'W' };

int dprint(string s){
    int x=0;
    int y=0;
    for(int i=0; i <s.length(); ++i){
        switch(s[i]){
            case 'N': y += (i+1); break;
            case 'E': x += (i+1); break;
            case 'S': y -= (i+1); break;
            case 'W': x -= (i+1); break;
        }
    }
    fprintf(stderr, "%d %d\n", x, y);
}

int visited[5000][5000];

int main()
{
    int T;
    scanf("%d", &T);
    for(int tcase=1; tcase<=T; ++tcase){
        pos_t s(0, 0);
        pos_t g(0, 0);
        scanf("%d %d", &g.x, &g.y);
        deque<pair<pos_t, string> > q;
        q.push_back(make_pair(s, ""));
        string ans = "";
        memset(visited, 0, sizeof(visited));
        while(!q.empty()){
            pair<pos_t, string> item = q.front(); q.pop_front();
            pos_t& c = item.first;
            string& step = item.second;
            visited[c.x+2000][c.y+2000] = 1;
            if(step.length() >= 500)
                continue;
            for(int i=0; i < 4; ++i){
                pos_t n_c;
                n_c.x = c.x + ( (step.length()+1) * dirs[i][0] );
                n_c.y = c.y + ( (step.length()+1) * dirs[i][1] );
                if(visited[n_c.x+2000][n_c.y+2000]) continue;
#if 0
                if(abs(n_c.x) >= 500) {
                    continue;
                    printf("%d > %d %d\n", abs(n_c.x), g.x*10, abs(n_c.x) > g.x*10);
                    printf("%d > %d\n", abs(n_c.x), g.x*10); exit(1);}
                if(abs(n_c.y) >= 500) {
                    continue;
                    printf("%d > %d %d\n", abs(n_c.y), g.y*10, abs(n_c.y) > g.y*10);
                    printf("%d > %d\n", abs(n_c.y), g.y*10); exit(1);}
#endif
                    
                string new_step = step + dirs_str[i];
                if( n_c.x == g.x  && n_c.y == g.y ){
                    ans = new_step;
                    break;
                }
                q.push_back(make_pair(n_c, new_step));
            }
            if(ans.length())
                break;
        }
        printf("Case #%d: %s\n", tcase, ans.c_str());
        fprintf(stderr, "Case #%d: %s\n", tcase, ans.c_str());
        fprintf(stderr, "%d %d\n", g.x, g.y);
        dprint(ans);
    }
    return 0;
}
