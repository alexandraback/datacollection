#!/usr/bin/python
# coding: UTF-8

# T can be either X or O so replace it by both

def check_same(input_list):
  return input_list == [input_list[0]] * len(input_list)


def calc(ra, ml):
  total = 0
  ret = 0
  while total <= ml:
    total += 2 * ra + 1
    ra += 2
    ret += 1
  ret -= 1
  return ret

if __name__ == "__main__":
  #f = open('input-task-1-A.txt')
  #f_out = open('prob_1_out_sample.txt', 'w')
  f = open('A-small-attempt0.in')
  f_out = open('output_prob_1_small', 'w')
  T = int(f.readline()[:-1]) # of input cases
  
  for i in range(T):
    r, t = f.readline()[:-1].split()
    int_r = int(r)
    int_t = int(t)
    result = calc(int_r, int_t)
    f_out.write("Case #" + str(i+1 )+ ": " + str(result) + "\n")

