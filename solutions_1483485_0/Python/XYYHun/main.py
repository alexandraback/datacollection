Input = open('Input','r')
Output = open('Output','w')

dict_from = '''our language is impossible to understand
there are twenty six factorial possibilities
so it is okay if you want to just give up'''

dict_to = '''ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv'''

# built dict.
d = dict()
for index, char in enumerate(dict_to) :
  d[char] = dict_from[index]
d['q'] = 'z'
d['z'] = 'q'

print d

for i in xrange(0, int(Input.readline())) :

  Output.write("Case #%s: " % (i+1))

  for char in Input.readline() :
    Output.write(d[char])

