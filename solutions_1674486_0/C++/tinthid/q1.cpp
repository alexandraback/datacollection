#include<iostream>
using namespace std;
int a[1500][1500]={0};
//int sum[1500][1500];
int n,s,start,end;
void clear(){
    for(int i=0;i<1200;i++)
        for(int j=0;j<1200;j++){
            a[i][j]=0;
            //sum[i][j]=0;
        }
}
void dfs(int x){
    if(x==end)s++;
    for(int i=0;i<n;i++){
        if(a[x][i]==1)dfs(i);
    }
}
int main(){

    int t,c;
    int m;
    cin >> t;
    for(int i=0;i<t;i++){
            clear();
            s=0;
            cin >> n;
            for(int j=0;j<n;j++){
                cin >> m;
                for(int k = 0;k<m;k++){
                    cin >> c;

                    a[j][c-1]=1;
                }
            }
            for(int j=0;j<n;j++){
                for(int k = 0;k<n;k++){
                    if(k!=j){
                        start = j;
                        end = k;
                        s=0;
                        dfs(start);
                        if(s>1)break;
                    }
                }
                if(s>1)break;
            }


            cout << "Case #" << i+1 << ": " ;
            if(s>=2)
            cout << "Yes" << endl;
            else
            cout << "No" <<endl;
    }
    return 0;
}
