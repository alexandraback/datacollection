#include<bits/stdc++.h>
using namespace std;
string ans[]={"RICHARD","GABRIEL"};
int main(){
    int t,d;
 ifstream cin("D-large.in");
  ofstream cout("op4large.txt");
    cin>>t;
    int x,r,c,p;
    for(int tt=1;tt<=t;tt++){
        cin>>x>>r>>c;
        if(r>c)swap(r,c);
        p=0;
        if((r*c)%x==0&&x<=6&&!(x>r&&x>c)){
            if(x<=2)p=1;
            else if(x==3&&r>1&&c>1)p=1;
            else if(x==4&&(r>=3&&c>=4))p=1;
            else if(x==5&&(r*c)>=20)p=1;
            else if(x==6&&(r*c)>=30)p=1;
        }
        cout<<"Case #"<<tt<<": "<<ans[p]<<endl;

    }
    return 0;
}
