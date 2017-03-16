'''
Created on Apr 25, 2013

@author: yexijiang
'''

from sys import stdin
import math

def process_case():
  r, t = [int(num) for num in stdin.readline().split()]
  
  count = 0
  while True:
    area = math.pi * (2 * r + 1)
#     print t
    if area <= t * math.pi:
      t -= area / math.pi
      count = count + 1
      r = r + 2
    else:
      break
      
  return count

if __name__ == '__main__':
  cases = int(stdin.readline())
  with open('result.txt', 'w') as f:
    for count in range(cases):
#       print("Case #{0}: {1}".format(count + 1, process_case()))
      f.write("Case #{0}: {1}\n".format(count + 1, process_case()))