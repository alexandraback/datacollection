#include<iostream>
#include<cmath>
#include<iomanip>
#include<algorithm>

using namespace std;


int main(int argv,char** argc){

    int ntest;
    cin>>ntest;
    cout<<fixed;
    cout<<setprecision(4);

    for(int testi=0;testi<ntest;testi++){

        int n;
        cin>>n;

        double* naomiblock=new double[n];
        double* kenblock=new double[n];

        for(int i=0;i<n;i++){
            cin>>naomiblock[i];
        }

        for(int i=0;i<n;i++){
            cin>>kenblock[i];
        }

        sort(naomiblock,naomiblock+n);
        sort(kenblock,kenblock+n);


        //finding cheating one.
        //loop from start
        //if current naomi is lowe,
        //say that it has slighly less then ken highest.
        //ken will pick that one.
        //if current naomi is higher, then say it is higher than eny ken have.
        //ken will pick the lower one. 
        

        int currentcounter=0;
        int keni=0;
        int kentop=n-1;

        for(int ni=0;ni<n;ni++){
            double curnaomi=naomiblock[ni];
            double curken=kenblock[keni];
            if(curnaomi<curken){
                kentop--;
            }else{
                keni++;
                currentcounter++;
            }
        }

        int cheatingone=currentcounter;

        //Not cheating one
        
        bool* usedken=new bool[n];

        for(int i=0;i<n;i++){
            usedken[i]=false;
        }

        currentcounter=0;
        int naomii=0;

        while(naomii<n){
            
            double curnaomi=naomiblock[naomii];
            bool findlow=false;
            for(int i=0;i<n;i++){
                if(!usedken[i]){
                    if(kenblock[i]>curnaomi){
                        findlow=true;
                        usedken[i]=true;
                        break;
                    }
                }
            }

            if(!findlow){
                currentcounter++;
            }

            naomii++;
        }


        cout<<"Case #"<<testi+1<<": "<<cheatingone<<" "<<currentcounter<<endl;

        /*
        for(int i=0;i<n;i++){
            cout<<naomiblock[i]<<" ";
        }
        cout<<endl;

        for(int i=0;i<n;i++){
            cout<<kenblock[i]<<" ";
        }
        cout<<endl;
        */
        


    }
    return 0;
}


