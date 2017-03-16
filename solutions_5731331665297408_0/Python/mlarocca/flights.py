'''
Created on 12/apr/2014

@author: mlarocca
'''
from sys import argv
from copy import copy

def read_input(f):
  lines = open(f, 'r')
  N = int(lines.readline().strip())
  

  for i in xrange(N):
    
    n, m = map(int, lines.readline().strip().split(" "))
    G = {i: [] for i in xrange(n)}  #graph
    min_lab_val = float('inf')
    min_lab_idx = 0
    labels = []
    labels_values = []
    for j in xrange(n):
      lab = lines.readline().strip()
      labels.append(lab)
      lab = int(lab)
      labels_values.append(lab)
      if min_lab_val > lab:
        min_lab_val = lab
        min_lab_idx = j

    for k in xrange(m):
      #vertices starts from one in input
      e_from, e_to = map(lambda x: int(x) - 1, lines.readline().strip().split(" "))
      G[e_from].append(e_to) 
      G[e_to].append(e_from) 

    yield i+1, G, labels, labels_values, min_lab_idx
    

def dfs(G, labels, labels_values, source):
  
  res = []
  visited = set()

  def rec_dfs(v, reachable_prev_lev, least_prev_level):
    visited.add(v)
    res.append(labels[v])
    
    next_labels = []
    
    for u in G[v]:
      if not u in visited:
        next_labels.append((labels_values[u], u))
    next_labels = sorted(next_labels, reverse=True)
    #print v,  next_labels, reachable_prev_lev, least_prev_level
    
    while len(next_labels) > 0:
      label, u = next_labels.pop()
      if u in visited:
        continue
      
      reachable = {v for (_, v) in next_labels if not (v in visited)}

      if label <= least_prev_level:
        if len(next_labels) > 0:
          if len(reachable - reachable_prev_lev) == 0:
            min_label =  min(next_labels[-1][0], least_prev_level)
          else:
            min_label = next_labels[-1][0]
        else:
          min_label = least_prev_level

        rec_dfs(u, reachable | reachable_prev_lev, min_label)
      else:
        if len((reachable | set([u])) - reachable_prev_lev) == 0:
          #all the adjacent vertices can be reached by previously visited vertices, and none will have a smaller label than the one reachable previously
          #print v ,u , "EEEE"
          return
        else:
          if len(next_labels) > 0:
            min_label =  min(next_labels[-1][0], least_prev_level)
          else:
            min_label = least_prev_level
          rec_dfs(u, reachable | reachable_prev_lev, min_label)

 
  rec_dfs(source, set(), float('inf'))   
  #print visited
  #print ''.join(res)
  #assert(len(visited) == len(G))
  return ''.join(res)


if __name__ == '__main__':
  for test_case, G, labels, labels_values, min_lab_idx in read_input(argv[1]):
    #print test_case, G, labels, labels_values, min_lab_idx
    #print bin(int(A))
    #print bin(int(B))
    #print bin(int(K))
    #print " - - - "
    res = dfs(G, labels, labels_values, min_lab_idx)
    print "Case #%d: %s" % (test_case, res)
