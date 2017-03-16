#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <fstream>
#include <set>

using namespace std;

#define FOR(i, A, B) for(int i=(A); i<(B); i++)
#define REP(i, N) for(int i=0; i<(N); i++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define MP make_pair
#define PB push_back
#define VI vector<int>
#define VS vector<string>
#define PII pair<int, int>
#define X first
#define Y second

int aabs(int a) { return (a<0)?-a:a; }
int mmax(int a, int b) { return (a>b)?a:b; }
int mmin(int a, int b) { return (a<b)?a:b; }

int x, y;

int main()
{
    int T;
    cin >> T;
    
    set<pair < int , pair< pair< int,  int>, pair<int, string> > > > q;
    
    REP(caso, T) {
        cin >> x >> y;
        
        string path="";
        int xx=0, yy=0;
        
        if(aabs(x) < aabs(y)) {
            FOR(i, 1, aabs(x)) {
                if(i % 2) {
                    path += 'N';
                    yy += i;
                } else {
                    path += 'S';
                    yy -= i;
                }
            }
            if(x < 0) path += 'W';
            else if(x > 0) path += 'E';
            int step = aabs(x)+1;
            
            //cout << path << " " << yy << endl;
            
            if(y < 0) yy += step, step++, path+='N';
            else yy -= step, step++, path+='S';
            
            //cout << path << " " << yy << endl;
            
            //if(step % 2 == 1 and yy+step > y) yy -= step, step++;
            //else if(step % 2 == 0 and yy-step < y) y += step, step++;
            
            while(yy != y) {
                
                //cout << path << " " << yy << endl;
                
                if(step % 2) yy += step, path+='N';
                else yy -= step, path+='S';
                step++;
            }
            
        } else {
            FOR(i, 1, aabs(y)) {
                if(i % 2) {
                    path += 'E';
                    xx += i;
                } else {
                    path += 'W';
                    xx -= i;
                }
            }
            if(y < 0) path += 'S';
            else if(y > 0) path += 'N';
            int step = aabs(y)+1;
            
            //cout << path << " " << xx << endl;
            
            if(x < 0) xx += step, step++, path+='E';
            else xx -= step, step++, path+='W';
            
            //if(step % 2 == 1 and yy+step > y) yy -= step, step++;
            //else if(step % 2 == 0 and yy-step < y) y += step, step++;
            
            //cout << path << " " << xx << endl;
            
            while(xx != x) {
                //cout << path << " " << xx << endl;
                if(step % 2) xx += step, path+='E';
                else xx -= step, path+='W';
                step++;
            }
        }
        
        
        //q.clear();
        //q.insert(MP(0, MP( MP(0,0), MP(1, ""))));
        //string ret = "";
        //while(!q.empty()) {
        //    pair < int , pair< pair< int,  int>, pair<int, string> > > p = *q.begin();
        //    q.erase(q.begin());
        //    
        //    string & path = p.Y.Y.Y;
        //    int xx = p.Y.X.X, yy = p.Y.X.Y, step = p.Y.Y.X;
        //    
        //    if(xx == x and yy+step == y) {
        //        ret = path + 'N';
        //        break;
        //    } else if(aabs(xx) <= 300 and aabs(yy+step) <= 300) q.insert(MP(SZ(path)+1, MP( MP(xx, yy+step), MP(step+1, path+'N'))));
        //    
        //    if(xx == x and yy-step == y) {
        //        ret = path + 'S';
        //        break;
        //    } else if(aabs(xx) <= 300 and aabs(yy-step) <= 300) q.insert(MP(SZ(path)+1, MP( MP(xx, yy-step), MP(step+1, path+'S'))));
        //    
        //    if(xx+step == x and yy == y) {
        //        ret = path + 'E';
        //        break;
        //    } else if(aabs(xx+step) <= 300 and aabs(yy) <= 300) q.insert(MP(SZ(path)+1, MP( MP(xx+step, yy), MP(step+1, path+'E'))));
        //    
        //    if(xx-step == x and yy == y) {
        //        ret = path + 'W';
        //        break;
        //    } else if(aabs(xx-step) <= 300 and aabs(yy) <= 300) q.insert(MP(SZ(path)+1, MP( MP(xx-step, yy), MP(step+1, path+'W'))));
        //}
        
        
        cout << "Case #" << caso+1 << ": " << path << endl;
    }
    
}
