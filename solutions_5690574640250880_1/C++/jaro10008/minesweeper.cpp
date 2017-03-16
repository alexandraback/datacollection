#include<fstream>
#include<iomanip>

using namespace std;

int main(){
    int T,R,C,M,wolne,klocki;
    char tab[2500];
    ifstream od("input");
    ofstream zap("output");
    od>>T;
    for(int licznik=1;licznik<=T;++licznik){
        zap<<"Case #"<<licznik<<":"<<endl;
        od>>R>>C>>M;
        wolne=R*C-M;
        if(wolne!=1){
            if(C==1){
                if(wolne<2){
                    zap<<"Impossible"<<endl; continue;
                }
                else{
                    zap<<"c\n";
                    while(--wolne)  zap<<".\n";
                    while(M--) zap<<"*\n";
                    continue;

                }
            }
            if(R==1){
                if(wolne<2){
                    zap<<"Impossible"<<endl; continue;
                }
                else{
                    zap<<"c";
                    while(--wolne)  zap<<".";
                    while(M--) zap<<"*";
                    zap<<endl;
                    continue;

                }
            }
            if(wolne<4||(wolne%2&&(R==2||C==2))){
                zap<<"Impossible"<<endl; continue;
            }
            for(int i=0;i<R*C;++i) tab[i]='*';
            if(wolne%2==0){
                if(R>C){
                    klocki=wolne/(2*R);
                    wolne%=2*R;
                    for(int j=0;j<klocki;++j)
                    for(int i=0;i<R;++i){
                        tab[2*j+i*C]='.'; tab[2*j+i*C+1]='.';
                    }
                    if((C-2*klocki<2)||wolne==2) for(int i=0;i<wolne;++i) tab[2*klocki+i*C]='.';
                    else{
                        for(int i=0;i<wolne/2;++i){ tab[2*klocki+i*C]='.';tab[2*klocki+i*C+1]='.';}
                    }
                }
                else{
                    klocki=wolne/(2*C);
                    wolne%=2*C;
                    for(int j=0;j<klocki;++j)
                    for(int i=0;i<C;++i){
                        tab[2*j*C+i]='.'; tab[2*j*C+i+C]='.';
                    }
                    if((R-2*klocki<2)||wolne==2) for(int i=0;i<wolne;++i) tab[2*klocki*C+i]='.';
                    else{
                        for(int i=0;i<wolne/2;++i){ tab[2*klocki*C+i]='.';tab[2*klocki*C+i+C]='.';}
                    }
                }
            }
            else{
                wolne-=3;
                if(wolne<=4){zap<<"Impossible\n"; continue;}
                if(R>C){
                    klocki=wolne/(2*R);
                    wolne%=2*R;
                    for(int j=0;j<klocki;++j)
                    for(int i=0;i<R;++i){
                        tab[2*j+i*C]='.'; tab[2*j+i*C+1]='.';
                    }
                    if((C-2*klocki<2)) for(int i=0;i<wolne+3;++i) tab[2*klocki+i*C]='.';
                    else if(wolne==2){
                        if(R<5){
                            if(R<3){ zap<<"Impossible\n"; continue;}
                            else{ tab[2*klocki]='.'; tab[2*klocki+1]='.'; tab[2*klocki+C]='.'; tab[2*klocki+1+C]='.'; tab[2*klocki+2*C]='.';

                            }
                        }
                        else for(int i=0;i<5;++i) tab[2*klocki+i*C]='.';
                    }
                    else{
                        for(int i=0;i<wolne/2;++i){ tab[2*klocki+i*C]='.';tab[2*klocki+i*C+1]='.';}
                        if(C>2*(klocki+1)&&wolne/2>=3){
                            tab[2*klocki+2]='.'; tab[2*klocki+2+C]='.'; tab[2*klocki+2+2*C]='.';
                        }
                        else if(klocki){
                            if(R-wolne/2==2){
                                tab[2*klocki+(wolne/2)*C]='.';tab[2*klocki+(wolne/2)*C+1]='.';tab[2*klocki+(wolne/2+1)*C]='.';
                            }
                            else if(R-wolne/2>2){
                                tab[2*klocki+(wolne/2)*C]='.';tab[2*klocki+(wolne/2)*C+C]='.';tab[2*klocki+(wolne/2)*C+2*C]='.';
                            }
                            else{zap<<"Impossible\n"; continue;}
                        }
                        else {zap<<"Impossible\n"; continue;}
                    }
                }
                else{
                    klocki=wolne/(2*C);
                    wolne%=2*C;
                    for(int j=0;j<klocki;++j)
                    for(int i=0;i<C;++i){
                        tab[2*j*C+i]='.'; tab[2*j*C+i+C]='.';
                    }
                    if((R-2*klocki<2)) for(int i=0;i<wolne+3;++i) tab[2*klocki*C+i]='.';
                    else if(wolne==2){
                        if(C<5){
                            if(C<3){ zap<<"Impossible\n"; continue;}
                            else{ tab[2*klocki*C]='.'; tab[2*klocki*C+C]='.'; tab[2*klocki*C+1]='.'; tab[2*klocki*C+C+1]='.'; tab[2*klocki*C+2]='.';

                            }
                        }
                        else for(int i=0;i<5;++i) tab[2*klocki*C+i]='.';
                    }
                    else{
                        for(int i=0;i<wolne/2;++i){ tab[2*klocki*C+i]='.';tab[2*klocki*C+i+C]='.';}
                        if(R>2*(klocki+1)&&wolne/2>=3){
                            tab[2*klocki*C+2*C]='.'; tab[2*klocki*C+2*C+1]='.'; tab[2*klocki*C+2*C+2]='.';
                        }
                        else if(klocki){
                            if(C-wolne/2==2){
                                tab[2*klocki*C+(wolne/2)]='.';tab[2*klocki*C+(wolne/2)+C]='.';tab[2*klocki*C+(wolne/2+1)]='.';
                            }
                            else if(C-wolne/2>2){
                                tab[2*klocki*C+(wolne/2)]='.';tab[2*klocki*C+(wolne/2)+1]='.';tab[2*klocki*C+(wolne/2)+2]='.';
                            }
                            else{zap<<"Impossible\n"; continue;}
                        }
                        else {zap<<"Impossible\n"; continue;}
                    }
                }
            }
        }
        else{
            for(int i=0;i<R*C;++i) tab[i]='*';
        }
        tab[0]='c';
        for(int i=0;i<R;++i){
            for(int j=0;j<C;++j) zap<<tab[i*C+j];
            zap<<endl;
        }
    }
    od.close(); zap.close();


}
