#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#define inf 2000000000
#define ll long long
#define pci pair<char,int>
#define Max

using namespace std;

void conv(char p,char q,char& r,int& d){

    d=1;

    if(p=='1'){r=q;return;}

    if(q=='1'){r=p;return;}

    if(p==q){r='1';d=-1;return;}

    if(p=='i'){

        if(q=='j'){
                r='k';
                return;
        }

        else{
            r='j';
            d=-1;
            return;
        }
    }

    else if(p=='j'){

        if(q=='i'){
                r='k';
                d=-1;
                return;
        }

        else{
            r='i';
            return;
        }
    }

    else{

        if(q=='i'){
                r='j';
                return;
        }

        else{
            r='i';
            d=-1;
            return;
        }

    }
}

pci mul(pci a,pci b)
{

    char c;
    int sign;

    conv(a.first,b.first,c,sign);

    return make_pair(c,sign*a.second*b.second);

}


void pr(pci x)
{
    printf("%c %d\n",x.first,x.second);
}


pci target[4];
int tar[4];
string str;
map <pci , int > mymap;
char charList[]={'1','i','j','k'},ch;
int ops[8][8];
pci invMap[8];
int result[8][10005];
int got[8][10005][8];


int main()
{
    ll i,j,k,T,cas,ret=0,l,x,d;

    freopen("/Users/sakibshafayat/Documents/Codes/CodesRunning/Codejam15/Quali/C-large.in","r",stdin);
    freopen("/Users/sakibshafayat/Documents/Codes/CodesRunning/Codejam15/Quali/C-large.txt","w",stdout);

    target[1] = make_pair('i',1);
    target[2] = mul( target[1] , make_pair('j',1) );
    target[3] = mul( target[2] , make_pair('k',1) );

    for(k=0,j=1;j<=2;j++){
        for(i=0;i<4;i++){

            d=j;
            if(d==2) d=-1;

            ch=charList[i];

            mymap[make_pair(ch,(int)d)]=k;
            invMap[k]=make_pair(ch,(int)d);
            k++;

        }
    }

    tar[1]=mymap[target[1]];
    tar[2]=mymap[target[2]];
    tar[3]=mymap[target[3]];

    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            ops[i][j]=mymap[mul(invMap[i],invMap[j])];

        }
    }

    cin>>T;

    for(cas=1;cas<=T;cas++)
    {
        cin>>l>>x;

        cin>>str;

        ll current;


        for(i=0;i<8;i++){

            current = i;

            for(j=0;str[j];j++){

                result[i][j]=ops[current][mymap[make_pair(str[j],1)]];
                current = result[i][j];
            }

            for(k=0;k<8;k++){

                got[i][l][k]=-1;

                for(j=l-1;j>=0;j--){

                    if(result[i][j]==k) got[i][j][k]=j;
                    else got[i][j][k]=got[i][j+1][k];
                }
            }
        }

        ll lastPos[8];
        ll cStart,cEnd,cLength,cState;

        for(i=1;i<8;i++) lastPos[i]=-1;
        lastPos[0]=0;

        current=0;
        for(i=1;i<=x;i++){

            current=result[current][l-1];

            if(lastPos[current]==-1){
                    lastPos[current]=i;
            }

            else{

                cEnd = i;
                cStart = lastPos[current];
                cLength = cEnd - cStart;
                cState = current;
                break;

            }

        }

        if(i>x && current != tar[3]){

                ret=0;
                printf("Case #%d: %s\n",cas,ret ? "YES" : "NO");
                continue;

        }

        if(i<=x){

                ll remain = x-cStart;
                remain/=cLength;
                ll extra = x - cStart - cLength*remain;

                current = cState;

                while(extra--){

                    current = result[current][l-1];
                }


                if(current !=tar[3]){

                    ret=0;
                    printf("Case #%d: %s\n",cas,ret ? "YES" : "NO");
                    continue;
                }

        }

       // printf("%d %d %d\n",tar[1],tar[2],tar[3]);

        //printf("Here\n");

        ll start = 0;
        ll found = 1;
        ll next;

        for(i=1;i<=20 && i<=x && found<=2;i++,start = result[start][l-1]){

                //printf("got : %d\n",got[start][0][tar[found]]);

                if(got[start][0][tar[found]]==-1) continue;

                next = got[start][0][tar[found]] +1;
                found++;

                //printf("next %d\n",next);

                if(next==l) continue;
                if(found>2) continue;

                if(got[start][next][tar[found]]==-1) continue;

                found++;
        }

        ret = (found>2);

        printf("Case #%d: %s\n",cas,ret ? "YES" : "NO");
    }

    return 0;
}
