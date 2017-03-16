#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d\n",x)
#define sll(x) scanf("%I64d",&x)
#define pll(x) printf("%I64d\n",x)
#define sc(x) scanf("%c",&x)
#define pc(x) printf("%c",x)
#define sf(x) scanf("%f",&x)
#define pf(x) printf("%f",x)
#define sd(x) scanf("%lf",&x)
#define pd(x) printf("%lf",x)
#define sld(x) scanf("%Lf",&x)
#define pld(x) printf("%Lf",x)
#define clr(a) memset(a,0,sizeof(a))
#define MOD 1000000009
using namespace std;
char x[5][5];
ofstream f2("output.txt");
int n[5][5];
int r,c,m;
//int eq(char a[5][5],char b[5][5]){
//    for(int i=0;i<r;i++){
//        for(int j=0;j<c;j++){
//            if(a[i][j]!=b[i][j])
//                return 0;
//        }
//    }
//    return 1;
//}
void print(){
    int first=1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(x[i][j]=='*')
                f2<<x[i][j];
            else if(first&&n[i][j]==0){
                f2<<"c";
                first=0;
            }
            else{
                f2<<x[i][j];
            }
        }
        f2<<endl;
    }
//    for(int i=0;i<r;i++){
//        for(int j=0;j<c;j++){
//            cout<<n[i][j];
//        }
//        cout<<endl;
//    }
}
int ans=0;
int zeroat(int i,int j){
    if(i<0||i>=r||j<0||j>=c)
        return 0;
    if(n[i][j]==0)
        return 1;
    else
        return 0;
}
int mineat(int i,int j){
    if(i<0||i>=r||j<0||j>=c)
        return 0;
    if(x[i][j]=='*')
        return 1;
    else
        return 0;
}
int zaround(int i,int j){
    int ans=0;
    for(int a=i-1;a<=i+1;a++){
        for(int b=j-1;b<=j+1;b++){
            if(a==i&&b==j)
                continue;
            if(zeroat(a,b))
                ans++;
        }
    }
    return ans;
}
int mines_around(int i,int j){
    int ans=0;
    for(int a=i-1;a<=i+1;a++){
        for(int b=j-1;b<=j+1;b++){
            if(a==i&&b==j)
                continue;
            if(mineat(a,b))
                ans++;
        }
    }
    return ans;
}
int check(){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(x[i][j]=='*'){
                n[i][j]=-1;
            }
            else{
                int p=mines_around(i,j);
                n[i][j]=p;
            }
        }
    }
    int first=1;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            //cout<<i<<","<<j<<" "<<n[i][j]<<endl;
            if(n[i][j]==-1)
                continue;
            if(first){
                first=0;
                if(n[i][j]!=0)
                    return 0;
                continue;
            }
            if(zaround(i,j)==0)
                return 0;
        }
    }
    return 1;
}
void solve(int placed,int currentx,int currenty){
    if(placed==m&&check()){
        ans=1;
        //cout<<"placed="<<placed<<endl;
        print();
        return;
    }
    if(placed==m)
        return;
    if(currentx==r)
        return;
    int temp=x[currentx][currenty];
    if(currenty==c-1){
        x[currentx][currenty]='.';
        solve(placed,currentx+1,0);
        if(ans){
            return;
        }
        x[currentx][currenty]='*';
        solve(placed+1,currentx+1,0);
        if(ans){
            return;
        }
        x[currentx][currenty]=temp;
    }
    else{
        x[currentx][currenty]='.';
        solve(placed,currentx,currenty+1);
        if(ans){
            return;
        }
        x[currentx][currenty]='*';
        solve(placed+1,currentx,currenty+1);
        if(ans){
            return;
        }
        x[currentx][currenty]=temp;
    }
}
int main(void){
    ifstream f1("input.txt");
    int t;
    f1>>t;
    int xx=0;
    while(t--){
        xx++;
        f1>>r>>c>>m;
        cout<<r<<" "<<c<<" "<<m<<endl;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                x[i][j]='.';
            }
        }
        if(m+1==r*c){
            f2<<"Case #"<<xx<<":\n";
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(i==0&&j==0)
                        f2<<"c";
                    else
                        f2<<"*";
                }
                f2<<endl;
            }
            continue;
        }
        if(r*c==25){
            if(m==23||m==22||m==20||m==18){
                f2<<"Case #"<<xx<<":\n";
                f2<<"Impossible\n";
                continue;
            }
            else if(m==21){
                for(int i=0;i<5;i++){
                    for(int j=0;j<5;j++){
                        x[i][j]='*';
                    }
                }
                for(int i=0;i<2;i++){
                    for(int j=0;j<2;j++){
                        x[i][j]='.';
                    }
                }
                x[0][0]='c';
                f2<<"Case #"<<xx<<":\n";
                for(int i=0;i<5;i++){
                    for(int j=0;j<5;j++){
                        f2<<x[i][j];
                    }
                    f2<<endl;
                }
                continue;
            }
        }
        f2<<"Case #"<<xx<<":\n";
        ans=0;
        solve(0,0,0);
        if(!ans){
            f2<<"Impossible\n";
        }
    }
    return 0;
}
