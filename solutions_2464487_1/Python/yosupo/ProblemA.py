# -*- coding: utf-8 -*-
from math import sqrt

r = 0
def inknum(n):
    return (r+2*(n+1))*n

if __name__ == "__main__":
    s = input().splitlines()
    count = int(s[0])
    f=open("output.txt", "w")
    result = list()
    for i,date in enumerate(s[1:: ]):
        date = date.split()
        r = int(date[0])
        t = int(date[1])
        r = 2*r - 3
        a = 1
        while (inknum(a) <= t):
            a*=2
        a//=2
        b=a
        while(a != 1):
            a//=2
            if (inknum(b+a) <= t):
                b+=a
        result.append("Case #"+str(i+1)+": "+str(b)+ "\n")
    f.writelines(result)
    f.close()
