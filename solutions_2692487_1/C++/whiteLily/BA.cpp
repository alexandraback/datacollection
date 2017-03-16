/* 
 * File:   BA.cpp
 * Author: eajisah
 *
 * Created on May 4, 2013, 9:10 PM
 */

#include <cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<stack>
#include<queue>
#include<list>
#include<cctype>  //They check whether the character passed as parameter belongs to a certain category also lower to upper conversion done
#include<ciso646> //This header defines eleven macro constants with alternative spellings for those C++ operators not supported by the ISO646 standard character set
#include<climits>
#include<cmath>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<vector>
#define FT(t,n) for(int t=1;t<=n;t++)
#define FR(i,n) for(int i=0;i<n;i++)
#define RFR(i,n) for(int i=n-1;i>=0;i--)

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    freopen("A-small.in","r",stdin);
    freopen("A-small.out","w",stdout);
    unsigned int test;
    scanf("%d",&test);
    FT(t,test){
        printf("Case #%d: ",t);
        unsigned int n,a,cpa;
        long long m[102];
        
        scanf("%d %d",&a,&n);
        FR(i,n){
            scanf("%lu",&m[i]);
            //long long ll=m[i];
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(m[i]>m[j]){
                    long long t;
                    t=m[j];
                    m[j]=m[i];
                    m[i]=t;
                }
            }
        }
        unsigned int ct=0,ct1=0;
        cpa=a;
        FR(x,n){
            if(a==1){
                printf("%d",n);
                goto en;
            }
            else if(a>m[x]){
                a+=m[x];
            }
            else{
                if((2*a-1)>m[x]){
                        a+=m[x]-a+1;
                        x--;
                        ct++;
                }
                else{
                    ct+=(n-x);
                    break;
                }
            }
        }
        FR(x,n){
            if(cpa==1){
                printf("%d",n);
                goto en;
            }
            else if(cpa>m[x]){
                cpa+=m[x];
            }
            else{
                        cpa+=cpa-1;
                        x--;
                        ct1++;
            }
        }
        if(ct<ct1)
                printf("%d",ct);
        else
            printf("%d",ct1);
        en:
        printf("\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

