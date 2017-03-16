# encoding: UTF-8

from __future__ import absolute_import, division

import collections
import itertools
import sys
import functools

class gcj:
    IN = open('D:\code jam\input.in', 'r')
    OUT = open('D:\code jam\output.txt', 'w')
    buf = None

    identity = lambda x: x

    @classmethod
    def _read_line(cls):
        if cls.buf:
            res = cls.buf
            cls.buf = None
        else:
            res = cls.IN.readline()
        if not res:
            raise EOFError()
        return res

    @classmethod
    def line(cls, conv=identity):
        line = cls._read_line()
        return conv(line.rstrip(b'\r\n'))

    @classmethod
    def splitline(cls, conv=identity):
        line = cls._read_line()
        return [conv(x) for x in line.split()]

    @classmethod
    def whitespace(cls):
        line = None
        while not line:
            line = cls._read_line()
            i = 0
            l = len(line)
            while i < l and line[i].isspace():
                i += 1
            line = line[i:]
        cls.buf = line

    @classmethod
    def token(cls, conv=identity):
        cls.whitespace()
        line = cls._read_line()
        i = 0
        l = len(line)
        while i < l and not line[i].isspace():
            i += 1
        cls.buf = line[i:] if i < l else None
        return conv(line[:i])

    @classmethod
    def tokens(cls, cnt, conv=identity):
        #tokens=[]
        #for _ in range(cnt):
        #    tokens.append(cls.token(conv))
        #return tokens   
        return [cls.token(conv) for _ in range(cnt)]

    current_case = 0

    @classmethod
    def case(cls):
        cls.current_case += 1
        return 'Case #{}:'.format(cls.current_case)
    
    @classmethod
    def writefile(cls, case, solve):
        cls.OUT.write( case + " " + str(solve) + '\n')
        return
    
def solve(case):
    #Get Variables
    C,D,V = gcj.tokens(3, int) #can be token(int) or tokens(N, int) # can be int or str
    Dlist = gcj.tokens(D, int) #can be token(int) or tokens(N, int) # can be int or str

    print('C:', C)    
    print('D:', D)    
    print('V:', V) 
    print('Dlist:', Dlist)   


    result=0
    i=0
    
    if V>0 and Dlist[0]!=1:
        Dlist = [1] + Dlist[:]
        result+=1
    print('Dlist2:', Dlist)   
    test=C
    i=1
            
    while test<=V:
        while i<len(Dlist) and Dlist[i] <= test+1: # existentes servem?
            test+=Dlist[i]*C #qto consigo pagar
            i+=1
        
        #ultrassou V
        if test>=V:
            print('Dlist3:', Dlist) 
            return result
        
        #ou introduzir nova
        if i<len(Dlist):
            Dlist = Dlist[:i] + [test+1] + Dlist[i:]
        else:
            Dlist = Dlist + [test+1]
        result+=1
        

 
    
    
    return result

def lcm(a,b):
    gcd, tmp = a,b
    while tmp != 0:
        gcd,tmp = tmp, gcd % tmp
    return int(a*b/gcd)

def main():
    t = gcj.token(int)
    for _ in range(t):
        case = gcj.case()
        if case == "Case #34:":
            j=1
        result = solve(case)
        
        gcj.writefile(case, result)
        print(case, result)

main()
