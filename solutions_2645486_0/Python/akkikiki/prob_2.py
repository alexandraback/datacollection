#!/usr/bin/python
# coding: UTF-8

# T can be either X or O so replace it by both

def check_same(input_list):
  return input_list == [input_list[0]] * len(input_list)


def search(array, val_array, N, total, now_answer, R, now_ene):
  # be careful of out-of-one error
  if N == 0: 
    #print now_answer
    temp_ans = max(now_answer.pop(), total)
    now_answer.append(temp_ans)
    return
  
  for elem in array:
    if now_ene - elem < 0: continue #pruning
    temp_val_array = val_array
    top = temp_val_array.pop(0)
    temp_total = total
    total += elem * top
    #recharge it
    now_ene_temp = min(now_ene - elem + R, E)
    temp_array = [i for i in range(now_ene_temp + 1)]
    search(temp_array, temp_val_array, N-1, total, now_answer, R, now_ene_temp)
    total = temp_total
    temp_val_array.insert(0, top)
    #print temp_val_array

if __name__ == "__main__":
  f = open('B-small-attempt1.in')
  f_out = open('prob_2_out_small.txt', 'w')
  #f = open('input-task-1.txt')
  #f_out = open('output_prob_1_small', 'w')
  T = int(f.readline()[:-1]) # of input cases
  
  for i in range(T):
    e, r, n = f.readline()[:-1].split()
    E = int(e)
    R = int(r)
    N = int(n)
    temp = f.readline()[:-1].split()
    #print temp
    answer = []
    v_array = []
    for e in temp:
      #print e
      v_array.append(int(e))
    #print v_array
    array = [j for j in range(E+1)]
    if E == R:
      t = E * sum(v_array)
      f_out.write("Case #" + str(i+1)+ ": " + str(t) + "\n")
    else:  
      now_answer = [1, 0]
      search(array, v_array, N, 0, now_answer, R, E) 
      f_out.write("Case #" + str(i+1)+ ": " + str(now_answer[1]) + "\n")

