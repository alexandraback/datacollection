#include<iostream>
#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int main(){
    int T,ncas=0;
    scanf("%d",&T);
    while(T--){
        char board[5][5];
        vector<string> combi;
        string tmp;

        for(int i=0;i<4;i++)
            scanf("%s",board[i]);
        for(int i=0;i<4;i++)
            combi.push_back(board[i]);
        for(int i=0;i<4;i++){
            tmp="";
            for(int j=0;j<4;j++){
                tmp += board[j][i];
            }
            combi.push_back(tmp);
        }

        tmp="";
        for(int i=0;i<4;i++){
            tmp += board[i][i];
        }
        combi.push_back(tmp);
        tmp="";
        for(int i=3,j=0;i>=0;i--,j++){
            tmp += board[j][i];
        }
        combi.push_back(tmp);

        int spacios=0,xWin=0,oWin=0;
        for(int i=0;i<combi.size();i++){
            int nX=0,nO=0;
            for(int j=0;j<4;j++){
                if(combi[i][j]=='X'){
                    nX++;
                    continue;
                }
                else if(combi[i][j]=='O'){
                    nO++;
                    continue;

                }
                else if(combi[i][j]=='T'){
                    nX++;
                    nO++;
                    continue;
                }else{
                    spacios++;
                }
            }
            if(nX==4)
                xWin++;
            else if(nO==4)
                oWin++;
            //cout<<i<<": "<<combi[i]<<endl;
        }
        //cout<<"X: "<<xWin<<" O: "<<oWin<<" spaces: "<<spacios<<endl;
        if(xWin > oWin){
            printf("Case #%d: X won\n",++ncas);
            continue;
        }else if(oWin > xWin){
            printf("Case #%d: O won\n",++ncas);
            continue;
        }else if(oWin == xWin and !spacios){
            printf("Case #%d: Draw\n",++ncas);
            continue;
        }else{
            printf("Case #%d: Game has not completed\n",++ncas);
            continue;
        }
        cin>>tmp;
    }
}
