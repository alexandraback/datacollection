#include <stdio.h>
#include <iostream>
#include <set>

using namespace std;

int n;

double f(int i,double p,set<pair<int,int> > s,int x, int y, int xx,int yy){
    //printf("putting %d at %d %d\n", i, x, y);
    //printf("set\n");
    set<pair<int,int> >::iterator ss,ll,rr;
    for(ss = s.begin(); ss != s.end(); ss++){
        //printf("%d,%d ",ss->first, ss->second);
    }
    //printf("\n");
    if(i > n){
        ss = s.find(pair<int,int>(xx,yy));
        if(ss != s.end()){
            return 1;
        }
        else{
            return 0;
        }
    }
    
    while(true){
        //printf("x:%d y:%d\n",x,y);
        if(y == 0){
            //printf("%d placed at %d %d\n",i,x,y);
            s.insert(pair<int,int>(x,y));
            return f(i+1,p,s,0,2*(i+1),xx,yy);
        }
        ss = s.find(pair<int,int>(x,y-2));
        ll = s.find(pair<int,int>(x+1,y-1));
        rr = s.find(pair<int,int>(x-1,y-1));
        
        if(ss != s.end()){
            //printf("not found!\n");
            
            if(ll != s.end() && rr != s.end()){
                s.insert(pair<int,int>(x,y));
                return f(i+1,p,s,0,2*(i+1),xx,yy);
            }
            if(ll != s.end()){
                x -= 1;
                y -= 1;
                continue;
            }
            if(rr != s.end()){
                x += 1;
                y -= 1;
                continue;
            }
            else{
                return f(i,p/2,s,x-1,y-1,xx,yy)/2 + f(i,p/2,s,x+1,y-1,xx,yy)/2;
            }
        }
        if(ll != s.end() && rr != s.end()){
            s.insert(pair<int,int>(x,y));
            return f(i+1,p,s,0,2*(i+1),xx,yy);
        }
        if(ll != s.end()){
            x -= 1;
            y -= 1;
            continue;
        }
        if(rr != s.end()){
            x += 1;
            y -= 1;
            continue;
        }
        else {
            y--;
        }

    }
}

int main(){
    set<pair<int,int> > s;
    int testnum, test;
    int x,y;
    scanf("%d",&testnum);
    for(test = 1; test <= testnum; test++){        
        scanf("%d %d %d",&n,&x,&y);
        double ans = f(1,1,s,0,0,x,y);
        printf("Case #%d: %lf\n",test,ans);
    }
    //printf("%lf\n",ans);
    return 0;
}