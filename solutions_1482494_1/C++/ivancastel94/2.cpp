#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
int main(){
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int min,mov,i,j,cases,t,n,newstars,stars,a[1002],b[1002];
    bool tabla[1002][2];
    cin>>t;
    cases=1;
    while(t>0){
        cin>>n;
        for(i=0;i<n;i++){
            cin>>a[i]>>b[i];
            tabla[i][0]=tabla[i][1]=0;
            }
        stars=mov=0;
        while(stars<2*n){
            newstars=stars;
            for(i=0;i<n;i++){
                if(b[i]<=stars&&tabla[i][1]==0&&tabla[i][0]==0){
                    newstars=newstars+2;
                    tabla[i][0]=tabla[i][1]=1;
                    break;
                    }
                }
            if(i==n){
                for(i=0;i<n;i++){
                    if(b[i]<=stars&&tabla[i][1]==0){
                        newstars++;
                        tabla[i][1]=1;
                        break;
                        }
                    }
                if(i==n){
                    min=-1;
                    for(i=0;i<n;i++){
                        if(a[i]<=stars&&tabla[i][0]==0){
                            if((min==-1)||(b[i]>b[min]))min=i;
                            }
                        }
                    if(min!=-1){
                        newstars++;
                        tabla[min][0]=1;
                        }
                    }
                }
            if(stars==newstars)break;
            stars=newstars;
            mov++;
            }
        if(stars!=2*n) printf("Case #%d: Too Bad\n",cases);
        else printf("Case #%d: %d\n",cases,mov);
        cases++;
        t--;
        }
    //system("pause");
    }
