#include <iostream>
using namespace std;

#define N 52
int b[2][N][N],vis[N][N];
char bd[N][N];
int r,c,m,rem;
bool fnd;

void print(){
    for(int i=0; i<r; i++)
        cout<<bd[i]<<endl;
}

int main(int argc, const char * argv[])
{
    ios::sync_with_stdio(false);
    int nCase; cin>>nCase;
    for(int ca=1; ca<=nCase; ca++){
        cin>>r>>c>>m;
        cout<<"Case #"<<ca<<":"<<endl;
        if(r*c==m){
            cout<<"Impossible"<<endl;
            continue;
        }
        if(r*c-m==1){
            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++)
                    cout<<(i+j==0?'c':'*');
                cout<<endl;
            }
            continue;
        }
        
        memset(bd, 0, sizeof(bd));
        fnd=false;
        int cur=0;
        for(int pos=0; pos<r*c; pos++){
            int i=pos/c, j=pos%c;
            if(cur<m&&(r==1||i<r-2)){
                bd[i][j] = '*';
                cur++;
            }
            else
                bd[i][j] = '.';
        }
        bd[r-1][c-1]='c';
        
        if(cur<m){
            if(m-cur==1&&cur>=3){
                int i=cur/c, j=cur%c;
                if(r==2||c>=3+2){
                    bd[i][j]=bd[i][j-1]=bd[i][j-2]='.';
                    for(j=0; j<2; j++)
                        bd[r-1][j]=bd[r-2][j]='*';
                    print();
                }
                else
                    cout<<"Impossible"<<endl;
            }
            else if((m-cur)%2==1 || (m-cur)/2>c-2)
                cout<<"Impossible"<<endl;
            else{
                for(int j=0; j<(m-cur)/2; j++)
                    bd[r-1][j]=bd[r-2][j]='*';
                print();
            }
        }
        else{
            int i=cur/c, j=cur%c-1;
            if(r==1 || cur%c==0 || j!=c-2)
                print();
            else if(i+1<r-2&&c>=3){
                bd[i][j]='.';
                bd[i+1][0] = '*';
                print();
            }
            else{
                if(j-2>=0){
                    bd[i][j]=bd[i][j-1]='.';
                    bd[r-1][0] = bd[r-2][0]='*';
                    print();
                }
                else
                    cout<<"Impossible"<<endl;
                
            }
        }
    }
    return 0;
}

