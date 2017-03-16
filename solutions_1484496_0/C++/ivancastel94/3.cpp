#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdio.h>
#include<string.h>
using namespace std;
int main(){
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    int cases,t,n,i,j,elements[30],sum,lim,aux;
    map<int,int> sumas;
    cin>>t;
    cases=1;
    while(t>0){
        cout<<"Case #"<<cases<<":"<<endl;
        cin>>n;
        for(i=0;i<n;i++){
            cin>>elements[i];
            }
        lim=pow(2,n);
        for(i=1;i<lim;i++){
            aux=i;
            sum=0;
            j=0;
            while(aux>0){
                if(aux%2==1)sum+=elements[j];
                j++;
                aux=aux/2;
                }
            if(sumas.count(sum)>0){
                aux=sumas[sum];
                j=0;
                while(aux>0){
                    if(aux%2==1)cout<<elements[j]<<" ";
                    j++;
                    aux=aux/2;
                    }
                cout<<endl;
                aux=i;
                j=0;
                while(aux>0){
                    if(aux%2==1)cout<<elements[j]<<" ";
                    j++;
                    aux=aux/2;
                    }
                cout<<endl;
                break;
                }
            else{
                sumas.insert(pair<int,int>(sum,i));
                }
            }
        if(i==lim)cout<<" Imposible"<<endl;
        sumas.clear();
        cases++;
        t--;
        }
    }
