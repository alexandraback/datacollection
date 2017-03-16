#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
int check(int f[30][30],int x0,int y0,int x1,int y1){
    double x(x0+0.5),y(y0+0.5),l(0);
    double dx=x1/2000.0;
    double dy=y1/2000.0;
    for(int i=0;i<2000;i++){
      //cout<<x<<' '<<y<<' '<<l<<endl;
      x+=dx;y+=dy;
      l+=sqrt(dx*dx+dy*dy);
      //cout<<x<<' '<<y<<endl;
      if(f[(int)x][(int)y]){
          int ddx=((int)x-(int)(x-dx))*f[(int)x][(int)(y-dy)];
          int ddy=((int)y-(int)(y-dy))*f[(int)(x-dx)][(int)y];
          if(ddx){dx=-dx;x=(int)(x+0.4)+abs(x-(int)(x+0.4))*abs(dx)/dx;};
          if(ddy){dy=-dy;y=(int)(y+0.4)+abs(y-(int)(0.4+y))*abs(dy)/dy;};
          
          if(!ddx&&!ddy)return 0;
          }
          if(abs((x-x0-0.5)*(y-dy-y0-0.5)-(x-dx-x0-0.5)*(y-y0-0.5))<1e-10&&((x-x0-0.5)*(x-dx-x0-0.5)<0||(y-y0-0.5)*(y-dy-y0-0.5)<0)&&l>0.5&&l<sqrt(x1*x1+y1*y1)-0.5){
              //cout<<(x-x0-0.5)<<(x-dx-x0-0.5)<<' '<<(y-y0-0.5)<<(y-dy-y0-0.5)<<' '<<x1<<' '<<y1<<' '<<i;cin>>l;
              return 0;}
      }
      
    //cin>>l;
    if((x-x0-0.5)*(x-x0-0.5)+(y-y0-0.5)*(y-y0-0.5)<0.3){//cout<<l<<' '<<x1<<' '<<y1<<' '<<x<<' '<<y<<endl;
    return 1;}
    else return 0;
}
int main(){
    ifstream in;
    in.open("D-large.in");
    ofstream out;
    out.open("large.out");
    int n;
    in>>n;
    for(int i=0;i<n;i++){
        int h,w,d,px,py,s(0);
        in>>h>>w>>d;
        int f[30][30]={0};
        for(int j=0;j<h;j++)
            for(int k=0;k<w;k++){
                char c;
                in>>c;
                if(c=='#')f[j][k]=1;
                if(c=='X'){px=j;py=k;}
                };
            //check(f,px,py,7,0);
            //cin>>s;
        for(int j=-d;j<d+1;j++)
            for(int k=-d;k<d+1;k++)
                if(j*j+k*k<=d*d&&(j!=0||k!=0))//{
                    s+=check(f,px,py,j,k);//if(check(f,px,py,j,k))out<<s<<' '<<j<<' '<<k<<endl;}
        out<<"Case #"<<i+1<<": "<<s<<endl;
        //cin>>s;
        }
    }
