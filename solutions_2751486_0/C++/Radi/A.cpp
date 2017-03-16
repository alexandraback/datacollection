#define Long long long
#include <stdio.h>
#include <string.h>
#include <set>
#include <iostream>
using namespace std;
char str[1000006];
set<int>S;
set<int>::iterator it;
int main(){
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    Long res;
    int con,n,i,t,len,tar,get;
    scanf("%d",&t);
    for(int cc=1;cc<=t;++cc){
        S.clear();
        res=0;
        scanf(" %s %d",str,&n);
        len=strlen(str);
        con=0;
        for(i=0;i<len;++i){
            if(str[i]!='a'&&str[i]!='e'&&str[i]!='i'&&str[i]!='o'&&str[i]!='u') ++con;
            else con=0;
            if(con>=n)
				S.insert(i);
        }
        S.insert(len);
        for(i=0;i<len;++i){
            tar=i+n-1;
            if(tar>=len) break;
            it=S.lower_bound(tar);
            get=*it;
            res+=len-get;
        }
        printf("Case #%d: ",cc);
        cout<<res<<endl;
    }
    return 0;
}
