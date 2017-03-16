#include<stdio.h>
#include<string>
#include<memory.h>
FILE *fo = fopen("/Users/JungRockJoon/Desktop/Rock/Algorithm/Codejam2016/Round1B/1/input.txt","r");
FILE *fp = fopen("/Users/JungRockJoon/Desktop/Rock/Algorithm/Codejam2016/Round1B/1/output.txt","w");
char text[10][6]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int tc[10]={4,3,3,5,4,4,3,5,5,4};

char l[2020],lc;
int word[30],count[20];
void del(int pos,char dif){
    int i, rem = word[dif-'A'];
    count[pos] = rem;
    for(i=0;i<tc[pos];i++){
        word[text[pos][i] - 'A'] -= rem;
    }
}
int main(){
    int t,T;
    fscanf(fo,"%d",&T);
    for(t=1;t<=T;t++){
        memset(l,0,sizeof(l));
        memset(word,0,sizeof(word));
        memset(count,0,sizeof(count));
        fscanf(fo,"%s",l);
        lc = strlen(l);
        int i;
        for(i=0;i<lc;i++){
            word[l[i]-'A']++;
        }
        del(0,'Z');
        del(8,'G');
        del(6,'X');
        del(2,'W');
        del(7,'S');
        del(3,'T');
        del(5,'V');
        del(4,'F');
        del(1,'O');
        del(9,'I');
        fprintf(fp,"Case #%d: ",t);
        for(i=0;i<=9;i++){
            for(int j=0;j<count[i];j++) {
                fprintf(fp, "%d", i);
            }
        }
        fprintf(fp,"\n");
    }
    return 0;
}