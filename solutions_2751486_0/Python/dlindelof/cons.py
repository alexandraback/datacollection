#!/usr/bin/python

def cons_pos(string):
  for (i, c) in enumerate(string):
    if c not in "aeiou":
      yield i

def sub_all_cons(string, pos, n):
  if pos+n > len(string):
    return False
  for (i, c) in enumerate(string[pos:pos+n]):
    if c in "aeiou":
      return False
  return True

def substr_containing_pos_n(string, pos, n):
  for start in xrange(pos+1):
    for end in xrange(pos+n, len(string)+1):
        yield (start, end)

if __name__ == "__main__":
  T = int(raw_input())
  for t in range(1, T+1):
    (string, n) = raw_input().split()
    n = int(n)
    substrings = set()
    for p in cons_pos(string):
      if sub_all_cons(string, p, n):
        for s in substr_containing_pos_n(string, p, n):
          substrings.add(s)
    print "Case #%d: %d" % (t, len(substrings))

