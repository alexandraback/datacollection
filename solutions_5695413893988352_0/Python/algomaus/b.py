#! /usr/bin/env python

def parse(lines):
  n = int(lines[0])
  words = []
  for i in range(n):
    words.append(lines[i+1])
  return words
  
def asInt(string, lastPosition):
  if lastPosition == -1:
    return 0
  
  #if lastPosition == 0 and string[0] == '?':
    #return 0

  lis = []
  for i in range(lastPosition+1):
    lis.append(string[i])
  return int(''.join(lis).replace(' ','').replace('[','').replace(']','').replace(',',''))
  
def solve(word):
  splitted = word.split(' ')
  coder = []
  jammer = []
  for i in splitted[0]:
    coder.append(i)
  for i in splitted[1]:
    jammer.append(i)
  
  coder_add = []
  jammer_add = []
  
  for i in range(len(coder)):
    if coder[i] == '?' and jammer[i] == '?':
      if i == 0 or (asInt(coder, i-1) == asInt(jammer, i-1)):
        if i+1 < len(coder) and coder[i+1] != '?' and jammer[i+1] != '?':
          if coder[i+1] > jammer[i+1]:
            coder[i] = '0'
            coder_add.append('0')
            jammer[i] = '1'
            jammer_add.append('1')
          elif coder[i+1] < jammer[i+1]:
            coder[i] = '1'
            coder_add.append('1')
            jammer[i] = '0'
            jammer_add.append('0')
          else:
            coder[i] = '0'
            coder_add.append(0)
            jammer[i] = '0'
            jammer_add.append(0)
        else:
          coder[i] = '0'
          coder_add.append(0)
          jammer[i] = '0'
          jammer_add.append(0)
      elif asInt(coder, i-1) > asInt(jammer, i-1):
        coder[i] = '0'
        coder_add.append(0)
        jammer[i] = '9'
        jammer_add.append(9)
      else:
        coder[i] = '9'
        coder_add.append(9)
        jammer[i] = '0'
        jammer_add.append(0)
        
  
    elif coder[i] == '?':
      if asInt(coder, i-1) == asInt(jammer, i-1):
         coder[i] = jammer[i]
         coder_add.append(jammer[i])
      
         #if int(jammer[i]) <= 5:
          #coder[i] = '0'
          #coder_add.append(0)
         #else:
          #coder[i] = '9'
          #coder_add.append(9)
      elif asInt(coder, i-1) > asInt(jammer, i-1):
        coder[i] = '0'
        coder_add.append(0)
      else:
        coder[i] = '9'
        coder_add.append(9)
    elif jammer[i] == '?':
      if asInt(coder, i-1) == asInt(jammer, i-1):
        jammer[i] = coder[i]
        jammer_add.append(coder[i])
      
        #if int(coder[i]) <= 5:
        #  jammer[i] = '0'
        #  jammer_add.append(0)
        #else:
        #  jammer[i] = '9'
        #  jammer_add.append(9)
      elif asInt(coder, i-1) < asInt(jammer, i-1):
          jammer[i] = '0'
          jammer_add.append(0)
      else:
          jammer[i] = '9'
          jammer_add.append(9)
  
  coder_add_str = str(coder).replace(' ','').replace('[','').replace(']','').replace(',','').replace('\'','')
  jammer_add_str = str(jammer).replace(' ','').replace('[','').replace(']','').replace(',','').replace('\'','')
  
  return coder_add_str + " " + jammer_add_str
    
#with open('A-large.in', 'r') as f:
with open('B-small-attempt1.in', 'r') as f:
  words = parse(f.read().splitlines())
for i in range(len(words)):
  wordSorted = solve(words[i])
  print "Case #" + str(i+1) + ": " + wordSorted
