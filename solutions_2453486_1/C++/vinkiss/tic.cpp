#include<iostream>
#include<cstdio>
#include<vector>
#include<string>

using namespace std;

int main(){
    int T,cas=0;
    scanf("%d",&T);
    while(T--){
        char solve[5][5];
        vector<string> veenu;
        string tmp;

        for(int i=0;i<4;i++)
            scanf("%s",solve[i]);
        for(int i=0;i<4;i++)
            veenu.push_back(solve[i]);
        for(int i=0;i<4;i++){
            tmp="";
            for(int j=0;j<4;j++){
                tmp += solve[j][i];
            }
            veenu.push_back(tmp);
        }

        tmp="";
        for(int i=0;i<4;i++){
            tmp += solve[i][i];
        }
        veenu.push_back(tmp);
        tmp="";
        for(int i=3,j=0;i>=0;i--,j++){
            tmp += solve[j][i];
        }
        veenu.push_back(tmp);

        int amit=0,xWin=0,oWin=0;
        for(int i=0;i<veenu.size();i++){
            int nX=0,nO=0;
            for(int j=0;j<4;j++){
                if(veenu[i][j]=='X'){
                    nX++;
                    continue;
                }
                else if(veenu[i][j]=='O'){
                    nO++;
                    continue;

                }
                else if(veenu[i][j]=='T'){
                    nX++;
                    nO++;
                    continue;
                }else{
                    amit++;
                }
            }
            if(nX==4)
                xWin++;
            else if(nO==4)
                oWin++;
            //cout<<i<<": "<<veenu[i]<<endl;
        }
        //cout<<"X: "<<xWin<<" O: "<<oWin<<" spaces: "<<amit<<endl;
        if(xWin > oWin){
            printf("Case #%d: X won\n",++cas);
            continue;
        }else if(oWin > xWin){
            printf("Case #%d: O won\n",++cas);
            continue;
        }else if(oWin == xWin and !amit){
            printf("Case #%d: Draw\n",++cas);
            continue;
        }else{
            printf("Case #%d: Game has not completed\n",++cas);
            continue;
        }
        cin>>tmp;
    }
}
