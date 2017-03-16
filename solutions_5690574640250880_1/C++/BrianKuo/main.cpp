#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("C-large.in");
    ofstream fout("C-large.out");
    int n;
    fin>>n;
    for(int t=1;t<=n;t++){
        int R,C,M,s;
        fin>>R>>C>>M;
        bool ans[R][C],imp=0;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                ans[i][j]=1;
            }
        }
        s=R*C-M;
        if(s==1){
            ans[0][0]=0;
        }
        else if(R==1){
            for(int i=0;i<s;i++)
                ans[0][i]=0;
        }
        else if(C==1){
            for(int i=0;i<s;i++)
                ans[i][0]=0;
        }
        else if(s<=3||s==5||s==7){
            imp=1;
        }
        else if(s==4){
            for(int i=0;i<=1;i++)
                for(int j=0;j<=1;j++)
                    ans[i][j]=0;
        }
        else if(R==2){
            if(s%2==1)
                imp=1;
            else
                for(int i=0;i<=1;i++)
                    for(int j=0;j<s/2;j++)
                        ans[i][j]=0;
        }
        else if(C==2){
            if(s%2==1)
                imp=1;
            else
                for(int i=0;i<s/2;i++)
                    for(int j=0;j<=1;j++)
                        ans[i][j]=0;
        }
        else if(s==6){
            for(int i=0;i<=1;i++)
                for(int j=0;j<=2;j++)
                    ans[i][j]=0;
        }
        else{
            if(s<=2*C){
                int S=0;
                for(int j=0;j<C;j++){
                    for(int i=0;i<=1;i++){
                        ans[i][j]=0;
                        S++;
                        if(S==s)break;
                    }
                    if(s==S||s-S==3)break;
                }
                if(s-S==3){
                    ans[2][0]=0;
                    ans[2][1]=0;
                    ans[2][2]=0;
                }
            }
            else{
                int S=0;
                for(int i=0;i<R;i++){
                    for(int j=0;j<C;j++){
                        ans[i][j]=0;
                        S++;
                        if(S==s)break;
                    }
                    if(s==S)break;
                }
                if(s%C==1&&s/C==2){
                    ans[s/C-1][C-1]=1;
                    ans[s/C-2][C-1]=1;
                    ans[s/C][1]=0;
                    ans[s/C][2]=0;
                }
                else if(s%C==1){
                    ans[s/C-1][C-1]=1;
                    ans[s/C][1]=0;
                }
            }
        }
        char ansstr[500];
        sprintf(ansstr,"Case #%d: ",t);
        fout<<ansstr<<endl;
        if(imp==0){
            for(int i=0;i<R;i++){
                for(int j=0;j<C;j++){
                    if(i==0&&j==0)
                        fout<<'c';
                    else if(ans[i][j]==0)
                        fout<<'.';
                    else
                        fout<<'*';
                }
                fout<<endl;
            }
        }
        else
            fout<<"Impossible"<<endl;
    }
    return 0;
}
