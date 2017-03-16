// Abdurrahman Akkas - abdurak
// Google CodeJam 2014
// Qualification Round
// Problem D

#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;
int War(double Nao[],double Ken[],int N){
    sort(Nao,Nao+N);
    sort(Ken,Ken+N);
    int KenPlayed[1000]={0};
    int count=0;
    for(int i=0;i<N;i++){
        int j=N-1;
        while(KenPlayed[j]==1) j--;
        if(Nao[i]>Ken[j]){
            count++;
            j=0;
            while(KenPlayed[j]==1) j++;
            KenPlayed[j]=1;
        }else{
            j=0;
            while(Ken[j]<Nao[i] || KenPlayed[j]==1) j++;
            KenPlayed[j]=1;
        }
    }
    return count;
}
int Deceived(double Nao[],double Ken[],int N){
    sort(Nao,Nao+N);
    sort(Ken,Ken+N);
    int i=N-1,j=N-1,count=0;
    for(i=N-1;i>=0;i--){
        if(Nao[j]>Ken[i]){ count++; j--;}
    }
    return count;
}
int main(){
    ifstream fin("D.in");
    ofstream fout("D.out");
    int T,iT;
    fin>>T;
    for(iT=1;iT<=T;iT++){
        int N;
        fin>>N;
        double Nao[N],Ken[N];
        for(int i=0;i<N;i++) fin>>Nao[i];
        for(int i=0;i<N;i++) fin>>Ken[i];
        fout<<"Case #"<<iT<<": ";
        fout<<Deceived(Nao,Ken,N)<<" ";
        fout<<War(Nao,Ken,N);
        fout<<endl;
    }
    return 0;
}
