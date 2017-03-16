#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int abs(int i)
{
    return i>0?i:-i;
}
int getend(int sum){
    int i,j=0;
    for(i=1;i<100000;i++){
        j+=i;
        if(sum<=j){
            if((j-sum)%2==0)
            break;
        }

    }
    return i;
}
int getend1(int sum){
    int i,j=0;
    for(i=1;i<100000;i++){
        j+=i;
        if(sum<=j){
            break;
        }

    }
    return i;
}
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-out","w",stdout);
    int i,j,k,m,n,t,c,x,y,sum,end,del,endx,delx,endy,dely;
    cin>>t;
    for(c=1;c<=t;++c){
        cin>>x>>y;
//        cout<<x<<" "<<y<<endl;
        sum=abs(x)+abs(y);
//        cout<<sum<<endl;
        end = getend(sum);
        int ss=(end+1)*end/2-sum;
        del = ss/2;
//        cout<<end<<" "<<del<<endl;

        endx = getend1(abs(x));
        if(endx>=del)
        endx = getend1(abs(x)+del*2);
        int sx=(endx+1)*endx/2-abs(x);
        delx = sx;
//        cout<<endx<<" "<<delx<<endl;

//
//
//        endy = getend1(abs(y));
//        int sy=(endy+1)*endy/2-abs(y);
//        dely = sy;
//        cout<<endy<<" "<<dely<<endl;
        printf("Case #%d: ",c);
        for(i=1;i<=end;i++){
            //x
            if(i<=endx && i!=delx){

                if(x>0){
                    if(i==del)
                    {
                       printf("W");
                    }else{
                        printf("E");
                    }

                }else{
                    if(i==del)
                    {
                       printf("E");
                    }else{
                        printf("W");
                    }
                }

            }else{
                if(y>0){
                    if(i==del)
                    {
                       printf("S");
                    }else{
                        printf("N");
                    }

                }else{
                    if(i==del)
                    {
                       printf("N");
                    }else{
                        printf("S");
                    }
                }

            }


        }

        cout<<endl;


    }
    return 0;
}

