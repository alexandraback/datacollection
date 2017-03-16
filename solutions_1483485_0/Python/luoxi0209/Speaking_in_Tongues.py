import sys

x = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv"
y = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up"

ma = {}
for i in range(len(x)):
    ma[x[i]] = y[i]
ma['z'] = 'q'
ma['q'] = 'z'
case = int(raw_input())
for i in range(1, case + 1):
    line = sys.stdin.readline()
    sys.stdout.write("Case #%d: " % i)
    for w in line:
        if w != "\n": 
            sys.stdout.write(ma[w])
    sys.stdout.write("\n")
