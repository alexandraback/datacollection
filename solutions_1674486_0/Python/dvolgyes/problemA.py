#!/usr/bin/python
import numpy as np                      # open source library, http://doc.scipy.org/
import numpy.linalg as linalg           # open source library, http://doc.scipy.org/
import scipy                            # open source library, http://doc.scipy.org/
import sympy                            # open source library, https://github.com/sympy/sympy/wiki/
import networkx as nx                   # open source library, http://networkx.lanl.gov/
import threading,sys,os,time,re         # standard python libraries
#import visual                           # visual python
#from visual import vector


from sympy import Symbol


def list_of_parents(graph,i):
    result=[]
    result.extend(graph[i])
    for p in graph[i]:
        result.extend(list_of_parents(graph,p))
    return result

def list_of_parents2(graph,i,j):
    result=[]
    for p in graph[i]:
        if p!=j:
            result.append(p)    
            result.extend(list_of_parents(graph,p))
    return result


def compare(set1,set2):

    for a in set1:
        if a in set2: return True
    return False

def solve(graph):
    for point in range(0,len(graph)):
        parents=graph[point]
        for p1 in parents:
           if compare(list_of_parents2(graph,point,p1),list_of_parents(graph,p1)): return True
           for p2 in parents:
               if p1!=p2:
                   if compare(list_of_parents(graph,p1),list_of_parents(graph,p2)): return True

                                      
    return False

for testcase in xrange(1, int(sys.stdin.readline())+1):
    N = int(sys.stdin.readline())
    osok=[]
    for i in range(0,N):
       tmp = [int(w) for w in sys.stdin.readline().split()]
       tmp = tmp[1:]
       tmp = [int(w)-1 for w in tmp]
       osok.append(set(list(tmp)))
#    print osok
    res=solve(osok)
    if res==True:
        solution="Yes"
    else:
        solution="No"
    print 'Case #%d: %s' % (testcase, solution)
#    print

