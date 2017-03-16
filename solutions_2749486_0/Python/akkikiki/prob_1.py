#!/usr/bin/python
# coding: UTF-8

# T can be either X or O so replace it by both

if __name__ == "__main__":
  #f = open('input-task-1.txt')
  #f_out = open('prob_1_out.txt', 'w')
  f = open('B-small-attempt0.in')
  f_out = open('output_prob_1_small', 'w')
  T = int(f.readline()[:-1]) # of input cases
  
  for i in range(T):
    temp_X, temp_Y = f.readline()[:-1].split()
    X = int(temp_X)
    Y = int(temp_Y)
    #print X, Y
    result = []
    if X > 0:
      result.append('WE' * X)
    if X < 0:
      result.append('EW' * (-1 * X))
    if Y > 0:
      result.append('SN' * Y)
    if Y < 0:
      result.append('NS' * (-1 * Y))
    f_out.write("Case #" + str(i+1 )+ ": " + ''.join(result) + "\n")

