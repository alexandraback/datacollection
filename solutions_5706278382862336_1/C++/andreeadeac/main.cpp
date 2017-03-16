#include <fstream>
using namespace std;

ifstream in("elf.in");
ofstream out("elf.out");

int t;

void  putere(long long x, long long &cod, long long &ex){
    cod=1;
    ex=0;
    while(x>0){
        if(x%2==1 && x!=1){
            cod=0;
            x=x/2;
        }
        else{
            if(x!=1)
                ex++;
            x=x/2;
        }
    }
}

long long cmmdc(long long p, long long q){
    long long t;
    while (q != 0)
    {
        t = q;
        q = p % q;
        p = t;
    }
    return p;
}

void simplificare(long long &p, long long &q){
    long long x;
    x=cmmdc(p,q);
    p=p/x;
    q=q/x;
}

long long putere2(int q){
    long long cod,ex,q1;
    do{
        putere(q,cod,ex);
        if(cod!=1)
            q--;
    }while(cod==0);
    return q;
}

long long niv(long long p, long long q,  long long nivel){
    long long cod,ex,q1,q2;
    if(p==1){
        putere(q,cod,ex);
        return nivel+ex;
    }
    else{
        p=putere2(p);
        q1=q/2;
        simplificare(p,q);
        if(q1>q){
            putere(q,cod,ex);
            return nivel+ex;
        }
        else{
            putere(q1,cod,ex);
            return nivel+ex;
        }
    }
}
int main()
{
    long long i,cod,ex,p,q,nivel;
    char c;
    in>>t;
    for(i=1;i<=t;i++){
        in>>p>>c>>q;
        simplificare(p,q);
        putere(q,cod,ex);
        out<<"Case #"<<i<<": ";
        if(cod==0)
            out<<"impossible";
        else{
            nivel=niv(p,q,0);
            out<<nivel;
        }
        out<<"\n";
    }
    return 0;
}
