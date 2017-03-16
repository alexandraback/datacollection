#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool Win(vector<string> M, char S)
{
    int pnum = 0;
    int qnum =0;
    for(int i=0; i< 4; i++)
    {
        int num =0;
        for(int j=0; j<4;j++)
        {
            if(M[i][j]==S|| M[i][j]=='T')
                num++;
        }
        if (num == 4) return true;
        num = 0;
        for (int j=0; j<4; j++)
        {
            if(M[j][i]==S || M[j][i]=='T')
                num++;
        }
        if(num == 4 ) return true;
        if(M[i][i]== S || M[i][i]=='T') pnum++;
        if(M[i][3-i] == S || M[i][3-i] =='T') qnum++;
    }
    return pnum==4||qnum==4;
}

bool Full(vector<string> M)
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(M[i][j] == '.')
                return false;
        }
    }
    return true;
}
int main()
{
    int T; cin>>T;
    for(int t=1;t<=T; t++)
    {
        vector<string> M;
        string tmp;
        for(int i=0; i<4; i++)
        {
            cin>>tmp;
            M.push_back(tmp);
        }
        if(Win(M,'X'))
            cout<<"Case #"<<t<<": X won"<<endl;
        else if(Win(M,'O'))
            cout<<"Case #"<<t<<": O won"<<endl;
        else if(Full(M))
            cout<<"Case #"<<t<<": Draw"<<endl;
        else
            cout<<"Case #"<<t<<": Game has not completed"<<endl;
    }
    return 0;
}
