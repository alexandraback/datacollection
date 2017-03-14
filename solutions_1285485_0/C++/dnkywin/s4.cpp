#include<iostream>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

int main(){
    ifstream in("s4.in"); ofstream out("s4.out");

    int T;
    in>>T;
    for (int t=0;t<T;t++){
        int W,H,D;
        in>>H>>W>>D;
        int sx,sy;
        char c;
        string s;
        for (int i=0;i<H;i++){
            in>>s;
            for (int j=0;j<W;j++){
                if (s[j] == 'X'){
                    sx = 2*j-1;
                    sy = 2*i-1;
                }
            }
        }
        cout<<sx<<" "<<sy<<"\n";
        int w = 2*(W-2);
        int h = 2*(H-2);
        cout<<w<<" "<<h<<"\n";
        vector<int> xx;
        vector<int> yy;
        D*=2;

/*        for (int x = w*((sx - D)/w); x <= w* ((sx + D)/w)+w; x+=w ){
            for (int y = h* ((sy-D)/h); y<= h* ((sy+D)/h)+h; y+=h){
                if ((x-sx)*(x-sx) + (y-sy)*(y-sy) <=D*D){
                    bool flag=false;
                    for (int i=0;i<xx.size();i++){
                        if (((xx[i]-sx)*(y-sy) == (yy[i]-sy)*(x-sx)) && ((x-sx)*(xx[i]-sx) + (y-sy)*(yy[i]-sy)>0)){
                            flag = true;
                            break;
                        }
                    }
                    if (!flag){
                        xx.push_back(x);
                        yy.push_back(y);
                    }
                }
            }
        }*/
        for (int x = sx + 2*w*((sx - D)/(2*w)) - 2*w; x <= sx + 2*w* ((sx + D)/(2*w))+2*w; x+=2*w ){
            for (int y = sy + 2*h* ((sy-D)/(2*h)) - 2*h; y<= sy+2*h* ((sy+D)/(2*h))+2*h; y+=2*h){
                if ((x-sx)*(x-sx) + (y-sy)*(y-sy) <=D*D){
                    bool flag=false;
                    for (int i=0;i<xx.size();i++){
                        if (((xx[i]-sx)*(y-sy) == (yy[i]-sy)*(x-sx)) && ((x-sx)*(xx[i]-sx) + (y-sy)*(yy[i]-sy)>0)){
                            flag = true;
                            break;
                        }
                    }
                    if (!flag){
                        xx.push_back(x);
                        yy.push_back(y);
                    }
                }
            }
        }
        for (int x = -sx + 2*w*((sx - D)/(2*w))-2*w; x <= -sx + 2*w* ((sx + D)/(2*w))+2*w; x+=2*w ){
            for (int y = -sy + 2*h* ((sy-D)/(2*h))-2*h; y<= -sy + 2*h* ((sy+D)/(2*h))+2*h; y+=2*h){
                if ((x-sx)*(x-sx) + (y-sy)*(y-sy) <=D*D){
                    bool flag=false;
                    for (int i=0;i<xx.size();i++){
                        if (((xx[i]-sx)*(y-sy) == (yy[i]-sy)*(x-sx)) &&((x-sx)*(xx[i]-sx) + (y-sy)*(yy[i]-sy)>0)){
                            flag = true;
                            break;
                        }
                    }
                    if (!flag){
                        xx.push_back(x);
                        yy.push_back(y);
                    }
                }
            }
        }
        for (int x = sx + 2*w*((sx - D)/(2*w))-2*w; x <= sx + 2*w* ((sx + D)/(2*w))+2*w; x+=2*w ){
            for (int y = -sy + 2*h* ((sy-D)/(2*h))-2*h; y<= -sy+2*h* ((sy+D)/(2*h))+2*h; y+=2*h){
                if ((x-sx)*(x-sx) + (y-sy)*(y-sy) <=D*D){
                    bool flag=false;
                    for (int i=0;i<xx.size();i++){
                        if (((xx[i]-sx)*(y-sy) == (yy[i]-sy)*(x-sx)) && ((x-sx)*(xx[i]-sx) + (y-sy)*(yy[i]-sy)>0)){
                            flag = true;
                            break;
                        }
                    }
                    if (!flag){
                        xx.push_back(x);
                        yy.push_back(y);
                    }
                }
            }
        }
        for (int x = -sx + 2*w*((sx - D)/(2*w))-2*w; x <= -sx+ 2*w* ((sx + D)/(2*w))+2*w; x+=2*w ){
            for (int y = sy + 2*h* ((sy-D)/(2*h))-2*h; y<= sy+2*h* ((sy+D)/(2*h))+2*h; y+=2*h){
                if ((x-sx)*(x-sx) + (y-sy)*(y-sy) <=D*D){
                    bool flag=false;
                    for (int i=0;i<xx.size();i++){
                        if (((xx[i]-sx)*(y-sy) == (yy[i]-sy)*(x-sx)) && ((x-sx)*(xx[i]-sx) + (y-sy)*(yy[i]-sy)>0)){
                            flag = true;
                            break;
                        }
                    }
                    if (!flag){
                        xx.push_back(x);
                        yy.push_back(y);
                    }
                }
            }
        }
        out<<"Case #"<< t+1<<": "<<xx.size()-1<<"\n";
    }

}
