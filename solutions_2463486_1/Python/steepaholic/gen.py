import sys
import math

num=int(sys.argv[1])
bound=int(math.ceil(math.sqrt(num)))
print "bound = %d" % bound

for i in range(1, bound):
    if str(i)[::-1] <> str(i):
        continue
    asdf = i * i
    if str(asdf)[::-1] <> str(asdf):
        continue
    print "%d," % asdf,
