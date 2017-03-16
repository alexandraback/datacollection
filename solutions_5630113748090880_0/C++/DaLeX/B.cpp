#include <iostream>
#include <fstream>
#include <strings.h>
using namespace std;

int main()
{
    int t, n, hh[2501], x, i, k, m, xx[50],tmp;
//    fstream infile("test.in");
    fstream infile("B-small-attempt0.in");
//    fstream infile("B-large.in");
//    ofstream outfile("test.out");
    ofstream outfile("B-small.out");
//    ofstream outfile("B-large.out");
    infile >> t;
    cout<<t<<endl;
    for (m=1; m<=t; ++m){
        
		infile >> n;
        cout<<n<<endl;
        
		for (i=1;i<2501;i++)hh[i]=0;
        
		for(i=1;i<2*n;i++){
        	for(k=0;k<n;k++){
			    infile >> x;
    	    	cout<<x<<" ";
        		hh[x]++;
        	}
        	cout<<endl;
		}
		
		k=0;
		for(i=1;i<=2500;i++)
			if(hh[i]%2){
				xx[k]=i;
				k++;
			}
		
		for(i=0;i<n-1;i++)
			for(k=i;k<n-1;++k)
				if(xx[k]>xx[k+1]){
					tmp=xx[k];
					xx[k]=xx[k+1];
					xx[k+1]=tmp;
					cout<<i<<","<<k<<endl;
				}

	    outfile << "Case #"<<m<<": ";
   		cout << "Case #"<<m<<": "; 
   		for (i=0;i<n;i++){
   			cout<<xx[i]<<" ";
   			outfile<<xx[i]<<" ";
		   }
 		cout<<endl;
   		outfile<<endl;

    }

    infile.close();
    outfile.close();
}
