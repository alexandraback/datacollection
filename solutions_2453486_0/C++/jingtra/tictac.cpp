#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>

using namespace std;

int main(){
    string s;
    getline(cin, s);
    int T = atoi(s.c_str());
    int t=0;

    while(t<T){
        cout << "Case #" << ++t << ": ";
        vector<string> vec;
        while(getline(cin, s) && s.size()>3)
            vec.push_back(s);

        //check draw
        bool dots=false;
        for(int i=0; i<4; ++i){
            for(int j=0; j<4; ++j){
                if(vec[i][j]=='.') 
                    dots = true;
            }
        }

        bool draw = true;
        bool x_win;
        bool like1 = true;

        for(int i=0; i<4; ++i){
            char a;
            like1 = true;

            for(int j=0; j<4; ++j)
                if(vec[i][j] != 'T' && vec[i][j] !='.')
                    a = vec[i][j];

            for(int j=0; j<4; ++j)
                like1 = like1&(vec[i][j] == a||vec[i][j]=='T');

            if(like1){
                draw = false;
                cout << a << " won" << endl;
                break;
            }

            like1 = true;

            for(int j=0; j<4; ++j)
                if(vec[j][i] != 'T' && vec[j][i] !='.')
                    a = vec[j][i];

            for(int j=0; j<4; ++j)
                like1 = like1&(vec[j][i] == a||vec[j][i]=='T');

            if(like1){
                draw = false;
                cout << a << " won" << endl;
                break;
            }
        }

        char a;
        if(!draw) continue;

        if(vec[0][0] == '.') a='Z';
        else if(vec[0][0] == 'T'){
            if(vec[1][1] == '.') a='Z';
            a = vec[1][1];
        } else a = vec[0][0];

        like1 = true;
        for(int j=0; j<4; ++j)
            like1 = like1&(vec[j][j] == a||vec[j][j]=='T');

        if(like1){
            cout << a << " won" << endl;
            continue;
        }

        if(vec[0][3] == '.') a='Z';
        else if(vec[0][3] == 'T'){
            if(vec[1][2] == '.') a='Z';
            a = vec[1][2];
        } else a = vec[0][3];


        like1=true;
        for(int j=0; j<4; ++j)
            like1 = like1&(vec[j][3-j] == a||vec[j][3-j]=='T');

        if(like1){
            cout << a << " won" << endl;
            continue;
        }

        if(draw && dots)
            cout << "Game has not completed" << endl;
        else if(draw) 
            cout << "Draw" << endl;

    }
    return 0;
}
