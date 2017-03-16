#include<bits/stdc++.h>
using namespace std;
void get(int x[4][4]){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            cin>>x[i][j];
    }
}
int main()
{
    freopen("A-small-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    int x[4][4],y[4][4];
    int tc;
    cin>>tc;
    int a,b;

    for(int t=1;t<=tc;t++){
        cin>>a;get(x);
        cin>>b;get(y);
        int count=0;int ans;
        for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        if(x[a-1][i]==y[b-1][j]){
            count++;
            ans=x[a-1][i];
        }
        cout<<"Case #"<<t<<": ";
        switch(count){
    case 1:
        cout<<ans<<endl;
        break;
    case 0:
        cout<<"Volunteer cheated!"<<endl;
        break;
    default:
       cout<<"Bad magician!"<<endl;
       break;

        }
    }
}




