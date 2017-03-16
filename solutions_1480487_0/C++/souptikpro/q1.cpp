#include<iostream>
using namespace std;

main()
{
      int t,tst; cin>>t;
      for(tst=1;tst<=t;tst++)
      {
        double N,x=0.0,neg,negsum,add;
        int n,i,j,spc;
        cin>>N; n=N;
        double s[n];
        double dif[n],y[n];
        for(i=0;i<n;i++) {cin>>s[i]; x+=s[i];}
        
        
        neg=0.0;negsum=0.0;
        for(i=0;i<n;i++)
        {
        //dif[i]= x-(n*s[i]);
        y[i] =(100.0)* ((2*x)-((N)*s[i]))/(x*N);
       // y[i] = (100.0)*(1+ (dif[i]/x))/N;
        if(y[i]<0) {neg++;negsum+=y[i];}
         } 
         
         //cout<<"\nNeg is "<<neg<<endl;
//         cout<<"negsum is "<<negsum<<endl;
//          cout<<"Case #"<<tst<<": ";
//       for(i=0;i<n;i++) 
//        printf("%.6f ",y[i]);
//        cout<<endl;
         
         //if(neg>0)
//         {
//           N=N-neg;
//           for(i=0;i<n;i++) {
//                             if(y[i]<0) y[i]=0;
//                             else y[i] =(100.0)* ((2*x)-((N)*s[i]))/(x*N);
//                             }}
         
         
   if(neg>0)
   {
            add = negsum/(N-neg);
           // cout<<"add is "<<add<<endl;
            for(i=0;i<n;i++) {
                              if(y[i]<0) y[i]=0;
                              else y[i]+=add;}}
            
   
        cout<<"Case #"<<tst<<": ";
       for(i=0;i<n;i++) 
        printf("%.6f ",y[i]);
        cout<<endl;
        
        }//end of tstcase
        }//end
        
        
