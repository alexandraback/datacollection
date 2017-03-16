#!/usr/bin/python


#f = open('A-sample.in')
f = open('A-large.in')
inputline = f.readline()
numcase = int(inputline)

fout = open('a_result_large.txt', 'w')

prob=[]
  

for i in range (0,numcase):
  line = f.readline()
  linelist = line.split()
  numcont = int(linelist[0])
  scores=[]
  totscore = 0
  min_score = 0
  for j in range(1,numcont+1):

    this_score = int(linelist[j])
    if j == 1:
      min_score = this_score
    elif this_score < min_score:
      min_score = this_score
    scores.append(this_score)
    totscore = totscore + this_score 
  answers = []
  answ_sentence = "Case #"+str(i+1)+":"
  #print "total_score="+str(totscore)
  num_safe = 0.0
  avg_safe = (2.0*totscore)/numcont
  totpoints_safe = 0
  for j in range (0,numcont):
    if scores[j] >= avg_safe:
      num_safe = num_safe + 1
      totpoints_safe += scores[j] 
  #print " numcont="+str(numcont)+" num_safe="+str(num_safe)+"avg_safe="+str(avg_safe)
  avg_safe = ((2.0*totscore)-totpoints_safe) / (numcont-num_safe)
  #print "avg_safe="+str(avg_safe)+" num_safe="+str(num_safe)+" totsafe="+str(totpoints_safe)
  for j in range (0,numcont):
    #print " score="+str(scores[j])
    req_score = avg_safe - scores[j]
    #print " req_score="+str(req_score)
    #answers.append(req_score/totscore)
    if req_score < 0:
      needed = 0.0
    else:
      needed = 100.0*req_score/totscore
    answ_sentence = answ_sentence + " " + '%.6f' % (needed)

    #current_prob = current_prob * prob[j]
  fout.write(answ_sentence)
  fout.write('\n')
  #print answ_sentence
  #print "Case #"+str(i+1)+": "+ '%.6f' % answer

f.close()
fout.close()

