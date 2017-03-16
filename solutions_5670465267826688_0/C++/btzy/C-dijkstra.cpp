#include<cstdio>
using namespace std;
int tc,l;
long long x;
char arr[10000]; // 1ijk 0mno = 01234567
char multarr[4][4]={{0,1,2,3},{1,4,3,6},{2,7,4,1},{3,2,5,4}};
inline char mult(const char a,const char b){
    return multarr[(a&3)][(b&3)]^(a&4)^(b&4);
}
inline char getat(const long long index){
    return arr[index%l];
}
inline bool findnext(long long& curr,const char target){
    //printf("findnext %d %hhd\n",curr,target);
    long long last=curr;
    char c=0;
    for(;true;++curr){
        //printf("-- %d %hhd\n",curr,getat(curr));
        if(curr>=x*l)return false;
        char val=getat(curr);
        c=mult(c,val);
        //printf("c= %hhd\n",c);
        if(c==target){
            ++curr;
            return true;
        }
        if(curr-last>=l*4)return false;
    }
}
inline bool findall(long long& curr,const char target){
    //printf("findnext %d %hhd\n",curr,target);
    long long last=curr;
    char c=0;
    for(;true;++curr){
        //printf("-- %d %hhd\n",curr,getat(curr));
        if(curr>=x*l)return false;
        char val=getat(curr);
        c=mult(c,val);
        //printf("c= %hhd\n",c);
        if(c==target&&((x*l)-(curr+1))%(l*4)==0){
            ++curr;
            return true;
        }
        if(curr-last>=l*4)return false;
    }
}
int main(){
    scanf("%d",&tc);
    for(int ct=1;ct<=tc;++ct){
        scanf("%d%lld",&l,&x);
        for(int i=0;i<l;++i){
            scanf(" %c",&arr[i]);
            switch(arr[i]){
            case 'i':
                arr[i]=1;
                break;
            case 'j':
                arr[i]=2;
                break;
            case 'k':
                arr[i]=3;
                break;
            }
        }
        bool b=true;
        long long curr=0;
        if(b)b=findnext(curr,1);
        if(b)b=findnext(curr,2);
        if(b)b=findall(curr,3);
        printf("Case #%d: %s\n",ct,b?"YES":"NO");
    }
}
