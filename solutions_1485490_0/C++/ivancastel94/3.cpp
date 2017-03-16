#include<iostream>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdio.h>
#include<string.h>
using namespace std;

unsigned long long int max(vector <unsigned long long int> a1, vector <unsigned long long int> A1, vector <unsigned long long int> b1, vector <unsigned long long int> B1){
    vector<unsigned long long int> a,A,b,B;
    a=a1;
    A=A1;
    b=b1;
    B=B1;
    unsigned long long int sum,sum1,sum2;
    if(A.size()==0)return 0;
    if(B.size()==0)return 0;
    if(A[0]==B[0]){
        if(a[0]>b[0]){
            sum=b[0];
            a[0]-=b[0];
            B.erase(B.begin());
            b.erase(b.begin());
            return max(a,A,b,B)+sum;
            }
        if(a[0]<b[0]){
            sum=a[0];
            b[0]-=a[0];
            a.erase(a.begin());
            A.erase(A.begin());
            return max(a,A,b,B)+sum;
            }
        else{
            sum=a[0];
            a.erase(a.begin());
            A.erase(A.begin());
            b.erase(b.begin());
            B.erase(B.begin());
            return max(a,A,b,B)+sum;
            }
        }
    a.erase(a.begin());
    A.erase(A.begin());
    b.erase(b.begin());
    B.erase(B.begin());
    sum1=max(a,A,b1,B1);
    sum2=max(a1,A1,b,B);
    if(sum1>sum2)return sum1;
    return sum2;
    }

int main(){
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    unsigned long long int i,t,cases,n,m,ai,Ai,bi,Bi;
    vector<unsigned long long int> a,A,b,B;
    cin>>t;
    cases=1;
    while(t>0){
        cin>>n>>m;
        for(i=0;i<n;i++){
            cin>>ai;
            cin>>Ai;
            a.push_back(ai);
            A.push_back(Ai);
            }
        for(i=0;i<m;i++){
            cin>>bi;
            cin>>Bi;
            b.push_back(bi);
            B.push_back(Bi);
            }
        cout<<"Case #"<<cases<<": "<<max(a,A,b,B)<<endl;
        a.clear();
        A.clear();
        b.clear();
        B.clear();
        cases++;
        t--;
        }
    }
