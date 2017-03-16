import sys

a = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv"
b = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up"
dict = {}

for i in xrange(len(a)):
    dict[a[i]] = b[i]
dict["y"] = "a"
dict["e"] = "o"
dict["q"] = "z"
dict["z"] = "q"

file = open(sys.argv[1])
nc = int(file.readline().rstrip())

def foo(s):
    result = ""
    for i in xrange(len(s)):
        result += dict[s[i]]
    return result

for i in xrange(nc):
    s = file.readline().rstrip()
    s = foo(s)
    print "Case #{}: {}".format(i+1,s)
