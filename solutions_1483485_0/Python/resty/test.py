a = ['ejp mysljylc kd kxveddknmc re jsicpdrysi', 
	 'rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd',
	 'de kr kd eoya kw aej tysr re ujdr lkgc jv']
b = ['our language is impossible to understand',
     'there are twenty six factorial possibilities',
     'so it is okay if you want to just give up']

d = {}
for i in xrange(len(a)):
    for j in xrange(len(a[i])):
            if a[i][j] != ' ':
                    d[a[i][j]] = b[i][j]
#x = [(d[i]) for i in d]
d['z'] = 'q';
d['q'] = 'z';
        
d['\n'] = ''

import sys
skip = input()
case = 0
for line in sys.stdin:
    now = ""
    for x in line:
       if x in d:
          now += d[x]
       else:
          now += x
    case += 1
    print "Case #%d: %s" %(case, now)


