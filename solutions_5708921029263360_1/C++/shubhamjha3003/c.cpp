#include<cstdio>
#include<vector>
int mat[3][20][20];
class wear{
    public:
    int x,y,z;
    wear(int x1,int y1,int z1){
        x=x1;
        y=y1;
        z=z1;
    }
};
using namespace std;
int main()
{
    int t,j,p,s,i,x,y,z,k,ans;
    vector<wear> arr;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d%d%d%d",&j,&p,&s,&k);
        for(x=0;x<3;x++){
            for(y=0;y<20;y++){
                for(z=0;z<20;z++){
                    mat[x][y][z]=0;
                }
            }
        }
        ans=0;
        arr.clear();
        for(x=1;x<=j;x++){
            for(y=1;y<=p;y++){
                if(x==y)
                    continue;
                if(mat[0][x][y]>=k){
                    continue;
                }
                for(z=1;z<=s;z++){
                    //printf("%d %d %d:%d %d %d\n",x,y,z,mat[0][x][y],mat[1][y][z],mat[2][x][z]);
                    if(y==z||x==z)
                        continue;
                    if(mat[1][y][z]>=k){
                        continue;
                    }
                    if(mat[2][x][z]>=k){
                        continue;
                    }
                    if(mat[0][x][y]>=k){
                        continue;
                    }
                    arr.push_back(wear(x,y,z));
                    mat[0][x][y]++;
                    mat[1][y][z]++;
                    mat[2][x][z]++;
                }
            }
        }
        for(x=1;x<=j;x++){
            for(y=1;y<=p;y++){
                if(mat[0][x][y]>=k){
                    continue;
                }
                for(z=1;z<=s;z++){
                    if(x!=y&&y!=z&&x!=z)
                        continue;
                    if(mat[1][y][z]>=k){
                        continue;
                    }
                    if(mat[2][x][z]>=k){
                        continue;
                    }
                    if(mat[0][x][y]>=k){
                        continue;
                    }
                    arr.push_back(wear(x,y,z));
                    mat[0][x][y]++;
                    mat[1][y][z]++;
                    mat[2][x][z]++;
                }
            }
        }
        ans=arr.size();
        printf("Case #%d: %d\n",i,ans);
        for(x=0;x<arr.size();x++){
            printf("%d %d %d\n",arr[x].x,arr[x].y,arr[x].z);
        }
    }
    return 0;
}
