//for small test case

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <locale>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct centre{
long long int x;
long long int y;
}place;

int main(void)
{
    ifstream cin ("B-small-attempt2.in");
    ofstream cout ("B-small-attempt2.out");
    long long int T,h;
    long long int N;
    double ans;
    cin>>T;
    for(h=0;h<T;h++)
    {
        cin>>N>>place.x>>place.y;
        //cout<<N<<" "<<place.x<<" "<<place.y<<"\n";
        if(N==1){
            if(place.x==0&&place.y==0)  ans=1;
            else                        ans=0;
        }

        else if(N==2){
            if(place.x==0&&place.y==0)          ans=1;
            else if(place.x==2&&place.y==0)     ans=0.5;
            else if(place.x==-2&&place.y==0)    ans=0.5;
            else                                ans=0;
        }

        else if(N==3){
            if(place.x==0&&place.y==0)          ans=1;
            else if(place.x==2&&place.y==0)     ans=0.75;
            else if(place.x==-2&&place.y==0)    ans=0.75;
            else if(place.x==1&&place.y==1)     ans=0.25;
            else if(place.x==-1&&place.y==1)    ans=0.25;
            else                                ans=0;
        }

        else if(N==4){
            if(place.x==0&&place.y==0)          ans=1;
            else if(place.x==2&&place.y==0)     ans=1;
            else if(place.x==-2&&place.y==0)    ans=1;
            else if(place.x==1&&place.y==1)     ans=0.5;
            else if(place.x==-1&&place.y==1)    ans=0.5;
            else                                ans=0;
        }

        else if(N==5){
            if(place.x==0&&place.y==0)          ans=1;
            else if(place.x==2&&place.y==0)     ans=1;
            else if(place.x==-2&&place.y==0)    ans=1;
            else if(place.x==1&&place.y==1)     ans=1;
            else if(place.x==-1&&place.y==1)    ans=1;
            else                                ans=0;
        }

        else if(N==6){
            if(place.x==0&&place.y==0)          ans=1;
            else if(place.x==2&&place.y==0)     ans=1;
            else if(place.x==-2&&place.y==0)    ans=1;
            else if(place.x==1&&place.y==1)     ans=1;
            else if(place.x==-1&&place.y==1)    ans=1;
            else if(place.x==1&&place.y==2)     ans=1;
            else                                ans=0;
        }

        else if(N==7){
            if(place.x==0&&place.y==0)          ans=1;
            else if(place.x==2&&place.y==0)     ans=1;
            else if(place.x==-2&&place.y==0)    ans=1;
            else if(place.x==1&&place.y==1)     ans=1;
            else if(place.x==-1&&place.y==1)    ans=1;
            else if(place.x==1&&place.y==2)     ans=1;
            else if(place.x==-4&&place.y==0)    ans=0.5;
            else if(place.x==4&&place.y==0)     ans=0.5;
            else                                ans=0;
        }

        else if(N==8){
            if(place.x==0&&place.y==0)          ans=1;
            else if(place.x==2&&place.y==0)     ans=1;
            else if(place.x==-2&&place.y==0)    ans=1;
            else if(place.x==1&&place.y==1)     ans=1;
            else if(place.x==-1&&place.y==1)    ans=1;
            else if(place.x==1&&place.y==2)     ans=1;
            else if(place.x==-4&&place.y==0)    ans=0.75;
            else if(place.x==4&&place.y==0)     ans=0.75;
            else if(place.x==-3&&place.y==1)    ans=0.25;
            else if(place.x==3&&place.y==1)     ans=0.25;
            else                                ans=0;
        }

        else if(N==9){
            if(place.x==0&&place.y==0)          ans=1;
            else if(place.x==2&&place.y==0)     ans=1;
            else if(place.x==-2&&place.y==0)    ans=1;
            else if(place.x==1&&place.y==1)     ans=1;
            else if(place.x==-1&&place.y==1)    ans=1;
            else if(place.x==1&&place.y==2)     ans=1;
            else if(place.x==-4&&place.y==0)    ans=0.875;
            else if(place.x==4&&place.y==0)     ans=0.875;
            else if(place.x==-3&&place.y==1)    ans=0.5;
            else if(place.x==3&&place.y==1)     ans=0.5;
            else if(place.x==-2&&place.y==2)    ans=0.125;
            else if(place.x==2&&place.y==2)     ans=0.125;
            else                                ans=0;
        }

        else if(N==10){
            if(place.x==0&&place.y==0)          ans=1;
            else if(place.x==2&&place.y==0)     ans=1;
            else if(place.x==-2&&place.y==0)    ans=1;
            else if(place.x==1&&place.y==1)     ans=1;
            else if(place.x==-1&&place.y==1)    ans=1;
            else if(place.x==1&&place.y==2)     ans=1;
            else if(place.x==-4&&place.y==0)    ans=0.9375;
            else if(place.x==4&&place.y==0)     ans=0.9375;
            else if(place.x==-3&&place.y==1)    ans=0.6875;
            else if(place.x==3&&place.y==1)     ans=0.6875;
            else if(place.x==-2&&place.y==2)    ans=0.3125;
            else if(place.x==2&&place.y==2)     ans=0.3125;
            else if(place.x==-1&&place.y==3)    ans=0.0625;
            else if(place.x==1&&place.y==3)     ans=0.0625;
            else                                ans=0;
        }

        else if(N==11){
            if(place.x==0&&place.y==0)          ans=1;
            else if(place.x==2&&place.y==0)     ans=1;
            else if(place.x==-2&&place.y==0)    ans=1;
            else if(place.x==1&&place.y==1)     ans=1;
            else if(place.x==-1&&place.y==1)    ans=1;
            else if(place.x==1&&place.y==2)     ans=1;
            else if(place.x==-4&&place.y==0)    ans=1;
            else if(place.x==4&&place.y==0)     ans=1;
            else if(place.x==-3&&place.y==1)    ans=0.8333333;
            else if(place.x==3&&place.y==1)     ans=0.8333333;
            else if(place.x==-2&&place.y==2)    ans=0.5;
            else if(place.x==2&&place.y==2)     ans=0.5;
            else if(place.x==-1&&place.y==3)    ans=0.1666667;
            else if(place.x==1&&place.y==3)     ans=0.1666667;
            else                                ans=0;
        }

        else if(N==12){
            if(place.x==0&&place.y==0)          ans=1;
            else if(place.x==2&&place.y==0)     ans=1;
            else if(place.x==-2&&place.y==0)    ans=1;
            else if(place.x==1&&place.y==1)     ans=1;
            else if(place.x==-1&&place.y==1)    ans=1;
            else if(place.x==1&&place.y==2)     ans=1;
            else if(place.x==-4&&place.y==0)    ans=1;
            else if(place.x==4&&place.y==0)     ans=1;
            else if(place.x==-3&&place.y==1)    ans=1;
            else if(place.x==3&&place.y==1)     ans=1;
            else if(place.x==-2&&place.y==2)    ans=0.75;
            else if(place.x==2&&place.y==2)     ans=0.75;
            else if(place.x==-1&&place.y==3)    ans=0.25;
            else if(place.x==1&&place.y==3)     ans=0.25;
            else                                ans=0;
        }

        else if(N==13){
            if(place.x==0&&place.y==0)          ans=1;
            else if(place.x==2&&place.y==0)     ans=1;
            else if(place.x==-2&&place.y==0)    ans=1;
            else if(place.x==1&&place.y==1)     ans=1;
            else if(place.x==-1&&place.y==1)    ans=1;
            else if(place.x==1&&place.y==2)     ans=1;
            else if(place.x==-4&&place.y==0)    ans=1;
            else if(place.x==4&&place.y==0)     ans=1;
            else if(place.x==-3&&place.y==1)    ans=1;
            else if(place.x==3&&place.y==1)     ans=1;
            else if(place.x==-2&&place.y==2)    ans=1;
            else if(place.x==2&&place.y==2)     ans=1;
            else if(place.x==-1&&place.y==3)    ans=0.5;
            else if(place.x==1&&place.y==3)     ans=0.5;
            else                                ans=0;
        }
        else if(N==14){
            if(place.x==0&&place.y==0)          ans=1;
            else if(place.x==2&&place.y==0)     ans=1;
            else if(place.x==-2&&place.y==0)    ans=1;
            else if(place.x==1&&place.y==1)     ans=1;
            else if(place.x==-1&&place.y==1)    ans=1;
            else if(place.x==1&&place.y==2)     ans=1;
            else if(place.x==-4&&place.y==0)    ans=1;
            else if(place.x==4&&place.y==0)     ans=1;
            else if(place.x==-3&&place.y==1)    ans=1;
            else if(place.x==3&&place.y==1)     ans=1;
            else if(place.x==-2&&place.y==2)    ans=1;
            else if(place.x==2&&place.y==2)     ans=1;
            else if(place.x==-1&&place.y==3)    ans=1;
            else if(place.x==1&&place.y==3)     ans=1;
            else                                ans=0;
        }

        else if(N==15){
            if(place.x==0&&place.y==0)          ans=1;
            else if(place.x==2&&place.y==0)     ans=1;
            else if(place.x==-2&&place.y==0)    ans=1;
            else if(place.x==1&&place.y==1)     ans=1;
            else if(place.x==-1&&place.y==1)    ans=1;
            else if(place.x==1&&place.y==2)     ans=1;
            else if(place.x==-4&&place.y==0)    ans=1;
            else if(place.x==4&&place.y==0)     ans=1;
            else if(place.x==-3&&place.y==1)    ans=1;
            else if(place.x==3&&place.y==1)     ans=1;
            else if(place.x==-2&&place.y==2)    ans=1;
            else if(place.x==2&&place.y==2)     ans=1;
            else if(place.x==-1&&place.y==3)    ans=1;
            else if(place.x==1&&place.y==3)     ans=1;
            else if(place.x==0&&place.y==4)     ans=1;
            else                                ans=0;
        }

        else if(N==16){
            if(place.x==0&&place.y==0)          ans=1;
            else if(place.x==2&&place.y==0)     ans=1;
            else if(place.x==-2&&place.y==0)    ans=1;
            else if(place.x==1&&place.y==1)     ans=1;
            else if(place.x==-1&&place.y==1)    ans=1;
            else if(place.x==1&&place.y==2)     ans=1;
            else if(place.x==-4&&place.y==0)    ans=1;
            else if(place.x==4&&place.y==0)     ans=1;
            else if(place.x==-3&&place.y==1)    ans=1;
            else if(place.x==3&&place.y==1)     ans=1;
            else if(place.x==-2&&place.y==2)    ans=1;
            else if(place.x==2&&place.y==2)     ans=1;
            else if(place.x==-1&&place.y==3)    ans=1;
            else if(place.x==1&&place.y==3)     ans=1;
            else if(place.x==0&&place.y==4)     ans=1;
            else if(place.x==-6&&place.y==0)    ans=0.5;
            else if(place.x==6&&place.y==0)     ans=0.5;
            else                                ans=0;
        }

        else if(N==17){
            if(place.x==0&&place.y==0)          ans=1;
            else if(place.x==2&&place.y==0)     ans=1;
            else if(place.x==-2&&place.y==0)    ans=1;
            else if(place.x==1&&place.y==1)     ans=1;
            else if(place.x==-1&&place.y==1)    ans=1;
            else if(place.x==1&&place.y==2)     ans=1;
            else if(place.x==-4&&place.y==0)    ans=1;
            else if(place.x==4&&place.y==0)     ans=1;
            else if(place.x==-3&&place.y==1)    ans=1;
            else if(place.x==3&&place.y==1)     ans=1;
            else if(place.x==-2&&place.y==2)    ans=1;
            else if(place.x==2&&place.y==2)     ans=1;
            else if(place.x==-1&&place.y==3)    ans=1;
            else if(place.x==1&&place.y==3)     ans=1;
            else if(place.x==0&&place.y==4)     ans=1;
            else if(place.x==-6&&place.y==0)    ans=0.75;
            else if(place.x==6&&place.y==0)     ans=0.75;
            else if(place.x==-5&&place.y==1)    ans=0.25;
            else if(place.x==5&&place.y==1)     ans=0.25;
            else                                ans=0;
        }

        else if(N==18){
            if(place.x==0&&place.y==0)          ans=1;
            else if(place.x==2&&place.y==0)     ans=1;
            else if(place.x==-2&&place.y==0)    ans=1;
            else if(place.x==1&&place.y==1)     ans=1;
            else if(place.x==-1&&place.y==1)    ans=1;
            else if(place.x==1&&place.y==2)     ans=1;
            else if(place.x==-4&&place.y==0)    ans=1;
            else if(place.x==4&&place.y==0)     ans=1;
            else if(place.x==-3&&place.y==1)    ans=1;
            else if(place.x==3&&place.y==1)     ans=1;
            else if(place.x==-2&&place.y==2)    ans=1;
            else if(place.x==2&&place.y==2)     ans=1;
            else if(place.x==-1&&place.y==3)    ans=1;
            else if(place.x==1&&place.y==3)     ans=1;
            else if(place.x==0&&place.y==4)     ans=1;
            else if(place.x==-6&&place.y==0)    ans=0.875;
            else if(place.x==6&&place.y==0)     ans=0.875;
            else if(place.x==-5&&place.y==1)    ans=0.5;
            else if(place.x==5&&place.y==1)     ans=0.5;
            else if(place.x=-4&&place.y==2)     ans=0.125;
            else if(place.x==4&&place.y==2)     ans=0.125;
            else                                ans=0;
        }

        else if(N==19){
            if(place.x==0&&place.y==0)          ans=1;
            else if(place.x==2&&place.y==0)     ans=1;
            else if(place.x==-2&&place.y==0)    ans=1;
            else if(place.x==1&&place.y==1)     ans=1;
            else if(place.x==-1&&place.y==1)    ans=1;
            else if(place.x==1&&place.y==2)     ans=1;
            else if(place.x==-4&&place.y==0)    ans=1;
            else if(place.x==4&&place.y==0)     ans=1;
            else if(place.x==-3&&place.y==1)    ans=1;
            else if(place.x==3&&place.y==1)     ans=1;
            else if(place.x==-2&&place.y==2)    ans=1;
            else if(place.x==2&&place.y==2)     ans=1;
            else if(place.x==-1&&place.y==3)    ans=1;
            else if(place.x==1&&place.y==3)     ans=1;
            else if(place.x==0&&place.y==4)     ans=1;
            else if(place.x==-6&&place.y==0)    ans=0.9375;
            else if(place.x==6&&place.y==0)     ans=0.9375;
            else if(place.x==-5&&place.y==1)    ans=0.6875;
            else if(place.x==5&&place.y==1)     ans=0.6875;
            else if(place.x=-4&&place.y==2)     ans=0.3125;
            else if(place.x==4&&place.y==2)     ans=0.3125;
            else if(place.x==-3&&place.y==3)    ans=0.0625;
            else if(place.x==3&&place.y==3)     ans=0.0625;
            else                                ans=0;
        }

        else if(N==20){
            if(place.x==0&&place.y==0)          ans=1;
            else if(place.x==2&&place.y==0)     ans=1;
            else if(place.x==-2&&place.y==0)    ans=1;
            else if(place.x==1&&place.y==1)     ans=1;
            else if(place.x==-1&&place.y==1)    ans=1;
            else if(place.x==1&&place.y==2)     ans=1;
            else if(place.x==-4&&place.y==0)    ans=1;
            else if(place.x==4&&place.y==0)     ans=1;
            else if(place.x==-3&&place.y==1)    ans=1;
            else if(place.x==3&&place.y==1)     ans=1;
            else if(place.x==-2&&place.y==2)    ans=1;
            else if(place.x==2&&place.y==2)     ans=1;
            else if(place.x==-1&&place.y==3)    ans=1;
            else if(place.x==1&&place.y==3)     ans=1;
            else if(place.x==0&&place.y==4)     ans=1;
            else if(place.x==-6&&place.y==0)    ans=0.96875;
            else if(place.x==6&&place.y==0)     ans=0.96875;
            else if(place.x==-5&&place.y==1)    ans=0.8125;
            else if(place.x==5&&place.y==1)     ans=0.8125;
            else if(place.x=-4&&place.y==2)     ans=0.5;
            else if(place.x==4&&place.y==2)     ans=0.5;
            else if(place.x==-3&&place.y==3)    ans=0.1875;
            else if(place.x==3&&place.y==3)     ans=0.1875;
            else if(place.x==-2&&place.y==4)    ans=0.03125;
            else if(place.x==2&&place.y==4)     ans=0.03125;
            else                                ans=0;
        }

        cout<<"Case #"<<h+1<<": "<<ans;
        cout<<"\n";
    }

    return 0;
}
