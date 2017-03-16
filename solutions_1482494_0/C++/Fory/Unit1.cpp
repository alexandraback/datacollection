#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

struct TJuego{
    int una,dos;
};

operator <(const TJuego &a,const TJuego &b)
{
    if (a.dos!=b.dos){
        return a.dos<b.dos;
    }
    return a.una>b.una;
}

int mejor;
int N;
int memoria[1001][2002];

void busca(vector<TJuego>&juegos,vector<int> &estado,int estrellas,int pasos)
{
    //check if it is possible to beat best score
    int h=(N<<1)-estrellas;
    if (h==0)
    {
        if (pasos<mejor)
        {
            mejor=pasos;
            return;
        }
    }
    h+=h&1;
    h>>=2;
    if ((pasos+h)>=mejor)
        return;
    //take all the 2 star games possible
    for (int i=0;i<N;i++)
    {
        if (estado[i]==2)
            continue;
        if (estrellas<juegos[i].una)
            continue;
        if (estrellas>=juegos[i].dos)
        {
            //take this game
            int prev=estado[i];
            estado[i]=2;
            busca(juegos,estado,estrellas+2-prev,pasos+1);
            estado[i]=prev;
            return;
        }
    }
    //only 1 star games are possible, take one of those games
    for (int i=0;i<N;i++)
    {
        if ((estado[i]==0)&&(estrellas>=juegos[i].una))
        {
            estado[i]=1;
            busca(juegos,estado,estrellas+1,pasos+1);
            estado[i]=0;
        }
    }
}

int main(int argc, char* argv[])
{
    int T;
    scanf("%d",&T);
    for (int t=1;t<=T;t++)
    {
        scanf("%d",&N);
        vector<TJuego> juegos;
        vector<int> estado;
        vector<int> todo;
        juegos.resize(N);
        estado.resize(N);
        todo.resize(2*N);
        mejor=1000000;
        for (int n=0;n<N;n++)
        {
            scanf("%d %d",&juegos[n].una,&juegos[n].dos);
            estado[n]=0;
            todo[2*n]=juegos[n].una;
            todo[2*n+1]=juegos[n].dos;
        }
        sort(juegos.begin(),juegos.end());
        busca(juegos,estado,0,0);
        if (mejor==1000000)
        {
            printf("Case #%d: Too Bad\n",t);
            continue;
        }
        printf("Case #%d: %d\n",t,mejor);
    }
    return 0;
}
//---------------------------------------------------------------------------

