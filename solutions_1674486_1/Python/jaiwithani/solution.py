#!/usr/bin/env python
#By Jai Dhyani    
 
import math, sys, os
 
def getints(f):
    return [int(x) for x in f.readline().split()]

def read_case(f):
    num_classes=getints(f)[0]
    children=[[] for x in xrange(num_classes)]
    print len(children)
    roots=[]
    parents=[]
    print "There are %d children:"%num_classes
    for x in xrange(num_classes):
        parents.append([par-1 for par in getints(f)[1:]])
        if len(parents[-1])==0:
            roots.append(x)
        for p in parents[-1]:
            print p
            children[p].append(x)
    leaves=[]
    for i,c in enumerate(children):
        if len(c)==0:
           leaves.append(i) 
    return parents,leaves,roots,children

def solve( parents,leaves, roots, children ):
    for r in roots:
        queue=children[r][:]
        visited=[False for x in xrange(len(parents))]
        while len(queue)!=0:
            q=queue.pop(0)
            if visited[q]:
                return 'Yes'
            visited[q]=True
            queue.extend(children[q])
    return 'No'


    """
    print 'leaves: %s'%(str(leaves))
    ancestors=[[False for x in parents] for y in parents]
    descendents=[set() for y in parents]
    queue=leaves
    while len(queue)>0:
        node=queue.pop(0)
        for p in parents[node]:
            queue.append(p)
            if ancestors[node][p]:
                print '\tDIAG: young:%d\told:%d'%(node,p)
                return 'Yes'
            if node in descendents[p]:
                print '\tDIAG: young:%d\told:%d'%(node,p)
                return 'Yes'
            else:
                ancestors[node][p]=True
                descendents[p].add(node)
        for d in descendents[node]:
            for p in parents[node]:
                if ancestors[d][p]:
                    print '\tDIAG: young:%d\told:%d'%(d,p)
                    return 'Yes'
                else:
                    ancestors[d][p]=True
                    descendents[p].add(d)
    return 'No'
"""

if __name__ == '__main__':
    filenames = [f for f in os.listdir('.') if f[-2:]=='in']
    for filename in filenames:
        outname=filename+'.out'
        f=open(filename)
        out=open(outname,'w')
        try:
            numtrials = getints(f)[0]
        except IndexError as ie:
            print 'no input data in %s'%filename
            exit(0)
        for i in xrange(numtrials):
            print '\n\n\nCASE %d'%(i+1)
            answer_num = solve(*read_case(f))
            answer_str = "Case #%d: %s"%(i+1,answer_num)
            print(answer_str)
            out.write(answer_str+'\n')
