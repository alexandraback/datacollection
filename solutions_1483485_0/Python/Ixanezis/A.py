import sys
t = int(sys.stdin.readline())
s1 = "qzejp mysljylc kd kxveddknmc re jsicpdrysi | rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd | de kr kd eoya kw aej tysr re ujdr lkgc jv"
s2 = "zqour language is impossible to understand | there are twenty six factorial possibilities | so it is okay if you want to just give up"
mapping = dict()
for a,b in zip(s1, s2):
    mapping[a] = b
 
for i, line in enumerate(sys.stdin.readlines()):
    if line.strip() == '': break
    print "Case #{0}: ".format(i+1) + ''.join(map(lambda x: mapping[x], line.strip()));

