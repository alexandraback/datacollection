#include <iostream>
#include <string>

using namespace std;

int main(){
    int T;
    cin>>T;
    int tempT=T;
    while(tempT-->0){
        string s;
        cin>>s;
        
        int count[26]={0};
        int digit[10];
        for(int i=0;i<s.length();i++){
            count[(int)(s[i])-65]++;
        }
        digit[0]=count[(int)('Z')-65];
        count[(int)('Z')-65]-=digit[0];
        count[(int)('E')-65]-=digit[0];
        count[(int)('R')-65]-=digit[0];
        count[(int)('O')-65]-=digit[0];
        digit[2]=count[(int)('W')-65];
        count[(int)('T')-65]-=digit[2];
        count[(int)('W')-65]-=digit[2];
        count[(int)('O')-65]-=digit[2];
        digit[8]=count[(int)('G')-65];
        count[(int)('E')-65]-=digit[8];
        count[(int)('I')-65]-=digit[8];
        count[(int)('G')-65]-=digit[8];
        count[(int)('H')-65]-=digit[8];
        count[(int)('T')-65]-=digit[8];
        digit[6]=count[(int)('X')-65];
        count[(int)('S')-65]-=digit[6];
        count[(int)('I')-65]-=digit[6];
        count[(int)('X')-65]-=digit[6];
        digit[4]=count[(int)('U')-65];
        count[(int)('F')-65]-=digit[4];
        count[(int)('O')-65]-=digit[4];
        count[(int)('U')-65]-=digit[4];
        count[(int)('R')-65]-=digit[4];
        digit[5]=count[(int)('F')-65];
        count[(int)('F')-65]-=digit[5];
        count[(int)('I')-65]-=digit[5];
        count[(int)('V')-65]-=digit[5];
        count[(int)('E')-65]-=digit[5];
        digit[7]=count[(int)('V')-65];
        count[(int)('S')-65]-=digit[7];
        count[(int)('E')-65]-=digit[7]*2;
        count[(int)('V')-65]-=digit[7];
        count[(int)('N')-65]-=digit[7];
        digit[1]=count[(int)('O')-65];
        count[(int)('O')-65]-=digit[1];
        count[(int)('N')-65]-=digit[1];
        count[(int)('E')-65]-=digit[1];
        digit[9]=count[(int)('I')-65];
        count[(int)('N')-65]-=digit[9]*2;
        count[(int)('I')-65]-=digit[9];
        count[(int)('E')-65]-=digit[9];
        digit[3]=count[(int)('H')-65];
        cout<<"Case #"<<T-tempT<<": ";
        for(int i=0;i<10;i++){
            for(int j=0;j<digit[i];j++){
                cout<<i;
            }
        }
        cout<<endl;
    }
    return 0;
}