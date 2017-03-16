#include<iostream>
#include<cstdio>
using namespace std;

const int mx = 60;
char b[mx][mx];
int r,c,m;
void fillb(char ch){
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            b[i][j] = ch;
}
int main(){
    freopen("cfinal.in","r",stdin);
    freopen("cfinal.out","w",stdout);
    int t,m;
    bool possible;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++){
        scanf("%d %d %d",&r,&c,&m);
        fillb('.');
        possible = true;
        if(m==r*c-1){
            fillb('*');
            b[0][0] = 'c';
        }
        else if(r==1 || c==1){
            for(int i=0;i<r && m>0;i++)
                for(int j=0;j<c && m>0;j++)                    
                    b[i][j] = '*',
                        m--;
            b[r-1][c-1] = 'c';
        }
        else if(r==2 || c==2){
            if(r*c-m==2 || m%2==1) 
                possible = false;
            else{
                if(r==2){
                    for(int i=0;i<c && m>0;i++)
                        b[0][i] = b[1][i] = '*',
                        m-=2;
                    b[0][c-1] = 'c';
                }
                else{
                    for(int i=0;i<r && m>0;i++)
                        b[i][0] = b[i][1] = '*',
                        m-=2;
                    b[r-1][0] = 'c';
                }
            }
        }
        else{
            //                cout<<"m="<<m<<" r="<<r<<" c="<<c<<endl;
            if(m<=(r-2)*(c-2)){
                for(int i=0;i<r-2 && m>0;i++)
                    for(int j=0;j<c-2 && m>0;j++)
                        b[i][j] = '*', 
                        m--;
                b[r-1][c-1] = 'c';
            }
            else{
                int rem = m-(r-2)*(c-2);
                for(int i=2;i<r;i++)
                    for(int j=2;j<c;j++)
                        b[i][j] = '*';

                if(rem%2==0){
                    if(r*c-m>=4){
                        m-=(r-2)*(c-2);
                        for(int i=r-1;i>=2 && m>0;i--)
                            b[i][0] = b[i][1] = '*',
                            m-=2;
                        for(int i=c-1;i>=2 && m>0;i--)
                            b[0][i] = b[1][i] = '*',
                            m-=2;
                        b[0][0] = 'c';
                    }
                    else possible = false;
                }
                else{
                    if(r*c-m>=9){
                        m-=(r-2)*(c-2);
                        m++;
                        b[2][2] = '.';

                        for(int i=r-1;i>=3 && m>0;i--)
                            b[i][0] = b[i][1] = '*',
                                m-=2;

                        for(int i=c-1;i>=3 && m>0;i--)
                            b[0][i] = b[1][i] = '*',
                                m-=2;

                        b[0][0] = 'c';
                    }
                    else possible = false;
                }
            }


        }
//        printf("Case #%d\n",tc);
        printf("Case #%d:\n",tc);
        if(possible){
            for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                    if(b[i][j]=='r') b[i][j] = '.';
                    printf("%c",b[i][j]);
                }
                printf("\n");
            }
        }
        else printf("Impossible\n");
    }
    return 0;
}
