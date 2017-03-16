#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<string>

const int MAXN = 1010;

using namespace std;

int N;
pair<string,string> table[MAXN];
map<string,map<string,int> > a,b;
map<string,int> fa,fb;

void init(){
    a.clear(); b.clear();
    fa.clear(); fb.clear();
}

int solve(){
    int counter = 0;
    for(int i=0;i<N;i++){
        if( fa[table[i].first] > 0 && fb[table[i].second] > 0 )
            counter++;
        else if( fa[table[i].first] > 0 ){
            map<string,int>::iterator it;
            for( it = a[table[i].first].begin(); it != a[table[i].first].end(); ++it ){
                if( (fb[it -> first]) > 1 ){
                    counter++;
                    break;
                }
            }
        }else if( fb[table[i].second] > 0 ){
            map<string,int>::iterator it;
            for( it = b[table[i].second].begin(); it != b[table[i].second].end(); ++it ){
                if( fa[it->first] > 1 ){
                    counter++;
                    break;
                }
            }
        }

        a[table[i].first][table[i].second]++;
        b[table[i].second][table[i].first]++;
        fa[table[i].first]++;
        fb[table[i].second]++;
    }

    return counter;
}

int main(){
    freopen("input.txt", "r", stdin );
    freopen("output.txt", "w", stdout );

    int T; cin>>T;
    for(int t=1;t<=T;t++){
        cin>>N;
        for(int i=0;i<N;i++)
            cin>>table[i].first>>table[i].second;
        init();
        printf( "Case #%d: %d\n", t, solve() );
    }
}
