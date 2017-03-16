a= "ejp mysljylc kd kxveddknmc re jsicpdrysi"
a+= " rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd"
a+= " de kr kd eoya kw aej tysr re ujdr lkgc jv"
a+= " y qeez"

b= "our language is impossible to understand"
b+=" there are twenty six factorial possibilities"
b+=" so it is okay if you want to just give up"
b+=" a zooq"

# print "".join(sorted(set(a)))
# print "".join(sorted(set(b)))

import sys

m = {}

for i in range(len(a)) :
    m[a[i]] = b[i]


N = int(sys.stdin.readline())
case = 1
for l in sys.stdin :
    o = ""
    l = l.strip("\n")
    for c in l :
	o += m[c]
    print "Case #"+str(case)+": "+o 
    case +=1
