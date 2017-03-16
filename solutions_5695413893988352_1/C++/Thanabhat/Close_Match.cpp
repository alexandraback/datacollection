/*
AUTHOR: THANABHAT KOOMSUBHA
LANG: C++
*/

#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<list>
#include<set>
#include<queue>
#include<map>
#include<cctype>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<ctime>

using namespace std;


char a[30],b[30];
long long aa,bb;
int len;

void check(long long aaa, long long bbb){
//    printf("->check %lld %lld\n",aaa,bbb);
//    printf("->aabb %lld %lld\n",aa,bb);
    if(aa==-1){
        aa=aaa;
        bb=bbb;
    }else if(abs(aaa-bbb)<abs(aa-bb)){
        aa=aaa;
        bb=bbb;
    }else if(abs(aaa-bbb)==abs(aa-bb)){
        if(aaa<aa){
            aa=aaa;
            bb=bbb;
        }else if(aaa==aa&&bbb<bb){
            aa=aaa;
            bb=bbb;
        }
    }
}

/*
state
0 =
1 <
2 >
*/
void rec(int pos, int state){
//    printf("rec, pos->%d, %s %s, state->%d\n",pos,a,b,state);

    if(pos==len){
        long long aaa,bbb;
        sscanf(a,"%lld",&aaa);
        sscanf(b,"%lld",&bbb);
//        printf("check %lld %lld\n",aaa,bbb);
        check(aaa,bbb);
        return;
    }

    if(a[pos]!='?'&&b[pos]!='?'){
        if(state==0){
            if(a[pos]==b[pos]){
                rec(pos+1,state);
            }else if(a[pos]<b[pos]){
                rec(pos+1,1);
            }else if(a[pos]>b[pos]){
                rec(pos+1,2);
            }
        }else{
            rec(pos+1,state);
        }
    }else if(a[pos]=='?'&&b[pos]=='?'){
        if(state==0){
            a[pos]='0';b[pos]='0';
            rec(pos+1,0);
            a[pos]='0';b[pos]='1';
            rec(pos+1,1);
            a[pos]='1';b[pos]='0';
            rec(pos+1,2);
        }else if(state==1){
            a[pos]='9';b[pos]='0';
            rec(pos+1,state);
        }else if(state==2){
            a[pos]='0';b[pos]='9';
            rec(pos+1,state);
        }
        a[pos]='?';
        b[pos]='?';
    }else if(a[pos]!='?'&&b[pos]=='?'){
        if(state==0){
            int n = a[pos]-'0';
            b[pos]=n+'0';
            rec(pos+1,0);
            if(n<9){
                b[pos]=n+1+'0';
                rec(pos+1,1);
            }
            if(n>0){
                b[pos]=n-1+'0';
                rec(pos+1,2);
            }
        }else if(state==1){
            b[pos]='0';
            rec(pos+1,state);
        }else if(state==2){
            b[pos]='9';
            rec(pos+1,state);
        }
        b[pos]='?';
    }else if(a[pos]=='?'&&b[pos]!='?'){
        if(state==0){
            int n = b[pos]-'0';
            a[pos]=n+'0';
            rec(pos+1,0);
            if(n>0){
                a[pos]=n-1+'0';
                rec(pos+1,1);
            }
            if(n<9){
                a[pos]=n+1+'0';
                rec(pos+1,2);
            }
        }else if(state==1){
            a[pos]='9';
            rec(pos+1,state);
        }else if(state==2){
            a[pos]='0';
            rec(pos+1,state);
        }
        a[pos]='?';
    }
}

int solve(int cc){
    aa=-1;
    bb=-1;
    scanf("%s %s",a,b);
    len = strlen(a);

    rec(0,0);
//    printf("=aabb %lld %lld\n",aa,bb);
    printf("Case #%d: %0*lld %0*lld\n",cc,len,aa,len,bb);

    return 1;
}

int main(){

//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        solve(i);
    }

	return 0;
}
