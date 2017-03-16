#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int numOfN(double c,double f,double x){

    double result=((f*(x-c))/c-2)/f;
    
    if(result<0){
        return 0;
    }else{
        return (int)(result)+1;
    }

}

double timeOnN(double c,double f,int n){
    double counter=0;

    for(int i=0;i<n;i++){
        counter+=(c/(i*f+2));
    }

    return counter;
}

int main(int argv,char** argc){

    int ntest;
    cin>>ntest;
    cout<<fixed;
    cout<<setprecision(7);

    for(int testi=0;testi<ntest;testi++){

        double c,f,x;
        cin>>c>>f>>x;


        int nn=numOfN(c,f,x);
        double elapsed=timeOnN(c,f,nn);
        double crate=nn*f+2;
        double nexttime=x/crate;

        cout<<"Case #"<<testi+1<<": ";
        double total=elapsed+nexttime;
        cout<<total<<endl;


        /*

        double curtime=0;
        double currate=2;
        int numfactory=0;

        //while the time for new factory + cookie on next rate is less than cookie now
        while( (x/(currate+f))+(c/currate) < x/currate ){
            
            //add time for new cookie factory
            curtime+=c/currate;
            //now add rate
            //currate+=f; too many error

            numfactory++;
            currate=2+numfactory*f;

        }
        
        curtime+=x/currate;

        cout<<"Case #"<<testi+1<<": ";
        cout<<curtime<<endl;

        */

    }
    return 0;
}


