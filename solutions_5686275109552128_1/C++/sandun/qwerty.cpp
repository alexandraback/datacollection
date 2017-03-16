100
1
3
4
1 2 1 2
1
4
5
5 7 7 1 7
3
8 5 2
1
6
1
1
3
5 8 4
1
9
3
2 8 5
2
2 1
3
4 2 3
4
8 8 8 8
3
8 8 8
4
9 9 3 4
3
8 1 9
6
1 1 5 5 9 9
4
9 3 4 3
4
4 3 2 1
2
5 5
2
9 8
5
7 8 1 4 1
3
7 5 3
5
8 8 8 8 8
5
4 5 4 2 2
5
3 4 2 2 3
3
2 8 3
4
3 8 6 5
2
9 9
3
9 9 9
5
5 5 4 3 3
5
2 3 1 5 2
3
6 4 1
4
4 8 5 7
4
9 5 9 3
5
5 1 4 3 5
4
9 5 5 8
2
4 8
4
8 4 1 9
2
9 9
5
5 4 3 2 1
6
5 5 5 5 9 9
5
4 4 5 1 2
2
8 4
4
1 5 6 8
3
4 5 6
1
5
5
3 5 5 5 4
4
8 1 2 3
4
1 9 8 7
1
4
2
7 7
6
2 9 9 9 3 3
2
9 6
3
1 5 5
2
9 7
3
1 8 1
6
3 3 5 5 9 9
3
1 2 9
6
6 6 6 6 9 9
4
7 5 3 1
3
4 2 3
2
8 8
4
6 7 5 6
3
1 1 8
4
9 9 9 9
2
4 9
4
1 3 7 9
3
8 2 1
3
9 5 1
3
6 5 4
5
8 8 3 2 3
3
7 7 3
3
8 9 4
6
9 9 9 9 9 9
3
5 4 4
5
2 5 5 4 1
6
5 6 9 6 9 6
5
9 9 9 9 9
3
3 2 1
6
7 7 7 7 7 9
1
8
3
9 7 3
5
4 5 2 4 1
4
5 4 5 9
6
6 5 4 3 2 1
2
6 6
3
7 8 8
4
1 9 8 1
4
9 1 9 4
4
7 1 7 8
6
5 5 5 9 9 9
3
5 1 7
6
3 6 6 6 9 9
4
1 8 4 4
3
1 4 3
4
4 4 1 7#include <bits/stdc++.h>
using namespace std;
const int maxn = 1500;
int cut[maxn][maxn];
int main(){
    freopen("E:\\in.txt","r",stdin);
    freopen("E:\\out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    for(int i=1;i<maxn;++i)
        cut[i][0]=i;
    for(int i=1;i<maxn;++i){
        for(int j=1;j<maxn;++j){
            if(j<=i){
                cut[i][j]=(j-1)+(i+j-1)/j;
                cut[i][j]=min(cut[i][j],cut[i][j-1]);
            }else{
                cut[i][j]=cut[i][j-1];
            }
        }
    }
    int T,n;
    static int a[111111];
    static int res[111111];
    cin>>T;
    for(int cas=1;cas<=T;++cas){
        cout<<"Case #"<<cas<<": ";
        cin>>n;
        for(int i=0;i<n;++i){
           cin>>a[i];
           res[i]=a[i];
        }
        int ma=*max_element(a,a+n);
        int ans=1111111;
        for(int sz=1;sz<=ma;++sz){
            int cut=0;
            for(int i=0;i<n;++i){
                cut+=(a[i]-1)/sz;
            }
            ans=min(ans,cut+sz);
        }
        cout<<ans<<endl;
    }
    return 0;
}


5
4 3 2 1 1
1
7
4
5 6 7 7
