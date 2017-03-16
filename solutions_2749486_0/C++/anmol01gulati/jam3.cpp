#include<iostream>
#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t,x,y,counter=1,xprev,yprev;
    vector<char> coord;
    scanf("%d",&t);
    for(int i=1;i<=t;i++){
        counter=1;
        coord.clear();
        scanf("%d %d",&x,&y);
        xprev=0;
        yprev=0;
        while(x!=xprev){
         if(x-xprev >0){
            xprev+=counter;
            counter++;
            coord.push_back('E');
         } else{
             xprev+=counter;
             coord.push_back('E');
             counter++;
             xprev-=counter;
             coord.push_back('W');
             counter++;
         }
        }
        while(y!=yprev){
            if(y-yprev >0){
                yprev-=counter;
                coord.push_back('S');
                counter++;
                        yprev+=counter;
                coord.push_back('N');
                counter++;

            } else{
                yprev+=counter;
                coord.push_back('N');
                counter++;
                                yprev-=counter;
                coord.push_back('S');
                counter++;
            }
        }
        printf("Case #%d: ",i);
        for(int j=0;j<coord.size();j++){
            printf("%c",coord[j]);
        }
        printf("\n");
    }

    return 0;
}
