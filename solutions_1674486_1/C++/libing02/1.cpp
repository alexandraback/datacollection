#include<stdio.h>
#include<memory.h>
#include<vector>
#include<queue>
using std::vector;
using std::queue;
int main(){
    freopen("input.in","r",stdin);
    freopen("output_lib.txt","w",stdout);

    int t=0;
    scanf("%d" ,&t);

    int i=0;
    for(i=0;i<t;i++){
        int n=0;
        scanf("%d" ,&n);
        //init graph
        vector<int> * list=new vector<int>[n];
        int j=0;
        for(j=0;j<n;j++){
            int ni=0;
            scanf("%d",&ni);
            int ith=0;
            for(ith=0;ith<ni;ith++){
                int tmp=0;
                scanf("%d",&tmp);
                list[j].push_back(tmp-1);
            }
        }
        bool result=false;
        //ÓÐÏòÍ¼±éÀú
        bool *isVisit=new bool[n];
        //for every node
        for(j=0;j<n;j++){
            memset(isVisit,false,n*sizeof(bool));
            vector<int> qu;
            qu.push_back(j);
            //init
            while(!qu.empty()){
                int neigh=qu[qu.size()-1];
                qu.pop_back();
                //
                if(isVisit[neigh]){
                    result=true;
                    goto L1;
                }
                else{
                    isVisit[neigh]=true;
                    for(vector<int>::iterator ite=list[neigh].begin();ite!=list[neigh].end();ite++){
                        int pos=*ite;
                        if(isVisit[pos]){
                            result=true;
                            goto L1;
                        }
                        else{
                            qu.push_back(pos);
                        }
                    }
                }
            }
        }

L1:     if(result)
            printf("Case #%d: Yes\n",i+1);
        else
            printf("Case #%d: No\n",i+1);
    }
    return 0;
}

