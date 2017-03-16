#include<iostream>
#include<set>
#include<queue>

using namespace std;

class step{
public:
    int x, y, l;
    string path;
    step(int a, int b, int c, string s){
        x = a, y = b, l = c, path = s;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    int t, x, y, i;
    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    char dc[] = "NESW";
    cin >> t;
    for (int u = 1 ; u <= t ; ++u){
        queue<step> q;
        set<pair<int, int> > s;
        q.push(step(0, 0, 1, ""));
        s.insert(make_pair(0, 0));
        cin >> x >> y;
        while (1){
            int sx = q.front().x, sy = q.front().y, sl = q.front().l;
            for (i = 0 ; i < 4 ; ++i){
                int nx = sx + dx[i] * sl, ny = sy + dy[i] * sl;
                if (nx == x && ny == y){
                    cout << "Case #" << u << ": " << q.front().path << dc[i] << endl;
                    break;
                }
                if (!s.count(make_pair(nx, ny))){
                    s.insert(make_pair(nx, ny));
                    q.push(step(nx, ny, sl + 1, q.front().path + dc[i]));
                }
            }
            q.pop();
            if (i < 4)break;
        }
    }
    return 0;
}
