/*
AUTHOR: THANABHAT KOOMSUBHA
LANG: C++
*/

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<list>
#include<set>
#include<queue>
#include<map>
#include<cctype>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<ctime>

using namespace std;

int solve(int cc){

    int N;
    int D[1024];
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&D[i]);
    }

    int perm[1024];
    int pos[1024];
    for(int i=N;i>=0;i--){
        for(int j=N-1;j>=0;j--){
            if(j>=N-i){
                perm[j]=1;
            }else{
                perm[j]=0;
            }
        }
//        printf("===>");
//        for(int j=0;j<N;j++){
//            printf("%d",perm[j]);
//        }
//        printf("\n");
        do {

            int _last = 0;
            for(int k=0;k<N;k++){
                if(perm[k]==1){
                    pos[_last++]=k+1;
                }
            }
//        printf("---------->");
//        for(int j=0;j<N;j++){
//            printf("%d",perm[j]);
//        }
//        printf("\n");
            do{
//                for(int j=0;j<i;j++){
//                    printf("%d",pos[j]);
//                }
//                printf("\n");
                bool sol=true;
                for(int k=0;k<i;k++){
                    int prev,next;
                    if(k==0){
                        if(i==1){
                            prev = pos[k];
                            next = pos[k];
                        }else{
                            prev = pos[i-1];
                            next = pos[k+1];
                        }
                    }else if(k==i-1){
                        if(i==1){
                            prev = pos[k];
                            next = pos[k];
                        }else{
                            prev = pos[k-1];
                            next = pos[0];
                        }
                    }else{
                        prev = pos[k-1];
                        next = pos[k+1];
                    }
                    if(prev!=D[pos[k]-1]&&next!=D[pos[k]-1]){
                        sol=false;
                        break;
                    }
                }
                if(sol){
                    printf("Case #%d: %d\n",cc,i);
                    return 1;
                }
            }while(next_permutation(pos,pos+i));


        } while(next_permutation(perm,perm+N));
    }

    printf("Case #%d: %d\n",cc,0);
    return 1;
}

int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        solve(i);
    }

	return 0;
}
