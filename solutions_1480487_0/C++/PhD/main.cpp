#include <iostream.h>
#include <fstream.h>
#include <math.h>

double f(double,double);
double realfun(double);
int main(){
    double x[50],y[50],F1,F2,F3,F4,max,er;
    int i,j,n;
    x[0]=0;
    y[0]=-2;
    n=10;
    double h=1.0/n;
    ofstream fout("out.txt");
    max=0;
    clrscr();
    fout<<"Runge-Kutta:"<<endl;
    fout<<x[0]<<"\t"<<y[0]<<endl;
    for(i=0;i<n;i++){
        x[i+1]=x[i]+h;
        F1=f(x[i],y[i]);
        F2=f(x[i]+h/2.0,y[i]+h/2.0*F1);
        F3=f(x[i]+h/2.0,y[i]+h/2.0*F2);
        F4=f(x[i+1],y[i]+h*F3);
        y[i+1]=y[i]+(F1+2*F2+2*F3+F4)*h/6.0;
        er=fabs(realfun(x[i+1])-y[i+1]);
        if (er>max) max=er;
        fout<<x[i+1]<<" \t"<<y[i+1]<<"  \t Real: "<<realfun(x[i+1])<<"   \t "<<er<<endl;
    }
    fout<<"Adamsa:"<<endl;
    for(i=3;i<n;i++){
        y[i+1]=y[i]+(h/24.0)*(55*f(x[i],y[i])-59*f(x[i-1],y[i-1])+37*f(x[i-2],y[i-2])-9*f(x[i-3],y[i-3]));
        er=fabs(realfun(x[i+1])-y[i+1]);
        if (er>max) max=er;
        fout<<x[i+1]<<" \t"<<y[i+1]<<"  \t Real: "<<realfun(x[i+1])<<"   \t "<<er<<endl;
    }
    return 0;
}
double f(double x,double y){
    return 2*((x*x*x)-x+y*x);
}
double realfun(double x){
    return (x*x)*exp(2*(x*x));
}

