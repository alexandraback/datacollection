'''
Created on Apr 25, 2013

@author: yexijiang
'''

from sys import stdin

def process_case():
  E, R, N = [int(num) for num in stdin.readline().split()]
  vec = [int(num) for num in stdin.readline().split()]
  return simu(E, E, R, vec, 0, 0)
  
def simu(E, maxE, R, vec, idx, gain):
  if idx == len(vec):
    return gain
  else:
    newE = E
    if idx != 0:  #regain
      newE = min(newE + R, maxE)
    gains = [simu(newE - i, maxE, R, vec, idx + 1, gain + i * vec[idx]) for i in range(0, newE + 1)]
    return max(gains)

if __name__ == '__main__':
  cases = int(stdin.readline())
  with open('result.txt', 'w') as f:
    for count in range(cases):
#       print("Case #{0}: {1}".format(count + 1, process_case()))
      f.write("Case #{0}: {1}\n".format(count + 1, process_case()))
      
