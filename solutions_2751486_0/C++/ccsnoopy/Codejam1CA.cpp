#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
using namespace std;

bool isVowel(char x){
    return x=='a'||x=='e'||x=='o'||x=='u'||x=='i';
}

int main(void){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    string str, str2;
    int tc, casecounter = 1;
    int n;
    scanf("%d",&tc);
    while(tc--){
        cin>>str>>n;
        int length = str.length();
        int streak, total = 0;
        for(int i=0;i<length;i++){
            for(int j=1;j<length-i+1;j++){
                str2 = str.substr(i,j);
                streak = 0;
                //cout<<str2<<endl;
                if(str2.length()>=n){
                    for(int k=0;k<str2.length();k++){
                        if(isVowel(str2[k]))streak = 0;
                        else streak++;
                        if(streak>=n){
                            total++;
                            break;
                        }
                    }
                }
            }
        }
        printf("Case #%d: %d\n",casecounter++, total);
    }



    return 0;
}
