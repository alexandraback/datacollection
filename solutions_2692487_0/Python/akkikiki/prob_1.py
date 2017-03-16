#!/usr/bin/python
# coding: UTF-8

# T can be either X or O so replace it by both

#A is the initial value
def valid(input_list, A, temp_N):
  temp_sum = A
  ops = 0
  i = 0
  while i < temp_N:
    #print i, temp_N
    if temp_sum > input_list[i]:
      temp_sum += input_list[i]
      i += 1
    else:
      temp_sum += temp_sum - 1
      ops += 1
  # ith indice is the bad part
  return ops
  # this time, -1 stands for good


if __name__ == "__main__":
  #f = open('input-task-1.txt')
  #f_out = open('prob_1_out.txt', 'w')
  f = open('A-small-attempt2.in')
  f_out = open('output_prob_1_small', 'w')
  T = int(f.readline()[:-1]) # of input cases
  for i in range(T):
    temp_A, temp_N = f.readline()[:-1].split(' ')
    temp_values = f.readline()[:-1].split(' ')
    #print temp_values
    values = []
    for e in temp_values:
      values.append(int(e))
    values.sort()
    #print values
    A = int(temp_A)
    N = int(temp_N)
    #print 'case ' + str(i+1)
    result = N
    if A != 1:
      result = valid(values, A, N)
      for j in range(N):
        temp_result = valid(values[:-(j + 1)], A, N-(j+1))
        temp_result += j+1
        result = min(temp_result, result)
    f_out.write("Case #" + str(i+1 )+ ": " + str(result) + "\n")
