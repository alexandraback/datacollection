#include <fstream>
#include <iostream>

using namespace std;

string str1,str2;
char line,row,diag1,diag2,a[5][5];
string ans[10]={"XXXT","XXTX","XTXX","TXXX","XXXX","OOOT","OOTO","OTOO","TOOO","OOOO"};
bool indica;
int n;

int check(string str){
    for (int i=0;i<10;i++)
        if (str==ans[i]){
            if (ans[i][0]=='T') return ans[i][1]; else return ans[i][0];
        }
    return ' ';
}

int main(){
    ofstream out("20130413_1.out");
    ifstream in("A-small-attempt0.in");
    in>>n;
    for (int t=0;t<n;t++){
    out<<"Case #"<<t+1<<": ";
    indica=false;
    for (int i=0;i<4;i++)
        for (int j=0;j<4;j++){
            in>>a[i][j];
            if (a[i][j]=='.') indica=true;
    }
    getline(in,str1);
    for (int i=0;i<4;i++){
        line=' ';
        row=' ';
        str1="";
        str2="";
        for (int j=0;j<4;j++){
            str1+=a[i][j];
            str2+=a[j][i];
        }
        line=check(str1);
        row=check(str2);
        if (line!=' '){
            out<<line<<" won"<<endl;
            break;
        }
        if (row!=' '){
            out<<row<<" won"<<endl;
            break;
        }
    }
    if (line!=' '||row!=' ') continue;
    diag1=' ';
    diag2=' ';
    str1="";
    str2="";
    for (int i=0;i<4;i++){
        str1+=a[i][i];
        str2+=a[i][3-i];
    }
    diag1=check(str1);
    diag2=check(str2);
        if (diag1!=' '){
            out<<diag1<<" won"<<endl;
            continue;
        }
        if (diag2!=' '){
            out<<diag2<<" won"<<endl;
            continue;
        }
    if (indica) out<<"Game has not completed"<<endl;
    else out<<"Draw"<<endl;
}
    return 0;
}
