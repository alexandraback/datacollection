import string
import sys

decoder = string.maketrans(' acbedgfihkjmlonqpsrutwvyxz', ' yehosvcdxiulgkbzrntjwfpamq')

T = int(sys.stdin.readline())
for case in xrange(T):
    print "Case #%d: %s" % (case + 1, sys.stdin.readline().strip().translate(decoder))

    
