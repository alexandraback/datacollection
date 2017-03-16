'''
Created on 28-04-2012

@author: Hokanos
'''
import sys
import math
from collections import deque
def bfs(g,s):
    qu = deque([])
    odw = []
    for i in range(len(g)):
        odw.append(0)
    
    odw[s] += 1
    for i in range(len(g[s])):
        qu.append(g[s][i])
    
    while(len(qu) != 0):
        v = qu.popleft()
        odw[v] += 1
        if(odw[v] > 1):
            return True
            
        for i in range(len(g[v])):
            qu.append(g[v][i])
    
    return False
        
def main():
    f = open(sys.argv[1],"r")
    fw = open("out.out","w")
    nn = int(f.readline())
    #print("bla bla")
    #print(nn)
    for i in range(nn):
        v = f.readline().rstrip().split(" ")
        n = int(v[0])
        biggest = 0
        graf = []
        odw = []
        graf.append(0)
        for j in range(n):
            l = f.readline().rstrip().split(" ")
            print(l)
            count = int(l[0])
            tab = []
            odw.append(0)
            for k in range(count):
                tab.append(int(l[k+1]))
            
            graf.append(tab)
            if biggest == 0:
                biggest = j+1
            else:
                if len(graf[biggest]) < len(tab):
                    biggest = j+1
                
            print(tab)
        
        print(biggest)
        ret = bfs(graf,biggest)
        if(ret == False):
            for j in range(1,len(graf)):
                if j == biggest:
                    continue
                
                ret = bfs(graf,j)
                if(ret == True):
                    break
        
        if(ret == True):
            fw.write("Case #"+str(i+1)+": Yes\n") 
        else:
            fw.write("Case #"+str(i+1)+": No\n")     
    fw.close()
    f.close()
    
main()     