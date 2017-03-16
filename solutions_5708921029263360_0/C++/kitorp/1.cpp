#include<bits/stdc++.h>
using namespace std;

struct node{
    int a,b,c;
}temp;
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("C-small-attempt0.in","r",stdin);
    freopen("c-small.txt","w",stdout);
    int T;
    cin>>T;
    for(int t_c=1;t_c<=T;t_c++){
        int shirtpant[10][10];
        int shirtjacket[10][10];
        int pantjacket[10][10];
        bool all[10][10][10];
        memset(shirtpant,0,sizeof(shirtpant));
        memset(shirtjacket,0,sizeof(shirtjacket));
        memset(pantjacket,0,sizeof(pantjacket));
        memset(all,0,sizeof(all));
        int J,P,S,K;
        cin>>J>>P>>S>>K;
        int num=0;
        vector<node> mv;
        for(int x=0;x<J;x++){
            for(int y=0;y<P;y++){
                for(int z=0;z<S;z++){
                    if(all[x][y][z]) continue;
                    if(shirtjacket[z][x]==K) continue;
                    if(shirtpant[z][y]==K) continue;
                    if(pantjacket[y][x]==K) continue;
                    all[x][y][z]=1;
                    shirtjacket[z][x]++;
                    shirtpant[z][y]++;
                    pantjacket[y][x]++;
                    num++;
                    temp.a=x;
                    temp.b=y;
                    temp.c=z;
                    mv.push_back(temp);

                }
            }
        }
        cout<<"Case #"<<t_c<<": "<<num<<"\n";
        for(int i=0;i<mv.size();i++){
            cout<<mv[i].a+1<<" "<<mv[i].b+1<<" "<<mv[i].c+1<<"\n";
        }
    }

}
