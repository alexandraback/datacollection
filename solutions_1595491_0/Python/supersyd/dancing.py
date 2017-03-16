f= open('B-small-attempt0.in')
txt = f.read()
f.close()
txt = txt.strip().split('\n')

t = int(txt[0])
txt = txt[1:]

string = ""

for i in range(t):
  cases = txt[i].split()
  surprises = int(cases[1])
  max_score = int(cases[2])
  n = cases[0]
  cases = cases[3:]
  
  scores = []
  bigger = 0 
  potent = 0 
  #assume flat cases. 
  for j in range(len(cases)):
    c = int(cases[j]) 
    no = int(c/3)
    scores.append(str(no)+str(no))
    if c % 3 == 0:
      scores[j] += str(no)
      if no >= max_score: bigger += 1
      elif no ==max_score-1 and no != 0: potent += 1 
    elif c % 3 == 1:
      scores[j] += str(no+1)
      if no+1 >= max_score: bigger += 1
    else:
      scores[j] = str(no+1)+str(no+1)+str(no)
      if no+1 >= max_score: bigger += 1 
      elif no+1 == max_score-1: potent += 1
  if potent > surprises: potent = surprises 
  answer = bigger + potent 
  string += "Case #"+str(i+1)+": " +str(answer)+ "\n" 

print string
f = open('out','w')
f.write(string)
f.close()


