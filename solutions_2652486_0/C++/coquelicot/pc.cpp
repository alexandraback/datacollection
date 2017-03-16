#include <cstdio>

int R, N, M, K; // N = 3

bool win(int *guess, int *nums){

    static int stp = 0;
    static int exist[1000];

    ++stp;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                int get = 1;
                if(i) get *= guess[1];
                if(j) get *= guess[2];
                if(k) get *= guess[3];
                exist[get] = stp;
            }
        }
    }

    for(int i = 1; i <= K; i++){
        if(nums[i] > 1000 || exist[nums[i]] != stp) return false;
    }
    return true;

}

int main(){

    scanf("%*d"); //t
    printf("Case #1:\n");

    scanf("%d %d %d %d" ,&R ,&N ,&M ,&K);

    while(R--){

        int nums[20];
        for(int i = 1; i <= K; i++) scanf("%d" ,&nums[i]);

        int guess[4];
        for(guess[1] = 2; guess[1] <= M; guess[1]++){
            for(guess[2] = guess[1]; guess[2] <= M; guess[2]++){
                for(guess[3] = guess[2]; guess[3] <= M; guess[3]++){
                    if(win(guess, nums)) goto end;
                }
            }
        }
end:
        printf("%d%d%d\n" ,guess[1] ,guess[2] ,guess[3]);

    }

}
