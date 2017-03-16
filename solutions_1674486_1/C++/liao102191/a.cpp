/***************************************************************************
 * 
 * Copyright (c) 2012, Inc. All Rights Reserved
 * 
 **************************************************************************/
 
 
 
/**
 * @file a.cpp
 * @author work
 * @date 2012/04/28 09:34:48
 * @brief 
 *  
 **/

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int main() {
    int T, N, case_num = 1;
    scanf("%d", &T);
    while (case_num <= T) {
        scanf("%d", &N);
        int map[N + 1][N + 1], a, b, n;
        int sum = 0;
        for (int i = 0; i <= N; i ++) {
            for (int j = 0; j <= N; j ++) {
                map[i][j] = 0;
            }
        }
        for (int i = 0; i < N; i ++) {
            scanf("%d", &n);
            for (int j =0 ;j < n; j++) {
                scanf("%d", &b);
                map[i + 1][b] = 1;
            }
        }

        int used[N + 1], reached[N + 1], queue[N + 1], queue_start = 0, queue_len = 1;
        int is_ok = 0;
        memset(used, 0, sizeof(used));

        for (int i = 1; i <= N; i ++) {
            if (used[i] == 1) {
                continue;
            }
            queue_start = 0;
            memset(reached, 0, sizeof(reached));
            queue[queue_start] = i;
            queue_len = 1;
            while(queue_len > queue_start) {
                int cur_node = queue[queue_start];
                for (int j = 1; j <= N; j++) {
                    if (map[cur_node][j] == 0) {
                        continue;
                    }
                    reached[j] ++;
                    if (reached[j] > 1) {
                        is_ok = 1;
                        break;
                    }
                    queue[queue_len ++] = j;
                    used[j] = 1;
                }
                if (is_ok) {
                    break;
                }
                queue_start ++;
            }

            if (is_ok) {
                break;
            }
        }
        
        printf("Case #%d: ", case_num);
        if (is_ok) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
        case_num ++;
    }

    return 0;
}




















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
