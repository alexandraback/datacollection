import re
# input() reads a string with a line of input, stripping the '\n' (newline) at the end.
# This is all you need for most Google Code Jam problems.
t = int(input())  # read a line with a single integer
for i in range(1, t + 1):
  
  
  n = [s for s in input()]  # read a list of integers, 2 in this case
  index = 0
  while index < len(n)-1:
    if n[index]  == n[index+1]:
       n.pop(index+1)
       continue  
    index += 1
  answer = len(n)-1 if  n[-1]=="+" else len(n) 
  print("Case #{}: {}".format(i, answer))
  # check out .format's specification for more formatting options