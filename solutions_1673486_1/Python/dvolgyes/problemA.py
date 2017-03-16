#!/usr/bin/python
import numpy as np                      # open source library, http://doc.scipy.org/
import numpy.linalg as linalg           # open source library, http://doc.scipy.org/
import scipy                            # open source library, http://doc.scipy.org/
import sympy                            # open source library, https://github.com/sympy/sympy/wiki/
import networkx as nx                   # open source library, http://networkx.lanl.gov/
import threading,sys,os,time,re   # standard library





class Problem(threading.Thread):
    def __init__(self,A,B,p):
        self.A=A
        self.B=B
        self.p=p
        self.solution=""
        threading.Thread.__init__(self)

    def run(self):
        self.best=B+2 # press enter and finish
        # press back N times, where 0<N<A
        self.ptmp=1.0
        for i in range(0,self.A+1):
            self.back=self.A-i
            self.cost=(self.B-self.A+1+2*self.back)*self.ptmp+(1.0-self.ptmp)*(self.B+1+(self.B-self.A+1+2*self.back))
            self.best=min(self.best,self.cost)
            if i<A:
                self.ptmp=self.ptmp*self.p[i]
        self.solution="%s" % self.best
        
cores=4
threads=[]
problems=int(sys.stdin.readline())

for problem in range(0,problems):
    tmp=sys.stdin.readline().split(" ")
    A=int(tmp[0])
    B=int(tmp[1])
    tmp=sys.stdin.readline().split(" ")
    plist=[]
    for t in tmp:
        plist.append(float(t))
    threads.append(Problem(A=A,B=B,p=plist))
    threads[-1].start()
    threads[-1].join()    
    while threading.active_count()>cores+1:
        time.sleep(0.1)
    
for problem in range(0,problems):
    threads[problem].join()
    print "Case #%i: %s" % (problem+1,threads[problem].solution)


