#include<stdio.h>
#include<cstring>

int main()
{
    freopen("sa.in","r",stdin);
    freopen("sa.out","w",stdout);
    char lan1[]=" qejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjv";
    char lan2[]=" zourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveup";
    char ss[101];
    int len=strlen(lan1);
    int i,cc,cases,j;
    scanf("%d\n",&cases);
    for(cc=1;cc<=cases;cc++){
        printf("Case #%d: ",cc);
        gets(ss);
        for(i=0;ss[i];i++){
            for(j=0;j<len;j++){
                if(lan1[j]==ss[i]){
                    printf("%c",lan2[j]);
                    break;
                }
            }
            if(j==len)printf("q");
        }
        puts("");
    }
    
    return 0;
}
