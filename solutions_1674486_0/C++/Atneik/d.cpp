#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int MAT[50][10];

vector<int> temp;
vector<int>::iterator it;
int f=0;

void get(int s)
{
    s--;
    for (int z=0; z<MAT[s][z]!=0; z++) {
        it=find(temp.begin(),temp.end(),MAT[s][z]);
        //printf("-%d-",MAT[s][z]);
        if (it != temp.end()) {
            f=1;
        }
        else{
            temp.push_back(MAT[s][z]);
            
            get(MAT[s][z]);
        }
    }
    
}

int main() {

    int T,i;
    scanf("%d",&T);
        
    for(i=0;i<T;i++)
    {
        int N,j,flag=0;
    
        
        for (j=0; j<50; j++) {
            int z;
            for (z=0; z<10; z++) {
                MAT[j][z]=0;
            }
        }
        
        scanf("%d",&N);
        
        for (j=0; j<N; j++) {
            int M,z;
            scanf("%d",&M);
            
            for (z=0; z<M; z++) {
                scanf("%d",&MAT[j][z]);
            }
        }
        
        /*
        for (j=0; j<N; j++) {
            int z;
            for (z=0; MAT[j][z]!=0; z++) {
                printf("%d ",MAT[j][z]);
            }
            printf("\n");
        }
        */
        for (j=0; j<N; j++) {
            f=0;
            temp.erase(temp.begin(),temp.end());
            get(j+1);
            //printf("\n");
            if (f) {
                flag=1;
            }
            
        }
        if (flag) {
            printf("Case #%d: Yes\n",i+1);
        }else
            printf("Case #%d: No\n",i+1);
    }
    
    return 0;
}