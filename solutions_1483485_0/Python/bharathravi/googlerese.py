#!/usr/bin/python
import string

codes = ['ejp mysljylc kd kxveddknmc re jsicpdrysi', \
'rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd', \
'de kr kd eoya kw aej tysr re ujdr lkgc jv']

trans = ['our language is impossible to understand', \
'there are twenty six factorial possibilities', \
'so it is okay if you want to just give up']


transmap = {}


for j in range(0, len(codes)):
  code = codes[j]
  tran = trans[j]
  for i in range(0, len(code)):
    thischar = code[i]
    if thischar == ' ':
      continue

    if thischar in transmap:
      if transmap[thischar] != tran[i]:
        print 'ERROR'
    else:
      transmap[thischar] = tran[i]

transmap['z'] = 'q'
transmap['q'] = 'z'


f = open('input')
num = int(f.readline())

for i in range(0, num):
  output = 'Case #' + str(i+1) + ': '
  line = f.readline().rstrip()
  for j in range(0, len(line)):
    if line[j] == ' ':
      output += ' '
    else:
      output += transmap[line[j]]
  print output

