#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
struct keyset{
    int numkeys[200];
    keyset(){
        memset(numkeys,0,sizeof(numkeys));
    }
};
keyset clone(keyset k){
    return k;
}
int keyneeded[200];
vector<int> contents[200];
bool dp[1048576];
bool visited[1048576];
bool ischestclosed(int bitmask,int cchest){
    return ((bitmask>>cchest)&1)==1;
}
int openchest(int bitmask,int cchest){
    return bitmask&(~(1<<cchest));
}
bool allopen(int bitmask){
    return bitmask==0;
}
int createallclosed(int numchests){
    return (1<<numchests)-1;
}
keyset removekey(keyset ckeys,int ckey){
    keyset res=clone(ckeys);
    res.numkeys[ckey]--;
    return res;
}
keyset addkey(keyset ckeys,int ckey){
    keyset res=clone(ckeys);
    res.numkeys[ckey]++;
    return res;
}
keyset updateopenchest(keyset keys,int cchest){
    keys=removekey(keys,keyneeded[cchest]);
    //printf("%d %d ",keys.numkeys[0],contents[cchest].size());
    for(int i=0;i<contents[cchest].size();i++){
        keys=addkey(keys,contents[cchest][i]);
    }
    //printf("%d\n",keys.numkeys[0]);
    return keys;
}
void printdptable(int numchests){
    for(int i=0;i<(1<<numchests);i++){
        printf("%d ",dp[i]);
    }
}
bool search(int bitmask,keyset keys,int numchests){
    if(allopen(bitmask)) return true;
    else if(visited[bitmask]) return dp[bitmask];
    else{
        bool possible=false;
        for(int i=0;i<numchests;i++){
            if(ischestclosed(bitmask,i)&&keys.numkeys[keyneeded[i]]>0){
                //printf("%d %d %d %d %d\n",keyneeded[i],bitmask,keys.numkeys[0],openchest(bitmask,i),updateopenchest(keys,i).numkeys[0]);
                /*if(bitmask==1000176){
					int a=0;
				}*/
				if(search(openchest(bitmask,i),updateopenchest(keys,i),numchests)){
                    possible=true;
                    break;
                }
            }
        }
        visited[bitmask]=true;
        dp[bitmask]=possible;
        return possible;
    }
}
void outputans(int bitmask,keyset keys,int numchests){
    if(allopen(bitmask)) return;
    else{
        bool possible=false;
        for(int i=0;i<numchests;i++){
            if(ischestclosed(bitmask,i)&&keys.numkeys[keyneeded[i]]>0){
                int newbitmask=openchest(bitmask,i);
                if(search(newbitmask,updateopenchest(keys,i),numchests)){
                    printf(" %d",i+1);
                    outputans(openchest(bitmask,i),updateopenchest(keys,i),numchests);
                    break;
                }
            }
        }
    }
}
int main(){
    freopen("QD.in","r",stdin);
    freopen("QD.out","w",stdout);
    int numcases;
    scanf("%d",&numcases);
    for(int ccase=0;ccase<numcases;ccase++){
        memset(dp,false,sizeof(dp));
        memset(visited,false,sizeof(visited));
        int numkeys,numchests;
        scanf("%d%d",&numkeys,&numchests);
        keyset ckeys;
        for(int i=0;i<numkeys;i++){
            int ckey;
            scanf("%d",&ckey);
            ckeys=addkey(ckeys,ckey-1);
        }
        for(int i=0;i<numchests;i++) contents[i].clear();
        for(int i=0;i<numchests;i++){
            int numcontents;
            scanf("%d%d",&keyneeded[i],&numcontents);keyneeded[i]--;
            for(int i2=0;i2<numcontents;i2++){
                int ckey;
                scanf("%d",&ckey);
                contents[i].push_back(ckey-1);
            }
        }
        printf("Case #%d:",ccase+1);
        if(search(createallclosed(numchests),ckeys,numchests)){
            //printdptable(numchests);
            outputans(createallclosed(numchests),ckeys,numchests);
        }
        else printf(" IMPOSSIBLE");
        printf("\n");
    }
    return 0;
}
