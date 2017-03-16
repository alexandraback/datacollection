#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
int p[100][100];
int main() {
	int x,c=1;
	cin>>x;
	while(x--) {
        int j,p,s,k, w = 0;
        cin>>j>>p>>s>>k;
        printf("Case #%d: ",c++);     
        
        if(j == 1 && p == 1 && s == 1) {
        	cout<<"1\n";
        	cout<<"1 1 1";
        } else if(j == 1 && p == 1 && s == 2) {
        	if(k == 1) {
        		cout<<"1\n";
        	    cout<<"1 1 1";
        	}	
        	else if(k >= 2) {
        		cout<<"2\n";
        	    cout<<"1 1 1\n1 1 2";
        	}	
        } else if(j == 1 && p == 1 && s == 3) {
        	if(k == 1) {
        		cout<<"1\n";
        	    cout<<"1 1 1";
        	}	
        	else if(k == 2) {
        		cout<<"2\n";
        	    cout<<"1 1 1\n1 1 2";
        	}	
        	else if(k >= 3) {
        		cout<<"3\n";
        	    cout<<"1 1 1\n1 1 2\n1 1 3";
        	}	
        } else if(j == 1 && p == 2 && s == 2) {
        	if(k == 1) {
        		cout<<"2\n";
        	    cout<<"1 1 1\n1 2 2";
        	}	
        	else if(k >= 2) {
        		cout<<"4\n";
        	    cout<<"1 1 1\n1 1 2\n1 2 1\n1 2 2";
        	}	
        } else if(j == 1 && p == 2 && s == 3) {
        	if(k == 1) {
        		cout<<"2\n";
        	    cout<<"1 1 1\n1 2 2";
        	}	
        	else if(k == 2) {
        		cout<<"4\n";
        	    cout<<"1 1 1\n1 1 2\n1 2 1\n1 2 2";
        	}	
        	else if(k >= 3) {
        		cout<<"6\n";
        	    cout<<"1 1 1\n1 1 2\n1 1 3\n1 2 1\n1 2 2\n1 2 3";
        	}	
        } else if(j == 1 && p == 3 && s == 3) {
        	if(k == 1) {
        		cout<<"3\n";
        	    cout<<"1 1 1\n1 2 2\n1 3 3";
        	}	
        	else if(k == 2) {
        		cout<<"6\n";
        	    cout<<"1 1 1\n1 1 2\n1 2 3\n1 2 2\n1 3 1\n1 3 3";
        	}	
        	else if(k >= 3) {
        		cout<<"9\n";
        	    cout<<"1 1 1\n1 1 2\n1 1 3\n1 2 1\n1 2 2\n1 2 3\n1 3 1\n1 3 2\n1 3 3";
        	}	
        } else if(j == 2 && p == 2 && s == 2) {
        	if(k == 1) {
        		cout<<"4\n";
        	    cout<<"1 1 1\n1 2 2\n2 1 2\n2 2 1";
        	}	
        	else if(k >= 2) {
        		cout<<"8\n";
        	    cout<<"1 1 1\n1 1 2\n1 2 1\n1 2 2\n2 1 1\n2 1 2\n2 2 1\n2 2 2";
        	}	
        } else if(j == 2 && p == 2 && s == 3) {
        	if(k == 1) {
        		cout<<"4\n";
        	    cout<<"1 1 1\n1 2 2\n2 1 2\n2 2 1";
        	}	
        	else if(k == 2) {
        		cout<<"8\n";
        	    cout<<"1 1 1\n1 2 2\n2 1 2\n2 2 1\n1 1 2\n1 2 1\n2 1 3\n2 2 2";
        	}	
        	else if(k >= 3) {
        		cout<<"12\n";
        	    cout<<"1 1 1\n1 1 2\n1 1 3\n1 2 1\n1 2 2\n1 2 3\n2 1 1\n2 1 2\n2 1 3\n2 2 1\n2 2 2\n2 2 3";
        	}	
        } else if(j == 2 && p == 3 && s == 3) {
        	if(k == 1) {
        		cout<<"5\n";
        	    cout<<"1 1 1\n1 2 2\n2 1 2\n2 2 1\n1 3 3";
        	}	
        	else if(k == 2) {
        		cout<<"10\n";
        	    cout<<"1 1 1\n1 2 2\n1 3 3\n2 1 2\n2 2 1\n2 3 3\n1 1 2\n1 2 1\n2 1 1\n2 2 2"; 
        	}	
        	else if(k >= 3) {
        		cout<<"18\n";
        	    cout<<"1 1 1\n1 1 2\n1 1 3\n1 2 1\n1 2 2\n1 2 3\n1 3 1\n1 3 2\n1 3 3\n2 1 1\n2 1 2\n2 1 3\n2 2 1\n2 2 2\n2 2 3\n2 3 1\n2 3 2\n2 3 3";
        	}
        } else if(j == 3 && p == 3 && s == 3) {
        	if(k == 1) {
        		cout<<"7\n";
        	    cout<<"1 1 1\n1 2 2\n2 1 2\n2 2 1\n1 3 3\n3 1 3\n3 3 1";
        	}	
        	else if(k == 2) {
        		cout<<"14\n";
        	    cout<<"1 1 1\n1 2 2\n1 3 3\n2 1 2\n2 2 1\n2 3 3\n1 1 2\n1 2 1\n2 1 1\n2 2 2\n3 1 3\n3 2 3\n3 3 1\n3 3 2"; 
        	}	
        	else if(k >= 3) {
        		cout<<"27\n";
        	    cout<<"1 1 1\n1 1 2\n1 1 3\n1 2 1\n1 2 2\n1 2 3\n1 3 1\n1 3 2\n1 3 3\n2 1 1\n2 1 2\n2 1 3\n2 2 1\n2 2 2\n2 2 3\n2 3 1\n2 3 2\n2 3 3\n3 1 1\n3 1 2\n3 1 3\n3 2 1\n3 2 2\n3 2 3\n3 3 1\n3 3 2\n3 3 3";
        	}
        } 
        
        printf("\n");     
	}
	return 0;
}
