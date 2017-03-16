#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>
typedef long long ll;
using namespace std;
int N,T,H;
int speed[500001];
int pos[500001];
int main()
{
    freopen("txt.in","r",stdin);
    freopen("out","w",stdout);
    cin >> T;
    for(int t=0;t<T;t++){
        cin>> N;
        H=0;
        for(int i=0;i<N;i++){
            int di,hi,mi;
            cin >> di>>hi>>mi;
            for(int j=H;j<H+hi;j++){
                speed[j]=mi+j-H;
                pos[j]=di;
            }
            H+=hi;
        }
        if(H==1 || speed[1]==speed[0]){
            cout << "Case #" << t+1 << ": " << 0 << endl;
        } else {
            int slow=0;
            if(speed[1]>speed[0]){
                slow=1;
            }
            int slowPos=pos[slow];
            int slowSpeed=speed[slow];
            int fastPos=pos[1-slow];
            int fastSpeed=speed[1-slow];
            float herbPos=min(slowPos,fastPos)-0.10000000001;
            int herbSpeed=slowSpeed;
            //if(herbPos>fastPos)
                fastPos-=360;

            float tofc=(herbPos-fastPos)*(herbSpeed*fastSpeed)*1.0/(360*(fastSpeed-herbSpeed));
            if(tofc<0)tofc*=-1;
            float posOfContact1=360.0/herbSpeed*tofc+herbPos;
            //cout << tofc << " " << herbPos << " " << herbSpeed*1.0 << " " << posOfContact1 << endl;

            herbSpeed=fastSpeed;
            tofc=(herbPos-slowPos)*(herbSpeed*slowSpeed)*1.0/(360*(slowSpeed-herbSpeed));
            if(tofc<0)tofc*=-1;
            float posOfContact2=360.0/herbSpeed*tofc+herbPos;
            //cout << tofc << " " << herbPos << " " << herbSpeed*1.0 << " " << posOfContact2 << endl;
            if(posOfContact1>360 || posOfContact2>360){
                cout << "Case #" << t+1 << ": " << 0 << endl;
            } else {
                cout << "Case #" << t+1 << ": " << 1 << endl;
            }
        }
    }
    return 0;
}
