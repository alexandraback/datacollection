#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream cin;
    cin.open("data.txt");
    ofstream cout;
    cout.open("output.txt");
    int cases, r, c, m, contr, contc, m2;
    bool no;
    cin >> cases;
    for(int i=1;i<=cases;i++){
        no=false;
        contr=0;
        contc=0;
        cin >> r >> c >> m;
        m2=m;
        char arr[r][c];
        for(int j=0;j<r;j++){
            for(int k=0;k<c;k++){
                arr[j][k]='.';
            }
        }
        while(m!=0){
            if(contr==r){
                no=true;
                break;
            }
            arr[contr][contc]='*';
            contc++;
            if(contc==c){
                contr++;
                contc=0;
            }
            m--;
        }
        if(contr==r-2&&contc==2){
            arr[r-2][1]='.';
            arr[r-1][0]='*';
        }
        if((r==3||r==4||r==5)&&(c==4||c==5)&&contr==r-3&&contc==c-1){
            arr[r-2][0]='*';
            arr[r-1][0]='*';
            arr[r-3][c-2]='.';
            arr[r-3][c-3]='.';
            contc=0;
        }
        cout << "Case #" << i << ":" << endl;
        if(no)
            cout << "Impossible" << endl;
        else if(m2+1==r*c){
            arr[r-1][c-1]='c';
            for(int j=0;j<r;j++){
                        for(int k=0;k<c;k++){
                            cout << arr[j][k];
                        }
                        cout << endl;
                    }
        }
        else{
            if(c>=2&&r>=2){
                if(arr[r-2][c-2]!='.'||(contc+1==c&&c!=3)||(contc==1&&contr==r-2)||(r>=3&&c>=3&&contc>=c-1)||(contr==r-2&&contc==c-2))
                    cout << "Impossible" << endl;
                else{
                    arr[r-1][c-1]='c';
                    for(int j=0;j<r;j++){
                        for(int k=0;k<c;k++){
                            cout << arr[j][k];
                        }
                        cout << endl;
                    }
                }
            }
            else{
                if(c==1&&r!=1){
                    if(arr[r-2][c-1]!='.')
                        cout << "Impossible" << endl;
                    else{
                        arr[r-1][c-1]='c';
                        for(int j=0;j<r;j++){
                            for(int k=0;k<c;k++){
                                cout << arr[j][k];
                            }
                            cout << endl;
                        }
                    }
                }
                else if(r==1&&c!=1){
                    if(arr[r-1][c-2]!='.')
                        cout << "Impossible" << endl;
                    else{
                        arr[r-1][c-1]='c';
                        for(int j=0;j<r;j++){
                            for(int k=0;k<c;k++){
                                cout << arr[j][k];
                            }
                            cout << endl;
                        }
                    }
                }
                else{
                    if(arr[0][0]=='*')
                        cout << "Impossible" << endl;
                    else
                        cout << "c" << endl;
                }
            }
        }
    }
    cin.close();
    cout.close();
    return 0;
}
