import sys
import string
inp = sys.stdin
T = int(inp.readline())

table = string.maketrans('acbedgfihkjmlonpsrutwvyxqz',
                         'yehosvcdxiulgkbrntjwfpamzq')

for cas in xrange(1, T + 1):
  print "Case #%d:" % cas,
  print string.translate(inp.readline().strip(), table)
