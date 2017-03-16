#include<stdio.h>
#include<stdlib.h>
char *digit[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int count[26];

int deleteCount(int d, int c){
    for(int i=0;digit[d][i] != 0;i++){
        count[digit[d][i] - 'A'] -= c;
    }
};

int main(){
    int T;
    int ansCount[10];
    char str[2222];
    scanf("%d",&T);
    for(int ca= 1;ca <=T;ca++){
        for(int i=0;i<26;i++)count[i] = 0;
        for(int i=0;i<10;i++)ansCount[i] = 0;
        scanf("%s", str);
        for(int i=0;str[i] != 0;i++){
            count[str[i] - 'A'] ++;
        }
        
        
        ansCount[0] = count['Z' - 'A'];
        deleteCount(0, ansCount[0]);
        ansCount[2] = count['W' - 'A'];
        deleteCount(2, ansCount[2]);
        ansCount[4] = count['U' - 'A'];
        deleteCount(4, ansCount[4]);
        ansCount[6] = count['X' - 'A'];
        deleteCount(6, ansCount[6]);
        ansCount[8] = count['G' - 'A'];
        deleteCount(8, ansCount[8]);


        ansCount[1] = count['O' - 'A'];
        deleteCount(1, ansCount[1]);
        


        ansCount[3] = count['R' - 'A'];
        deleteCount(3, ansCount[3]);

        ansCount[5] = count['F' - 'A'];
        deleteCount(5, ansCount[5]);
        ansCount[7] = count['S' - 'A'];
        deleteCount(7, ansCount[7]);
        ansCount[9] = count['I' - 'A'];
        deleteCount(9, ansCount[9]);

        printf("Case #%d: ", ca);
        for(int i=0;i<10;i++){
            for(int j=0;j<ansCount[i];j++){
                printf("%d",i);
            }
        }
        printf("\n");
    }
    return 0;
}
