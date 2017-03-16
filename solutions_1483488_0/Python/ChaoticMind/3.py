#!/usr/bin/python -tt

import sys

index = {}

def compute(A, B): 
  for k in range(B-A):
    i = k+A
    
    eq = list(str(i))
    for z in range(len(eq)-1):
      #print eq
      eq.append(eq.pop(0))
      if eq[0] == '0':
        continue
      permuted = int(''.join(eq))
      
      if (permuted >= A and permuted <= B and not permuted == i):
        mininmum = min(permuted, i)
        maximum = max(permuted, i)
        if mininmum not in index:
          index[mininmum] = [maximum]
        elif maximum not in index[mininmum]:
          index[mininmum].append(maximum)
    
    #print 
  return

def main():
  f = open("C-small-attempt0.in", 'rU')
  lines = f.readline()
  
  output = open('output', 'w')
  for i in range(int(lines)):
    line = map(int, f.readline().split(" "))
    A = line.pop(0)
    B = line.pop(0)
    #A = 100
    #B = 500
    index.clear()
    out = compute(A, B)
    
    #print index
    counter = 0
    for k in index.values():
      for j in k:
        counter = counter + 1
    #print counter
    
    #sys.exit()
    #print out
    output.write("Case #"+str(i+1)+': '+str(counter)+'\n')
    #print "Case #",print str(i+1), out, 
  f.close()
  output.close()
  
if __name__ == '__main__':
  main()

