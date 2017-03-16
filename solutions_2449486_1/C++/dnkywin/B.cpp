#include<iostream>
#include<fstream>
using namespace std;

int main(){
    int T;
    ifstream in("B.in");ofstream out("B.out");
    in>>T;
    int heights[100][100];
    bool rowelim[100], colelim[100];
    for (int t=0;t<T;t++){
        out<<"Case #"<<t+1<<": ";
        int N,M;
        in>>N>>M;
        for (int i=0;i<N;i++) for (int j=0;j<M;j++) in>>heights[i][j];

        for (int i=0;i<N;i++){
            rowelim[i] = false;
        }
        for (int j=0;j<M;j++){
            colelim[j] = false;
        }
        int rows = N, cols = M;
        while(rows>0 || cols>0){
            int m = 101;
            int mi, mj;
            for (int i=0;i<N;i++){
                for (int j=0;j<M;j++){
                    if (rowelim[i] == false && colelim[j] == false && (m>heights[i][j])){
                        m = heights[i][j];
                        mi = i;
                        mj = j;
                    }
                }
            }
            bool can_row = true;
            for (int j=0;j<M;j++){
                if (heights[mi][j]!=m && !colelim[j]){
                    can_row = false;
                    break;
                }
            }
            bool can_col = true;
            for (int i=0;i<N;i++){
                if (heights[i][mj]!=m && !rowelim[i]){
                    can_col = false;
                    break;
                }
            }
            if (!can_col && !can_row){
                out<<"NO\n";
                break;
            }
            if (can_col){
                colelim[mj] = true;
                cols--;
            }
            if (can_row){
                rowelim[mi] = true;
                rows--;
            }
        }
        if (rows==0 || cols == 0){
            out<<"YES\n";
        }
    }
}
