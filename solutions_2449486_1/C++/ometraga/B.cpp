#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;
int lawn[100][100];
int N, M;
bool cut[100][100];
vector < pair <int, pair <int,int> > > v;

bool cmp (pair < int, pair <int,int> > a, pair < int, pair <int,int> > b)
{
    return a.first < b.first;
}

bool go_vert(int r, int c, int v)
{
    for(int i=0; i<N; i++) if(lawn[i][c] > v) return 0;
    return 1;
}

bool go_hor(int r, int c, int v)
{
    for(int i=0; i<M; i++) if(lawn[r][i] > v) return 0;
    return 1;
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    cin >> T;
    for(int t=1; t<=T; t++)
    {
        v.clear();
        memset(cut, 0, sizeof(cut));
        cin >> N >> M;
        
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
            {                
                cin >> lawn[i][j];
                
                pair <int,int> p;
                p.first = i;
                p.second = j;
                
                pair < int , pair <int,int> > q;
                q.first = lawn[i][j];
                q.second = p;
                
                v.push_back(q);
            }
        
        sort(v.begin(), v.end(), cmp);
        
        bool ans = 1;
        
        for(int i=0; i<v.size(); i++)
        {
            int a = v[i].second.first;
            int b = v[i].second.second;
            if(cut[a][b]) continue;
            
            int c = v[i].first;
            if(go_vert(a,b,c))
            {
                for(int j=0; j<N; j++) cut[j][b] = 1;
            }
            else if(go_hor(a,b,c))
            {
                for(int j=0; j<M; j++) cut[a][j] = 1;
            }
            else
            {
                ans = 0;
                break;
            }
        }
        
        cout << "Case #" << t << ": ";
        if(ans) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
}
