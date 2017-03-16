import math
import sys
Num=500;
Pum=1;
def fast_pow(a , b):
    x=1;
    y=a;
    while(b!=0):
        if(b%2==1):
            x=x*y;
        y=y*y;
        b=b//2;
    return x;
def to_base_x(S , X):
    j=31;
    Ans=0;
    for i in range (0,32):
        #print("HI")
        c=fast_pow(X,j);
        if(S[i]=='1'):
            Ans=Ans+c;
        j=j-1;
    return Ans;
def prime(X):
    a=math.sqrt(X);
    a=int(a);
    if(X%2==0):
        return 2;
    for i in range (3,100001,2):
        #print(i)
        if(X%i==0):
            return i;
    return 0;

def solve(S , a):
    #print(S)
    global Num
    global Pum
    if(Num==0):
        return 0;
    if(a==32):
        A=[];
        for i in range (2,11):
            V=to_base_x(S,i);
            #print(V)
            #print(V)
            K=prime(V);
            if(K==0):
                return 0;
            A.append(K);
        #print("Hello")
        sys.stdout.write(S+" ")
        for i in A:
            sys.stdout.write(str(i)+" ")
        print(" ")
        Num=Num-1;
        Pum=Pum+1;
        return 0;
    if(a<31):
        solve(S+'0',a+1)
    solve(S+'1',a+1)
    return 0;
def main():
    s="";
    s=s+'1';
    solve(s,1);
main()


        
