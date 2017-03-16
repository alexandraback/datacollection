#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

char s[1010];
string out1;
string out2;
int cnt[30];
int main (){
    int T;
    scanf("%d",&T);
    for(int I=1 ; I <= T ; I++){
        out1="";
        out2="";
        fill(cnt,cnt+30,0);
        scanf("%s",s);
        int len=strlen(s);
        for(int i = 0 ; i < len ; i ++){
            cnt[s[i]-'A']++;
        }
        int choose=25;
        for(int i = len-1 ; i >=0 ; i --){
            while(cnt[choose]==0)choose--;
            if(s[i]-'A'==choose){
                out1=out1+s[i];
                cnt[choose]--;
            }
            else{
                out2=s[i]+out2;
                cnt[s[i]-'A']--; 
            }
        }
        printf("Case #%d: %s\n",I,(out1+out2).c_str()); 
    }


}
