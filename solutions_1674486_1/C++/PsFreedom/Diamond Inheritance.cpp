#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int Check[1001];

int FindCycle(vector<int> myNode[],int startNode,int count){
    int i,sum=0;
    Check[startNode]++;
    //printf(">>> start : %d| count : %d | Check : %d\n",startNode,count,Check[startNode]);

    if(count >=1){
        if(Check[startNode] > 1){
            return 1;
        }
    }
    for(i=0; i<myNode[startNode].size(); i++){
        sum+=FindCycle(myNode,myNode[startNode][i],count+1);
    }
    return sum;
}

int main(){
    int i,j,k,nTest,nNode,nEdge,parent,flagCycle;

    scanf("%d",&nTest);

    for(i=0;i<nTest;i++){
        vector<int> myNode[1001];
        flagCycle=0;
        scanf("%d",&nNode);

        for(j=0;j<nNode;j++){
            scanf("%d",&nEdge);
            for(k=0;k<nEdge;k++){
                scanf("%d",&parent);
                myNode[j+1].push_back(parent);
            }
        }
        printf("Case #%d: ",i+1);
        for(j=1;j<=nNode;j++){
            for(k=0;k<1001;k++){
                Check[k]=0;
            }
            if(FindCycle(myNode,j,0)){
                printf("Yes\n");
                flagCycle=1;
                break;
            }
            //printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
        }
        if(flagCycle==0){
            printf("No\n");
        }
    }
    return 0;
}
