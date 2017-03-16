#!/usr/bin/python

import sys
from itertools import combinations_with_replacement  

class Node:
    def __init__(self,num,visited):
        self.num=num
        self.visited=visited
        self.visited.append(num)

def calculate(numNodes,edges):
    #print edges
    queue=[]
    for n in range(1,numNodes+1): 
        queue.append(Node(n,[]))
    while len(queue)>0:
        node=queue.pop(-1)
        for edge in edges[node.num]:
            if edge in node.visited:
               return "Yes"
            else:
               queue.append(Node(edge,node.visited))
    return "No"

if __name__ == "__main__":
    f = sys.stdin
    if len(sys.argv) >= 2:
        fn = sys.argv[1]
        f = open(fn)
   
    count = int(f.readline())
    for c in range(count): 
        line=f.readline()
        split=line.split(" ")
        numNodes=int(split[0])
        edges=dict()
        for i in range(0,numNodes):
            line=f.readline()
            split=line.split(" ")
            edges[i+1]=[]
            if len(split)==1:
                continue
            for s in range(1,int(split[0])+1): 
                edges[i+1].append(int(split[s]))
        print "Case #%d: %s" %(c+1,calculate(numNodes,edges))


