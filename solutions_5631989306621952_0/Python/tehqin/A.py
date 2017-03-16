
T = int(raw_input())

for tc in range(1, T+1):

   s = raw_input()
   res = s[0]
   for c in s[1:]:
      if c < res[0]:
         res = res + c
      else:
         res = c + res
   print 'Case #%d: %s' % (tc, res)
