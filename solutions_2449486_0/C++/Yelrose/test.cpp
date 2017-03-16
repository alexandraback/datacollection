#include <iostream>
#include <cstdio>
using namespace std;

int grid[100][100];
int main(){
    int T;
    int ca = 1;
    cin >> T;
    while(T --){
        int n,m;
        cin >> n >> m;
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < m;j ++){
                cin >> grid[i][j];
            }
        }
        bool can = true;
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < m;j ++){
                bool heng = true;
                for(int k = 0;k < m;k ++){
                    if(grid[i][k] > grid[i][j])heng = false;
                }
                bool shu = true;
                for(int k = 0;k < n;k ++){

                    if(grid[k][j] > grid[i][j])shu = false;
                }
                if(!heng && !shu)can = false;
            }
        }
        printf("Case #%d: %s\n",ca,can?"YES":"NO");
        ca ++;
    }
}
