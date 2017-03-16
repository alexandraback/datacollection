#include <stdio.h>
#include <string.h>
char in[3][100]={"ejp mysljylc kd kxveddknmc re jsicpdrysi",
                        "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                        "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
char out[3][100]={"our language is impossible to understand",
                        "there are twenty six factorial possibilities",
                        "so it is okay if you want to just give up"};
char mp[200];
bool mark[200];
char str[200];
int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int i,j,len,ii,t;
    for(i=0;i<3;++i){
        len=strlen(in[i]);
        for(j=0;j<len;++j) mp[in[i][j]]=out[i][j];
    }
	mp['z']='q';
    for(i='a';i<='z';++i){
        if(mp[i]==0) ii=i;
        else mark[mp[i]]=true;
    }
    for(i='a';i<='z';++i) if(mark[i]==false) break;
    mp[ii]=i;
    scanf("%d",&t);getchar();
    for(int cc=1;cc<=t;++cc){
        gets(str);
        len=strlen(str);
        printf("Case #%d: ",cc);
        for(i=0;i<len;++i) printf("%c",mp[str[i]]);
        printf("\n");
    }
    return 0;
}
