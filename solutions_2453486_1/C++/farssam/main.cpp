#include<stdio.h>

char pan[5][5];

int is_comp(char a[5]){
    char c;
    int i;

    c=a[0];
    if(c=='T'){
        c=a[1];
    }

    if(c=='.')
        return 0;
    for(i=0;i<4;i++){
        if(a[i]!=c && a[i]!='T')
            return 0;
    }

    if(c=='X')
        return 2;
    return 1;

}

int solve(void){
    int i,j,w=0,y,k;
    char a[5];

    for(i=0;i<4;i++){
        //her
        for(j=0;j<4;j++){
            if(pan[i][j]=='.'){
                w++;
            }
            a[j]=pan[i][j];
        }
        k=is_comp(a);
        if(k>0)
            return k;
        //vertical
        for(j=0;j<4;j++){
            a[j]=pan[j][i];
        }
        k=is_comp(a);
        if(k>0)
            return k;
    }

    //right-diagonal
   for(i=0;i<4;i++){
        a[i]=pan[i][i];
   }
    k=is_comp(a);
    if(k>0)
        return k;

   //left-down diagonal
   for(i=0;i<4;i++){
        a[i]=pan[i][3-i];

   }
    k=is_comp(a);
    if(k>0)
        return k;

    if(w==0){
        return 0;
    }
    return -1;

}

int main(void){
    int t,i,j;

    FILE *in,*out;
    in=fopen("input","r");
    out=fopen("output.txt","w");

    fscanf(in,"%d",&t);
    for(i=1;i<=t;i++){
        for(j=0;j<4;j++){
            fscanf(in,"%s",pan[j]);
        }
        //fscanf(in,"%s",pan[j]);

//        for(j=0;j<4;j++){
//            fprintf(out,"%s\n",pan[j]);
//        }
//        fprintf(out,"\n\n");
        //fscanf(in,"%s",pan[j]);



        j=solve();
        if(j==-1){
            fprintf(out,"Case #%d: Game has not completed\n",i);
        }else if(j==0){
            fprintf(out,"Case #%d: Draw\n",i);
        }else if(j==1){
            fprintf(out,"Case #%d: O won\n",i);
        }else{
            fprintf(out,"Case #%d: X won\n",i);
        }
    }

    return 0;
}
