import re, copy
import math

class Node(object):
    def __init__(self, data):
        self.data = data
        self.arriv=[]
        self.tnode = None
        self.neighbors = []

    def add_neighbor(self, x):
        self.neighbors.append(x)

class Graph(object):    
    def __init__(self):
        self.nodes=[]
        self.edges=[]

    def add_node(self, n):
        self.nodes.append(n)

    def add_edge(self,n,m):
        self.edges.append((n,m))
        n.add_neighbor(m)
        m.add_neighbor(n)

class TNode(Node):
    def __init__(self,node, parent):
        self.node=node
        self.parent = parent
        self.children = []
        self.neighbors=node.neighbors
        node.tnode=self

    def add_child(self,n):
        self.children.append(n)
        
    def desc(self):
        a=[]
        b=self.children
        while len(b)>0:
            i=b[0]
            b.remove(i)
            a.append(i)
            b+=i.children
        return a
    
class Tree(object):
    def __init__(self,root):
        self.nodes=[TNode(root,None)]
        self.edges=[]
        self.root = root

    def add_node(self,n,parent):
        m=TNode(n,parent)
        self.nodes.append(m)
        parent.add_child(m)
        
inp=open("C-small-attempt1.in","r")
outp=open("Cs_oupt.txt","w")
lines = inp.readlines()
lines=[re.sub('\n','',line) for line in lines]

def rem(l,x):
    if x in l:
        return l.remove(x)
    else:
        return l

def ans(g):
    l=g.nodes
    l.sort(key=lambda x:x.data)
    t=Tree(l.pop(0))
    answer=t.root.data
    for i in t.root.neighbors:
        i.arriv.append(t.root)
    while len(l)>0:
        count=0
        node=None
        while count<len(l) and node is None:
            if len(l[count].arriv)>0:
                node=l[count]
            else:
                count+=1
        if node is None:
            print "ERROR"
            return "ERROR"
        l.remove(node)
        answer+=node.data
        for i in node.neighbors:
            i.arriv.append(node)
        p = node.arriv[-1]
        t.add_node(node,p.tnode)
        for n in p.tnode.desc():
            for j in n.neighbors:
                rem(j.arriv,n)
    del g
    del t
    return answer

k=int(lines.pop(0))
for i in range(k):
    [a,b]=map(int,re.split(' ',lines.pop(0)))
    g=Graph()
    for j in range(a):
        g.add_node(Node(lines.pop(0)))
    for j in range(b):
        [x1,x2]=map(lambda x:int(x)-1,re.split(' ',lines.pop(0)))
        g.add_edge(g.nodes[x1],g.nodes[x2])
    outp.write("Case #"+str(i+1)+": "+ans(g)+"\n")
outp.close()
