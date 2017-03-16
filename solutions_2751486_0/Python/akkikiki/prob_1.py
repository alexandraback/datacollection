#!/usr/bin/python
# coding: UTF-8

# T can be either X or O so replace it by both

def count_consonant(name):
  vowel = ['a', 'i', 'u', 'e', 'o']
  score = 0
  max_score = 0
  prev_consonant = False
  for char in name:
    if prev_consonant and not char in vowel:
      score += 1 
      
    elif not char in vowel: # voel needs to be defined
      score += 1
      prev_consonant = True
   
    else:
      max_score = max(score, max_score)
      score = 0
      prev_consonant = False
  max_score = max(score, max_score)
  return max_score

if __name__ == "__main__":
  #f = open('input-task-1.txt')
  #f_out = open('prob_1_out.txt', 'w')
  f = open('A-small-attempt0.in')
  f_out = open('output_prob_1_small', 'w')
  T = int(f.readline()[:-1]) # of input cases
  
  for i in range(T):
    name, temp_n = f.readline()[:-1].split()
    n = int(temp_n)
    L = len(name)
    result = 0
    for j in range(L):
      for k in range(j+1, L+1):
        temp_name = name[j:k]
        score = count_consonant(temp_name)
        print temp_name, score
        if score >= n:
          result += 1
    f_out.write("Case #" + str(i+1 )+ ": " + str(result) + "\n")

