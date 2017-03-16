#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<set>
using namespace std;

#define LIM 2000005

int arr[2*LIM],parent[2*LIM];
int num[32];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int cases;
    scanf("%d",&cases);
    for(int tt=1;tt<=cases;tt++){
        int N;
        cin>>N;
        for(int i=0;i<LIM;i++) arr[i]=parent[i]=0;
        for(int i=0;i<20;i++){
            scanf("%d",&num[i]);
        }
        arr[0]=1;
        int k1=-1,k2=-1,r;
        for(int i=0;i<20;i++){
            if(k1!=-1) break;
            for(int j=LIM-1;j>=0;j--){
                if(arr[j] && arr[j+num[i]]){
                    k1=j;
                    k2=j+num[i];
                    r=num[i];
                    break;
                }
                else if(arr[j]){
                    parent[j+num[i]]=j;
                    arr[j+num[i]]++;
                }
            }
        }
        if(k1==-1) printf("Case #%d:\nImpossible\n",tt);
        else{
            set<int> A,B;
            int curr=k1;
            A.insert(r);
            while(parent[curr]||curr){
                A.insert(curr-parent[curr]);
                curr=parent[curr];
            }
            curr=k2;
            while(parent[curr]||curr){
                //printf("%d ",curr-parent[curr]);
                B.insert(curr-parent[curr]);
                curr=parent[curr];
            }
            printf("Case #%d:\n",tt);
            set<int>::iterator it;
            for(it=A.begin();it!=A.end();it++){
                if(B.find(*it)==B.end()){
                    printf("%d ",*it);
                }
            }
            printf("\n");
            for(it=B.begin();it!=B.end();it++){
                if(A.find(*it)==A.end()){
                    printf("%d ",*it);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
