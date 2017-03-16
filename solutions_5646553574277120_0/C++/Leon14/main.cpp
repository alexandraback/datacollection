#include <iostream>
#include <fstream>
#include <conio[1].h>

using namespace std;

int i,j,t,h,c,v,d,monedas[100],valores[100],nuevas;

int llena(int a, int tot)
{
    int aux;
    //cout<<a<<" "<<tot<<" "<<d<<endl;
   // getch();

    if(a<=d)
    {

aux=tot+monedas[a];
if(aux<=v)
{
    valores[aux]=1;

    //cout<<aux<<endl;
    llena(a+1,aux);

}


    llena(a+1,tot);


    }
return 0;
}

int main()
{
    ifstream in("C-small-attempt1.in");
    ofstream out("salidalessmoney.out");


    in>>t;
    for(h=1;h<=t;h++)
    {
        in>>c>>d>>v;
        nuevas=0;
        for(i=1;i<=d;i++)
        {
            in>>monedas[i];
        }

        for(i=1;i<=v;i++)
        {
            valores[i]=0;
        }

        llena(1,0);
        for(i=1;i<=v;i++)
        {

            if(valores[i]==0)
            {
                nuevas=nuevas+1;
                llena(1,i);
            }
        }


        out<<"Case #"<<h<<": "<<nuevas<<endl;

    }




    in.close();
    out.close();
    return 0;
}
