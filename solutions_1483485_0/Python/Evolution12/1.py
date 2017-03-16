import sys


if __name__ == '__main__':
  l4 = list("our language is impossible to understand")
  l5 = list("there are twenty six factorial possibilities")
  l6 = list("so it is okay if you want to just give up")
  l1 = list("ejp mysljylc kd kxveddknmc re jsicpdrysi") 
  l2 = list("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd")
  l3 = list("de kr kd eoya kw aej tysr re ujdr lkgc jv")
  
  d ={}
  for i in range(0, len(l1)):
    d[l1[i]] = l4[i]
  for i in range(0, len(l2)):
    d[l2[i]] = l5[i]
  for i in range(0, len(l3)):
    d[l3[i]] = l6[i]
  d['z'] = 'q'
  d['q'] = 'z'

  inputs = raw_input()
  count = 1 
  for i in range(0, int(inputs)):
    l = list(raw_input())
    print "Case #" + str(count) + ": ",
    for i in l:
      sys.stdout.write(	d[i]),
    count = count + 1
    print
