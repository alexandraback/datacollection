//
//  main.c
//  codejam_2016_round_2_1
//
//  Created by JerryChang on 2016/4/16.
//  Copyright © 2016年 Ron. All rights reserved.
//

#include <stdio.h>

struct Unit {
    char word;
    int next;
};

int main(int argc, const char * argv[]) {
    int T;
    scanf("%d",&T);
    int i;
    for(i = 0 ;i < T;i++){
        char word[1005] = {0};
        int j;
        for(j = 0;j<1005;j++){
            word[j] = -1;
        }
        scanf("%s",word);
        int head;
        int last;
        struct Unit list[1005];
        list[0].word = word[0];
        list[0].next = -1;
        head = 0;
        last = 0;
        for(j = 1; word[j]!=-1;j++){
            list[j].word = word[j];
            list[j].next = -1;
            if(word[j]>=list[head].word){
                list[j].next = head;
                head = j;
            }
            else{
                list[last].next = j;
                last = j;
            }
        }
        int point = head;
        printf("Case #%d: ",i+1);
        for(j = 0;point!=-1;j++){
            printf("%c",list[point].word);
            point = list[point].next;
        }
        printf("\n");
    }
    return 0;
}
