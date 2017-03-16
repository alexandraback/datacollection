//Google codeJam 2013 Round 1C Problem A
//Abdurrahman Akkas
//recursive fonksiyon yazmayacagima yemin ederim
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
    long long T,i,n,j,k,l,min,ii;
    char ch;
    long long N;
    cin >> T;
    for(i=1;i<=T;i++)
    {
        N=0;
        j=0;
        cin>>ch;
        FILE *file1=fopen("temp.txt","w");
        while(ch!=' '){
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
                fprintf(file1,"%c",'a');
            else
                fprintf(file1,"%c",'b');
            j++;
            cin>> noskipws >>ch;
        }
        fclose(file1);
        cin>>n;
        l=0;
        min=-1;
        file1=fopen("temp.txt","r");
        char ttemp;
        for(k=0;k<j;k++){
            fscanf(file1,"%c",&ttemp);
            if(ttemp=='b')
                l++;
            else
                l=0;
            if(l>=n)
                min=k-n+1;
            if(min!=-1){
                N+=min+1;
            }
        }
        fclose(file1);
        cout<<"Case #"<<i<<": "<<N<<"\n";
        cin>>ch; 
    }
    cin>>T;
    cin>>T;
    return 0;
}
