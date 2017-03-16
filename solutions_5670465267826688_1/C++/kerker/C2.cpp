#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s1[100005],s2[100005],ss[10004];
char pre[100005],ppre[100005];

char get(char a,char b){
    if(a=='1' && b=='1')    return '1';
    else if(a=='1' && b=='i')   return 'i';
    else if(a=='1' && b=='j')   return 'j';
    else if(a=='1' && b=='k')   return 'k';
    else if(a=='1' && b=='2')   return '2';
    else if(a=='1' && b=='I')   return 'I';
    else if(a=='1' && b=='J')   return 'J';
    else if(a=='1' && b=='K')   return 'K';
    else if(a=='2' && b=='1')   return '2';
    else if(a=='2' && b=='i')   return 'I';
    else if(a=='2' && b=='j')   return 'J';
    else if(a=='2' && b=='k')   return 'K';
    else if(a=='2' && b=='2')   return '1';
    else if(a=='2' && b=='I')   return 'i';
    else if(a=='2' && b=='J')   return 'j';
    else if(a=='2' && b=='K')   return 'k';
    else if(a=='i' && b=='1')   return 'i';
    else if(a=='i' && b=='i')   return '2';
    else if(a=='i' && b=='j')   return 'k';
    else if(a=='i' && b=='k')   return 'J';
    else if(a=='i' && b=='2')   return 'I';
    else if(a=='i' && b=='I')   return '1';
    else if(a=='i' && b=='J')   return 'K';
    else if(a=='i' && b=='K')   return 'j';
    else if(a=='j' && b=='1')   return 'j';
    else if(a=='j' && b=='i')   return 'K';
    else if(a=='j' && b=='j')   return '2';
    else if(a=='j' && b=='k')   return 'i';
    else if(a=='j' && b=='2')   return 'J';
    else if(a=='j' && b=='I')   return 'k';
    else if(a=='j' && b=='J')   return '1';
    else if(a=='j' && b=='K')   return 'I';
    else if(a=='k' && b=='1')   return 'k';
    else if(a=='k' && b=='i')   return 'j';
    else if(a=='k' && b=='j')   return 'I';
    else if(a=='k' && b=='k')   return '2';
    else if(a=='k' && b=='2')   return 'K';
    else if(a=='k' && b=='I')   return 'J';
    else if(a=='k' && b=='J')   return 'i';
    else if(a=='k' && b=='K')   return '1';
    else if(a=='I' && b=='1')   return 'I';
    else if(a=='I' && b=='i')   return '1';
    else if(a=='I' && b=='j')   return 'K';
    else if(a=='I' && b=='k')   return 'j';
    else if(a=='I' && b=='2')   return 'i';
    else if(a=='I' && b=='I')   return '2';
    else if(a=='I' && b=='J')   return 'k';
    else if(a=='I' && b=='K')   return 'J';
    else if(a=='J' && b=='1')   return 'J';
    else if(a=='J' && b=='i')   return 'k';
    else if(a=='J' && b=='j')   return '1';
    else if(a=='J' && b=='k')   return 'I';
    else if(a=='J' && b=='2')   return 'j';
    else if(a=='J' && b=='I')   return 'K';
    else if(a=='J' && b=='J')   return '2';
    else if(a=='J' && b=='K')   return 'i';
    else if(a=='K' && b=='1')   return 'K';
    else if(a=='K' && b=='i')   return 'J';
    else if(a=='K' && b=='j')   return 'i';
    else if(a=='K' && b=='k')   return '1';
    else if(a=='K' && b=='2')   return 'k';
    else if(a=='K' && b=='I')   return 'j';
    else if(a=='K' && b=='J')   return 'I';
    else if(a=='K' && b=='K')   return '2';
    while(1) printf("XD\n");
    return 'P';
}
char test(char now,long long M){
    if(M==1)    return now;
    else if(M==0)   return '1';
    char tmp = test(now,M/2);
    if(M%2==0)  return get(tmp,tmp);
    else    return get(get(tmp,tmp),now);
}

int main(){
    
    int T;
    long long M;
    scanf(" %d",&T);
    for(int t=0,N;t<T && scanf(" %d %lld",&N,&M)==2;t++){
        scanf(" %s",ss);
        for(int i=0,j=0;i<8;i++)
            for(int k=0;k<N;k++)
                s1[j++] = ss[k];
        for(int i=0,j=8*N-1;i<8;i++)
            for(int k=N-1;k>=0;k--)
                s2[j--] = ss[k];
        
        long long NN = (long long)N*M;
        pre[0] = s1[0];
        for(int i=1;i<8*N;i++)
            pre[i] = get(pre[i-1],s1[i]);
        ppre[8*N-1] = s2[8*N-1];
        for(int i=8*N-2;i>=0;i--)
            ppre[i] = get(s2[i],ppre[i+1]);
        char tmp = ss[0];
        for(int i=1;i<N;i++)
            tmp = get(tmp,ss[i]);
        if(test(tmp,M)!='2'){
            printf("Case #%d: NO\n",t+1);
            continue;
        }

        int ok = 0;
        for(int i=0;i<8*N && ok==0;i++){
            if(pre[i]=='i'){
                for(int j=8*N-1;j>=0 && ok==0;j--){
                    if(ppre[j]=='k'){
                        if((i+1)+(8*N-j) < NN)
                            ok = 1;
                    }
                }
            }
        }
        if(ok==0)   printf("Case #%d: NO\n",t+1);
        else    printf("Case #%d: YES\n",t+1);
    }

    return 0;
}
