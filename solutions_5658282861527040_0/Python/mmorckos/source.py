#!/usr/bin/python

''' New Lottery Game'''
def new_lottery_game (filename):
  inFile = open (filename, 'r')
  outFile = open ('output.out', 'w')

  num_cases = int (inFile.readline ().strip ())
  for i in range (0, num_cases):
    line = inFile.readline ().strip ()
    lst = [int(x) for x in line.split(' ')]
    A = lst[0]
    B = lst[1]
    K = lst[2]
    combination = A * B
    diff = 0
    if (B < A):
      print "CRASH CRASH"
      tmp = A
      A = B
      B = tmp

    if not (K > A and K > B):
      tmp = K
      while tmp < A:
        for x in range (K, B):
          if tmp & x >= K:
            diff += 1
        tmp += 1

    outFile.write ("Case #" + str (i + 1) + ": " + str (combination - diff) + '\n')
  outFile.close ()
  inFile.close ()

def main ():
  new_lottery_game ("B-small-attempt0.in")
main ()