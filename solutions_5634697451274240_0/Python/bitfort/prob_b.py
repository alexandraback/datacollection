

# Let's say we always "merge" pancakes if they are touching and have the same
# side facing up

# In our merged stack, then we will always alternate.
# So we only need to keep track of the face of the top pancake, plus the
# number of "merged" pancakes in the stack...

happy = [None for i in xrange(101)]
sad = [None for i in xrange(101)]


# now... let us think of what a "fip" would be for this merged stack...
# for a happy stack (top pancake is happy), we have two interesting cases: 
# (h1) +-+-+-+-...+ (odd length stack)
# (h2) +-+-+-+-...- (even length stack)
# For sad, we have 2 similar cases:
# (s1) -+-+-+-...- (odd length stack)
# (s2) -+-+-+-...+ (even length stack)
#
#   h1:
#        1    h1 -> s2 (length--)
#        2    h1 -> h1
#        all  h1 -> s1
#   h2:
#        1    h2 -> s1 (length--)
#        2    h2 -> h2
#        all  h2 -> h2
#   s1:
#        1    s1 -> h2 (length--)
#        2    s1 -> s1
#        all  s1 -> h1
#   s2:
#        1    s2 -> h1 (length--)
#        2    s2 -> s2
#        all  s2 -> s2


# now we need to seed our base cases...
happy[1] = 0 # +
happy[2] = 2 # +-
sad[1] = 1 # -
sad[2] = 1 # -+

# populate our lookup
def pop_lookup():
  for i in xrange(2, 101):
    if i % 2 == 0:
      # this case is h2 and s2
      happy[i] = sad[i - 1] + 1
      sad[i] = happy[i - 1] + 1
    else:
      # this case is h1 and s1
      happy[i] = min(sad[i - 1] + 1, happy[i - 1] + 2)
      sad[i] = min(happy[i - 1] + 1, happy[i] + 1)


def convert(s):
  l = 0
  prev = None
  for c in s:
    if c != prev:
      prev = c
      l += 1
  return s[0], l


def solve(first, l):
  if first == '+':
    return happy[l]
  if first == '-':
    return sad[l]


pop_lookup()

def doit(x):
  first, l = convert(x)
  return solve(first, l)


t = raw_input()
for n in xrange(int(t)):
  s = raw_input()
  print 'Case #{}: {}'.format(n + 1, doit(s))
