#include<stdio.h>
#include<cstring>
#define lgmax 50
using namespace std;
long long nra, nrb,rezanr,rezbnr,dif,rezdif,lg, t, ii,z=10,o='0';
char a[lgmax], b[lgmax], reza[lgmax], rezb[lgmax], fina[lgmax], finb[lgmax];

void verif(){
    nra=nrb=0;
    for (int index=0;index<lg;index++){
        nra=nra*z+reza[index]-o;
        nrb=nrb*z+rezb[index]-o;
    }
    dif=nra-nrb;
    if (dif<0)
        dif=-dif;
    if ((rezdif==-1)|| ((dif<rezdif) || ((dif==rezdif) && (nra<rezanr)) || ((dif==rezdif) && (nra==rezanr) && (nrb<rezbnr)))){ //??
        rezdif=dif;
        rezanr=nra;
        rezbnr=nrb;
        for (int index=0;index<lg;index++){
            fina[index]=reza[index];
            finb[index]=rezb[index];

        }
    }

}

void maiMic(int poz){
    for (int index=poz;index<lg;index++){
        reza[index]=a[index];
        if (a[index]=='?')
            reza[index]='9';
        rezb[index]=b[index];
        if (b[index]=='?')
            rezb[index]='0';
    }
    verif();
}


void maiMare(int poz){
    for (int index=poz;index<lg;index++){
        reza[index]=a[index];
        if (a[index]=='?')
            reza[index]='0';
        rezb[index]=b[index];
        if (b[index]=='?')
            rezb[index]='9';
    }
    verif();
}

bool cifra(char a){
    return (a>='0')&&(a<='9');
}

void egal(int poz){
    int index;
    for (index=poz;index<lg;index++)
        if (a[index]==b[index]){
            reza[index]=rezb[index]=a[index];
            if (reza[index]=='?'){
                reza[index]='0';
                rezb[index]='1';
                maiMic(index+1);
                reza[index]='1';
                rezb[index]='0';
                maiMare(index+1);
                reza[index]=rezb[index]='0';
            }
        }
        else
            break;
    if (index<lg){
        if (cifra(a[index])&&(cifra(b[index]))){
            reza[index]=a[index];   rezb[index]=b[index];
            if (a[index]<b[index])
                maiMic(index+1);
            if (a[index]==b[index])
                egal(index+1);
            if (a[index]>b[index])
                maiMare(index+1);
        }
        else{
            if (cifra(a[index])){
                reza[index]=a[index];
                if (a[index]>='1'){
                    rezb[index]=a[index]-1;
                    maiMare(index+1);
                }
                rezb[index]=a[index];
                egal(index+1);
                if (a[index]<='8'){
                    rezb[index]=a[index]+1;
                    maiMic(index+1);
                }
            }
            else{
                rezb[index]=b[index];
                if (b[index]>='1'){
                    reza[index]=b[index]-1;
                    maiMic(index+1);
                }
                reza[index]=b[index];
                egal(index+1);
                if (b[index]<='8'){
                    reza[index]=b[index]+1;
                    maiMare(index+1);
                }
            }
        }
    }else
        verif();
}

int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    scanf("%d",&t);
    for (ii=1;ii<=t;ii++){
        scanf("%s %s\n",&a,&b);
        lg=strlen(a);rezdif=-1;
        egal(0);
        printf("Case #%d: ",ii);
        for (int index=0;index<lg;index++)
            printf("%c",fina[index]);

        printf(" ");
        for (int index=0;index<lg;index++)
            printf("%c",finb[index]);
        printf("\n");
        //printf("%d %d\n",rezanr,rezbnr);
    }
    return 0;
}
