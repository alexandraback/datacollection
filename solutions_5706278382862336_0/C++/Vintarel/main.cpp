//
//  main.cpp
//  CodeJam
//
//  Created by Nelson on 24/03/2014.
//  Copyright (c) 2014 Nelson. All rights reserved.
//


#include <iostream>
#include <stdio.h>
using namespace std;

long long GCD(long long a, long long b)
{
	if(a<b)
	{
		long long aux = b;
		b = a;
		a = aux;
	}
	long long r=a%b;
	while(r != 0)
	{
		a = b;
		b = r;
		r = a%b;
	}	
	return b;
}

long long pow2(int n)
{
	return 1LL<<n;
}


int checkIfPow2(long long number)
{
	if(number == 0LL)
		return -1;
	if ((number & (number-1)) != 0LL)	//not a power of 2
		return -1;
	int n=0;
	while( (number & 1) == 0)
	{
		number = number>>1;
		n++;
	}
		
	return n;

}

int main(int argc, const char * argv[])
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    
    int T, n, res;
    cin>>T;
    long long p, q, pow2res;
    
    //long long num = pow2(42);
    //cout<<num<<endl;
    //cout<<"now="<<checkIfPow2(num)<<endl;
    
    
    for(int i=0; i<T; i++)
    {
    	
    	scanf("%lld/%lld", &p, &q);
    	long long g = GCD(p, q);
    	//cout<<p/g<<" "<<q/g<<endl;
    	p = p/g;
    	q = q/g;
    	n = checkIfPow2(q);
    	if(n == -1)
        {
            cout<<"Case #"<<i+1<<": impossible"<<endl;
        }
    	else
    	{
    		res = n-1;
    		pow2res = q>>1;
    		while(res > 0 && (p&pow2res) == 0LL)
    		{
    			pow2res = pow2res>>1;
    			res--;
    		}
    		cout<<"Case #"<<i+1<<": "<<n-res<<endl;
    	}
    	
    	/*
        
        else if(res == 0)
        {
            cout<<"Case #"<<i+1<<": Volunteer cheated!"<<endl;
        }
        else
        {
            cout<<"Case #"<<i+1<<": Bad magician!"<<endl;
        }*/
    }
	return 0;
}

