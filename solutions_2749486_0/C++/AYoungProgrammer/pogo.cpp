#include <iostream>
#include <map>
#include <queue>
#include <sstream>
using namespace std;

struct node{
    int x,y,w;
    string dir;
};

int main(){


   freopen("pogo.in","r",stdin);
    freopen("pogo.out","w",stdout);

    int t;
    cin>>t;

    for(int T=0;T<t;T++){
        printf("Case #%d: ",T+1);
        int x,y;
        cin>>x>>y;

        int cx = 0;
        int cy = 0;
        int cur = 1;
        stringstream ss;
        while(cx!=x){
            if(cx<x){
                cx-=cur;
                cur++;
                cx+=cur;
                ss<<"WE";
            }
            else{
                cx+=cur;
                cur++;
                cx-=cur;
                ss<<"EW";
            }
            cur++;

        }
        while(cy!=y){
            if(cy<y){
                cy-=cur;
                cur++;
                cy+=cur;
                ss<<"SN";
            }
            else{
                cy+=cur;
                cur++;
                cy-=cur;
                ss<<"NS";
            }

            cur++;
        }
        cout<<ss.str()<<endl;

    }


}
