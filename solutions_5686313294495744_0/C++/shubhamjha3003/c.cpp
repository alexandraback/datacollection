#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main()
{
    int i,t,n,ans,j,k,tempval,tempans,l;
    char first[1100][30],second[1100][30];
    int arr[20];
    set< vector<char> > first_set,second_set;
    vector<char> temp,temp1;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d",&n);
        first_set.clear();
        second_set.clear();
        for(j=0;j<n;j++){
            scanf("%s",first[j]);
            scanf("%s",second[j]);
        }
        ans=0;
        for(j=0;j<1<<n;j++){
            tempval=j;
            tempans=0;
            first_set.clear();
            second_set.clear();
            for(k=0;k<n;k++){
                arr[k]=tempval%2;
                tempval/=2;
                if(arr[k]==1){
                    temp.clear();
                    for(l=0;first[k][l]!='\0';l++){
                        temp.push_back(first[k][l]);
                    }
                    if(first_set.find(temp)==first_set.end())
                        first_set.insert(temp);
                    temp.clear();
                    for(l=0;second[k][l]!='\0';l++){
                        temp.push_back(second[k][l]);
                    }
                    if(second_set.find(temp)==second_set.end())
                        second_set.insert(temp);
                }
            }
            tempans=0;
            for(k=0;k<n;k++){
                if(arr[k]==0){
                    temp.clear();
                    for(l=0;first[k][l]!='\0';l++){
                        temp.push_back(first[k][l]);
                    }
                    if(first_set.find(temp)==first_set.end()){
                        tempans=-1;
                        break;
                    }
                    temp.clear();
                    for(l=0;second[k][l]!='\0';l++){
                        temp.push_back(second[k][l]);
                    }
                    if(second_set.find(temp)==second_set.end()){
                        tempans=-1;
                        break;
                    }
                    tempans++;
                }
            }
            ans=max(ans,tempans);
        }
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}
