#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;
int a[2501],dig[20];
char s[5010], d[5010], q[5010], w[5010];
long long o,p, min1, s1Number, d1Number;

long long sNumber(int len)  {
	o = 0;
	for(int i= 0; i < len  ; i++) {
		o = o * 10 + (q[i] - '0');
	}
	return o;
}
long long dNumber(int len)  {
	p = 0;
	for(int i= 0; i < len  ; i++) {
		p = p * 10 + (w[i] - '0');
	}
	return p;
}

int main() {
	int x,c=1;
	cin>>x;
	while(x--) {
        cin>>s>>d;
        int len = strlen(s);
        min1 = 1000000LL * 1000000LL * 1000000LL;
        
        if(len == 1) {
        	if(s[0] == '?' && d[0] == '?') {
        		for(int j= 0; j < len; j++) q[j] = s[j];
        		       	         for(int j= 0; j < len; j++) w[j] = d[j];
        		s1Number = 0;
        		d1Number = 0;
        	}
			if(s[0] == '?' && d[0] != '?') {
				for(int j= 0; j < len; j++) q[j] = s[j];
        		       	         for(int j= 0; j < len; j++) w[j] = d[j];
        		s1Number = dNumber(len);
        		d1Number = dNumber(len);
        	}		
        	if(s[0] != '?' && d[0] == '?') {
        		for(int j= 0; j < len; j++) q[j] = s[j];
        		       	         for(int j= 0; j < len; j++) w[j] = d[j];
        		s1Number = sNumber(len);
        		d1Number = sNumber(len);
        	}		
        	printf("Case #%d: %lld %lld",c++, s1Number, d1Number);
        }
			
        if(len == 3) {
        	for(int i1= 0; i1 < 10; i1++) {
        	   for(int i2 = 0; i2 < 10; i2++) {
        		   for(int i3= 0; i3 < 10; i3++) {
        		       for(int i4= 0; i4 < 10; i4++) {
        	              for(int i5= 0; i5 < 10; i5++) {
        		             for(int i6= 0; i6 < 10; i6++) {
        		             	 for(int j= 0; j < len; j++) q[j] = s[j];
        		       	         for(int j= 0; j < len; j++) w[j] = d[j];
        		                 if(q[0] == '?') q[0] = (char) i1 + 48;
        		                 if(q[1] == '?') q[1] = (char) i2 + 48;
        		                 if(q[2] == '?') q[2] = (char) i3 + 48;
        		                 if(w[0] == '?') w[0] = (char) i4 + 48; 
        		                 if(w[1] == '?') w[1] = (char) i5 + 48; 
        		                 if(w[2] == '?') w[2] = (char) i6 + 48; 
        		                 if(abs(dNumber(len) - sNumber(len)) < min1) {
			                        s1Number = sNumber(len);
                        			d1Number = dNumber(len);
			                        min1 = abs(dNumber(len) - sNumber(len));
		                         } 	
                             } 
                          }	
                       }
                   } 
               }	
            }
            printf("Case #%d: ",c++);
        }	
        
        if(len == 2) {
        	for(int i1= 0; i1 < 10; i1++) {
        	   for(int i2 = 0; i2 < 10; i2++) {
        		   for(int i3= 0; i3 < 10; i3++) {
        		       for(int i4= 0; i4 < 10; i4++) {
        		       	         for(int j= 0; j < len; j++) q[j] = s[j];
        		       	         for(int j= 0; j < len; j++) w[j] = d[j];
        		                 if(q[0] == '?') q[0] = (char) i1 + 48;
        		                 if(q[1] == '?') q[1] = (char) i2 + 48;
        		                 if(w[0] == '?') w[0] = (char) i3 + 48; 
        		                 if(w[1] == '?') w[1] = (char) i4 + 48; 
        		                 //printf("Case #%d: %lld %lld",c++, sNumber(len), dNumber(len));
        		                 if(abs(dNumber(len) - sNumber(len)) < min1) {
			                        s1Number = sNumber(len);
                        			d1Number = dNumber(len);
			                        min1 = abs(dNumber(len) - sNumber(len));
		                         }	
                             } 
                          }	
               }	
            }
            printf("Case #%d: ",c++);
        }	
        
        
        if(len == 2) {
        	if(s1Number < 10) {
        		printf("0%lld ",s1Number);
        	}
        	else {
        		printf("%lld ",s1Number);
        	}
        	if(d1Number < 10) {
        		printf("0%lld",d1Number);
        	}
        	else {
        		printf("%lld ",d1Number);
        	}
        }
        if(len == 3) {
        	if(s1Number < 10) {
        		printf("00%lld ",s1Number);
        	}
        	else if(s1Number < 100) {
        		printf("0%lld ",s1Number);
        	} 
        	else {
        		printf("%lld ",s1Number);
        	}
        	if(d1Number < 10) {
        		printf("00%lld",d1Number);
        	}
        	else if(d1Number < 100) {
        		printf("0%lld",d1Number);
        	}
        	else {
        		printf("%lld ",d1Number);
        	}
        }
        printf("\n");
	}
	return 0;
}
