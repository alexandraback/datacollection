#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(){
    int T;
    ifstream in("A.in"); ofstream out("A.out");
    in>>T;
    int b[4][4][3];
    int num[4][4];for(int i=0;i<4;i++) for (int j=0;j<4;j++) num[i][j] = 0;
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            b[i][j][num[i][j]] = i;
            num[i][j]++;
        }
    }
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            b[i][j][num[i][j]] = j+4;
            num[i][j]++;
        }
    }
    for (int i=0;i<4;i++){
        b[i][i][num[i][i]] = 8;
        num[i][i]++;
    }
    for (int i=0;i<4;i++){
        b[i][3-i][num[i][3-i]] = 9;
        num[i][3-i]++;
    }
    for (int t=0;t<T;t++){
        out<<"Case #"<<t+1<<": ";
        string s[4];
        for (int i=0;i<4;i++) in>>s[i];
        int val[10]; for (int i=0;i<10;i++) val[i] = 0;
        int used = 0;
        int Ti=-1,Tj;
        for (int i=0;i<4;i++){
            for (int j=0;j<4;j++){
                int add = 0;
                if (s[i][j] == 'X'){add = 1;used++;}
                if (s[i][j] == 'O'){add = -1;used++;}
                if (s[i][j] == 'T'){used++;Ti = i; Tj = j;}
                for (int k=0;k<num[i][j];k++){
                    val[b[i][j][k]]+=add;
                }
            }
        }
        if (Ti>=0){
            for (int k=0;k<num[Ti][Tj];k++){
                if (val[b[Ti][Tj][k]]==3) val[b[Ti][Tj][k]]++;
                if (val[b[Ti][Tj][k]]==-3) val[b[Ti][Tj][k]]--;
            }
        }
        bool ended = (used==16);
        bool wins = false;
        bool Xwins = false;
        for (int i=0;i<10;i++){
            if (val[i]==4){
                wins = true;
                Xwins = true;
                break;
            }
            if (val[i]==-4){
                wins = true;
                Xwins = false;
                break;
            }
        }
        if (wins){
            if (Xwins){
                out<<"X won\n";
            }
            else{
                out<<"O won\n";
            }
        }
        else{
            if (ended){
                out<<"Draw\n";
            }
            else{
                out<<"Game has not completed\n";
            }
        }
    }

}
