
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;



struct Node{
    //Node(int _x,int _y,int _tx,int _ty):x(_x),y(_y),tx(_tx),ty(_ty){}
    Node(int _x,int _y):x(_x),y(_y){}

    int x,y;
    //int tx,ty;
    bool operator < (const Node& nd)const{
        return x<nd.x || (x==nd.x && y<nd.y);
    }
    bool samedirection(Node nd){
        return 
            (x*nd.y - y*nd.x==0) && (x*nd.x+y*nd.y>0) ;
    }
};

vector<Node> v;

char buf[50];

int main()
{
    int cs=0,T=0;
    scanf("%d",&T);
    while(cs++<T){
        v.clear();
        printf("Case #%d: ",cs);

        int w,h,d,x,y;
        int ans=0;
        scanf("%d%d%d",&h,&w,&d);
        gets(buf);
        for(int i=0;i<h;++i){
            gets(buf);
            for(int j=0;j<w;++j){
                if(buf[j]=='X')
                    //x=i,y=j;
                    x=j,y=i;
            }
        }
        int L = 1+2*d/(w-2);
        if(L<1+2*d/(h-2)) 
            L= 1+2*d/(h-2);
        //printf("L=%d d=%d x=%d y=%d w=%d h=%d\n",L,d,x,y,w,h);

        for(int i=-L;i<=L;++i){
            for(int j=-L;j<=L;++j){
                int xdelta;
                int ydelta;
                int dx,dy;

                if(i==0) xdelta=0;
                else
                    xdelta = i>0? 2*(w-1-x)-1 : 2*x-1;

                if(j==0) ydelta=0;
                else
                    ydelta = j<0? 2*(h-1-y)-1 : 2*y-1;
               
                dx = i%2==0 ? (w-2)*abs(i) : xdelta+ abs(i/2)*2*(w-2);
                dy = j%2==0 ? (h-2)*abs(j) : ydelta+ abs(j/2)*2*(h-2);
               
                if(dx*dx+dy*dy>d*d)
                    continue;


                bool ok=true;
                dx = dx*i/( i==0 ? 1 : abs(i) );
                dy = dy*j/( j==0 ? 1 : abs(j) );
                Node nd(dx,dy);
                for(int k=0;k<v.size();++k){
                    if(nd.samedirection( v[k])){
                        //printf("i=%d,j=%d voilate (%d,%d)\n",nd.x,nd.y, v[k].x, v[k].y);
                        ok=false;
                        break;
                    }
                }

 //               printf("i=%d j=%d\n",i,j);
 //               puts("OK");

                if(ok)
                    v.push_back(nd);
            }
        }

        //sort(v.begin(),v.end());
        //for(int i=0;i<v.size();++i)
        //    printf("%d %d\n",v[i].x,v[i].y);
        printf("%d\n",v.size()-1);

    }

    return 0;
}
