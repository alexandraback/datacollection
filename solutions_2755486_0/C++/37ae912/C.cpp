
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Base = 5000;

struct Node{
    int w,e,d,s;
    Node(int _w, int _e, int _d, int _s):w(_w), e(_e), d(_d), s(_s) { }

    bool operator < (const Node& nd)const{
        return d < nd.d;
    }
};


int buf[100010];
vector<Node> vn;

bool check(int w, int e, int s)
{
    bool res=false;

    for (int i=w; i<=e; ++i){
        if( buf[Base + i] <s ){
            res = true;
            //buf[Base + i] = s;
        }
    }

    //printf("w=%d e=%d s=%d res=%s\n", w,e, s, res ? "success" : "false");
    return res;
}

void update(int w, int e, int s)
{
    for (int i=w; i<=e; ++i){
        if( buf[Base + i] <s ){
            buf[Base + i] = s;
        }
    }
}

int main()
{
    int t,cs=0;
    scanf("%d",&t);
    while(cs++<t){
        
        int n;
        scanf("%d",&n);
        vn.clear();
        memset(buf,0,sizeof(buf));

        for(int i=0;i<n;++i){
            int di,ni,wi,ei,si, tdi, tpi, tsi;

            scanf("%d%d%d%d%d%d%d%d", &di, &ni, &wi, &ei, &si, &tdi, &tpi, &tsi);
        
            for(int j=0;j<ni;++j){
                int d = di + j*tdi;
                int w = wi + j*tpi;
                int e = ei + j*tpi;
                int s = si + j*tsi;
                vn.push_back( Node(2*w,2*e,d,s) );
            }
        }

        sort( vn.begin(), vn.end() );
    
        int res=0;

        int day = vn[0].d;
        for(int i=0;i<vn.size(); ++i){
            if( vn[i].d > day ){
                for(int j=i-1;j>=0;--j){
                    if(day == vn[j].d){
                        update(vn[j].w, vn[j].e, vn[j].s);
                    }
                    else break;
                }
                day = vn[i].d;
            }
            if( check( vn[i].w, vn[i].e, vn[i].s ) ) res++; 
        }
    
        printf("Case #%d: ",cs);

        cout<<res<<endl;

    }



    return 0;
}
