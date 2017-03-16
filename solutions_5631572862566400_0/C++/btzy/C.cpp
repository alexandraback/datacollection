#include<cstdio>
#include<algorithm>
using namespace std;
int t,n;
int fwd[1000];
vector<int>rev[1000];
bool visited[1000];
bool done[1000];
int max_cycle_size;
int dual_sum;

int find_rev(int currloc){
    //if(currloc<0||currloc>=n)printf("err\n");
    //printf("%d\n",currloc);
    int maxct=0;
    for(vector<int>::const_iterator it=rev[currloc].cbegin();it!=rev[currloc].cend();++it){
        maxct=max(maxct,find_rev(*it));
    }
    return maxct+1;
}

int find_rev(int currloc,int ignoreloc){
    //if(currloc<0||currloc>=n)printf("err\n");
    //printf("%d %d\n",currloc,ignoreloc);
    int maxct=0;
    for(vector<int>::const_iterator it=rev[currloc].cbegin();it!=rev[currloc].cend();++it){
        if(*it!=ignoreloc){
            maxct=max(maxct,find_rev(*it));
        }
    }
    return maxct+1;
}

int find_loc;
int find_visited(int currloc){
    //if(currloc<0||currloc>=n)printf("err\n");
    int nextloc=fwd[currloc];
    //if(nextloc<0||nextloc>=n)printf("err\n");
    if(nextloc==find_loc){
        return 1;
    }
    if(done[nextloc]||visited[nextloc])return 0;
    visited[nextloc]=true;
    int ret=find_visited(nextloc);
    visited[nextloc]=false;
    if(ret>0){
        done[nextloc]=true;
        return ret+1;
    }
    else{
        return 0;
    }
}
void try_find_loop(int startloc){
    find_loc=startloc;
    visited[startloc]=true;
    int ret=find_visited(startloc);
    visited[startloc]=false;
    if(ret>0){
        done[startloc]=true;
        if(ret>2){
            //printf("t1");
            max_cycle_size=max(max_cycle_size,ret);
        }
        else{
            //printf("t2");
            /*for(int i=0;i<n;++i){
                for(vector<int>::const_iterator it=rev[i].cbegin();it!=rev[i].cend();++it){
                    printf(" %d",*it);
                }
                printf("\n");
            }*/
            //printf("%d %d %d\n",ret,startloc,fwd[startloc]);
            int len1=find_rev(startloc,fwd[startloc]);
            int len2=find_rev(fwd[startloc],startloc);
            int sum=len1+len2;
            dual_sum+=sum;
        }
    }
}
int main(){
    scanf("%d",&t);
    for(int c=1;c<=t;++c){
        scanf("%d",&n);
        for(int i=0;i<n;++i){
            rev[i].clear();
        }
        for(int i=0;i<n;++i){
            scanf("%d",&fwd[i]);
            --fwd[i];
            rev[fwd[i]].push_back(i);
        }
        max_cycle_size=0;
        dual_sum=0;
        fill_n(done,n,false);
        fill_n(visited,n,false);
        for(int i=0;i<n;++i){
            if(!done[i])try_find_loop(i);
        }
        printf("Case #%d: %d\n",c,max(max_cycle_size,dual_sum));
    }
}
