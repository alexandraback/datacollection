#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

FILE *fin,*fout;
int n,l1[1010],l2[1010];

bool passed1[1010];
bool passed2[1010];
int stars;

int find2(){
    for(int i = 1;i <= n;++i)
        if(!passed2[i]){
            if(stars >= l2[i])
                return i;    
        }
    return -1;
}

int find1(){
    int maxn = 0;
    int ret = -1;
    for(int i = 1;i <= n;++i)
        if(!passed1[i]){
            if(stars >= l1[i]){
                if(maxn < l2[i]){
                    maxn = l2[i];
                    ret = i;    
                }
            }
        }
    return ret;
}

int main()
{
    fin = fopen("test.in","r");
    fout = fopen("ans.out","w");
    int T;
    fscanf(fin,"%d",&T);
    for(int i = 1;i <= T;++i){
        //printf("case %d\n",i);
        fscanf(fin,"%d",&n);
        for(int i = 1;i <= n;++i)
            fscanf(fin,"%d%d",&l1[i],&l2[i]);
        memset(passed1,false,sizeof(passed1));
        memset(passed2,false,sizeof(passed2));
        int ans = 0;
        stars = 0;
        bool ok = true;
        while(1){
            ok = true;
            for(int i = 1;i <= n;++i)
                if(!passed2[i])
                    ok = false;
            if(ok)
                break;
            int num;
            num = find2();
            if(num != -1){
                //printf("%d 2\n",num);
                ++ans;
                if(!passed1[num])
                    ++stars;
                ++stars;
                passed1[num] = true;
                passed2[num] = true;
                if(stars > n + n)
                    puts("shit");
                if(stars == n + n)
                    break;
            }else{
                num = find1();
                //printf("%d 1\n",num);
                if(num == -1)
                    break;
                else{
                    ++ans;
                    passed1[num] = true;
                    ++stars;
                }    
            }
        }
        ok = true;
        for(int i = 1;i <= n;++i)
            if(!passed2[i])
                ok = false;
        fprintf(fout,"Case #%d: ",i);
        if(ok)
            fprintf(fout,"%d\n",ans);
        else
            fprintf(fout,"Too Bad\n");
    }
    fclose(fin);
    fclose(fout);
    system("pause");
    return 0;    
}
