'''
Created on Apr 25, 2013

@author: yexijiang
'''

from sys import stdin
import math

def process_case():
  r, t = [int(num) for num in stdin.readline().split()]
  ink = t * math.pi
  
  count = 0
  while True:
    if 2 * math.pi * r * count + math.pi * (1 + count) * count <= ink:
      count = count + 1
    else:
      break
      
  return count

if __name__ == '__main__':
  cases = int(stdin.readline())
  with open('result.txt', 'w') as f:
    for count in range(cases):
#       print("Case #{0}: {1}".format(count + 1, process_case()))
      f.write("Case #{0}: {1}\n".format(count + 1, process_case()))