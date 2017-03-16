#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>

#define FOR(i, a, b) for(int i = (int)(a); i < (int)(b); i++)
#define DEBUG(x) { cout << #x << ": " << (x) << endl; }
#define SQR(x) ((x) * (x))
using namespace std;

//int pocet=0;
int arrived[1001];
int cislo[1001];
int p[1001];
int prisiel_z[1001];
int prisiel_pocet[1001];
int od[1001][11];
bool diamond;

bool chod_spat(int kto,int id,int tag)
{
     //cout<<"prisiel som z "<<id<<" na "<<kto<<" pre tag "<<tag<<endl;
     if (prisiel_z[kto]==tag) 
        {
        //cout<<"nasiel som zdroj"<<endl;
        return(true);
        }
     else if (prisiel_z[kto]==id) 
          {
             return(false);
          }
     else return(chod_spat(prisiel_z[kto],id,tag));
} 

void sir(int z,int kam,int tag)
{
     //cout<<"sirim sa z "<<z<<" na "<<kam<<" tag "<<tag<<endl;
     prisiel_z[kam]=z;
     bool uzbol=false;
     if (arrived[kam]==tag)
        {
        //cout<<"startujem"<<endl;
        diamond=chod_spat(kam,kam,tag);
        uzbol=true;
        }
     
     arrived[kam]=tag;
     prisiel_pocet[kam]=1;
     if (!uzbol)
     if (!diamond)
        {
        FOR(j,0,p[kam])
           {
           sir(kam,od[kam][j],tag);
           }
        }
}

int main()
{
int t;
FILE *in = fopen("Af.in","r");
FILE *out = fopen("Af.out","w");


int n;

fscanf(in,"%d",&t);
FOR(ca,0,t)
    {
    fscanf(in,"%d",&n);
    //cout<<"pocet "<<n<<endl<<endl;
    FOR(i,0,n)
    {
        fscanf(in,"%d",&p[i]);
        arrived[i]=-1;
                                        //cout<<ca<<endl<<endl;
        FOR(j,0,p[i])
        {
            fscanf(in,"%d",&od[i][j]);
            od[i][j]--;
            //cout<<i<<" z "<<od[i][j]<<endl;
        }
    }
    
    diamond=false;
    FOR(i,0,n)
    {
        if (p[i]>1)
           FOR(j,0,p[i])
              { 
              sir(i,od[i][j],i);
              if (diamond)
                 {
                 j=p[i];
                 i=n;
                 }
              }
    }
    


    fprintf(out,"Case #%d: ",ca+1);
    if (diamond) fprintf(out,"Yes\n");
    else  fprintf(out,"No\n");
    
    /*
    if (diamond)cout<<"YES";
    else cout<<"NO";
    //cin.get();*/
    }
    
    
fclose(out);
return 0;
}
