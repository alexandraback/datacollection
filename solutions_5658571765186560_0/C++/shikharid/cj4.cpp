#include<bits/stdc++.h>
using namespace std;
string ans[]={"RICHARD","GABRIEL"};
int main(){
    int t,d;
  //ifstream cin("D-small-attempt3.in");
  //ofstream cout("output3.txt");
    cin>>t;
    int x,r,c,p;
    for(int tt=1;tt<=t;tt++){
        cin>>x>>r>>c;
        p=0;
        if((r*c)%x==0&&x<=6&&!(x>r&&x>c)){
            if(x<=2)p=1;
            else if(x==3&&r>1&&c>1)p=1;
            else if(x==4&&((r==4&&c==4)||(r==3&&c==4)||(r==4&&c==3)))p=1;
            else if(x==5&&r>=3&&c>=5)p=1;
            else if(x==6){
                if(c==20&&(r%3)==0)p=1;
                if(c==15&&(r%4)==0)p=1;
                if(c==12&&(r%5)==0)p=1;
                if((c==10||c==20)&&r%6==0)p=1;
            }
        }
        cout<<"Case #"<<tt<<": "<<ans[p]<<endl;

    }
    return 0;
}
