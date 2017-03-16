def sol(S):
  R = S[0]
  for c in S[1:]:
    if c >= R[0]:
      R = c + R
    else:
      R = R + c
  return R

# print sol("CAB")
# print sol("JAM")
# print sol("CODE")
# print sol("ABAAB")
# print sol("CABCBBABC")
# print sol("ABCABCABC")
# print sol("ZXCASDQWE")
t = long(raw_input())  # read a line with a single integer

for i in xrange(1, t + 1):
    S = raw_input()
    print "Case #{}: {}".format(i, sol(S))
