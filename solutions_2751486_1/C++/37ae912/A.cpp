
#include <cstdio>
#include <vector>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;


const int N = 1000010;
char buf[N];
int len;
int n;

bool ok(char c){
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return false;
    return true;
}


// [s,t) must be constants
bool next(int& s, int & t)
{
    while(t-s<n && t<len){
        if( ok(buf[t]) ) t++;
        else{
            while(t<len && ok(buf[t])==false) t++;
            s=t;
            t++;
        }
    }

    return (t-s)==n;

}


int main()
{
    int t,cs=0;
    scanf("%d",&t);
    while(cs++<t){
    
        scanf("%s%d",buf,&n);

        len = strlen(buf);
        int s,t;
        s=t=0;

        printf("Case #%d: ",cs);

        if(  next(s,t) == false ){
            puts("0");
            continue;
        }

        long long res=0;

        for(int i=0;i<len;++i){
            if(i<=s){
                res += len - t + 1;
            }
            else{
                s=i;
                if( next(s,t)  == false )break;
                res += len - t + 1;
            }
            
            //printf("s=%d t=%d, i=%d, ct=%d\n",s,t,i,len-t+1);
        }
   
        cout<<res<<endl;

    }



    return 0;
}
