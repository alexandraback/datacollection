#include <iostream>
#include <cmath>

using namespace std;

int ocupados[101];
int marcados[101][101];
int matriz[101][101];
int N,M;

void vaciaOcupados()
{
    for(int i=0;i<=100;i++){
        ocupados[i]=0;
        for(int j=0;j<=100;j++){
            marcados[i][j]=0;
        }
    }
}

void procesarL(int pos,int tam)
{
    for(int i=0;i<N;i++)
    {
        if(matriz[i][pos]>tam)
            return;
    }
    for(int i=0;i<N;i++)
    {
        if(matriz[i][pos]==tam){
            marcados[i][pos]=1;
        }
    }
}

void procesarH(int pos,int tam)
{
    for(int i=0;i<M;i++)
    {
        if(matriz[pos][i]>tam)
            return;
    }
    for(int i=0;i<M;i++)
    {
        if(matriz[pos][i]==tam){
            marcados[pos][i]=1;
        }
    }
}

int esPosible()
{
    int i,j,k;
    
    for(i=100;i>=1;i--)
    {
        if(ocupados[i]==1)
        {
            for(j=0;j<M;j++)
            {
                procesarL(j,i);
            }
            for(j=0;j<N;j++)
            {
                procesarH(j,i);
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(marcados[i][j]==0)
            {
                return 0;
            }
        }
    }
    return 1;
}


int main()
{
    unsigned long long int i,j,k;
    int T;
    cin >>T;
    
    for(int i=1;i<=T;i++)
    {
        vaciaOcupados();
        cin >> N >> M;
        
        for(j=0;j<N;j++)
        {
            for(k=0;k<M;k++)
            {
                cin >> matriz[j][k];
                ocupados[matriz[j][k]]=1;
            }
        }
        if(esPosible())
        {
            cout << "Case #"<<i<<": YES" << endl;
        }
        else
        {
            cout << "Case #"<<i<<": NO"<< endl;
        }
        
    }
    
    return 0;
}
