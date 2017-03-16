#!/usr/bin/python


#f = open('a_consonants_sample.txt')
f = open('A-small-attempt0.in')
inputline = f.readline()
numcase = int(inputline)

fout = open('a_consonants_small_result.txt', 'w')

def check_consonant(word, n):
  long_cons = 0
  qualify = False
  for i in word:
    if i in "aiueo":
      long_cons = 0

    else:
      long_cons += 1
      if long_cons == n:
        qualify = True
        break
  #print " checking=",word," n=",n," result=",qualify 
  return qualify

for i in range (0,numcase):
  inputline = f.readline()
  linelist = inputline.split()
  word = linelist[0]
  n = int(linelist[1])
  answer = 0

  wlen = len(word)
  #print "wlen=",wlen
  for j in range(0,wlen):
    for k in range(n,wlen+1):
      if k >= (j + n):
        if check_consonant(word[j:k],n):
          answer += 1

  answ_sentence = "Case #"+str(i+1)+": "+ str(answer)
  fout.write(answ_sentence)
  fout.write('\n')
  print answ_sentence