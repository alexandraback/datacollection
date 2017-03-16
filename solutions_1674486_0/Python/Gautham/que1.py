import fileinput
import string

def intersect(a, b):
    """ return the intersection of two lists """
    return list(set(a) & set(b))

def union(a, b):
    """ return the union of two lists """
    return list(set(a) | set(b))

ofile = open('out.txt','w')
T = 0
count = 0
x = 0
case = 0
arr = []
for line in fileinput.input(): 
     if case == 0:
          T = int(line)
          case = 1
          #print line
     elif case == 1:       
          N = int(line)
          case = 2
          count = 0
          #print line
     elif case == 2:
          #print line
          sp = line.split()
          arr.append(map(int,sp[1:]))
          count+=1
          if(count == N):
               ofile.write("Case #"+str(x+1)+': ')
               found = 0
               arr2 = arr
               arr3 = []
               for k in range(N):
                    for i in range(N):
                         for j in range(len(arr[i])):
                              if not(intersect(arr[i],arr2[arr[i][j]-1]) == []):
                                   ofile.write("Yes\n")
                                   found = 1
                                   break
                              else:
                                   arr[i] = (union(arr[i],arr2[arr[i][j]-1]))
                                   arr3.append(arr2[arr[i][j]-1])
                                   #print arr
                         if(found == 1):
                              break
                    arr2 = arr3
                    if(found == 1):
                         break
               if(found == 0):
                    ofile.write("No\n")
               
               x += 1
               case = 1

ofile.close()
 
